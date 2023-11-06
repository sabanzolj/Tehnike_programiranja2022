//TP 2022/2023: LV 5, Zadatak 4
#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>

/*void Ispis(int n){
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
}*/




int main ()
{


std::cout<<"Unesite broj elemenata: ";
int size;
std::cin>>size;
std::deque<int> Dek;
std::cout<<"Unesite elemente: ";
std::for_each(Dek.begin(), Dek.end(), [](int &n){std::cin>>n;});

std::cout<<"Najveci element deka je "<<*(std::max_element(Dek.begin(),Dek.end()))<<std::endl;

std::cout<<"Najmanji element deka se pojavljuje "<<std::count(Dek.begin(), Dek.end(), *(std::min_element(Dek.begin(), Dek.end())))<<" puta u nizu"<<std::endl;

std::cout<<"U deku ima "<<std::count_if(Dek.begin(), Dek.end(), [](int n){int test=std::sqrt(n); return std::pow(test,2)==n;})<<" brojeva koji su potpuni kvadrati"<<std::endl;

std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*(std::min_element(Dek.begin(),Dek.end(),[](int a, int b){return [](int a){if(a==0){return 1;}return (int) std::log10(std::abs(a))+1;}(a)<[](int a){if(a==0){return 1;}return (int)std::log10(std::abs(a))+1;}}))<<std::endl;

int NeTrocifreni[1000];

int *kraj=std::copy_if(Niz, Niz+size, NeTrocifreni, NijeTrocifren);


std::cout<<"Elementi koji nisu trocifreni su: ";
std::for_each(NeTrocifreni, kraj, Ispis);






	return 0;
}