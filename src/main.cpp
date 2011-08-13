#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/freeglut.h>

// OpenCV stuff
#include <cv.h>
#include <highgui.h>
// OpenCV/Kinect compat
#include "libfreenect_cv.h"
#include "libfreenect_sync.h"

void lighten(IplImage *img) {
	for (int i = 0; i < img->imageSize / 2; i++) {
		((uint16_t*)img->imageData)[i] *= 32;
	}
}

int main() {
	cvNamedWindow("depth", 0);
	cvNamedWindow("rgb", 0);

	int key;
	int tilt = 0;
	while ((key = cvWaitKey(10)) != 27) {
		switch (key) {
			case 'w': tilt = MIN(45, tilt + 5); break;
			case 'x': tilt = MAX(-45, tilt - 5); break;
			case 's': tilt = 0;
		}
		freenect_sync_set_tilt_degs(tilt, 0);

		IplImage *rgb = freenect_sync_get_rgb_cv(0);
		cvCvtColor(rgb, rgb, CV_RGB2BGR);
		IplImage *depth = freenect_sync_get_depth_cv(0);
		lighten(depth);

		cvShowImage("rgb", rgb);
		cvShowImage("depth", depth);
	}
	freenect_sync_set_tilt_degs(0, 0);
}
