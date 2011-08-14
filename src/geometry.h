#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <math.h>

#define DEPTH_RES 2048

class Point {
	public:
		float x, y, z;
		Point();
		Point(int x, int y, int d);
		Point(float newX,float newY,float newZ);
};

class Vector {
	public:
		float x,y,z;
		Vector(float newDistanceX,float newDistanceY,float newDistanceZ);	
		void normalize();
};

class ColorPoint : public Point {
	public:
		float r,g,b;
		ColorPoint();
		ColorPoint(int x, int y, int d, float r, float g, float b);
		ColorPoint(float newX,float newY,float newZ,float newR, float newG, float newB);
};

class DepthMap {
	private:
		static float cache[2048];
		static bool init;
		static const float k1 = 1.1863;
		static const float k2 = 2842.5;
		static const float k3 = 0.1236;
	public:
		static void doInit();
		static float toDepth(int d);
};
#endif
