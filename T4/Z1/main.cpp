// TP 2022/2023: LV 4, Zadatak 1
#include <cmath>
#include <iostream>


int Cifre(long long int n, int &c_min, int &c_max) {
  int br = 0;

  int broj = n % 10;
  c_min = broj;
  c_max = broj;
  br++;
  n = n / 10;

  if (n < 0) {
    n = n * (-1);
    c_max *= (-1);
    c_min *= (-1);
  }

  while (n > 0) {
    int broj = n % 10;
    if (broj > c_max) {
      c_max = broj;
    } else if (c_min > broj) {
      c_min = broj;
    }

    n = n / 10;
    br++;
  }

  return br;
}

int main() {

  std::cout << "Unesite broj: ";
  long long int broj;
  std::cin >> broj;
  int a, b;

  int temp = Cifre(broj, a, b);

  std::cout << "Broj " << broj << " ima " << temp << " cifara, najveca je " << b
            << " a najmanja " << a << ".";

  return 0;
}