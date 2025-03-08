#ifndef RFM69_RUDP_WTP_H
#define RFM69_RUDP_WTP_H
#include <stdbool.h>
#include <stdint.h>

#include "wtp-1_0.h"
#include "rfm69_rp2040_interface.h"

bool rfm69_rudp_init(rfm69_context_t *rfm, const struct rfm69_config_s *config);

bool rfm69_tx_variable_packet(
		rfm69_context_t *rfm,
		uint8_t rx_address, 
		uint8_t *payload_buffer,
		uint8_t payload_size
);

bool rfm69_rx_variable_packet(
		rfm69_context_t *rfm,
		uint8_t *rx_buffer,
		uint8_t buffer_size,
		uint8_t timeout_ms
);

bool rfm69_rudp_tx(
		rfm69_context_t *rfm,
		uint8_t rx_address, 
		uint8_t *payload_buffer,
		uint32_t payload_size
);

#endif // RFM69_RUDP_WTP_H
