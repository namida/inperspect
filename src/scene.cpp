#include "geometry.h"
#include "scene.h"
#include "libfreenect_cv.h"
#include <cv.h>
#include <highgui.h>

#include <stdio.h>

void lighten(IplImage *img) {
	for (int i = 0; i < img->imageSize / 2; i++) {
		((uint16_t*)img->imageData)[i] *= 32;
	}
}

Scene::Scene() : rgb(NULL), depth(NULL) {
	cvNamedWindow("depth");
	cvNamedWindow("rgb");
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
