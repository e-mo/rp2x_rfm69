#include "rfm69_rp2040_rudp_irq.h"

typedef struct gpio_irq_signal {
	mutex_t 
} gpio_irq_signal_t;

void rudp_irq_init(void) {
	// Semaphore flags
	sem_init(&fifo_level_low, 1, 1);
	sem_init(&fifo_level_high, 1, 1);
	sem_init(&packet_sent, 1, 1);
	sem_init(&fifo_not_empty, 1, 1);
	sem_init(&payload_ready_or_timeout, 1, 1);
}
