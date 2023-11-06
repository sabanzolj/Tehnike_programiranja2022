//TP 2022/2023: LV 5, Zadatak 5
//greskom uradio zadatak u zadatku 3 pa zato sam kopirao ovde
#include <iostream>
#include <cmath>
#include <iomanip>

double TrapeznoPravilo(double fun(double), double a, double b, int n){

    double Temp=0;
    for(int k=1;k<n;k++){
        Temp+=fun(a+((b-a)/n)*k);
    }

    double Rez=Temp+(fun(a)+fun(b))/2;

    Rez=Rez*(b-a)/n;

    return Rez;

}


int main ()
{

    std::cout<<"Unesite broj podintervala: ";
    int interval;
    std::cin>>interval;

    double pi=atan(1)*4;

    std::cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose: "<<std::endl;

    std::cout<<"- Za funkciju sin x na intervalu (0,pi): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo(std::sin, 0, pi, interval)<<std::endl;

    std::cout<<"- Za funkciju x^3 na intervalu (0,10): "<<std::fixed<<std::setprecision(2)<<TrapeznoPravilo([](double x){return x*x*x;}, 0, 10, interval)<<std::endl;

    std::cout<<"- Za funkciju 1/x na intervalu (1,2): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo([](double x){return 1./x;}, 1, 2, interval)<<std::endl;




	return 0;
}