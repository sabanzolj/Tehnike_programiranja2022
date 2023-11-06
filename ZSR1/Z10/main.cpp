//TP 2022/2023: Skriveni Z 2, Zadatak 4
#include <iostream>
#include <cmath>
#include <vector>

template <typename NekiTip1,typename NekiTip2>
NekiTip1 GenerickaFunkcija(NekiTip1 *a1,NekiTip1 *a2,NekiTip2 *b1)decltype(){
    auto temp=a1;
    int brojac=0;
    while(temp!=a2){
     brojac++;
     temp++;
    }

    NekiTip1 Suma=0;
    for(int i=0;i<brojac;i++){
        auto c=(*a1)*NekiTip1(*b1);
        Suma+=c;
        a1++;
        b1++;
    }

    return Suma;
}


int main ()
{

int niz1[5]{1,2,3,4,5};
double niz2[5]{6,7,8,9,10};

int *pok1=niz1;
int *pok2=niz1+5;
int *pok3=niz2;






int rezultat=GenerickaFunkcija(pok1,pok2,pok3);

std::cout<<rezultat;



	return 0;
}
