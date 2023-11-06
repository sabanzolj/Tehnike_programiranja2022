// TP 2022/2023: LV 4, Zadatak 4
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename NekiTip>
void UnosBroja(const std::string &Ulaz, const std::string &Upozorenje,
               NekiTip &broj) {

  while (std::cout << Ulaz, !(std::cin >> broj) || std::cin.peek() != '\n') {

    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << Upozorenje << std::endl;
  }
}

int main() {

  double a;
  int b;
  UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", a);
  UnosBroja("Unesite cjelobrojni eksponent: ",
            "Neispravan unos, pokusajte ponovo...", b);

  double R = 1.;
  bool Negative = false;

  if (b < 0) {
    Negative = true;
  }

  for (int i = 0; i < abs(b); i++) {
    R = R * a;
  }

  if (Negative) {
    R = 1. / R;
  }

  std::cout << a << " na " << b << " iznosi " << R;

  return 0;
}
