//TP 2022/2023: LV 2, Zadatak 3
#include <iostream>
#include <cmath>
#include <complex>


int main ()
{

    std::cout<<"Unesite broj elemenata: "<<std::endl;
    int broj;
    std::cin>>broj;
    std::complex<double> Z=0;
    std::complex<double> a;

    for(int i=1;i<=broj;i++){
        std::cout<<"Z_"<<i<<" = ";
        std::cin>>a;
        Z+=1./a;
        
    }
    std::cout<<std::endl;

    Z=1./Z;

    std::cout<<"Paralelna veza ovih elemenata ima impedansu Z_ = ("<<Z.real()<<","<<Z.imag()<<").";



	return 0;
}