#ifndef RFM69_RUDP_IRQ_H
#define RFM69_RUDP_IRQ_H
// Helper IRQ routines for 

#include <stdint.h>
#include <stdbool.h>

#include "pico/sync.h"
#include "hardware/gpio.h"

#include "rfm69_rp2040_interface.h"

void rudp_irq_init(void);

#endif // RFM69_RUDP_IRQ_H
