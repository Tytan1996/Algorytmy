#ifndef BASICDRAWFUNCTIONS_HPP
#define BASICDRAWFUNCTIONS_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut.h>
#endif

#include <stdlib.h>//reinterpret_cast
#include <vector>

#include <boost/thread.hpp>

//STRUKTURA X, Y
struct vector2
{
    float x,y;
};

//WYKONAJ NA STARCIE
void onStart();

void getMouse (int button, int state,int x, int y);
void keyPressed(unsigned char key, int x, int y);
void display() ;

vector2 convertSize(float x,float y);//CIEZKO SIE OPERUJE NA 1.0F-0.0F

//TEKST
void drawString(const char* txt, float x,float y,float r,float g,float b);

//PRZYCISK
struct textBlock
{
    vector2 poz;
    vector2 size;
    const char* text="";
    bool hover=false;
    int selectionId;
    int Id;
};
class blockCollection
{
public:

    std::vector<textBlock> boxes;
    void drawAll();
    void addNew(textBlock nowy);
    void checkIfClick(vector2 mouse);
};


#endif // BASICDRAWFUNCTIONS_HPP
