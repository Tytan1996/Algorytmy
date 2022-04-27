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

#include "SortThread.hpp"
#include "PresetLoader.hpp"
#include <boost/thread.hpp>
#include <functional>
#include <string>


namespace AiSD
{



//STRUKTURA X, Y
struct vector2  //SOME SIMPLE STRUCTURES. VECTOR 2 IS USED FOR HOLDING POSITION ON THE SCREEN
{
    float x,y;
};
struct vector3//AND THE VECTOR3 AM USING FOR HOLIDNG COLORS
{
    float x,y,z;
};

//WYKONAJ NA STARCIE
void onStart();


void getNumber();
void drawBenchmarkResult();
void Circle(float r,float pos_x,float pos_y);
float autoScale(const std::vector<Record> &Tab);
void getMouse (int button, int state,int x, int y);
void display() ;

vector2 convertSize(float x,float y);//CIEZKO SIE OPERUJE NA 1.0F-0.0F


void drawTable(const std::vector<Record> &Tab,bool onlyLines,bool autoScaleMe=true,int columns=-1,vector3 Color={0.0f,0.0f,0.0f});

//TEKST
void drawString(const char* txt, vector2 pos,vector3 color,vector2 offset={0.0f,0.0f});

//PRZYCISK
struct textBlock
{
    vector2 poz;
    vector2 size;
    const char* text="";
    bool hover=false;
    int selectionId;
    int Id;
    std::function<void()> doOnClick;
};
class blockCollection
{
public:

    std::vector<textBlock> boxes;
    void drawAll();
    void addNew(textBlock nowy);
    void checkIfClick(vector2 mouse);
};

}

#endif // BASICDRAWFUNCTIONS_HPP
