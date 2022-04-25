#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut.h>
#endif


#include <boost/thread.hpp>

#include "DrawFunctions.hpp"
#include "SortThread.hpp"



int main(int argc, char** argv)
{
    boost::thread t1(AiSD::thread1);


    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Presentation");
    glutDisplayFunc(AiSD::display);
    glutMouseFunc(AiSD::getMouse);
    AiSD::onStart();
    glutMainLoop();

    return 0;
}
