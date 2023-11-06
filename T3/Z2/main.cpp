// TP 2022/2023: LV 3, Zadatak 2
#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> IzdvojiElemente(std::vector<int> Niz, bool Parnost) {

  std::vector<int> Parni;
  std::vector<int> Neparni;
  for (int x : Niz) {

    int broj = x;
    
    int S = 0;
    if(broj<0){
        S+=broj%10;
        broj=broj/10;
        broj=broj*(-1);
    }
    while (broj > 0) {
      S += broj % 10;
      broj = broj / 10;
    }

    if (S % 2 == 0) {
      Parni.push_back(x);
    }

    else if (S % 2 != 0) {
      Neparni.push_back(x);
    }
  }

  if (Parnost) {
    return Parni;
  } else {
    return Neparni;
  }
}

int main() {
  int n;
  std::cout << "Koliko zelite unijeti elemenata: ";
  std::cin >> n;

  if (n < 1) {
    std::cout << "Broj elemenata mora biti veci od 0!" << std::endl;
    return 0;
  }

  std::cout << "Unesite elemente: ";

  int a;
  std::vector<int> Niz;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    Niz.push_back(a);
  }

  std::cout << std::endl;

  std::vector<int> Temp = IzdvojiElemente(Niz, true);

  for (int i = 0; i < Temp.size(); i++) {
    if (i != Temp.size() - 1) {
      std::cout << Temp[i] << ",";
    } else {
      std::cout << Temp[i];
    }
  }

  std::cout << std::endl;

  Temp = IzdvojiElemente(Niz, false);

  for (int i = 0; i < Temp.size(); i++) {
    if (i != Temp.size() - 1) {
      std::cout << Temp[i] << ",";
    } else {
      std::cout << Temp[i];
    }
  }

  return 0;
}
