//TP 2022/2023: LV 3, Zadatak 7
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int NajvecaSirina(std::vector<std::vector<int>> Matrica) {
  int sirina = 0;
  int maxSirina=0;

  if(Matrica.size()==0){
      return 0;
  }

  for(int i=0;i<Matrica.size();i++){
     for(int j=0;j<Matrica[i].size();j++){
         sirina=0;

         if(Matrica[i][j]<0){
             sirina=sirina+1;
             Matrica[i][j]=Matrica[i][j]/10;
             Matrica[i][j]=Matrica[i][j]*(-1);
             sirina=sirina+1;

             
         }

         

         while(Matrica[i][j]>0){
             sirina=sirina+1;
             Matrica[i][j]=Matrica[i][j]/10;
         }

         if(sirina>maxSirina){
             maxSirina=sirina;
         }


     }
  }

  return maxSirina;
}

std::vector<std::vector<int>> PascalovTrougao(int n){

    std::vector<std::vector<int>> Trougao;

    for(int i=0;i<n;i++){

        Trougao[i].resize(i+1);
        Trougao[i][0]=Trougao[i][i]=1;

        for(int j=1;j<i;j++){
            Trougao[i][j]=Trougao[i-1][j-1]+Trougao[i-1][j];

        }

    }

    return Trougao;
}


int main ()
{
    try
    std::cout<<"Unesite broj redova: ";
    int br_redova;
    std::cin>>br_redova;

    if(br_redova<1){
        std::cout<<"Broj redova ne smije biti negativan";
        return 0;
    }

    std::vector<std::vector<int>> Temp=PascalovTrougao(br_redova);

    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_redova;j++){
            std::cout<<std::setw(NajvecaSirina(Temp))<<Temp[i][j]<<" ";

        }
        std::cout<<std::endl;
    }




	return 0;
}
