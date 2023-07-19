#ifndef RODCUT_HPP
#define RODCUT_HPP

#include <vector>
#include <iostream>
#include <cmath>


namespace AiSD
{
    using num=unsigned int;
    using tab=std::vector<num>;
    using price=int;
    num RodCutRecursive(tab& p,num n,price k);
    num RodCutRecursiveMem(tab& p,num n,price k);
    num RodCutBottomUp(tab& p,num n,price k);
    void printPossibilities(tab& p,num n,price k);

}

#endif // RODCUT_HPP
