# I2C: solenoid state (16-bit word)

[← Back to documentation index](../README.md)

## Teensy

The current Teensy DAQ firmware version does **not** include an I2C master read path for the relay/solenoid state word.

## Torito ESP (slave)

[`src/tsesp/main.cpp`](../../src/tsesp/main.cpp) registers **`Wire`** as a slave at **`I2C_SLAVE_ADDR`** (`0x09`):

- **On receive (master write):** expects **2 bytes**; updates `lastI2CValue` and may call **`setRelays()`** if **`RELAY_MSB_BIT`** is set.  
- **On request (master read):** returns the same **high / low** byte pair.

## End-to-end

The Torito ESP maintains the relay state word locally and exposes it over I2C for any external master. Keep **bit semantics** aligned with [relay bitmap](relay-bitmap.md) and LoRa payloads.
