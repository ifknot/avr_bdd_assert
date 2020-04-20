/*
 * require.h
 *
 * Created: 4/14/2020 7:17:15 PM
 *  Author: ifkno
 */ 

#include <stdint.h>

#ifndef REQUIRE_H_
#define REQUIRE_H_

/**
 * macro to set the software version
 * used to construct the error code
 * compile error unless set
 */
#define SET_VERSION(v) enum { _VERSION_ = v };

/**
 * macro to set the id to replace the _FILE_ string constant
 * placed at the top of every source file
 * the dummy __unique function concatenated with ## causes the linker to throw an error if the same file id is used more than once
 * compile error unless set and unique
 */
#define SET_FILE_ID(id) \
	enum { _FILE_ID_ = id }; \
	void __unique##id(void) {}

/**
 * test assertion require macro
 * calls fail action with args to construct a localized error code
 */
#define REQUIRE(expr) \
	if ((expr)) {} \
	else { \
		util::fail_action(_VERSION_, _FILE_ID_, __LINE__); \
	}

namespace util {
	
	/**
	 * Rather than filling up the program memory with constant strings from _FILE_ and failed expression info
	 * construct a 32 bit error code from:
	 * 1. software version number	8 bits	(otherwise the line number will be meaningless) 
	 * 2. the file id number		8 bits	(to avoid filename string constants)
	 * 3. the line number			16 bits
	 *
	 * There are then a number of fail action possibilities e.g.
	 * + saving the error code in eeprom 
	 * + abort with error to serial
	 * + enable login via a debug task for system interrogation
	 */
	void fail_action(uint8_t version, uint8_t id, uint16_t line);
	
}


#endif /* REQUIRE_H_ */