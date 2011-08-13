#include <stdlib.h>
#include <GL/glut.h>


#include "renderer.h"


Renderer::Renderer() : ypoz(0), zpoz(0) {
	
	glClearColor (0.0, 0.0, 0.0, 0.0); 
	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	
	glViewport (0, 0, 500, 500); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, 1, 1.0, 20.0);
	glMatrixMode (GL_MODELVIEW);
	
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
glVertex3f(0,2,0);
glVertex3f(3,0,0);
glVertex3f(-3,0,0);
glEnd();

// I sugest you test how it runs without this sleep too. Obviously it will be faster but that's not the reason it's here
// You could allways make the animation slower by making the angle increment smaller but the sleep here has a diffrent importance
// If you didn't put it then animation would run and different speeds depending on how big the window is...would run faster on a smaller window
// and slower in full screen.
// There are other ways to limit the fps but this will be enough for now

glutSwapBuffers();


}

