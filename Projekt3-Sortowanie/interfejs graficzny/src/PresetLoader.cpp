#include "PresetLoader.hpp"

#include <iostream>

char const * lTheOpenFileName;
char const * lFilterPatterns[2] = { "*.ini", "*.inipp" };

std::string openFile()
{
    FILE * lIn;
	lTheOpenFileName = tinyfd_openFileDialog("Load preset file","",2,lFilterPatterns,NULL,0);

	if (! lTheOpenFileName)
	{
		tinyfd_messageBox("Error","Open file name is NULL","ok","error",0);
		exit(1);
	}
    return lTheOpenFileName;
}

std::string saveFile()
{
    char const * lTheSaveFileName;
    lTheSaveFileName = tinyfd_saveFileDialog("Save your preset","preset ini",2,lFilterPatterns,NULL);
	if (!lTheSaveFileName)
	{
        tinyfd_messageBox("Error","Save file name is NULL","ok","error",1);
        exit(1);
	}
	std::cout<<lTheSaveFileName<<std::endl;

    return lTheSaveFileName;
}
