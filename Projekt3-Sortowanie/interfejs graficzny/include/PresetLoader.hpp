#ifndef PRESETLOADER_HPP
#define PRESETLOADER_HPP


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>


#include <stdio.h>
#include <string>

#include <cstdio>

#include "tinyfiledialog\tinyfiledialogs.h"

std::string openFile();
std::string saveFile();

#include <string>

#include <cstdio>
#include <vector>

#include "tinyfiledialog\tinyfiledialogs.h"
#include "simpleini/ini.h"
#include "Sort.h"

namespace AiSD
{
std::string openFile();
std::string saveFile();

struct PresetStruct
{
    std::string method;//sorting type
    std::string description;
    std::vector<Record> Tab;
};
void savePreset(std::string src,PresetStruct presetStruct);
PresetStruct openPreset(std::string src);
}



>>>>>>> origin/Interfejs-Projekt3
#endif // PRESETLOADER_HPP
