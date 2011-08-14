#include "geometry.h"
#include "common.h"

#include <stdio.h>

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
	float xwidth = tanf(0.497418837);	// 57 / 2 degrees in radians
	double ywidth = xwidth * YRES / XRES;

	Vector v = Vector(
		(xwidth * x) / (XRES - 1) - xwidth / 2,
		(ywidth * y) / (YRES - 1) - ywidth / 2,
		1
	);

	float depth = DepthMap::toDepth(d);

	this->x = v.x * depth;
	this->y = v.y * depth;
	this->z = v.z * depth;
}

Point::Point() : x(0), y(0), z(0) {
	
}

Vector::Vector(float newDistanceX,float newDistanceY,float newDistanceZ)
	: x(newDistanceX),y(newDistanceY),z(newDistanceZ) {
	
}

void Vector::normalize() {
	double mag = sqrt(x*x + y*y + z*z);
	x /= mag;
	y /= mag;
	z /= mag;
}

float DepthMap::cache[2048];
bool DepthMap::init = false;

void DepthMap::doInit() {
	for (int i = 0; i < DEPTH_RES; i++) {
		cache[i] = k3 * tanf(((float)i) / k2 + k1);
	}
}

float DepthMap::toDepth(int d) {
	if (!init) {
		doInit();
		init = true;
	}
	return cache[d];
}
