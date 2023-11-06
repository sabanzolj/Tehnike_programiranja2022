//TP 2022/2023: LV 2, Zadatak 5
#include <iostream>
#include <cmath>
#include <complex>


int main ()
{

    std::cout<<"Unesi broj elemenata:"<<std::endl;
    int broj;
    std::cin>>broj;
    std::complex<double> U=0;
    std::complex<double> Z=0;
    double a;
    double fi;
    

    for(int i=1;i<=broj;i++){
        std::cout<<"Z"<<i<<" = ";
        std::cin>>a;
        std::cout<<"fi"<<i<<" = ";
        std::cin>>fi;
        fi=fi*M_PI/180.0;
        U={a*cos(fi),a*sin(fi)};
        Z+=1./U;
        std::cout<<std::endl;
        
    }
    std::cout<<std::endl;

    Z=1./Z;

    std::cout<<"Paralelna veza ovih elemenata ima Z = "<<fabs(Z)<<" i fi = "<<arg(Z)*180.0/M_PI<<".";



	return 0;
}