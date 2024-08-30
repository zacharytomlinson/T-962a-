#include <stdint.h>
#include "circbuffer.h"

/**** Circular Buffer used by UART ****/

void init_circ_buf(tcirc_buf *cbuf) {
	cbuf->head = cbuf->tail = 0;
	cbuf->dropped = 0;
}

void add_to_circ_buf(tcirc_buf *cbuf, const char ch, const int block) {
	// Add char to buffer
	unsigned int newhead = cbuf->head + 1;
	if (newhead >= CIRCBUFSIZE) {
		newhead = 0;
	}
	while (newhead == cbuf->tail) {
		if (!block) {
			cbuf->dropped++;
			return;
		}

		// If blocking, this just keeps looping. Due to interrupt-driven
		// system the buffer might eventually have space in it, however
		// if this is called when interrupts are disabled it will stall
		// the system, so the caller is cautioned not to fsck it up.
	}

	cbuf->buf[cbuf->head] = ch;
	cbuf->head = newhead;
}


char get_from_circ_buf(tcirc_buf *cbuf) {
	// Get char from buffer
	// Be sure to check first that there is a char in buffer
	unsigned int newtail = cbuf->tail;
	const uint8_t retval = cbuf->buf[newtail];

	if (newtail == cbuf->head) {
		return 0xFF;
	}

	newtail++;
	if (newtail >= CIRCBUFSIZE) {
		// Rollover
		newtail = 0;
	}
	cbuf->tail = newtail;

	return retval;
}


int circ_buf_empty(const tcirc_buf *cbuf) {
	return cbuf->head == cbuf->tail;
}

unsigned int circ_buf_count(const tcirc_buf *cbuf) {
	int count = cbuf->head - cbuf->tail;

	if (count < 0) {
		count += CIRCBUFSIZE;
	}
	return count;
}
