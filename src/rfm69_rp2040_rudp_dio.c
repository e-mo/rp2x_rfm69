// rfm69_pico_rudp.c
// Interface implementation for rfm69_pico Reliable UDP

//	Copyright (C) 2024 
//	Evan Morse
//	Amelia Vlahogiannis

//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.

//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.

//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <https://www.gnu.org/licenses/>.
#include <stdio.h>

#include "hardware/sync.h"

#include "rfm69_rp2040_rudp_dio.h"
#include "rfm69_rp2040_rudp_irq.h"


// Helper function to initialize rfm69 context for use with rudp interface
bool rfm69_rudp_init(rfm69_context_t *rfm, const struct rfm69_config_s *config) {
	//if (!rfm69_init(rfm, config)) return false; 

    //rfm69_dcfree_set(rfm, RFM69_DCFREE_WHITENING);
	//rfm69_packet_format_set(rfm, RFM69_PACKET_VARIABLE);
	//rfm69_payload_length_set(rfm, WTP_PKT_SIZE_MAX);

	//// RFM69_FIFO_SIZE/2 == 33
	//rfm69_fifo_threshold_set(rfm, RFM69_FIFO_SIZE/2);
	//rfm69_crc_autoclear_set(rfm, false);

	//// DIO settings
	//// DIO0 changes between RX and TX so isn't set here
	//rfm69_dio1_config_set(rfm, RFM69_DIO1_PKT_TX_FIFO_LVL);
	//rfm69_dio2_config_set(rfm, RFM69_DIO2_PKT_TX_FIFO_N_EMPTY);

	//// Init irq semaphores
	////rudp_irq_init();

	//rfm69_mode_set(rfm, RFM69_OP_MODE_SLEEP);

	return true;
}

void semaphore_release_toggle(uint gpio, uint32_t event_mask, void *data) {
	semaphore_t *sem = (semaphore_t *)data;	
	sem_release(sem);
}

bool rfm69_tx_variable_packet(
		rfm69_context_t *rfm,
		uint8_t rx_address, 
		uint8_t *payload_buffer,
		uint8_t payload_size
)
{
	semaphore_t fifo_level;
	semaphore_t packet_sent;

	sem_init(fifo_level, 1, 1);
	sem_init(packet_sent, 1, 1);

	uint8_t header[] = {payload_size + 1, rx_address};
	if (!rfm69_write(rfm, RFM69_REG_FIFO, header, 2))
		return false;

	// Set first write size
	uint8_t write_size = payload_size > RFM69_FIFO_SIZE - 2 ? 
						 RFM69_FIFO_SIZE - 2 : payload_size;

	rfm69_mode_set(rfm, RFM69_OP_MODE_TX);
	for (;;) {
		rfm69_write(rfm, RFM69_REG_FIFO, payload_buffer, write_size);
		payload_size -= write_size;

		if (!payload_size) break;

		payload_buffer += write_size;
	
		// false = falls low
		//fifo_level_irq_wait(false);

		// When fifo_level clears, calculate new write size
		write_size = payload_size > RFM69_FIFO_SIZE/2 ? 
					 RFM69_FIFO_SIZE/2 : payload_size;
	}

	// Wait for packet to finish sending
	//packet_sent_irq_wait();

	rfm69_mode_set(rfm, RFM69_OP_MODE_SLEEP);

// Disable IRQ
	//fifo_level_irq_enable(rfm, false);
	//packet_sent_irq_enable(rfm, false);

	return true;
}

bool rfm69_rx_variable_packet(
		rfm69_context_t *rfm,
		uint8_t *rx_buffer,
		uint8_t buffer_size,
		uint8_t timeout_ms
)
{
}


bool rfm69_rudp_tx(
		rfm69_context_t *rfm,
		uint8_t rx_address, 
		uint8_t *payload_buffer,
		uint32_t payload_size
)
{

}

bool rfm69_rudp_rx(
		rfm69_context_t *rfm,
		uint32_t buffer_size,
		uint8_t *payload_buffer
)
{

}
