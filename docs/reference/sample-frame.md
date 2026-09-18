# `SampleFrame` and related types

[← Back to documentation index](../README.md)

## `SampleFrame`

Defined in [`lib/DataTypes/SampleFrame.h`](../../lib/DataTypes/SampleFrame.h).

| Field | Type | Meaning |
|-------|------|---------|
| `timestamp_us` | `uint32_t` | `micros()` at frame creation |
| `seq` | `uint32_t` | Monotonic frame counter |
| `valid_mask` | `uint8_t` | Bit *i* set if sensor *i* produced a good read |
| `status_bits` | `uint8_t` | `SPI_ERR`, `OVERRUN` flags from [`daqloop.h`](../../lib/DAQLoop/daqloop.h) |
| `payload[]` | `uint32_t[SENSOR_COUNT]` | Processed sensor values (e.g. PSI × 100 for pressure) |
| `raw_adc[]` | `uint16_t[SENSOR_COUNT]` | Raw ADC counts |

The struct is **trivially copyable** and **standard-layout** so it can be **memcopied** into SD files as binary blobs.

## `SensorDesc`

[`lib/DataTypes/SensorDesc.h`](../../lib/DataTypes/SensorDesc.h) — per-sensor static configuration: `id`, `sensorType` (temperature / low / high pressure), `bus_id`, `i2c_address`, `adc_channel`, `period_ticks`.

## `sensorconfig.h`

[`lib/DataTypes/sensorconfig.h`](../../lib/DataTypes/sensorconfig.h) — **sensor table** and **`SENSOR_COUNT`**. Must stay consistent. Optional **`ENABLE_PRESSURE_SERIAL`** for USB table output on Teensy.

## `hwconfig.h`

[`lib/DataTypes/hwconfig.h`](../../lib/DataTypes/hwconfig.h) — hardware constants including ADS1115 I2C address (`ADS1115_I2C_ADDR`).

## LoRa serialization note

[`LoraSend::serialize_frame_header`](../../lib/LoraSend/lorasend.cpp) packs **timestamp, seq, masks, raw_adc[]` only** — not the full `payload[]` array. See [LoRa protocols](../protocols/lora.md).

## Related

- [Ring buffers and dispatcher](ring-buffers-and-dispatcher.md)  
- [Configuration headers](configuration-headers.md)  
