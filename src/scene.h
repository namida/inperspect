#include <vector>
#include <cv.h>

#include "common.h"
#include "geometry.h"

class Scene {
	private:
		IplImage *rgb;
		IplImage *depth;
	public:
		ColorPoint points[XRES][YRES];
		std::vector<Point*> cloud;

		Scene();
		void fetchImage();
		void build();
};
