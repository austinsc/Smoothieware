/*
 *	ServoControl.h
 *	02 November 2017
 *	Matthew Buchanan, Mitchell Williams
 *	Forgeware
 */
 
#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

namespace mbed {class PwmOut;}

class Pin;

class ServoControl {
	
public:
	ServoControl();
	~ServoControl();
	
	void rotate_to(float dir);
	
private:
	mbed::PwmOut 	*control_pin;
	Pin				*feedback_pin;
};


#endif