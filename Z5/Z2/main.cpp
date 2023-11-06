//TP 2022/2023: Zadaća 5, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

class Padavine{
    int max_padavine;
    std::vector<int> VektorPadavina;

    public:

    explicit Padavine(int max_kol){
        if(max_kol<0 || max_kol==0)throw std::range_error("Ilegalna maksimalna kolicina");
        VektorPadavina=std::vector<int>();
        max_padavine=max_kol;
    }

    void RegistrirajPadavine(int p);
    int DajBrojDanaSaPadavinamaVecimOd(int broj)const;
    int DajMaksimalnuKolicinuPadavina()const;
    int DajMinimalnuKolicinuPadavina()const;
    int DajBrojRegistriranihPadavina()const;
    void Ispisi()const;
    void BrisiSve();
    
    friend Padavine operator+(const Padavine &a, int broj);
    friend Padavine operator+(int broj, const Padavine &a);
    friend Padavine &operator+=(Padavine &a, int broj);
    friend Padavine &operator+=(int broj, Padavine &a);
    friend Padavine operator-(const Padavine &a, int broj);
    friend Padavine operator-(int broj, const Padavine &a);
    friend Padavine operator-(const Padavine &a, const Padavine &b);
    friend Padavine &operator-=(Padavine &a, int broj);
    friend Padavine &operator-=(int broj, Padavine &a);
    friend Padavine &operator-=(Padavine &a,Padavine &b);
    Padavine &operator++();
    Padavine operator++(int a);
    Padavine operator-();
    friend bool operator==(const Padavine &a,const Padavine &b);
    friend bool operator!=(const Padavine &a,const Padavine &b);
    int operator[](int a)const;

};

void Padavine::RegistrirajPadavine(int p){
    if(p>max_padavine || p<0)throw std::range_error("Ilegalna kolicina padavina");
    VektorPadavina.push_back(p);
}

int Padavine::DajBrojDanaSaPadavinamaVecimOd(int broj)const{
    if(VektorPadavina.size()==0)throw std::range_error("Nema registriranih padavina");

    int dani=0;

    for(int p:VektorPadavina){
        if(p>broj)dani++;
    }

    return dani;

}

int Padavine::DajMaksimalnuKolicinuPadavina()const{
    if(VektorPadavina.size()==0)throw std::range_error("Nema registriranih padavina");

    int max=VektorPadavina[0];
    for(int i=0;i<VektorPadavina.size();i++){
        if(VektorPadavina[i]>max)max=VektorPadavina[i];
    }

    return max;
}

int Padavine::DajMinimalnuKolicinuPadavina()const{
    if(VektorPadavina.size()==0)throw std::range_error("Nema registriranih padavina");

    int min=VektorPadavina[0];

    for(int i=0;i<VektorPadavina.size();i++){
        if(VektorPadavina[i]<min)min=VektorPadavina[i];
    }
    return min;
}

int Padavine::DajBrojRegistriranihPadavina()const{
    int broj_padavina=VektorPadavina.size();
    return broj_padavina;
}

void Padavine::Ispisi()const{
    Padavine temp(*this);

    std::sort(temp.VektorPadavina.begin(),temp.VektorPadavina.end(),std::bind(std::greater<int>(), std::placeholders::_1, std::placeholders::_2));

    for(int p:temp.VektorPadavina){
        std::cout<<p<<" ";
    }


}

void Padavine::BrisiSve(){
    VektorPadavina.resize(0);
}

Padavine operator+(const Padavine &a,int broj){
    Padavine rezultat=a;
    rezultat.max_padavine=rezultat.max_padavine+broj;

    std::transform(rezultat.VektorPadavina.begin(),rezultat.VektorPadavina.end(),rezultat.VektorPadavina.begin(),std::bind(std::plus<int>(), std::placeholders::_1,broj));

    return rezultat;
}

Padavine operator+(int broj, const Padavine &a){
    Padavine rezultat=a+broj;
    return rezultat;
}

Padavine &operator+=(Padavine &a,int broj){
    a=a+broj;
    return a;
}

Padavine &operator+=(int broj,Padavine &a){
    a=a+broj;
    return a;
}

Padavine operator-(const Padavine &a,int broj){
    Padavine rezultat=a;
    rezultat.max_padavine=rezultat.max_padavine-broj;

    if(rezultat.max_padavine==0 || rezultat.max_padavine<0)throw std::domain_error("Nekorektan rezultat operacije");

    if(std::any_of(a.VektorPadavina.begin(), a.VektorPadavina.end(), std::bind(std::less<int>(),std::placeholders::_1,broj)))throw std::domain_error("Nekorektan rezultat operacije");

    std::transform(rezultat.VektorPadavina.begin(),rezultat.VektorPadavina.end(),rezultat.VektorPadavina.begin(),std::bind(std::minus<int>(),std::placeholders::_1,broj));

    return rezultat;

}

Padavine operator-(int broj, const Padavine &a){

    Padavine rezultat=a;
    rezultat.max_padavine=broj;

    std::transform(rezultat.VektorPadavina.begin(),rezultat.VektorPadavina.end(),rezultat.VektorPadavina.begin(),std::bind(std::minus<int>(),broj,std::placeholders::_1));

    return rezultat;
}

Padavine operator-(const Padavine &a, const Padavine &b){
    int size1=a.VektorPadavina.size();
    int size2=b.VektorPadavina.size();

    if(size1!=size2)throw std::domain_error("Nesaglasni operandi");

    Padavine rezultat(a.max_padavine);

    rezultat.VektorPadavina.resize(size1);

    std::transform(a.VektorPadavina.begin(),a.VektorPadavina.end(),b.VektorPadavina.begin(),rezultat.VektorPadavina.begin(), std::bind(std::minus<int>(),std::placeholders::_1, std::placeholders::_2));

    if(std::any_of(rezultat.VektorPadavina.begin(),rezultat.VektorPadavina.end(),std::bind(std::less<int>(),std::placeholders::_1,0)))throw std::domain_error("Nekorektan rezultat operacije");

    return rezultat;
}

Padavine &operator-=(Padavine &a,int broj){
    a=a-broj;
    return a;
}

Padavine &operator-=(int broj,Padavine &a){
    a=a-broj;
    return a;
}


Padavine &operator-=(Padavine &a,Padavine &b){
    a=a-b;
    return a;

}

Padavine &Padavine::operator++(){
    max_padavine++;
    std::transform(VektorPadavina.begin(),VektorPadavina.end(),VektorPadavina.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));

    return *this;

}

Padavine Padavine::operator++(int a){
    max_padavine++;
    Padavine p=*this;
    ++(*this);
    return p;
}

Padavine Padavine::operator-(){
    std::transform(VektorPadavina.begin(),VektorPadavina.end(),VektorPadavina.begin(),std::bind(std::minus<int>(),max_padavine,std::placeholders::_1));

    return *this;
}

bool operator==(const Padavine &a,const Padavine &b){
    int size1=a.VektorPadavina.size();
    int size2=b.VektorPadavina.size();
    if(size1!=size2)return false;
    return a.VektorPadavina==b.VektorPadavina;
}

bool operator!=(const Padavine &a,const Padavine &b){
    bool temp=!(a==b);
    return temp;
}

int Padavine::operator[](int a)const{
    if(a>VektorPadavina.size() || a<1)throw std::range_error("Neispravan indeks");

    return VektorPadavina[a-1];
}






int main ()
{


	return 0;
}
