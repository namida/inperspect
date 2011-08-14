#include "geometry.h"
#include "scene.h"
class Renderer {
	public:
		float ypoz, zpoz;
		Renderer();
		void render(Scene*);
		void animate();
};
