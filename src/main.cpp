#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <GL/freeglut.h>

#include <stdio.h>

// OpenCV stuff
#include <cv.h>
#include <highgui.h>
// OpenCV/Kinect compat
#include "libfreenect_cv.h"
#include "libfreenect_sync.h"

#include "scene.h"
#include "renderer.h"
#include "geometry.h"

#define TILT_MAX 45
#define TILT_MIN -45

Scene *scene;
Renderer * renderer;

void display() {
	scene->fetchImage();
	scene->build();
	renderer->render(scene);
}

void doTilt(int);
void doAbsTilt(int);
void handleKey(unsigned char key, int x, int y) {
	switch (key) {
		case 'w': doTilt(5); break;
		case 's': doAbsTilt(0); break;
		case 'x': doTilt(-5); break;
		case 27: doAbsTilt(0); exit(0);
	}
}

int _tilt = 0;
void doAbsTilt(int tilt) {
	_tilt = MAX(MIN(tilt, TILT_MAX), TILT_MIN);
	freenect_sync_set_tilt_degs(_tilt, 0);
}

void doTilt(int delta) {
	doAbsTilt(_tilt + delta);
}

int main(int argc, char **argv) {
	scene = new Scene;
	glutInit(&argc, argv);

	bool gl = true;
	if (argc > 1 && strcmp(argv[1], "--opencv") == 0) {
		gl = false;
	}

	if (!gl) {
		while (true) {
			scene->fetchImage();
			handleKey(cvWaitKey(10), 0, 0);
			scene->build();
		}
	} else {
		glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
		glutInitWindowSize (500, 500); 
		glutInitWindowPosition (100, 100);
		glutCreateWindow (argv[0]);
		glutDisplayFunc(display); 
		glutIdleFunc(display);
		renderer = new Renderer;
		//glutReshapeFunc(reshape);
		glutKeyboardFunc(handleKey);
		// This is the special thing for this lesson
		// We tell Glut to call our function every time he can
		glutMainLoop();
	}
}
