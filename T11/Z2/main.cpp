//TP 2022/2023: LV 11, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>



class StedniRacun{
    double stanje_racuna;
    static int br_kreiranih;
    static int br_aktivnih;
    public:
    StedniRacun(double x=0){
        if(x<0)throw std::logic_error("Nedozvoljeno pocetno stanje");
        stanje_racuna=x;
        br_aktivnih++;
        br_kreiranih++;
    }
    StedniRacun(const StedniRacun &s){
        stanje_racuna=s.stanje_racuna;
        br_kreiranih++;
        br_aktivnih++;
    }
    ~StedniRacun(){br_aktivnih--;}

    void Ulozi(double x){
        double temp=stanje_racuna+x;
        if(temp<0)throw std::logic_error("Transakcija odbijena");
        stanje_racuna=temp;
    }

    void Podigni(double x){
        if(x>stanje_racuna)throw std::logic_error("Transakcija odbijena");
        stanje_racuna-=x;
    }

    double DajStanje()const{return stanje_racuna;}

    void ObracunajKamatu(double x){
        if(x<0)throw std::logic_error("Nedozvoljena kamatna stopa");
        stanje_racuna+=stanje_racuna*(x/100);
    }

    static int DajBrojKreiranih(){return br_kreiranih;}
    static int DajBrojAktivnih(){return br_aktivnih;}


};

int StedniRacun::br_kreiranih=0;
int StedniRacun::br_aktivnih=0;

int main ()
{


	return 0;
}
