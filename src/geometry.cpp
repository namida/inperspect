#include "geometry.h"
#define DIST 5
#define XRES 640
#define YRES 480
#define XWIDTH 5.4


ColorPoint::ColorPoint(float newX,float newY,float newZ, float newR, float newG, float newB):Point(newX, newY,newZ),r(newR), g(newG),b(newB) {

}
ColorPoint::ColorPoint(int x, int y, int d, float r, float g, float b): Point(x, y, d), r(r), g(g), b(b) {
}

Vector::Vector(float newDistanceX,float newDistanceY,float newDistanceZ) : distanceX(newDistanceX),distanceY(newDistanceY),distanceZ(newDistanceZ) {
	
}

Point::Point(float newX,float newY,float newZ) : x(newX), y(newY),z(newZ) {
	
	
}
Point::Point() {
	
	
}
Point::Point(int x, int y, int d) {
	double ywidth = XWIDTH * YRES / XRES;

	this->x = ((XWIDTH * x) / (XRES - 1)) - (XWIDTH / 2);
	this->y = ((ywidth * y) / (YRES - 1)) - (ywidth / 2);
	this->z = DIST;
}


