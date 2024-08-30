#ifndef I2C_H_
#define I2C_H_

void I2C_Init(void);
int32_t I2C_Xfer(uint8_t slaveaddr, uint8_t* buf, uint32_t len, uint8_t trailingStop);

#endif /* I2C_H_ */
