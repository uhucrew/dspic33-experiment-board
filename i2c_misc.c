#include <stdbool.h>

#include "i2c_x.h"
#include "i2c_misc.h"


bool set_volume(uint8_t devaddr, uint8_t vol) {
    bool result;

    if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
        I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(I2C_MAX5387_REG_AB, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
        I2C2_write(vol, I2C_ACK, I2C_WAIT_US_DEFAULT) )
    {
        result = true;
    }
    else {
        result = false;
    }

    I2C2_stop(I2C_WAIT_US_LONG);
    return result;
}
