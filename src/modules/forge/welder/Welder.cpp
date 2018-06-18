/*
 *	Welder.cpp
 *	2 October 2017
 *	Matthew Buchanan
 *	Forgeware
 */

#include <math.h>

#include "Welder.h"

#include "Module.h"
#include "Conveyor.h"
#include "Gcode.h"
#include "Pin.h"
#include "Kernel.h"
#include "StreamOutputPool.h"

Welder::Welder() {
	
	on_off_pin.output();
	on_off_pin = false;
	high_low_pin.output();
	high_low_pin = false;
	polarity_pin.output();
	polarity_pin = false;
}

void Welder::on_module_loaded() { 

	this->register_for_event(ON_GCODE_RECEIVED);
	this->register_for_event(ON_HALT);
}

void Welder::on_gcode_received(void *argument) { 

	Gcode *gcode = static_cast<Gcode *>(argument);

    // M codes execute immediately
    if (gcode->has_m) {
        if (gcode->m == 710) { // turn welder on
			THEKERNEL->conveyor->wait_for_idle();
			on_off_pin = true;
        }
		if (gcode->m == 720) { // turn welder on (default)
			THEKERNEL->conveyor->wait_for_idle();	
			on_off_pin = false;
		}
		if (gcode->m == 711) { // switch to low voltage
			THEKERNEL->conveyor->wait_for_idle();
			high_low_pin = true;
		}
		if (gcode->m == 712) { // switch to high voltage (default)
			THEKERNEL->conveyor->wait_for_idle();
			high_low_pin = false;
		}
        if (gcode->m == 713) { // switch to DCEN
			THEKERNEL->conveyor->wait_for_idle();
			polarity_pin = true;
        }
		if (gcode->m == 714) { // switch to DCEP (default)
			THEKERNEL->conveyor->wait_for_idle();
			polarity_pin = false;
		}
    }
}

void Welder::on_halt() {
	
	on_off_pin = false;
	high_low_pin = false;
	polarity_pin = false;
}