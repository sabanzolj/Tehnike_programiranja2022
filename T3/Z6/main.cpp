// TP 2022/2023: LV 3, Zadatak 6
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


std::vector<std::vector<int>> KroneckerovProizvod(std::vector<int> Niz1,
                                                  std::vector<int> Niz2) {
  int m;
  int n;
  m = Niz1.size();
  n = Niz2.size();

  std::vector<std::vector<int>> Matrica(m, std::vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      Matrica[i][j] = Niz1[i] * Niz2[j];
    }
  }

  return Matrica;
}

int BrojRedova(std::vector<std::vector<int>> Matrica) { return Matrica.size(); }

int BrojKolona(std::vector<std::vector<int>> Matrica) {
  if (Matrica.size() != 0) {
    return Matrica[0].size();
  }
}

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



int main() {
  int m, n;
  std::vector<int> Niz1;
  std::vector<int> Niz2;
  std::cout << "Unesite broj elemenata prvog vektora: ";
  std::cin >> m;

  std::cout << "Unesite elemente prvog vektora: ";

  for (int i = 0; i < m; i++) {
    int broj;
    std::cin >> broj;
    Niz1.push_back(broj);
  }

  std::cout << "Unesite broj elemenata drugog vektora: ";
  std::cin >> n;

  std::cout << "Unesite elemente drugog vektora: "<<std::endl;

  for (int i = 0; i < n; i++) {
    int broj;
    std::cin >> broj;
    Niz2.push_back(broj);
  }

  std::vector<std::vector<int>> Matrica = KroneckerovProizvod(Niz1, Niz2);

  for (int i = 0; i < BrojRedova(Matrica); i++) {
    for (int j = 0; j < BrojKolona(Matrica); j++) {
      std::cout << std::setw(NajvecaSirina(Matrica)) <<Matrica[i][j]<<" ";
    }
    std::cout<<std::endl;
  }

  return 0;
}
