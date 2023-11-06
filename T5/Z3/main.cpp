//TP 2022/2023: LV 5, Zadatak 3
#include <iostream>
#include <cmath>
#include <algorithm>

void Ispis(int n){
    std::cout<<n<<" ";
}

bool PotpunKvadrat(int a){
    int test=std::sqrt(a);
    return std::pow(test,2)==a;
}

int BrojCifara(int a){
    if(a==0){
        return 1;
    }
    return std::log10(std::abs(a))+1;
}

bool UporediBrojCifara(int a, int b){
    return BrojCifara(a)<BrojCifara(b);
}

bool NijeTrocifren(int a){
    if(a<0){
        a*=-1;
    }

    return BrojCifara(a)!=3;
}




int main ()
{

int Niz[1000];

std::cout<<"Unesite broj elemenata (max. 1000): ";
int size;
std::cin>>size;
std::cout<<"Unesite elemente: ";
std::for_each(Niz, Niz+size, [](int &n){std::cin>>n;});

std::cout<<"Najveci element niza je "<<*(std::max_element(Niz,Niz+size))<<std::endl;

std::cout<<"Najmanji element niza se pojavljuje "<<std::count(Niz, Niz+size, *(std::min_element(Niz, Niz+size)))<<" puta u nizu"<<std::endl;

std::cout<<"U nizu ima "<<std::count_if(Niz, Niz+size, PotpunKvadrat)<<" brojeva koji su potpuni kvadrati"<<std::endl;

std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*(std::min_element(Niz,Niz+size,UporediBrojCifara))<<std::endl;

int NeTrocifreni[1000];

int *kraj=std::copy_if(Niz, Niz+size, NeTrocifreni, NijeTrocifren);


std::cout<<"Elementi koji nisu trocifreni su: ";
std::for_each(NeTrocifreni, kraj, Ispis);






	return 0;
}
