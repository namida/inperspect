class Point {
	public:
		float x, y, z;
		Point();
		Point(int x, int y, int d);
};
class ColorPoint : public Point {
	public:
		float r,g,b;
		ColorPoint();
		ColorPoint(int x, int y, int d, float r, float g, float b);
};
