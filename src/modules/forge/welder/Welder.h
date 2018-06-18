/*
 *	Welder.h
 *	2 October 2017
 *	Matthew Buchanan
 *	Forgeware
 */

#ifndef WELDER_H
#define WELDER_H

#include <stdint.h>

#include "gpio.h"
#include "Module.h"

class Welder: public Module {
	public:
		Welder();
		~Welder() {};

		void on_module_loaded();
		void on_gcode_received(void *argument);
		void on_halt();
		
	private:
	
		GPIO on_off_pin = GPIO(P1_22);
		GPIO high_low_pin = GPIO(P2_6);
		GPIO polarity_pin = GPIO(P2_4);
};

#endif