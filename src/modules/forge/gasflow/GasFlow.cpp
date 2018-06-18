/*
 *	GasFlow.cpp
 *	2 October 2017
 *	Matthew Buchanan
 *	Forgeware
 */

#include <math.h>

#include "GasFlow.h"

#include "Module.h"
#include "Conveyor.h"
#include "Gcode.h"
#include "Pin.h"
#include "Kernel.h"
#include "StreamOutputPool.h"

GasFlow::GasFlow() {
	
	gas_pin.output();
	gas_pin = false;
}

void GasFlow::on_module_loaded() { 

	this->register_for_event(ON_GCODE_RECEIVED);
	this->register_for_event(ON_HALT);
}

void GasFlow::on_gcode_received(void *argument) { 

	Gcode *gcode = static_cast<Gcode *>(argument);

    // M codes execute immediately
    if (gcode->has_m) {
        if (gcode->m == 770) { // turn gas on
			THEKERNEL->conveyor->wait_for_idle();
			gas_pin = true;
        }
		if (gcode->m == 780) { // turn gas off (default)
			THEKERNEL->conveyor->wait_for_idle();	
			gas_pin = false;
		}
    }
}

void GasFlow::on_halt() {
	
	gas_pin = false;
}