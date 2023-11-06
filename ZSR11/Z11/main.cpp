//TP 2022/2023: ZSR 11, Zadatak 11
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

class Zahtjev{
    std::string ime,prezime,tekst;
    int index,dan,mjesec,godina;
    public:
    Zahtjev(std::string ime,std::string prezime, std::string tekst, int index, int dan, int mjesec, int godina){
        int broj_dana[]={31,28,31,30,31,30,31,31,30,31,30,31};
         if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)broj_dana[1]++;
    if (godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])
      throw std::domain_error("Neispravan datum");

      this->dan=dan;this->mjesec=mjesec;this->godina=godina;
      this->ime=ime;
      this->prezime=prezime;
      this->index=index;
      this->tekst=tekst;

    }

    void Ispisi()const {
    std::cout << ime << " " << prezime << " " << tekst << " "
              << index << " " << dan << "/" << mjesec << "/" << godina << std::endl;
  }

};

class Zahtjevi{
    Zahtjev **kolekcija;
    const int max_br_zahtjeva;
    int br_zahtjeva;
    public:
    Zahtjevi(int max):max_br_zahtjeva(max),br_zahtjeva(0),kolekcija(new Zahtjev*[max]{}){}
    ~Zahtjevi(){
        for(int i=0;i<max_br_zahtjeva;i++){
            delete [] kolekcija[i];
        }
        delete[] kolekcija;
    }
    Zahtjevi(const Zahtjevi &z);
    Zahtjevi &operator =(Zahtjevi &&z);
    void Dodaj(std::string ime, std::string prezime, std::string tekst,
        int index, int dan, int mjesec, int godina);
  void IspisiObrisi();
  bool Test()const {if (br_zahtjeva)return true; return false;}

};

Zahtjevi::Zahtjevi(const Zahtjevi &z):max_br_zahtjeva(z.max_br_zahtjeva),br_zahtjeva(z.br_zahtjeva),kolekcija(new Zahtjev*[z.br_zahtjeva]{}){
    try{
        for(int i=0;i<br_zahtjeva;i++){
            kolekcija[i]=new Zahtjev(*z.kolekcija[i]);
        }

    }
    catch(...){
        for(int i=0;i<br_zahtjeva;i++){
            delete[] kolekcija[i];
        }
        delete[] kolekcija;
        throw;

    }

}

Zahtjevi &Zahtjevi::operator=(Zahtjevi &&z){
    if(this!=&z){
        delete[] kolekcija;
        kolekcija=z.kolekcija;
        z.kolekcija=nullptr;
        br_zahtjeva=z.br_zahtjeva;

    }
    return *this;
}




int main ()
{


	return 0;
}
