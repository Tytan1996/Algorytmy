#include "RodCut.hpp"



AiSD::num AiSD::RodCutRecursive(tab& p,num n)
{
    if(n==0)
        return 0;
    num q=0;
    for(num i=1;i<n;i++)
    {

        num a=p[i]+RodCutRecursive(p,n-i);
        q=a<q?q:a;
        //std::cout<<q<<"\n";
    }
    return q;
}


AiSD::num push_and_return(AiSD::tab &mem,AiSD::num h)
{
    mem.push_back(h);
    return h;
}

AiSD::num RodCutRecursiveMemA(AiSD::tab &p,AiSD::num n,AiSD::tab &mem)
{
    if(n==0)
        return 0;
    AiSD::num q=0;
    for(AiSD::num i=0;i<n;i++)
    {
        AiSD::num a=(mem.size()>=n-i)?mem[a]:push_and_return(mem,RodCutRecursiveMemA(p,n-i,mem));
        AiSD::num b=p[i]+a;
        AiSD::num q=b<q?q:b;
    }
    return q;
}

AiSD::num AiSD::RodCutRecursiveMem(tab& p,num n)
{
    tab memory;
    RodCutRecursiveMemA(p,n,memory);
}

