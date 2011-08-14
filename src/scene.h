#include <vector>
#include <cv.h>

#include "common.h"
#include "geometry.h"

class Scene {
	private:
		IplImage *rgb;
		IplImage *depth;
		double depthMap[2048];
	public:
		ColorPoint points[XRES][YRES];
		std::vector<Point*> cloud;

		Scene();
		void fetchImage();
		void build();
};
