#include "BasicDrawFunctions.hpp"

#include <iostream>



bool menuActive=true;

std::vector<std::vector<Record>> backupBenchmark;

blockCollection newCollection;
void onStart()
{
    newCollection.boxes.clear();
    newCollection.addNew({convertSize(0.0f,100.0f),convertSize(200.0f,50.0f),"Losowa",false,0,0,[](){setSetting(TableTypes::Random);}});
    newCollection.addNew({convertSize(0.0f,200.0f),convertSize(200.0f,50.0f),"Posortowana",false,0,1,[](){setSetting(TableTypes::Sorted);}});
    newCollection.addNew({convertSize(0.0f,300.0f),convertSize(200.0f,50.0f),"Odwrotnie Posort.",false,0,2,[](){setSetting(TableTypes::ReversSorted);}});

    newCollection.addNew({convertSize(300.0f,100.0f),convertSize(200.0f,50.0f),"ShellSort",false,1,3,[](){setSetting(SortingMethod::Shell);}});
    newCollection.addNew({convertSize(300.0f,200.0f),convertSize(200.0f,50.0f),"QuickSort",false,1,4,[](){setSetting(SortingMethod::Quick);}});
    newCollection.addNew({convertSize(300.0f,300.0f),convertSize(200.0f,50.0f),"MergeSort",false,1,5,[](){setSetting(SortingMethod::Merge);}});
    newCollection.addNew({convertSize(300.0f,400.0f),convertSize(200.0f,50.0f),"InsertSort",false,1,6,[](){setSetting(SortingMethod::Insertion);}});

    newCollection.addNew({convertSize(600.0f,100.0f),convertSize(200.0f,50.0f),"200",false,2,7,[](){setSetting(200);}});


    newCollection.addNew({convertSize(600.0f,550.0f),convertSize(200.0f,50.0f),"Start",false,3,8,[](){Start();}});//newCollection.boxes.clear();menuActive=false;
    newCollection.addNew({convertSize(0.0f,550.0f),convertSize(200.0f,50.0f),"Open",false,3,9,[](){openFile();}});
    newCollection.addNew({convertSize(300.0f,550.0f),convertSize(200.0f,50.0f),"Benchmark",false,3,10,[](){backupBenchmark=Benchmark();}});
}




void drawString(const char* txt, vector2 pos,float r,float g,float b,vector2 offset)
{
    const unsigned char* t = reinterpret_cast<const unsigned char *>( txt );
    glColor4f(r, g, b, 1.0f);

    glRasterPos2f(pos.x+offset.x, pos.y+offset.y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, t);
}
vector2 MouseBackup;
void getMouse (int button, int state,int x, int y)
{
    MouseBackup={(x/float(glutGet(GLUT_WINDOW_WIDTH)))*800.0f,(y/float(glutGet(GLUT_WINDOW_HEIGHT)))*600.0f};

    newCollection.checkIfClick({x,y});
    //std::cout<<"x:"<<x<<" y:"<<y<<std::endl;
}



/*
std::vector<Record> generateLimitedTable(const std::vector<Record> &Tab,int limited)
{
    if(limited>=Tab.size())
        return Tab;

    int limit=Tab.size()/limited;
    std::vector<Record> limitedTable;
    int sum=0;
    int num=0;
    for(int i=0;i<Tab.size();i++)
    {
        if(i%limit==0&&num!=0)
        {
            Record newRecord({' ',sum/num});
            limitedTable.push_back(newRecord);
            sum=0;
            num=0;
        }else
        {
            sum+=Tab[i].key;
            num+=1;
        }
    }

    return limitedTable;
}*/

void Circle(float r,float pos_x,float pos_y)
{
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    float x = 1.0f;
    float y = 1.0f;
    for (int i = 0; i <= 360; i++)
    {
        vector2 vec2=convertSize(r * sin(i)+pos_x, r * cos(i)+pos_y);
        glVertex2f((vec2.x-1.0f),(vec2.y-1.0f)*-1.0f);
    }
    glEnd();
}

float scaleX,scaleY;

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if(menuActive&&getProcessing())//jezeli zaczniesz sortowac to schowaj menu
        menuActive=false;

    if(menuActive)
    {
        drawString("Wybierz typ tablicy:",convertSize(0.0f,0.0f),0.0f,0.0f,0.0f,{-1.0f,0.9f});
        drawString("Wybierz sortowanie:",convertSize(300.0f,0.0f),0.0f,0.0f,0.0f,{-1.0f,0.9f});
        drawString("Wielkosc:",convertSize(600.0f,0.0f),0.0f,0.0f,0.0f,{-1.0f,0.9f});

    }else
    {
        newCollection.boxes.clear();
        //drawTable(generateLimitedTable(getTab(),200),false);
        drawTable(getTab(),false);
        if(getProcessing())
        {
            glutPostRedisplay();
        }else
        {

            int tabX=int((MouseBackup.x)/scaleX);
            int tabY=int((600.0f-MouseBackup.y)/scaleY);
            if(tabX>=0&&tabX<getTab().size())
            {
                std::string txt="Cursor: "+std::to_string(tabX)+"x"+std::to_string(tabY);
                txt+="\nTab["+std::to_string(tabX)+"]={key="+std::to_string(getTab()[tabX].key)+",id=\""+getTab()[tabX].ID+"\"}";
                drawString(txt.c_str(),convertSize(0.0f,0.0f),0.0f,0.0f,0.0f,{-1.0f,0.9f});
            }

            newCollection.addNew({convertSize(0.0f,70.0f),convertSize(200.0f,50.0f),"Back to menu",false,0,1,[](){menuActive=true;onStart();}});
            newCollection.addNew({convertSize(0.0f,140.0f),convertSize(200.0f,50.0f),"Save Preset",false,0,2,[](){saveFile();}});
        }

        /*for(int i=0;i<getTab().size();i++)
        {
            std::cout<<i<<" : "<<getTab()[i].key<<std::endl;
        }*/

    }



    newCollection.drawAll();

    Circle(5,MouseBackup.x,MouseBackup.y);

    glFlush();//rysuj
    //if(!menuActive)blockCollection.boxes.clear();
}


float autoScale(const std::vector<Record> &Tab)
{
    int max=1;
    for(int i=0;i<Tab.size();i++)
    {
        if(max<Tab[i].key)
            max=Tab[i].key;
    }
    return 800.0f/float(max)/1.34;
}



void drawTable(const std::vector<Record> &Tab,bool onlyLines)
{

    float scale=autoScale(Tab);
    scaleY=scale;//TO JEST INFORMACJA DLA TEXT'U SKALI
    scaleX=800.0f/Tab.size();

    vector2 b={-1.0f,-1.0f};

    for(int i=0;i<Tab.size();i++)
    {
        //std::cout<<Tab[i].key<<std::endl;
        if(!onlyLines)
        {
            newCollection.addNew({convertSize((800.0f/Tab.size())*i,600.0f-(Tab[i].key*scale)),convertSize(800.0f/Tab.size(),(Tab[i].key*scale)),"",false,-1,0,[](){}});
        }
        else
        {
            vector2 a=convertSize((800.0f/Tab.size())*(1.0f/2.0f+i),(Tab[i].key*scale));
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
            glVertex2f(a.x-1.0f,a.y-1.0f);
            glVertex2f(b.x-1.0f,b.y-1.0f);
            glEnd();
            b=a;
        }
    }
}


vector2 convertSize(float x,float y)
{
    //std::cout<<(1.0f/800.0f)*x-1.0f<<" x "<<(1.0f/600.0f)*y-1.0f<<std::endl;
    return {((2.0f/800.0f)*x),((2.0f/600.0f)*y)};
}


void blockCollection::drawAll()
{
    //std::vector<Record> test=getTab();
    //for(Record a:test)
    //    std::cout<<a.key<<std::endl;


    for(textBlock box:boxes)
    {
        glBegin(GL_QUADS);
        if(box.hover)//KOLOR ZAZNACZENIA
            glColor4f(0.3f, 0.3f, 0.3f,1.0f);
        else
            glColor4f(0.6f, 0.6f, 0.6f,1.0f);

        glVertex2f(box.poz.x-1.0f,(box.poz.y-1.0f)*-1.0f);
        glVertex2f(box.poz.x-1.0f+(box.size.x),(box.poz.y-1.0f)*-1.0f);
        glVertex2f(box.poz.x-1.0f+(box.size.x),(box.poz.y-1.0f+(box.size.y))*-1.0f);
        glVertex2f(box.poz.x-1.0f,(box.poz.y-1.0f+(box.size.y))*-1.0f);
        glEnd();
        vector2 vec2={box.poz.x-0.98f,(box.poz.y-1.0f+(box.size.y/2.0f))*-1.0f};
        drawString(box.text,vec2,0.0f,0.0f,0.0f);
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
        if(box.poz.x-1.0f<mx&&box.poz.y-1.0f<my&&box.poz.x-1.0f+(box.size.x)>mx&&box.poz.y-1.0f+(box.size.y)>my&&hoverID==-1&&box.selectionId!=-1)
        {
            hoverID=box.Id;
            hoverSelectionId=box.selectionId;
            box.doOnClick();
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
