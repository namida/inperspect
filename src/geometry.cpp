#include "geometry.h"

Point::Point(float newX,float newY,float newZ) : x(newX), y(newY),z(newZ) {
	
	
}
ColorPoint::ColorPoint(float newX,float newY,float newZ, float newR, float newG, float newB):Point(newX, newY,newZ),r(newR), g(newG),b(newB) {

}

Vector::Vector(float newDistanceX,float newDistanceY,float newDistanceZ) : distanceX(newDistanceX),distanceY(newDistanceY),distanceZ(newDistanceZ) {
	
}
