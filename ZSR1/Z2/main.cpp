//TP 2022/2023: Zadaća 2, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cstring>
#include <string>
#include <algorithm>

class ApstraktnoVozilo{
    protected:
    int tezina_vozila;
    public:
    ApstraktnoVozilo(int tezina):tezina_vozila(tezina){}
    virtual int DajTezinu()const{return tezina_vozila;}
    virtual int DajUkupnuTezinu()const=0;
    virtual void Ispisi()const=0;


};

class Automobil:public ApstraktnoVozilo{
std::vector<int> tezina_putnika;
int tezineputnika;
public:
Automobil(int T,std::vector<int> tezine):ApstraktnoVozilo(T),tezina_putnika(tezine){
    int zbir=0;
    for(int i=0;i<tezine.size();i++){
        zbir+=tezine[i];
    }
    tezineputnika=zbir;
}

int DajTezinu()const override{return tezina_vozila;}
int DajUkupnuTezinu()const override{return tezina_vozila+tezineputnika;}
void Ispisi()const override;

};

void Automobil::Ispisi()const{
    std::cout << "Vrsta vozila: Automobil" << std::endl
    << "Sopstvena tezina: " << tezina_vozila << " kg" << std::endl
    << "Tezine putnika: ";
    for(int i=0;i<tezina_putnika.size();++i) {
            std::cout << tezina_putnika.at(i) << " kg";
        if(i < tezina_putnika.size())
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    
    std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " kg";
}

class TeretnoVozilo:public ApstraktnoVozilo{
    int tezinatereta;
    public:
    TeretnoVozilo(int tezina_Vozila,int tezina_Tereta):ApstraktnoVozilo(tezina_Vozila),tezinatereta(tezina_Tereta){}
    int DajUkupnuTezinu()const override{return tezina_vozila+tezinatereta;}
    void Ispisi()const override{
         std::cout << "Vrsta vozila: Kamion" << std::endl
    << "Vlastita tezina: " << tezina_vozila << " kg" << std::endl
    << "Tezina tereta: " << tezinatereta << " kg" << std::endl
    << "Ukupna tezina: " << DajUkupnuTezinu() << " kg";
    }



};





int main ()
{

    std::vector<ApstraktnoVozilo*> vozila;

    std::cout<<"Koliko vozila zelite unijeti: ";
    int br;
    std::cin>>br;

    for(int i=0;i<br;i++){
        std::cout<<"Ako zelite unijeti putnicko vozilo pritisnite 1, a ako zelite unijeti teretno vozilo pritisnite 2.";
        int test=0;
        std::cin>>test;
        if(test==1){
            std::cout<<"Unesite tezinu vozila: ";
            int tezina_automobila;
            std::cin>>tezina_automobila;
            std::vector<int> putnici;
            std::cout<<"Koliko imate putnika? ";
            int br_putnika=0;
            std::cin>>br_putnika;
            std::cout<<"Unesite redom tezine putnika: ";
            for(int i=0;i<br_putnika;i++){
                int tezina;
                std::cin>>tezina;
                putnici.push_back(tezina);

            }
            Automobil *novi=new Automobil(tezina_automobila,putnici);
            vozila.push_back(novi);

        }
        else if(test==2){
            std::cout<<"Unesite tezinu kamiona:";
            int tezina_kamiona;
            std::cin>>tezina_kamiona;
            std::cout<<"Unesite tezinu tereta: ";
            int tezina_natovarenog;
            std::cin>>tezina_natovarenog;
            TeretnoVozilo *novi=new TeretnoVozilo(tezina_kamiona,tezina_natovarenog);
            vozila.push_back(novi);
        }
    }

     std::cout << "Ukupne tezine vozila nakon sortiranja " << std::endl;
        
        

     std::sort(vozila.begin(), vozila.end(), [](const ApstraktnoVozilo *v1, const ApstraktnoVozilo *v2) { return v1->DajUkupnuTezinu() < v2->DajUkupnuTezinu(); });

     for(int i=0;i<vozila.size();i++){
         vozila[i]->Ispisi();
         std::cout<<std::endl;
     }




	return 0;
}
