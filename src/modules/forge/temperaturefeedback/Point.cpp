
#include "Point.h"

Point::Point() {

	next = nullptr;
	for(int i = 0; i < NUM_PARAMS; i++) {
		params[i] = 0;
	}
}

Point::Point(float xpos, float ypos, float temp, float dir) {

	next = nullptr;
	params[0] = xpos;
	params[1] = ypos;
	params[2] = temp;
	params[3] = dir;
}

Point::~Point() {
	
	next = nullptr;
}

float Point::get_x_pos() {

	return params[0];
}

float Point::get_y_pos() {

	return params[1];
}

float Point::get_temp() {

	return params[2];
}

float Point::get_dir() {
	
	return params[3];
}