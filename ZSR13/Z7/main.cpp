//TP 2022/2023: ZSR 13, Zadatak 7
#include <iostream>
#include <cmath>
#include <ostream>
#include <string>
#include <stdexcept>
#include <algorithm>

class Knjiga{
    int id_knjige;
    int kolicina;
    std::string naziv_knjige,ime_pisca,zanr_knjige;
    int godina_izdanja;
    int id_citaoca;
    int broj_dana_na_citanju;
    public:
    Knjiga(int id_knjige,std::string naziv,std::string ime,std::string zanr,int godina){
        Knjiga::id_knjige=id_knjige;
        naziv_knjige=naziv;
        ime_pisca=ime;
        zanr_knjige=zanr;
        godina_izdanja=godina;
        id_citaoca=-1;
        broj_dana_na_citanju=-1;
    }

    int DajIDCitaoca()const{return id_citaoca;}
    int DajIDKnjige()const{return id_knjige;}
    std::string DajNazivKnjige()const{return naziv_knjige;}
    std::string DajImePisca()const{return ime_pisca;}
    std::string DajZanr()const{return zanr_knjige;}
    int DajGodinu()const{return godina_izdanja;}
    int BrojDana()const{return broj_dana_na_citanju;}

    void Zaduzi(int broj){
        id_citaoca=broj;
        broj_dana_na_citanju=0;
        
    }

    void Razduzi(){
        id_citaoca=0;
        broj_dana_na_citanju=-1;
    }

    bool operator !(){
        if(id_citaoca!=0)return true;
        else return false;
    }

    Knjiga& operator++() {
        if (id_citaoca != 0) {
            broj_dana_na_citanju++;
        }
        return *this;
    }

    Knjiga operator++(int) {
        Knjiga temp(*this);
        ++(*this);
        return temp;
    }

    friend bool operator ==(const Knjiga &k1,const Knjiga &k2){
        if(k1.DajNazivKnjige()==k2.DajNazivKnjige() && k1.ime_pisca==k2.ime_pisca && k1.zanr_knjige==k2.zanr_knjige && k1.godina_izdanja==k2.godina_izdanja)return true;
        else return false;
    }

    friend bool operator !=(const Knjiga &k1,const Knjiga &k2){
        return !(k1==k2);
    }

    virtual void Ispisi(std::ostream &ispis)const{
        ispis<<"Naziv knjige: "<<naziv_knjige<<' '<<"Ime pisca: "<<ime_pisca<<' '<<"Godina izdanja: "<<godina_izdanja<<std::endl;
        
    }

    friend std::ostream &operator <<(std::ostream &ispis,const Knjiga &k){
        k.Ispisi(ispis);
        return ispis;
    }


};

class Udzbenik:public Knjiga{
    std::string Predmet;
    public:
    std::string DajPredmet()const{return Predmet;}
    Udzbenik(int id,std::string naziv,std::string ime,std::string zanr,int godina,std::string p):Knjiga(id,naziv,ime,zanr,godina),Predmet(p){}
    void Ispisi(std::ostream &ispis)const override{
        Knjiga::Ispisi(ispis);
        ispis<<"Predmet: "<<Predmet<<std::endl;
    }



};

class Biblioteka{
 const int max_kapacitet;
 int br_knjiga;
 Knjiga **kolekcija;
 public:
 explicit Biblioteka(int size):max_kapacitet(size){
     kolekcija=new Knjiga*[size];
     br_knjiga=0;
 }

 ~Biblioteka(){
 for(int i=0;i<br_knjiga;i++){
     delete[] kolekcija[i];
 }
 delete [] kolekcija;
 }

 Biblioteka(const Biblioteka &b)=delete;
 Biblioteka &operator =(const Biblioteka &b)=delete;

 void DodajKnjigu(int id_knjige,std::string naziv,std::string ime,std::string zanr,int godina){
     if(br_knjiga==max_kapacitet)throw std::domain_error("Kapacitet biblioteke je popunjen");
     Knjiga novaKnjiga(id_knjige,naziv,ime,zanr,godina);
     kolekcija[br_knjiga++]=new Knjiga(novaKnjiga);
     
 }

 void DodajUdzbenik(int id,std::string naziv,std::string ime,std::string zanr,int godina,std::string p){
     if(br_knjiga==max_kapacitet)throw std::domain_error("Kapacitet biblioteke je popunjen");
     Udzbenik u(id,naziv,ime,zanr,godina,p);
     kolekcija[br_knjiga++]=new Knjiga(u);
 }

 void ZaduziKnjigu(int broj_knjige, int broj_citaoca){
     int indeks=-1;
 for(int i=0;i<br_knjiga;i++){
     if(kolekcija[i]->DajIDKnjige()==broj_knjige)indeks=i;
 }
 if(indeks==-1)throw std::domain_error("Knjiga sa ovim rednim brojem ne postoji");

 kolekcija[indeks]->Zaduzi(broj_citaoca);


 }

 void RazduziKnjigu(int broj_knjige){
     int indeks=-1;
 for(int i=0;i<br_knjiga;i++){
     if(kolekcija[i]->DajIDKnjige()==broj_knjige)indeks=i;
 }
 if(indeks==-1)throw std::domain_error("Knjiga sa ovim rednim brojem ne postoji");

 kolekcija[indeks]->Razduzi();

 }

 bool TestZaduzenosti(int broj_knjige){
     int indeks=-1;
 for(int i=0;i<br_knjiga;i++){
     if(kolekcija[i]->DajIDKnjige()==broj_knjige)indeks=i;
 }
 if(indeks==-1)throw std::domain_error("Knjiga sa ovim rednim brojem ne postoji");

 return !kolekcija[indeks];

 }

 int DajBrojCitaoca(int broj_knjige){
     int indeks=-1;
 for(int i=0;i<br_knjiga;i++){
     if(kolekcija[i]->DajIDKnjige()==broj_knjige)indeks=i;
 }
 if(indeks==-1)throw std::domain_error("Knjiga sa ovim rednim brojem ne postoji");

 return kolekcija[indeks]->DajIDCitaoca();

 }

 void SortirajKnjige(){
     std::sort(kolekcija,kolekcija+br_knjiga,[](const Knjiga *a,const Knjiga *b){
         if(!*a && !*b){
             return a->DajNazivKnjige()<b->DajNazivKnjige();
         }
         else if(!*a)return true;

         else if(!*b)return false;

         else{
             return a->BrojDana()>b->BrojDana()
         }
     })

 }
};


int main ()
{


	return 0;
}
