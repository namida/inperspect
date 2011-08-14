#ifndef _GEOMETRY_H
#define _GEOMETRY_H
class Point {
	public:
		float x, y, z;
		Point();
		Point(int x, int y, int d);
		Point(float newX,float newY,float newZ);
};
class Vector {
	public:
		float distanceX,distanceY,distanceZ;
		Vector(float newDistanceX,float newDistanceY,float newDistanceZ);	
};
class ColorPoint : public Point {
	public:
		float r,g,b;
		ColorPoint();
		ColorPoint(int x, int y, int d, float r, float g, float b);
		ColorPoint(float newX,float newY,float newZ,float newR, float newG, float newB);
};
#endif
