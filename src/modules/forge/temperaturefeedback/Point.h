#ifndef POINT_H
#define POINT_H

#define NUM_PARAMS 4

class Point {

	public:
		Point();
		Point(float xpos, float ypos, float temp, float dir);
		~Point();
		
		Point* next;
		
		float get_x_pos();
		float get_y_pos();
		float get_temp();
		float get_dir();
		
	private:
		float params[NUM_PARAMS];
};

#endif