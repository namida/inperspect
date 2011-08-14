#include "geometry.h"

#define DIST 5
#define XRES 640
#define YRES 480
#define XWIDTH 5.4

Point::Point(int x, int y, int d) {
	double ywidth = XWIDTH * YRES / XRES;

	this->x = ((XWIDTH * x) / (XRES - 1)) - (XWIDTH / 2);
	this->y = ((ywidth * y) / (YRES - 1)) - (ywidth / 2);
	this->z = DIST;
}

ColorPoint::ColorPoint(int x, int y, int d, float r, float g, float b)
	: Point(x, y, d), r(r), g(g), b(b) {
}
