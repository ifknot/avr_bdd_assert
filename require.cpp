/*
 * require.cpp
 *
 * Created: 4/14/2020 8:03:05 PM
 *  Author: ifkno
 */ 

#include "require.h"
#include "avt_uart_minimal/uart_minimal_device.h"

namespace util {
	
	void fail_action(uint8_t version, uint8_t id, uint16_t line) {
		auto& uart = singleton::uart_minimal_device::instance();
		uart.write_hex(version);
		uart.write_hex(id);
		uart.write_hex(line >> 8);
		uart.write_hex(line);
#ifdef LOG_ERRORS
		// use eeprom device to log error code 
#endif
	}

}
