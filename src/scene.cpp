#include "geometry.h"
#include "scene.h"
#include "libfreenect_cv.h"
#include <cv.h>
#include <highgui.h>
#include "geometry.h"

#include <stdio.h>

void lighten(IplImage *img) {
	for (int i = 0; i < img->imageSize / 2; i++) {
		((uint16_t*)img->imageData)[i] *= 32;
	}
}

Scene::Scene() : rgb(NULL), depth(NULL) {
	cvNamedWindow("depth");
	cvNamedWindow("rgb");
	cloud.push_back(new ColorPoint(0, 0, 1024, 1, 0, 0));
	cloud.push_back(new ColorPoint(639, 0, 1024, 1, 1, 0));
	cloud.push_back(new ColorPoint(639, 479, 1024, 0, 1, 0));
	cloud.push_back(new ColorPoint(0, 479, 1024, 0, 1, 1));
	cloud.push_back(new ColorPoint(319, 239, 1024, 1, 0, 1));
}

void Scene::fetchImage() {
	rgb = freenect_sync_get_rgb_cv(0);
	cvCvtColor(rgb, rgb, CV_RGB2BGR);
	depth = freenect_sync_get_depth_cv(0);
	lighten(depth);
}

void Scene::build() {
	cvShowImage("rgb", rgb);
	cvShowImage("depth", depth);
}
