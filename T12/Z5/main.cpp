//TP 2022/2023: LV 12, Zadatak 5
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
int main ()
{
	int n;
    std::cout << "Koliko zelite elemenata: ";
    std::cin >> n;
    std::vector<double> vektor(n);
    std::cout << "Unesite elemente: ";
    for(int i=0; i < n; i++) std::cin >> vektor[i];
//  std::transform(vektor.begin(), vektor.end(), vektor.begin(), std::bind1(std::divides<double>(), 1));
std::transform(vektor.begin(), vektor.end(), vektor.begin(), std::bind(std::divides<double>(), 1, std::placeholders::_1));
std::cout << "Transformirani elementi: ";
for(int i=0; i < n; i++) std::cout <<vektor[i] << " ";
return 0;
}