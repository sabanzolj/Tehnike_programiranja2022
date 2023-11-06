// TP 2022/2023: LV 3, Zadatak 5
#include <cmath>
#include <deque>
#include <iostream>

std::deque<int> IzdvojiElemente(std::deque<int> Niz, bool Parnost) {

  std::deque<int> Parni;
  std::deque<int> Neparni;
  for (int i=Niz.size()-1;i>=0;i--) {

    int broj = Niz[i];

    int S = 0;
    if (broj < 0) {
      S += broj % 10;
      broj = broj / 10;
      broj = broj * (-1);
    }
    while (broj > 0) {
      S += broj % 10;
      broj = broj / 10;
    }

    if (S % 2 == 0) {
      Parni.push_front(Niz[i]);
    }

    else if (S % 2 != 0) {
      Neparni.push_front(Niz[i]);
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
  std::deque<int> Niz;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    Niz.push_back(a);
  }

  std::cout << std::endl;

  std::deque<int> Temp = IzdvojiElemente(Niz, true);

  for (int i = 0; i<Temp.size(); i++) {
    if (i != Temp.size()-1) {
      std::cout << Temp[i] << ",";
    } else {
      std::cout << Temp[i];
    }
  }

  std::cout << std::endl;

  Temp = IzdvojiElemente(Niz, false);

  for (int i = 0; i <Temp.size(); i++) {
    if (i != Temp.size()-1) {
      std::cout << Temp[i] << ",";
    } else {
      std::cout << Temp[i];
    }
  }

  return 0;
}