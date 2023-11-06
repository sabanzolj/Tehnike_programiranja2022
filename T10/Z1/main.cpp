//TP 2022/2023: LV 10, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>

class StedniRacun{
    double stanje_racuna;
    public:
    StedniRacun(double x=0){
        if(x<0)throw std::logic_error("Nedozvoljeno pocetno stanje");
        stanje_racuna=x;
    }

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


};


int main ()
{


	return 0;
}
