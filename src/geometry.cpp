#include "geometry.h"
#include "common.h"

#define DIST 5
#define XWIDTH 5.4

ColorPoint::ColorPoint(float newX,float newY,float newZ, float newR, float newG, float newB)
	: Point(newX, newY,newZ),r(newR), g(newG),b(newB) {

}

ColorPoint::ColorPoint(int x, int y, int d, float r, float g, float b)
   	: Point(x, y, d), r(r), g(g), b(b) {
}

ColorPoint::ColorPoint() : Point(), r(0), g(0), b(0) {
}

Point::Point(float newX,float newY,float newZ) : x(newX), y(newY),z(newZ) {
	
}

Point::Point(int x, int y, int d) {
	double ywidth = XWIDTH * YRES / XRES;

	this->x = ((XWIDTH * x) / (XRES - 1)) - (XWIDTH / 2);
	this->y = ((ywidth * y) / (YRES - 1)) - (ywidth / 2);
	this->z = DIST;
}

Point::Point() : x(0), y(0), z(0) {
	
}

Vector::Vector(float newDistanceX,float newDistanceY,float newDistanceZ)
	: distanceX(newDistanceX),distanceY(newDistanceY),distanceZ(newDistanceZ) {
	
}

float DepthMap::cache[2048];
bool DepthMap::init = false;

void DepthMap::doInit() {
	for (int i = 0; i < DEPTH_RES; i++) {
		cache[i] = k3 * tanf(((float)i) / k2 / 2 + k1);
	}
}

float DepthMap::toDepth(int d) {
	if (!init) {
		doInit();
	}
	return cache[d];
}
