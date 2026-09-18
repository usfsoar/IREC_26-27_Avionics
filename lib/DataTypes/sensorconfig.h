#ifndef SENSORCONFIG_H
#define SENSORCONFIG_H

#include <SensorDesc.h>
#include <hwconfig.h>

#define SENSOR_COUNT 6

// Enable printing of pressure data to Serial from `main` (0 = off, 1 = on)
#ifndef ENABLE_PRESSURE_SERIAL
#define ENABLE_PRESSURE_SERIAL 0
#endif

// Sensor table - configure your hardware here
// NOTE: sensorType must match the dispatcher (LOWPRESSURE or HIGHPRESSURE).
const SensorDesc sensor_table[SENSOR_COUNT] = {
    // id, type, bus_id, i2c_address, adc_channel, period_ticks
    //{
    //    .id = 0,
    //    .sensorType = SensorDesc::type::LOWPRESSURE,
    //    .bus_id = 0,
    //    .i2c_address = ADS1115_I2C_ADDR,        // ADS1115 address
    //    .adc_channel = 0,           // ADS1115 input A0
    //    .period_ticks = 1           // Read every frame
    //}
};

#endif // SENSORCONFIG_H