// TP 2022/2023: LV 4, Zadatak 2
#include <cmath>
#include <iostream>
#include <string>


void IzvrniString(std::string &Rijec) {

  for (int i = 0; i < Rijec.length() / 2; i++) {
    char Temp = Rijec[i];
    Rijec[i] = Rijec[Rijec.length() - i - 1];
    Rijec[Rijec.length() - i - 1] = Temp;
  }
}

int main() {

  std::cout << "Unesi string: ";
  std::string Rijec;
  std::getline(std::cin, Rijec);
  IzvrniString(Rijec);
  std::cout << "Izvrnuti string je: " << Rijec;

  return 0;
}
