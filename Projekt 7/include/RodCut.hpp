#ifndef RODCUT_HPP
#define RODCUT_HPP

#include <vector>
#include <iostream>

namespace AiSD
{
    using num=unsigned int;
    using tab=std::vector<num>;
    num RodCutRecursive(tab& p,num n);
    num RodCutRecursiveMem(tab& p,num n);
    num RodCutBottomUp(tab& p,num n);
    void printPossibilities(tab& p,num n);
}

#endif // RODCUT_HPP
