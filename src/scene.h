#include <vector>
#include <cv.h>

#include "geometry.h"

class Scene {
	private:
		IplImage *rgb;
		IplImage *depth;
	public:
		ColorPoint points[640][480];
		std::vector<Point*> cloud;

		Scene();
		void fetchImage();
		void build();
};
