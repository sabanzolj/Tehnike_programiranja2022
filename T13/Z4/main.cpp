//TP 2022/2023: LV 13, Zadatak 4
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

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

class Fakultet{
    std::vector<ApstraktniStudent*> vektor;
    bool Test(int index){
        for(int i=0;i<vektor.size();i++){
           if(vektor[i]->DajBrojIndeksa()==index)return false;
        }
        return true;
    }
    public:
    Fakultet(){};
    ~Fakultet(){
        for(int i=0;i<vektor.size();i++){
            delete vektor[i];
            vektor[i]=nullptr;
        }
    }

    Fakultet(const Fakultet &f):vektor(f.vektor){
        for(int i=0;i<vektor.size();i++){
            vektor[i]=f.vektor[i]->DajKopiju();
        }

    }

    Fakultet &operator =(const Fakultet &f){
        std::vector<ApstraktniStudent*> novi(f.vektor.size());
        try{
            for(int i=0;i<f.vektor.size();i++){
                novi[i]=f.vektor[i]->DajKopiju();
            }
        }
        catch(...){throw;}

        for(int i=0;i<vektor.size();i++){
        delete vektor[i];
        vektor[i]=nullptr;
        }
        vektor=novi;
        return *this;

    }

    Fakultet(Fakultet &&f):vektor(f.vektor.size()){
        for(int i=0;i<vektor.size();i++){
            delete vektor[i];
        }
        vektor.resize(f.vektor.size());
        try{
            for(int i=0;i<vektor.size();i++){
                vektor[i]=f.vektor[i]->DajKopiju();
            }
        }
        catch(...){throw;}

        for(int i=0;i<f.vektor.size();i++){
            delete f.vektor[i];
            f.vektor[i]=nullptr;
        }

        f.vektor.resize(0);

    }

    Fakultet &operator =(Fakultet &&f){
        for(int i=0;i<vektor.size();i++){
            delete vektor[i];
        }
        vektor.resize(f.vektor.size());
        try{
            for(int i=0;i<vektor.size();i++){
                vektor[i]=f.vektor[i]->DajKopiju();
            }
        }
        catch(...){throw;}

        for(int i=0;i<f.vektor.size();i++){
            delete f.vektor[i];
            f.vektor[i]=nullptr;
        }

        f.vektor.resize(0);

        return *this;

    }

    void UpisiStudenta(std::string ime,std::string prezime,int broj){
        if(!Test(broj))throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
        ApstraktniStudent *temp=new StudentBachelor(ime,prezime,broj);
        vektor.push_back(temp);
    }

    void UpisiStudenta(std::string ime,std::string prezime,int broj,int godina){
        if(!Test(broj))throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
        ApstraktniStudent *temp=new StudentMaster(ime,prezime,broj,godina);
        vektor.push_back(temp);
    }

    void ObrisiStudenta(int broj){
        if(Test(broj))throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
        int pozicija=0;
        for(int i=0;i<vektor.size();i++){
            if(vektor[i]->DajBrojIndeksa()==broj){
                pozicija=i;
                break;
            }
        }

        vektor.erase(vektor.begin(),vektor.begin()+pozicija+1);


    }

    const ApstraktniStudent &operator [](int indeks)const{

        bool temp(false);

        for(int i=0;i<vektor.size();i++){
            if(vektor[i]->DajBrojIndeksa()==indeks){temp=true;break;}
        }

        if(!temp)throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");

        for(int i=0;i<vektor.size();i++){
            if(vektor[i]->DajBrojIndeksa()==indeks)return *vektor[i];
        }

        return *vektor[0];

    }

    ApstraktniStudent &operator [](int indeks) {
		if(Test(indeks)) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
		for(int i=0; i < vektor.size(); i++){
			if(vektor[i]->DajBrojIndeksa() == indeks) return *vektor[i];
		}
		return *vektor[0];
	}

    void IspisiSveStudente() const {
		auto novi = vektor;
		std::sort(novi.begin(), novi.end(), [](ApstraktniStudent* pok1, ApstraktniStudent *pok2){
		if(pok1->DajProsjek() == pok2->DajProsjek()) return pok1->DajBrojIndeksa() < pok2->DajBrojIndeksa();
		return pok1->DajProsjek() > pok2->DajProsjek();
		});
		for(int i=0; i < novi.size(); i++){ novi[i]->IspisiPodatke(); }
	}

};


int main ()
{


	return 0;
}