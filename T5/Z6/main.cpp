//TP 2022/2023: LV 5, Zadatak 6
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int Suma(int a){
    if(a<10){
        return a;
    }

    return Suma(a/10)+a%10;
}

int NegativnaSuma(int a){
    if(a<0){
        a*=-1;
    }
    return Suma(a);
}



void Upis(int n){
    
}

bool Veci(int a, int b){

    int Sa=NegativnaSuma(a);
    int Sb=NegativnaSuma(b);

    if(Sa==Sb){
        return a<b;
    }
    else{
        return Sa<Sb;
    }
}

void Ispis(int n){
    std::cout<<n<<" ";
}


int main ()
{

    std::cout<<"Unesite broj elemenata: ";
    int n;
    int broj;
    std::cin>>n;
    std::cout<<"Unesite elemente: ";
    std::vector<int> Vektor;

    
    for(int i=0;i<n;i++){
        std::cin>>broj;
        Vektor.push_back(broj);
    }

    std::cout<<"Niz sortiran po sumi cifara glasi: ";

    std::sort(Vektor.begin(), Vektor.end(), Veci);

    std::for_each(Vektor.begin(), Vektor.end(), Ispis);

    std::cout<<"\nUnesite broj koji trazite: ";
    int trazeni_broj;
    std::cin>>trazeni_broj;
    std::vector<int>::iterator it;
    it=std::find(Vektor.begin(),Vektor.end(),trazeni_broj);

    if(it==Vektor.end()){
        std::cout<<"Trazeni broj ne nalazi se u nizu!";
    }
    else{
        int poz=Vektor.end()-it;
        poz=n-poz;
        std::cout<<"Trazeni broj nalazi se na poziciji "<<poz;
    }



	return 0;
}
