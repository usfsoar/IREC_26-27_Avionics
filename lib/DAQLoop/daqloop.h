#ifndef DAQLOOP_H
#define DAQLOOP_H

#include <SampleFrame.h>
#include <ringbuffer.h>
#include <sensordispatcher.h>
#include <sensorconfig.h>
#include <cstdint>
#include <hwconfig.h>

// Status bit flags
#define SPI_ERR    (1 << 1)
#define OVERRUN    (1 << 2)

void daq_init();
void daq_step();

#endif // DAQLOOP_H
