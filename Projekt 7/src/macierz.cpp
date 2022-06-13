#include "macierz.h"

#include <iostream>
#include <limits>


AiSD::cost_t AiSD::MatrixChainRecursive(const AiSD::dim_arr& dim,AiSD::cost_arr& cost, AiSD::pos_arr& bracket_pos, size_t i,size_t j){

    if(i==j){
        return 0;
    }
    AiSD::cost_t q;

    cost[i][j] = std::numeric_limits<AiSD::cost_t>::max();
    for(size_t k=i;k<j;++k){
        q=MatrixChainRecursive(dim,cost,bracket_pos,i,k)+MatrixChainRecursive(dim,cost,bracket_pos,k+1,j)+dim[i-1]*dim[k]*dim[j];

        if(q<cost[i][j]){
            cost[i][j]=q;
            bracket_pos[i][j]=k;
        }
    }
    return cost[i][j];
}

void AiSD::MatrixChainResursive1 (const AiSD::dim_arr& dim,AiSD::cost_arr& cost, AiSD::pos_arr& bracket_pos){
    MatrixChainRecursive(dim,cost,bracket_pos,1,cost[0].size()-1);
}
void AiSD::MatrixChainOrder(const AiSD::dim_arr& dim, AiSD::cost_arr& cost, AiSD::pos_arr& bracket_pos){
    auto n=dim.size()-1;
    for(size_t l=2;l<=n;++l){
        for(size_t i=1;i<=n-l+1;i++){
            auto j=i+l-1;
            cost[i][j]=std::numeric_limits<AiSD::cost_t>::max();
            for(size_t k=1;k<=j-1;k++){
                auto q=cost[i][j]+cost[k+1][j]+dim[i-1]*dim[k]*dim[j];
                if(q<cost[i][j]){
                    cost[i][j]=q;
                    bracket_pos[i][j]=k;
                }
            }
        }
    }

}
void AiSD::Print(const AiSD::pos_arr& bracket_pos,size_t i,size_t j){
    if(i==j){
        std::cout<<"A"<<j;
    }else{
        std::cout<<"(";
        Print(bracket_pos,i,bracket_pos[i][j]);
        Print(bracket_pos,bracket_pos[i][j]+1,j);
        std::cout<<")";
    }
}
void AiSD::calculateMatrixMemory(){
    dim_arr Macierz {30,25,20,10,10,20,25,2,3,4,5,6,7,8,9,10};
    cost_arr cost1;
    cost1.resize(Macierz.size());
    for(auto& el: cost1){
        el.resize(Macierz.size());
    }
    pos_arr bracket_pos1;
    bracket_pos1.resize(Macierz.size()-1);
    for(auto& el: bracket_pos1){
        el.resize(Macierz.size());
    }
    MatrixChainResursive1( Macierz,cost1,bracket_pos1 );
    std::cout<<"Czas: "<<cost1[1].back();
    std::cout<<"\nNawiasy: ";
    Print(bracket_pos1,1,Macierz.size()-1);
}
void AiSD::calculateMatrix(){
    dim_arr Macierz {30,25,20,10,10,20,25,2,3,4,5,6,7,8,9,10};
    cost_arr cost1;
    cost1.resize(Macierz.size());
    for(auto& el: cost1){
        el.resize(Macierz.size());
    }
    pos_arr bracket_pos1;
    bracket_pos1.resize(Macierz.size()-1);
    for(auto& el: bracket_pos1){
        el.resize(Macierz.size());
    }
    MatrixChainOrder( Macierz,cost1,bracket_pos1 );
    std::cout<<"Czas: "<<cost1[1].back();
}

