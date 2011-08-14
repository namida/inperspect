#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>


#include "renderer.h"
#include "geometry.h"


Renderer::Renderer() : ypoz(0), zpoz(0) {
	
	
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	
	glViewport (0, 0, 500, 500); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, 1, 1.0, 200.0);
	glMatrixMode (GL_MODELVIEW);
	int j=0;
	for(double i=0;i<0.95;i+=0.1){
		float random = rand() % 10;
	
		pointsX[j] = Point(0.0f,0.1f,random);
		pointsY[j] = Point(0.1f,0.0f,random);
		pointsZ[j] = Point(-0.1f,0.0f,random);
		j++;
	}

}

void Renderer::render(void)
{
	// We increment the rotation angle for the triangle, and if it went over 360 we wrap it back to 0
	ypoz+=0.5;
	if (ypoz>360) ypoz=0;


	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();

	// We will draw things a little deeper into the screen
	glTranslatef(0,0,-6);
	// Lets do some rotations here
	// ypoz gets changed by the animation function and zpoz only by keyboard.
	// remember you can press 'y' and 'z' to play with these
	// The angle is in degrees (0..360)
	glRotatef(ypoz,0,1,0);
	glRotatef(zpoz,0,0,1);

	// I'm going to draw something simple here as we haven't yet discussed loading models
	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
		for(int i=0;i<10;i++){
			glVertex3f(pointsX[i].x,pointsX[i].y,pointsX[i].z);
			glVertex3f(pointsY[i].x,pointsY[i].y,pointsY[i].z);
			glVertex3f(pointsZ[i].x,pointsZ[i].y,pointsZ[i].z);
			/*printf("x1 %f,y1 %f,z1 %f\n",pointsX[i].x,pointsX[i].y,pointsX[i].z);
			printf("x2 %f,y2 %f,z2 %f\n",pointsY[i].x,pointsY[i].y,pointsY[i].z);
			printf("x3 %f,y3 %f,z3 %f\n",pointsZ[i].x,pointsZ[i].y,pointsZ[i].z);
			printf("-----------\n");*/
			
		}
		//glColor3f(0,1,0);
		//glVertex3f(0,0.3,0);
		//glVertex3f(0,0,0.2);
		//glVertex3f(0,0,-0.2);
	glEnd();

	// I sugest you test how it runs without this sleep too. Obviously it will be faster but that's not the reason it's here
	// You could allways make the animation slower by making the angle increment smaller but the sleep here has a diffrent importance
	// If you didn't put it then animation would run and different speeds depending on how big the window is...would run faster on a smaller window
	// and slower in full screen.
	// There are other ways to limit the fps but this will be enough for now

	glutSwapBuffers();


}

