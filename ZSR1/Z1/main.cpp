//TP 2022/2023: Zadaća 2, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cstring>
#include <string>

struct Datum{
    int dd,mm,gg;
    
};

class Zahtjev{
    protected:
std::string ime,prezime;
int broj_indexa;
std::string text_zahtjeva;
Datum datum_zahtjeva;
public:
Zahtjev(std::string IME,std::string PREZIME,int br_indexa,std::string tekst,Datum date):ime(IME),prezime(PREZIME),broj_indexa(br_indexa),text_zahtjeva(tekst){
    int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(date.gg%4==0)dani[1]++;
    if(date.gg<=0 || date.mm<1 || date.mm>12 || date.dd<1 || date.dd>dani[date.mm-1])throw std::domain_error("Neispravan datum");
    datum_zahtjeva.dd=date.dd;
    datum_zahtjeva.mm=date.mm;
    datum_zahtjeva.gg=date.gg;
}

std::string DajIme()const{return ime;}
std::string DajPrezime()const{return prezime;}
int DajBrojIndexa()const{return broj_indexa;}
std::string DajTekst()const{return text_zahtjeva;}

};

class Zahtjevi{
    Zahtjev **kolekcija;
    int max_kolekcija;
    int broj_elemenata; 
    public:
    Zahtjevi(int max_br_el):max_kolekcija(max_br_el),broj_elemenata(0){
        kolekcija=new Zahtjev*[max_br_el]{};
    }

    ~Zahtjevi(){
        for(int i=0;i<max_kolekcija;i++){
            delete[] kolekcija[i];
        }
        delete [] kolekcija;
    }

    Zahtjevi(const Zahtjevi &z){
        broj_elemenata=z.broj_elemenata;
        max_kolekcija=z.max_kolekcija;
        kolekcija=new Zahtjev*[z.max_kolekcija];
        for(int i=0;i<z.broj_elemenata;i++){
            kolekcija[i]=new Zahtjev(*z.kolekcija[i]);
        }

        

    }

    Zahtjevi &operator =(Zahtjevi &&z){
        for(int i=0;broj_elemenata;i++){
            delete[] kolekcija[i];
        }
        delete[] kolekcija;
        max_kolekcija=z.max_kolekcija;
        broj_elemenata=z.broj_elemenata;

        kolekcija=new Zahtjev*[max_kolekcija];

        for(int i=0;i<broj_elemenata;i++){
            kolekcija[i]=new Zahtjev(*z.kolekcija[i]);
        }

        for(int i=0;i<broj_elemenata;i++){
            delete[] z.kolekcija[i];
            z.kolekcija[i]=nullptr;
        }

        z.broj_elemenata=0;

        return *this;
    }

    void KreirajZahtjev(std::string IME,std::string PREZIME,int br_indexa,std::string tekst,Datum date){
        if(broj_elemenata==max_kolekcija)throw std::domain_error("Kolekcija je popunjena");
        kolekcija[broj_elemenata++]=new Zahtjev(IME,PREZIME,br_indexa,tekst,date);
        
    }

    bool TestKolekcije(){
        if(broj_elemenata==0)return true;
        return false;
    }

    void Izbrisi(){
         for(int i=0;i<broj_elemenata-1;i++){
             kolekcija[i]=kolekcija[i+1];
         }
         delete[] kolekcija[broj_elemenata-1];
         broj_elemenata--;
    }

    void Ispisi(){
        if(TestKolekcije())throw std::domain_error("Kolekcija je prazna");
        std::cout<<"Ime podnosioca zahtjeva: "<<kolekcija[0]->DajIme()<<std::endl;
        std::cout<<"Prezime podnosioca zahtjeva: "<<kolekcija[0]->DajPrezime()<<std::endl;
        std::cout<<"Broj indeksa: "<<kolekcija[0]->DajBrojIndexa()<<std::endl;
        std::cout<<"Tekst zahtjeva: "<<kolekcija[0]->DajTekst()<<std::endl;
        Izbrisi();
    }






};

int main(){

    std::cout<<"Koliko zelite podnijeti maksimalno zahtjeva: ";
    int max;
    std::cin>>max;
    int brojac=0;
    
    Zahtjevi kolekcija(max);
    try{
    for(int i=0;i<max;i++){
        std::cout<<"Unesite ime podnosioca zahtjeva: ";
        std::string IME;
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,IME);
        std::string PREZIME;
        std::cout<<"Unesite prezime: ";
        std::getline(std::cin,PREZIME);
        int br_indeksa;
        std::cout<<"Unesite broj indeksa: ";
        std::cin>>br_indeksa;
        std::string tekst;
        std::cout<<"Unesite tekst:";
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,tekst);
        int dan,mjesec,godina;
        std::cout<<"Unesite datum:";
        std::cin>>dan>>mjesec>>godina;
        Datum date;
        date.dd=dan;
        date.mm=mjesec;
        date.gg=godina;
        kolekcija.KreirajZahtjev(IME,PREZIME,br_indeksa,tekst,date);
        brojac++;
        std::cout<<"Ako ne zelite vise zahtjeva(unesite -1): ";
        int test=0;
        std::cin>>test;
        if(test==-1)break;



    }
    }
    catch(std::domain_error greska){
        std::cout<<greska.what();

    }

    for(int i=0;i<brojac;i++){
        kolekcija.Ispisi();
    }


    return 0;
}