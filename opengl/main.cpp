#include <stdlib.h>
#include <GL/glut.h>

static float ypoz = 0, zpoz = 0;

void init(void) 
{
glClearColor (0.0, 0.0, 0.0, 0.0); 
glEnable(GL_DEPTH_TEST);
glShadeModel (GL_SMOOTH);
}

void display(void)
{

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

void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
switch (key) {
case 27: // ESC key
exit(0);
break;
// These will allow you to force some extra rotation by pressing the 'y' and 'z' key.
case 'y': 
ypoz=ypoz+5;
if (ypoz>360) ypoz=0;
glutPostRedisplay();
break;
case 'z': 
zpoz = zpoz+5;
if (zpoz>360) zpoz=0;
glutPostRedisplay();
break;

}
}

// This is the animation function. As you can see it's just another function we tell GLUT to call for us
// in it's idle loop. Image there is a while(true) in glut framework that will draw the scene, and then call
// all the events that happened, and in the end it would call the animate function
void animate()
{
// We increment the rotation angle for the triangle, and if it went over 360 we wrap it back to 0
ypoz+=0.5;
if (ypoz>360) ypoz=0;

// Normally openGL doesn't continuously draw frames. It puts one in place and waits for you to tell him what to do next.
// Calling glutPostRedisplay() forces a redraw with the new angle
glutPostRedisplay();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
glutInitWindowSize (500, 500); 
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display); 
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);

// This is the special thing for this lesson
// We tell Glut to call our function every time he can
glutIdleFunc(animate);

glutMainLoop();
return 0;
}
