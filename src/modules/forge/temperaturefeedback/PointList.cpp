
#include "Point.h"
#include "PointList.h"


PointList::PointList() {

	head = nullptr;
	count = 0;
}

PointList::~PointList() {

	Point* p = head;
	Point* n;
	while (p != nullptr) {
		n = p;
		p = p->next;
		delete n;
	}
}

void PointList::add_to_head(float x, float y, float t, float d) {

	Point* n;
	n = new Point(x, y, t, d);
	n->next = head;
	head = n;
	count++;
}

void PointList::get_tail_params(float* x, float* y, float* t, float* d) {
	//optimize this by keeping track of a tail pointer
	Point* p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	*x = p->get_x_pos();
	*y = p->get_y_pos();
	*t = p->get_temp();
	*d = p->get_dir();
}

void PointList::delete_tail() {
	
	Point* p = head;
	Point* n = head;
	while (p->next != nullptr) {
		n = p;
		p = p->next;
	}
	n->next = nullptr;
	delete p;
	count--;
}

int PointList::get_count() {
	
	return count;
}

void PointList::clear_list() {
	
	Point* p = head;
	Point* n;
	while (p != nullptr) {
		n = p;
		p = p->next;
		delete n;
	}
	count = 0;
}