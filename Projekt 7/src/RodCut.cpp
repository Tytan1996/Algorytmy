#include "RodCut.hpp"

/*INSIDE*/
AiSD::num AiSD::RodCutRecursive(tab& p,num n,price k)
{
    if(n==0)
        return 0;

    num q=0;
    for(num i=1;i<=n;i++)
    {
        num a=p[i-1]+RodCutRecursive(p,n-i,-abs(k))-abs(k);
        q=a<q?q:a;
    }
    if(k>0)q+=k;
    return q;
}

/*OUTSIDE*/
AiSD::num push_and_return(AiSD::tab &mem,AiSD::num h)
{
    mem.push_back(h);
    return h;
}

/*OUTSIDE*/
AiSD::num RodCutRecursiveMemA(AiSD::tab &p,AiSD::num n,AiSD::tab &mem,AiSD::price k)
{
    if(n==0)//taki ficzer, ze 0 to automatyczny n
        //n=p.size()-1;
        return 0;
    AiSD::num q=0;
    for(AiSD::num i=1;i<=n;i++)
    {
        AiSD::num a=(mem.size()>n-i)?mem[n-i]:push_and_return(mem,RodCutRecursiveMemA(p,n-i,mem,-abs(k))-abs(k));
        AiSD::num b=p[i-1]+a;
        q=b<q?q:b;
    }
    if(k>0)q+=k;
    return q;
}

/*INSIDE*/
AiSD::num AiSD::RodCutRecursiveMem(tab& p,num n,price k)
{
    tab memory;
    return RodCutRecursiveMemA(p,n,memory,k);
}

/*INSIDE*/
AiSD::num AiSD::RodCutBottomUp(tab& p,num n,price k)
{
    if(n==0)
        return 0;
    tab R;
    R.reserve(n+1);

    R[0]=0;
    for(num j=1;j<=n;j++)
    {
        num q=0;
        for(num i=1;i<=j;i++)
        {
            num a=p[i-1]+R[j-i]-k;
            q=q>a?q:a;
        }
        R[j]=q;
    }
    return R[n]+1;
}

/*INSIDE*/
void AiSD::printPossibilities(tab& p,num n,price k)
{
    std::cout<<"\nWSZYSTKIE SPOSOBY CIECIA:\n";
    n=n-1;
    num maximum=0;

    bool a[n];
    for(num i=0;i<n;i++)
        a[i]=false;

    for(num j=0;j<pow(2,n);j++)
    {
        num h=j;
        for(num i=n-1;h>0;i--)
        {
            a[i]=h%2==0?false:true;//true ciac, false nie ciac
            h=h/2;
        }
        num l=1;
        num sum=0;
        std::string txt="";
        txt+="-";
        for(num i=0;i<n;i++)
        {
            if(a[i]==false)
            {
                txt+="-";
                l++;
            }
            else
            {
                sum-=k;//koszt
                sum+=p[l-1];
                txt+=" -";
                l=1;
            }
        }
        sum+=p[l-1];
        if(sum>maximum)
            maximum=sum;
        std::cout<<" "<<sum<<"\t"<<txt<<"\n";
    }
    std::cout<<"MAX="<<maximum<<"\n";
}



