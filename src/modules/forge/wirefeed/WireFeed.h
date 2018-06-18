/*
 *	WireFeed.h
 *	07 August 2017
 *	Matthew Buchanan
 *	Forgeware
 */

#ifndef WIRE_FEED_H
#define WIRE_FEED_H

#include <stdint.h>

#include "Module.h"

class Block;
class Pin;

namespace mbed { class PwmOut; }

class WireFeed: public Module {
	public:
		WireFeed();
		~WireFeed() {};

		void on_module_loaded();
		void on_gcode_received(void *argument);
		void on_halt();
		
	private:
		const Block *block;
		uint32_t feed_tick(uint32_t dummy);
		float pwm_duty_cycle();
	
		mbed::PwmOut *feed_pin;
		float rate;
		uint32_t period;
		bool feeding;
		float factor;
		bool ratio;
		
		float volume_per_mm;
		float wire_diam;
		float print_speed;
};

#endif