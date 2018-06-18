#ifndef POINT_LIST_H
#define POINT_LIST_H

class Point;

class PointList {

	public:
		PointList();
		~PointList();
		
		void add_to_head(float x, float y, float t, float d);
		void get_tail_params(float* x, float* y, float* t, float* d);
		void delete_tail();
		int get_count();
		void clear_list();
	
	private:
		Point* head;
		int count;

};

#endif