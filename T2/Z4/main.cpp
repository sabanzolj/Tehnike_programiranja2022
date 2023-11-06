//TP 2022/2023: LV 2, Zadatak 4
#include <iostream>
#include <cmath>
#include <complex>


int main ()
{

    std::cout<<"Unesite broj elemenata: "<<std::endl;
    int broj;
    std::cin>>broj;
    std::complex<double> U=0;
    std::complex<double> Z=0;
    double a;
    double b;

    for(int i=1;i<=broj;i++){
        std::cout<<"R"<<i<<" = ";
        std::cin>>a;
        std::cout<<"X"<<i<<" = ";
        std::cin>>b;
        U={a,b};
        Z+=1./U;
        std::cout<<std::endl;
        
    }
    std::cout<<std::endl;

    Z=1./Z;

    std::cout<<"Paralelna veza ovih elemenata ima R = "<<Z.real()<<" i X = "<<Z.imag()<<".";



	return 0;
}