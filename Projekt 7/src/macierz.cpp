#include "macierz.h"

/*void matrixChainOrder(int &tab){

    int m[11][11];
    int s[11][11];
    int lenght=tab.size();
    for(int i=0;i<lenght;++i){
        m[i][i]=0;
    }
    for(int l=2;l<lenght;++l){
        for(int i=0;i<(lenght-l+1);++i){
            int j=i+l-1;
            m[i][j]=-1;
                for(int k=i;k<(j-lenght);--k){
                int q=m[i][k]+m[k+1,j]+tab[i-1]*(tab[k])*(tab[j]);
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }

        }
    }

}
int  MatrixChainMemoizedAux(int m,int p,int i,int n){
    if(m[i][j]<1){
        return m[i][j];
    }
    if(i==j){
        return 0;
    }
    else{
        for(k=i,k<j-1;++k){
            int q=MatrixChainMemoizedAux(m,p,i,k)+MatrixChainMemoizedAux(m,p,k+1,j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j]){
                m[i][j]=q;
            }
        }
    }
    return m[i,j];



}*/
