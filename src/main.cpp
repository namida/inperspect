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

int main() {
	cvNamedWindow("depth");

	while (cvWaitKey(10) != 27) {
		IplImage *img = freenect_sync_get_depth_cv(0);
		cvShowImage("depth", img);
	}
}
