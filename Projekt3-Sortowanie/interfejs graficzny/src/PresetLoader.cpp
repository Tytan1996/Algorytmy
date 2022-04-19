#include "PresetLoader.hpp"

#include <iostream>

char const * lTheOpenFileName;
char const * lFilterPatterns[2] = { "*.ini", "*.inipp" };

std::string AiSD::openFile()
{
    FILE * lIn;
	lTheOpenFileName = tinyfd_openFileDialog("Load preset file","",2,lFilterPatterns,NULL,0);

	if (! lTheOpenFileName)
	{
		tinyfd_messageBox("Error","Can not open the file","ok","error",0);
		exit(1);
	}
    return lTheOpenFileName;
}

std::string AiSD::saveFile()
{
    char const * lTheSaveFileName;
    lTheSaveFileName = tinyfd_saveFileDialog("Save your preset","preset ini",2,lFilterPatterns,NULL);
	if (!lTheSaveFileName)
	{
        tinyfd_messageBox("Error","Can not open the file","ok","error",1);
        exit(1);
	}
	std::cout<<lTheSaveFileName<<std::endl;

    return lTheSaveFileName;
}


void AiSD::savePreset(std::string src,PresetStruct presetStruct)
{
    mINI::INIFile file(src);
    mINI::INIStructure ini;
    file.read(ini);
    ini.clear();//jezeli cos tu juz jest to to usun

    ini["settings"]["method"] = presetStruct.method;
    ini["settings"]["description"] = presetStruct.description;

    for(int i=0;i<presetStruct.Tab.size();i++)
    {
        ini[std::to_string(i)]["key"] = std::to_string(presetStruct.Tab[i].key);
        ini[std::to_string(i)]["ID"] = presetStruct.Tab[i].ID;
    }
    file.write(ini);
}
AiSD::PresetStruct AiSD::openPreset(std::string src)
{
    PresetStruct newStruct;

    mINI::INIFile file(src);
    mINI::INIStructure ini;
    file.read(ini);

    newStruct.method=ini["settings"]["method"];
    newStruct.description=ini["settings"]["description"];

    for(int i=0;true;i++)
    {
        if(ini.has(std::to_string(i)))
        {
            Record newRecord;

            newRecord.key=std::stoi(ini[std::to_string(i)]["key"]);
            std::string idCopy=ini[std::to_string(i)]["ID"];

            strncpy(newRecord.ID,idCopy.c_str(),5);
            newStruct.Tab.push_back(newRecord);
        }else
        {
            return newStruct;
        }

    }
}
