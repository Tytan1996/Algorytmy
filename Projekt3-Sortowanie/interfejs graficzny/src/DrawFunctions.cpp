#include "DrawFunctions.hpp"

#include <iostream>


bool benchState=false;
bool menuActive=true;
bool openMenuActive=false;
bool alreadySorted=false;
bool DefaultStart=false;
int backupProcessing=-1;//TO JEST DLATEGO BY W OSTATNIM MOMENCIE WYLAPAC ZMIANE OBRAZU
float scale = 1.0f; //NOTE THIS IS A SCALE FOR DRAWTABLE FUNCTIONS ONLY !!!

std::vector<std::vector<AiSD::Record>> backupBenchmark;


size_t inputGetNumber=0;
void cinInput()
{
    inputGetNumber=-1;
    size_t a;
    std::cout<<"Input a number: ";
    std::cin>>a;
    inputGetNumber=a;
    AiSD::setSetting(inputGetNumber);
}
void AiSD::getNumber()
{
    boost::thread t2(cinInput);
}

AiSD::blockCollection newCollection;
void AiSD::onStart()
{
    alreadySorted=false;
    openMenuActive=false;
    benchState=false;
    menuActive=true;
    DefaultStart=false;

    newCollection.boxes.clear();
    newCollection.addNew({convertSize(0.0f,100.0f),convertSize(200.0f,50.0f),"Random",false,0,0,[](){setSetting(TableTypes::Random);}});
    newCollection.addNew({convertSize(0.0f,200.0f),convertSize(200.0f,50.0f),"Sorted",false,0,1,[](){setSetting(TableTypes::Sorted);}});
    newCollection.addNew({convertSize(0.0f,300.0f),convertSize(200.0f,50.0f),"Inversely Sorted",false,0,2,[](){setSetting(TableTypes::ReversSorted);}});

    newCollection.addNew({convertSize(300.0f,100.0f),convertSize(200.0f,50.0f),"ShellSort",false,1,3,[](){setSetting(SortingMethod::Shell);}});
    newCollection.addNew({convertSize(300.0f,200.0f),convertSize(200.0f,50.0f),"QuickSort",false,1,4,[](){setSetting(SortingMethod::Quick);}});
    newCollection.addNew({convertSize(300.0f,300.0f),convertSize(200.0f,50.0f),"MergeSort",false,1,5,[](){setSetting(SortingMethod::Merge);}});
    newCollection.addNew({convertSize(300.0f,400.0f),convertSize(200.0f,50.0f),"InsertSort",false,1,6,[](){setSetting(SortingMethod::Insertion);}});

    newCollection.addNew({convertSize(600.0f,100.0f),convertSize(200.0f,50.0f),"200",false,2,7,[](){setSetting(200);}});
    newCollection.addNew({convertSize(600.0f,200.0f),convertSize(200.0f,50.0f),"100",false,2,8,[](){setSetting(100);}});
    newCollection.addNew({convertSize(600.0f,300.0f),convertSize(200.0f,50.0f),"10",false,2,9,[](){setSetting(10);}});
    newCollection.addNew({convertSize(600.0f,400.0f),convertSize(200.0f,50.0f),"(Console)",false,2,10,[](){getNumber();}});

    newCollection.addNew({convertSize(600.0f,550.0f),convertSize(200.0f,50.0f),"Start",false,3,11,[](){Start(false);menuActive=false;backupProcessing=-1;DefaultStart=true;}});//newCollection.boxes.clear();menuActive=false;
    newCollection.addNew({convertSize(0.0f,550.0f),convertSize(200.0f,50.0f),"Open",false,4,12,[](){AiSD::ApplyPresetStruct(AiSD::openPreset(AiSD::openFile()));menuActive=false;openMenuActive=true;backupProcessing=-1;}});
    newCollection.addNew({convertSize(300.0f,550.0f),convertSize(200.0f,50.0f),"Benchmark",false,5,13,[](){AiSD::startBenchmark();benchState=true;menuActive=false;backupProcessing=-1;}});



}



void AiSD::drawBenchmarkResult()
{
    drawString("Red-Quick\nYellow-Merge\nGreen-Insert\nBlue-Shell",convertSize(650.0f,-480.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
    int max=1;
    vector3 color={0.0f,0.0f,0.0f};
    newCollection.boxes.clear();
    for(std::vector<Record> a : AiSD::getResultBenchmark())
        for(Record b : a)
            if(max<b.key)
                max=b.key;
    scale=800.0f/float(max)/1.34;
    for(std::vector<Record> a : AiSD::getResultBenchmark())
    {
        for(Record b : a)
        {
            switch(b.ID[0])//IN ID I SAVED A COLOR
            {
            case 0:
                color={1.0f,0.0f,0.0f};
                break;
            case 1:
                color={1.0f,1.0f,0.0f};
                break;
            case 2:
                color={0.0f,1.0f,0.0f};
                break;
            case 3:
                color={0.0f,0.0f,1.0f};
                break;
            }
        }

        drawTable(a,true,false,100,color);
    }

}

void AiSD::drawString(const char* txt, vector2 pos,vector3 color,vector2 offset)
{
    const unsigned char* t = reinterpret_cast<const unsigned char *>( txt );
    glColor4f(color.x, color.y, color.z, 1.0f);

    glRasterPos2f(pos.x+offset.x, pos.y+offset.y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, t);
}
AiSD::vector2 MouseBackup;
void AiSD::getMouse (int button, int state,int x, int y)
{
    MouseBackup={(x/float(glutGet(GLUT_WINDOW_WIDTH)))*800.0f,(y/float(glutGet(GLUT_WINDOW_HEIGHT)))*600.0f};

    if(state==0)
    newCollection.checkIfClick({x,y});
}

void AiSD::Circle(float r,float pos_x,float pos_y)
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

int sortingTime=0;
float scaleX,scaleY;

void AiSD::display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if(restrictDraw())
    {
        drawString("Wait...",convertSize(400.0f,-300.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
    }
    //else
    {
        if(menuActive&&getProcessing())//jezeli zaczniesz sortowac to schowaj menu
            menuActive=false;

        if(menuActive)
        {
            drawString("Select type of table:",convertSize(0.0f,0.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
            drawString("Select method of sorting:",convertSize(300.0f,0.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
            drawString("Select size of table:",convertSize(600.0f,0.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});

        }else
        {
            newCollection.boxes.clear();


            if(benchState==false)
            {
                if(AiSD::restrictDraw()==false&&!restrictDraw())
                    drawTable(AiSD::getPrintTable(),false);
            }
            else
            {
                if(AiSD::restrictDraw()==false)
                    drawBenchmarkResult();
                if(getProcessing())
                    drawString("Wait...",convertSize(400.0f,-300.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
            }
            if(!getProcessing())
            {
                newCollection.addNew({convertSize(0.0f,70.0f),convertSize(200.0f,50.0f),"Back to menu",false,6,14,[](){menuActive=true;onStart();benchState=false;}});
                if((!benchState&&openMenuActive==false)&&!restrictDraw())
                {
                    newCollection.addNew({convertSize(0.0f,140.0f),convertSize(200.0f,50.0f),"Save Sorted",false,7,15,[](){savePreset(saveFile(),GeneratePresetStruct("Sorted table",false));}});
                    newCollection.addNew({convertSize(0.0f,210.0f),convertSize(200.0f,50.0f),"Save Unsorted",false,8,16,[](){savePreset(saveFile(),GeneratePresetStruct("File generated by program",true));}});
                }
            }
            if(openMenuActive==true&&!restrictDraw())
            {
                if(alreadySorted==false)
                    newCollection.addNew({convertSize(600.0f,0.0f),convertSize(200.0f,50.0f),"Sort",false,9,17,[](){alreadySorted=true;Start(true);backupProcessing=-1;}});
                else
                    newCollection.addNew({convertSize(0.0f,140.0f),convertSize(200.0f,50.0f),"Save",false,10,18,[](){savePreset(saveFile(),GeneratePresetStruct("Sorted table",false));}});
            }
            newCollection.drawAll();
            if(!alreadySorted&&openMenuActive)
                 drawString(getDescription().c_str(),convertSize(0.0f,-560.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
            if(!getProcessing()&&backupProcessing<5)backupProcessing++;//ostatnia zmiana byla niewidoczna bo getProcessing bylo szybsze. To jest spowolnienie by zrobic opoznienie o 5 jednostek
            if(backupProcessing<5)
            {
                glutPostRedisplay();
            }else
            {

                int tabX=int((MouseBackup.x)/scaleX);
                int tabY=int((600.0f-MouseBackup.y)/scaleY);
                if(tabX>=0&&tabX<getPrintTable().size())
                {
                    std::string txt="";
                    if(!benchState)
                        txt+="Cursor: "+std::to_string(tabX)+"x"+std::to_string(tabY)+"\nTab["+std::to_string(tabX)+"]={key="+std::to_string(getPrintTable()[tabX].key)+",id=\""+getPrintTable()[tabX].ID+"\"}";
                    else
                        txt+=std::to_string(int(tabX*stepSizeBenchmark()))+"elements "+std::to_string(tabY)+"microsecounds";
                    drawString(txt.c_str(),convertSize(0.0f,0.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
                }
                if((alreadySorted||DefaultStart)&&!restrictDraw())
                {
                    std::string txt="Sorting took "+std::to_string(getTime())+" microsecounds";
                    drawString(txt.c_str(),convertSize(0.0f,-560.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
                }
            }
        }
        if(menuActive)
            newCollection.drawAll();

    }

    if(inputGetNumber==-1)
    {
        drawString("Input value in console",convertSize(400.0f,-470.0f),{0.0f,0.0f,0.0f},{-1.0f,0.9f});
        glutPostRedisplay();
    }

    Circle(2,MouseBackup.x,MouseBackup.y);
    glFlush();//rysuj
}


float AiSD::autoScale(const std::vector<Record> &Tab)
{
    int max=1;
    for(int i=0;i<Tab.size();i++)
    {
        if(max<Tab[i].key)
            max=Tab[i].key;
    }
    return 800.0f/float(max)/1.34;
}


void AiSD::drawTable(const std::vector<Record> &Tab,bool onlyLines,bool autoScaleMe,int columns,vector3 color)
{
    if(Tab.size()==0)return;
    if(columns==-1||columns==0)
        columns=Tab.size();
    if(autoScaleMe)
        scale=autoScale(Tab);
    scaleY=scale;//TO JEST INFORMACJA DLA TEXT'U SKALI
    scaleX=800.0f/columns;

    vector2 b={-1.0f,-1.0f};

    for(int i=0;i<Tab.size();i++)
    {
        if(!onlyLines)
        {
            newCollection.addNew({convertSize((800.0f/columns)*i,600.0f-(Tab[i].key*scale)),convertSize(800.0f/columns,(Tab[i].key*scale)),"",false,-1,-1,[](){}});
        }
        else
        {
            vector2 a=convertSize((800.0f/columns)*(1.0f/2.0f+i),(Tab[i].key*scale));
            glColor3f(color.x, color.y, color.z);
            glBegin(GL_LINES);
            glVertex2f(a.x-1.0f,a.y-1.0f);
            glVertex2f(b.x-1.0f,b.y-1.0f);
            glEnd();
            b=a;
        }
    }
}


AiSD::vector2 AiSD::convertSize(float x,float y)
{
    return {((2.0f/800.0f)*x),((2.0f/600.0f)*y)};
}


void AiSD::blockCollection::drawAll()
{

    for(textBlock box:boxes)
    {
        glBegin(GL_QUADS);
        if(box.hover)//KOLOR ZAZNACZENIA
            glColor4f(0.3f, 0.3f, 0.3f,1.0f);
        else
            glColor4f(0.6f, 0.6f, 0.6f,1.0f);
        if(box.text=="")
            glColor4f(0.7f, 0.9f, 0.7f,1.0f);

        glVertex2f(box.poz.x-1.0f,(box.poz.y-1.0f)*-1.0f);
        glVertex2f(box.poz.x-1.0f+(box.size.x),(box.poz.y-1.0f)*-1.0f);
        glVertex2f(box.poz.x-1.0f+(box.size.x),(box.poz.y-1.0f+(box.size.y))*-1.0f);
        glVertex2f(box.poz.x-1.0f,(box.poz.y-1.0f+(box.size.y))*-1.0f);
        glEnd();
        vector2 vec2={box.poz.x-0.98f,(box.poz.y-1.0f+(box.size.y/2.0f))*-1.0f};
        drawString(box.text,vec2,{0.0f,0.0f,0.0f});
    }
}

void AiSD::blockCollection::addNew(textBlock nowy)
{
    boxes.push_back(nowy);
}
void AiSD::blockCollection::checkIfClick(vector2 mouse)
{
    int hoverID=-1;
    int hoverSelectionId=-1;
    //POZYCJA MYSZY
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
