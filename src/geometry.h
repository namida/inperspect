class Point {
	public:
		float x, y, z;
		Point(float newX,float newY,float newZ);
};
class ColorPoint:public Point {
	public:
		float r,g,b;
		ColorPoint(float newX,float newY,float newZ,float newR, float newG, float newB);
};
class Vector {
	public:
		float distanceX,distanceY,distanceZ;
		Vector(float newDistanceX,float newDistanceY,float newDistanceZ);
};
