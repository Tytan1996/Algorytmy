#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut.h>
#endif


#include <boost/thread.hpp>

#include "BasicDrawFunctions.hpp"
#include "SortThread.hpp"



int main(int argc, char** argv)
{
    boost::thread t1(watek);

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Prezentacja");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(getMouse);
    onStart();
    glutMainLoop();

    return 0;
}
