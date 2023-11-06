//TP 2022/2023: LV 11, Zadatak 3
//greskom sam ovaj zadatak uradio u prostoru predvidjenom za zatadatak 4 pa sam ga kopirao ovde

#include <ios>
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <iomanip>

class Tim{
    char ime_tima[20];
    int broj_odigranih;
    int broj_pobjeda;
    int broj_nerijesenih;
    int broj_poraza;
    int broj_datih;
    int broj_primljenih;
    int broj_poena;

    public:

    Tim(const char ime[]){
        int duzina=strlen(ime);
        if(duzina>20)throw std::range_error("Predugacko ime tima");
        strcpy(ime_tima, ime);
        broj_odigranih=0;
        broj_pobjeda=0;
        broj_nerijesenih=0;
        broj_poraza=0;
        broj_datih=0;
        broj_primljenih=0;
        broj_poena=0;
    }

    void ObradiUtakmicu(int br_datih, int br_primljenih){
        if(br_datih<0 || br_primljenih<0)throw std::range_error("Neispravan broj golova");
        broj_datih+=br_datih;
        broj_primljenih+=br_primljenih;
        broj_odigranih++;
        if(br_primljenih<br_datih){
            broj_poena+=3;
            broj_pobjeda++;
        }
        else if(br_primljenih>br_datih){
            broj_poraza++;
        }
        else if(br_datih==br_primljenih){
            broj_poena+=1;
            broj_nerijesenih++;
        }
        
    }

    const char *DajImeTima()const {return ime_tima;}

    int DajBrojPoena() const{return broj_poena;}
    int DajGolRazliku() const{return broj_datih-broj_primljenih;}

    void IspisiPodatke(){
        std::cout<<std::left<<std::setw(20)<<DajImeTima()<<std::right<<std::setw(4)<<broj_odigranih<<std::right<<std::setw(4)<<broj_pobjeda<<std::right<<std::setw(4)<<broj_nerijesenih<<std::right<<std::setw(4)<<broj_poraza<<std::right<<std::setw(4)<<broj_datih<<std::right<<std::setw(4)<<broj_primljenih<<std::right<<std::setw(4)<<broj_poena<<std::endl;
    }

};


int main ()
{


	return 0;
}

