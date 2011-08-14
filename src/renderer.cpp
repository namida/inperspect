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
	/*int j=0;
	for(double i=0;i<0.95;i+=0.1){
		float random = rand() % 10;
	
		pointsX[j] = Point(0.0f,0.1f,random);
		pointsY[j] = Point(0.1f,0.0f,random);
		pointsZ[j] = Point(-0.1f,0.0f,random);
		j++;
	}*/

}

void Renderer::render(Scene* scene)
{
	// We increment the rotation angle for the triangle, and if it went over 360 we wrap it back to 0
	ypoz+=5;
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
	//glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
		
		for(int i=0;i<scene->cloud.size();i++){
			float random = ((float)rand())/RAND_MAX;
			glColor3f(scene->cloud[i]->r,scene->cloud[i]->g,scene->cloud[i]->b);
			glVertex3f(-scene->cloud[i]->x,-scene->cloud[i]->y+0.01,scene->cloud[i]->z-(5+random));
			glVertex3f(-scene->cloud[i]->x+0.01,-scene->cloud[i]->y,scene->cloud[i]->z-(5+random));
			glVertex3f(-scene->cloud[i]->x-0.01,-scene->cloud[i]->y,scene->cloud[i]->z-(5+random));
			/*printf("x %f,y %f,z %f\n",scene->cloud[i]->x,scene->cloud[i]->y,scene->cloud[i]->z);
			printf("-----------\n");
			printf("size %d\n",scene->cloud.size());
			*/
			
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

