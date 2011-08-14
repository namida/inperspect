#include "geometry.h"
class Renderer {
	public:
		float ypoz, zpoz;
		Point pointsX[10], pointsY[10], pointsZ[10];
		Renderer();
		void render();
		void animate();
};
