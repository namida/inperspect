#include "scene.h"
#include "libfreenect_cv.h"
#include <cv.h>
#include <highgui.h>

void lighten(IplImage *img) {
	for (int i = 0; i < img->imageSize / 2; i++) {
		((uint16_t*)img->imageData)[i] *= 32;
	}
}

Scene::Scene() {
	cvNamedWindow("depth");
	cvNamedWindow("rgb");
}

void Scene::build() {
	IplImage *rgb = freenect_sync_get_rgb_cv(0);
	cvCvtColor(rgb, rgb, CV_RGB2BGR);
	IplImage *depth = freenect_sync_get_depth_cv(0);
	lighten(depth);

	cvShowImage("rgb", rgb);
	cvShowImage("depth", depth);
}
