#include "BasicDrawFunctions.hpp"

#include <iostream>

blockCollection newCollection;
void onStart()
{
    newCollection.addNew({convertSize(10.0f,100.0f),convertSize(200.0f,50.0f),"Losowa",false,0,0});
    newCollection.addNew({convertSize(10.0f,250.0f),convertSize(200.0f,50.0f),"Posortowana",false,0,1});
    newCollection.addNew({convertSize(10.0f,400.0f),convertSize(200.0f,50.0f),"Odwrotnie Posort.",false,0,2});

    newCollection.addNew({convertSize(500.0f,100.0f),convertSize(200.0f,50.0f),"ShellSort",false,1,3});
    newCollection.addNew({convertSize(500.0f,250.0f),convertSize(200.0f,50.0f),"QuickSort",false,1,4});
    newCollection.addNew({convertSize(500.0f,400.0f),convertSize(200.0f,50.0f),"MergeSort",false,1,5});
    newCollection.addNew({convertSize(500.0f,550.0f),convertSize(200.0f,50.0f),"CountingSort",false,1,6});

    newCollection.addNew({convertSize(1200.0f,1100.0f),convertSize(200.0f,50.0f),"Start",false,2,7});
}

void drawString(const char* txt, float x,float y,float r,float g,float b)
{
    const unsigned char* t = reinterpret_cast<const unsigned char *>( txt );

    glColor4f(r, g, b, 1.0f);
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, t);
}
void getMouse (int button, int state,int x, int y)
{
    newCollection.checkIfClick({x,y});
    //std::cout<<"x:"<<x<<" y:"<<y<<std::endl;
}

void keyPressed(unsigned char key, int x, int y)
{
    //printf("%d\n",key);
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawString("Wybierz typ tablicy:",-0.98f,0.92f,0.0f,0.0f,0.0f);
    drawString("Wybierz sortowanie:",-0.4f,0.92f,0.0f,0.0f,0.0f);

    newCollection.drawAll();


    glFlush();//rysuj
}


vector2 convertSize(float x,float y)
{
    //std::cout<<(1.0f/800.0f)*x-1.0f<<" x "<<(1.0f/600.0f)*y-1.0f<<std::endl;
    return {((1.0f/800.0f)*x),((1.0f/600.0f)*y)};
}


void blockCollection::drawAll()
{
    for(textBlock box:boxes)
    {
        glBegin(GL_QUADS);
        if(box.hover)//KOLOR ZAZNACZENIA
            glColor4f(0.3f, 0.3f, 0.3f,1.0f);
        else
            glColor4f(0.6f, 0.6f, 0.6f,1.0f);

        glVertex2f(box.poz.x-1.0f,(box.poz.y-1.0f)*-1.0f);
        glVertex2f(box.poz.x-1.0f+(box.size.x*2.0f),(box.poz.y-1.0f)*-1.0f);
        glVertex2f(box.poz.x-1.0f+(box.size.x*2.0f),(box.poz.y-1.0f+(box.size.y*2.0f))*-1.0f);
        glVertex2f(box.poz.x-1.0f,(box.poz.y-1.0f+(box.size.y*2.0f))*-1.0f);
        glEnd();
        drawString(box.text,box.poz.x-0.98f,(box.poz.y-1.0f+(box.size.y))*-1.0f,0.0f,0.0f,0.0f);
    }
}
void blockCollection::addNew(textBlock nowy)
{
    boxes.push_back(nowy);
}
void blockCollection::checkIfClick(vector2 mouse)
{
    int hoverID=-1;
    int hoverSelectionId=-1;
    float mx=(mouse.x/(glutGet(GLUT_WINDOW_WIDTH)/2.0f))-1.0f;
    float my=(mouse.y/(glutGet(GLUT_WINDOW_HEIGHT)/2.0f))-1.0f;
    for(textBlock &box:boxes)//PO KLIKNIECIU ZAZNACZ JEDNO
    {
        if(box.poz.x-1.0f<mx&&box.poz.y-1.0f<my&&box.poz.x-1.0f+(box.size.x*2.0f)>mx&&box.poz.y-1.0f+(box.size.y*2.0f)>my&&hoverID==-1)
        {
            hoverID=box.Id;
            hoverSelectionId=box.selectionId;
            box.hover=true;
        }
    }
    for(textBlock &box:boxes)//RESZTE ODZNACZ
    {
        if(hoverSelectionId==box.selectionId)
            if(hoverID!=box.Id)
                box.hover=false;
    }
}
