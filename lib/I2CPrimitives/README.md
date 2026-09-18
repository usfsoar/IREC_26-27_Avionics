=========
i2c_write
=========
Generic helper for small I2C write operations

=========================
i2c_read / i2c_write_read
=========================

I'm going to be honest with you reader. Don't use these, just use the Adafruit libraries and Wire.
Originally made to directly control the I2C writes, but I switched to using the libraries instead in the other function calls for simplicity, meaning these functions are somewhat deprecated.
I'm fairly sure those libraries will handle I2C writes better than any code I'd write.