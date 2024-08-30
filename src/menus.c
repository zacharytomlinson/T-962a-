#include <stdarg.h>
#include <stdio.h>
#include "menus.h"

void m_printf(const char* format, ...) {
    char buffer[sizeof(format) + 4];
    va_list args;

    va_start (args, format);
    snprintf(buffer, sizeof(buffer), "\n%s\n", format);
    printf(buffer, args);
    va_end(args);
}