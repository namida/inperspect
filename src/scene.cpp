#include "libfreenect_cv.h"
#include <cv.h>
#include <highgui.h>

#include "scene.h"
#include "geometry.h"
#include "common.h"

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
}

void Scene::build() {
	cvShowImage("rgb", rgb);
	cvShowImage("depth", depth);

	cloud.clear();

	for (int i = 0; i < YRES; i++) {
		for (int j = 0; j < XRES; j++) {
			Rgb color = ((Rgb*)rgb->imageData)[i * 640 + j];
			uint16_t d = ((uint16_t*)depth->imageData)[i * 640 + j];
			points[j][i] = ColorPoint(j, i, d,
					(float)color.b / 255, (float)color.g / 255, (float)color.r / 255);
		}
	}

	for (int i = 0; i < XRES; i++) {
		for (int j = 0; j < YRES; j++) {
			cloud.push_back(&points[i][j]);
		}
	}
}

