#include "daqloop.h"

// Global state
static uint32_t seq = 0;
static uint32_t tick = 0;

// External buffers (declared in main)
extern RingBuffer daq_buffer;

void daq_init() {
    seq = 0;
    tick = 0;
}

void daq_step() {
    SampleFrame frame{};              // zero-initialize entire struct (clears padding/unused fields)
    frame.seq = seq++;
    frame.timestamp_us = micros();
    frame.valid_mask = 0;
    frame.status_bits = 0;

    for (int i = 0; i < SENSOR_COUNT; i++) {
        const SensorDesc &desc = sensor_table[i];
        
        // Check if scheduled this frame
        if ((tick % desc.period_ticks) != 0) {
            continue;
        }
        // Read the sensor directly from its configured I2C address.
        int32_t processed_value;
        int16_t raw_adc;
        if (sensor_read_dispatch(desc, processed_value, raw_adc)) {
            frame.payload[desc.id] = processed_value;
            frame.raw_adc[desc.id] = raw_adc;
            frame.valid_mask |= (1 << desc.id);
        } else {
            frame.status_bits |= SPI_ERR;
        }
    }

    // Push to DAQ buffer (every frame)
    if (!daq_buffer.push(&frame)) {
        frame.status_bits |= OVERRUN;
    }

    tick++;
}
