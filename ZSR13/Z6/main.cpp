//TP 2022/2023: ZSR 13, Zadatak 6
#include <iostream>
#include <cmath>
#include <ostream>
#include <string>
#include <cstring>

const double PI=4*std::atan(1);

class ApstraktniLik{
    int brojac;
    std::string naziv;
    public:
    ApstraktniLik(std::string ime):brojac(1),naziv(ime){}
    int DajBrojac()const{return brojac;}
    std::string DajNaziv()const{return naziv;}
    virtual double DajObim()const=0;
    friend std::ostream  &operator <<(std::ostream &izlaz,ApstraktniLik &a){
        izlaz<<"Lik: ";
        izlaz<<a.DajNaziv();
        izlaz<<" Obim: ";
        izlaz<<a.DajObim();
        return izlaz;


    }

    friend bool operator <(const ApstraktniLik &a1, const ApstraktniLik &a2){
        return a1.DajObim()<a2.DajObim();
    }

    friend bool operator >(const ApstraktniLik &a1, const ApstraktniLik &a2){
        return a1.DajObim()>a2.DajObim();
    }

    ApstraktniLik &operator ++(){
        brojac++;
        return *this;
    }


};

class Krug:public ApstraktniLik{
    double poluprecnik;
    public:
    Krug(double r):poluprecnik(r),ApstraktniLik("Krug"){}
    double DajObim()const override{
        return 2*poluprecnik*PI;
    }


};

class Pravougaonik:public ApstraktniLik{
    double a,b;
    public:
    Pravougaonik(double A,double B):a(A),b(B),ApstraktniLik("Pravougaonik"){}
    double DajObim()const override{
        return 2*(a+b);
    }

};

class Trougao:public ApstraktniLik{
 double a,b,c;
 public:
 Trougao(double A, double B, double C):a(A),b(B),c(C),ApstraktniLik("Trougao"){}
 double DajObim()const override{
     return a+b+c;
 }

};

class Lik{
    ApstraktniLik **kolekcija;
    int max_kapacitet;
    int br_elemenata;
    int *pnb;
    template <typename tip>
    bool Test(tip l){
        if(l.br_elemenata==l.max_kapacitet)throw std::domain_error("Kapacitet je popunjen");
         for(int i=0;i<l.br_elemenata;i++){
             if(kolekcija[i]->DajObim()==l.DajObim()){++l;return false;}
         }
         return true;
    }
    public:
    explicit Lik(int max):max_kapacitet(max),br_elemenata(1),kolekcija(new ApstraktniLik*[max]{}){}
    Lik(const Lik &l){
        kolekcija=new ApstraktniLik*[l.max_kapacitet];
        for(int i=0;i<l.br_elemenata;i++){
            kolekcija[i]=l.kolekcija[i];
        }

        br_elemenata=l.br_elemenata;
        max_kapacitet=l.max_kapacitet;
        (*pnb)++;
    }

    ~Lik(){
        (*pnb)--;
        if((*pnb)==0){}
        for(int i=0;i<br_elemenata;i++){
            delete[] kolekcija[i];
        }
        delete[] kolekcija;
    }

    Lik &operator =(const Lik &l)=delete;

    void DodajKrug(double r){
        if(br_elemenata==max_kapacitet)throw std::domain_error("Kapacitet je popunjen");
        Krug *krug=new Krug(r);
        kolekcija[br_elemenata++]=krug;

    }

    void DodajPravougaonik(double a,double b){
        Pravougaonik *novi=new Pravougaonik(a,b);
        if(Test(novi))kolekcija[br_elemenata++]=novi;

    }

    void DodajTrougao(double a,double b,double c){
    Trougao *novi=new Trougao(a,b,c);
        Test(novi);
    kolekcija[br_elemenata++]=novi;
    }




};





int main ()
{

    


	return 0;
}
