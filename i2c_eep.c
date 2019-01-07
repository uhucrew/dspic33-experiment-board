#include "i2c_x.h"
#include "i2c_eep.h"


uint16_t ee_read_bytes(uint8_t devaddr, uint16_t eeaddr, uint16_t len, uint8_t *buf, bool bit9)
{
    uint16_t iter = 0;
    uint16_t n = 0;
    uint8_t  addrhi, addrlo;

    if (bit9) {
        if (eeaddr > EE_SIZE_BIT9) return 0;
    }
    else {
        if (eeaddr > EE_SIZE) return 0;
    }

    void read_loop(uint8_t bit9_high) {
        if (I2C2_rep_start(I2C_WAIT_US_DEFAULT) &&
            I2C2_dev_access(devaddr | bit9_high | I2C_READ, I2C_WAIT_US_DEFAULT) )
        {
            do {
                if (I2C2_read(&buf[n], I2C_ACK, I2C_WAIT_US_DEFAULT))
                {
                    n++;
                }
                else iter++;
            }
            while ((n < len-1) && (iter < EEP_MAX_ITER));

            if (n == (len-1))
                if (I2C2_read(&buf[n], I2C_NACK, I2C_WAIT_US_DEFAULT)) n++;

            I2C2_stop(I2C_WAIT_US_LONG);
        }
        else {
            iter++;
            I2C2_stop(I2C_WAIT_US_LONG);
        }
    }

    while ((n < len) && (iter < EEP_MAX_ITER)) {
        addrlo = (eeaddr + n) & 0xff;

        if (bit9) {
            addrhi = ((eeaddr + n) >> 7) & 2;

            if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
                I2C2_dev_access(devaddr | addrhi | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
                I2C2_write(addrlo, I2C_ACK, I2C_WAIT_US_DEFAULT) )
            {
                read_loop(addrhi);
            }
            else {
                iter++;
                I2C2_stop(I2C_WAIT_US_LONG);
            }
        }
        else {
            addrhi = ((eeaddr + n) >> 8) & 0xff;

            if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
                I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
                I2C2_write(addrhi, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
                I2C2_write(addrlo, I2C_ACK, I2C_WAIT_US_DEFAULT) )
            {
                read_loop(0);
            }
            else {
                iter++;
                I2C2_stop(I2C_WAIT_US_LONG);
            }
        }
    }
    return n;
}


uint16_t ee_write_bytes(uint8_t devaddr, uint16_t eeaddr, uint16_t len, uint8_t *buf, bool bit9)
{
    uint16_t iter = 0, ack_wait = 0;
    uint16_t n = 0;
    uint8_t addrhi, addrlo;

    if (bit9) {
        if (eeaddr > EE_SIZE_BIT9) return 0;
    }
    else {
        if (eeaddr > EE_SIZE) return 0;
    }

    void write_loop() {
        iter = 0;

        do
        {
            if (I2C2_write(buf[n], I2C_ACK, I2C_WAIT_US_DEFAULT))
            {
                n++;
            }
            else iter++;
        }
        while ((((eeaddr + n) % PAGE_SIZE) > 0) && (n < (len - 1)) && (iter < EEP_MAX_ITER));

        if (n == (len - 1))
            if (I2C2_write(buf[n], I2C_ACK, I2C_WAIT_US_DEFAULT)) n++;

        I2C2_stop(I2C_WAIT_US_LONG);
    }


    void ack_poll() {
        ack_wait = 0;

        while (ack_wait < EEP_MAX_ITER)
        {
            if (bit9) {
                if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
                    I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
                    I2C2_write(0, I2C_ACK, I2C_WAIT_US_DEFAULT) )
                {
                    I2C2_stop(I2C_WAIT_US_LONG);
                    return;
                }
                else ack_wait++;
            }
            else {
                if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
                    I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
                    I2C2_write(0, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
                    I2C2_write(0, I2C_ACK, I2C_WAIT_US_DEFAULT) )
                {
                    I2C2_stop(I2C_WAIT_US_LONG);
                    return;
                }
                else ack_wait++;
            }
        }
    }


    while ((n < len) && (iter < EEP_MAX_ITER))
    {
        addrlo = (eeaddr + n) & 0xff;

        if (bit9) {
            addrhi = ((eeaddr + n) >> 7) & 2;
            if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
                I2C2_dev_access(devaddr | addrhi | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
                I2C2_write(addrlo, I2C_ACK, I2C_WAIT_US_DEFAULT) )
            {
                write_loop();
                ack_poll();
            }
            else
            {
                iter++;
                I2C2_stop(I2C_WAIT_US_LONG);
            }
        }
        else  {
            addrhi = ((eeaddr + n) >> 8) & 0xff;
            if (I2C2_start(I2C_WAIT_US_DEFAULT) &&
                I2C2_dev_access(devaddr | I2C_WRITE, I2C_WAIT_US_DEFAULT) &&
                I2C2_write(addrhi, I2C_ACK, I2C_WAIT_US_DEFAULT) &&
                I2C2_write(addrlo, I2C_ACK, I2C_WAIT_US_DEFAULT) )
            {
                write_loop();
                ack_poll();
            }
            else
            {
                iter++;
                I2C2_stop(I2C_WAIT_US_LONG);
            }
        }
    }

    return n;
}
