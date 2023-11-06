//TP 2022/2023: LV 13, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <cstring>

class ApstraktniStudent{
    protected:
    std::string ime_studenta;
    std::string prezime_studenta;
    int broj_indexa;
    int broj_polozenih_ispita;
    double prosjek;

public:
ApstraktniStudent(std::string ime,std::string prezime, int broj){
    ime_studenta=ime;
    prezime_studenta=prezime;
    broj_indexa=broj;
    broj_polozenih_ispita=0;
    prosjek=5;
}

std::string DajIme()const{
    return ime_studenta;
}

std::string DajPrezime()const{
    return prezime_studenta;
}

int DajBrojIndeksa()const{
    return broj_indexa;
}

int DajBrojPolozenih()const{
    return broj_polozenih_ispita;
}

double DajProsjek()const{
return prosjek;
}

void RegistrirajIspit(int ocjena){
if(ocjena<5 || ocjena>10)throw std::domain_error("Neispravna ocjena");
else if(ocjena==5)return;
else if(ocjena>5){
    double suma=prosjek*broj_polozenih_ispita;
    suma+=ocjena;
    broj_polozenih_ispita++;
    prosjek=suma/broj_polozenih_ispita;
}
}

void PonistiOcjene(){
    broj_polozenih_ispita=0;
    prosjek=5;
}

virtual void IspisiPodatke()const = 0;
virtual ApstraktniStudent *DajKopiju()const = 0;
virtual ~ApstraktniStudent(){};

};

class StudentBachelor:public ApstraktniStudent{
    public:
    StudentBachelor(std::string ime,std::string prezime,int br_indexa):ApstraktniStudent(ime, prezime, br_indexa){}

    void IspisiPodatke()const{
        std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
    }

    StudentBachelor *DajKopiju()const{
        return new StudentBachelor(*this);
    }


};

class StudentMaster:public ApstraktniStudent{
    int godina_zavrsetka;
  public:
    StudentMaster(std::string ime,std::string prezime,int br_indexa,int god):ApstraktniStudent(ime, prezime, br_indexa),godina_zavrsetka(god){}

    void IspisiPodatke()const{
        std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godina_zavrsetka<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
        }
    

    StudentMaster *DajKopiju()const{
        return new StudentMaster(*this);
    }

};


int main ()
{


	return 0;
}
