#ifndef _SCENE_H
#define _SCENE_H
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
		std::vector<ColorPoint*> cloud;

		Scene();
		void fetchImage();
		void build();
};
#endif

