#include "fibonacco.h"

#include <iostream>


size_t AiSD::CiagFic(int n){
    if(n<2){
        return n;
    }
    return CiagFic(n-2)+CiagFic(n-1);
}

size_t AiSD::CiagFic1(int n){
    if(n<2){
         return n;
    }
    else{
        size_t tmp, a=1,b=0;
        for(size_t i=2;i<=n;++i){
            tmp=a;
            a+=b;
            b=tmp;
        }
        return a;
    }
    return 0;
}


