//TP 2022/2023: LV 9, Zadatak 5
#include <iostream>
#include <cmath>
#include <stdexcept>

class Sat{
    int sekunde;

    public:
    static bool DaLiJeIspravno(int h, int m, int s){return !(h>23 || h<0 || m>59 || m<0 || s<0 || s>59);}

    void Postavi(int h, int m, int s){
        if(!DaLiJeIspravno(h, m, s))throw std::domain_error("Neispravno vrijeme");
        Sat::sekunde=h*3600; Sat::sekunde+=m*60; Sat::sekunde+=s;}

    void PostaviNormalizirano(int h, int m, int s){
        int sekunde=h*3600+m*60+s;
        int sekunde_temp=sekunde%86400;
        if(sekunde_temp<0)sekunde_temp+=86400;
        Sat::sekunde=sekunde_temp;
    }

    Sat &Sljedeci(){
        PomjeriZa(1);
        return *this;

    }

    Sat &Prethodni(){
        PomjeriZa(-1);
        return *this;
    }

    Sat &PomjeriZa(int pomak){
        
        Sat::sekunde+=pomak;
        PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde());
        return *this;
    }

    void Ispisi() const {
        std::cout<<(DajSate()<10?"0":"")<<DajSate()<<":"<<(DajMinute()<10?"0":"")<<DajMinute()<<":"<<(DajSekunde()<10?"0":"")<<DajSekunde();
        }

    int DajSate() const {return Sat::sekunde/3600;}
    int DajMinute() const {return (Sat::sekunde%3600)/60;}
    int DajSekunde() const {return (Sat::sekunde%3600)%60;}

    friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2);

    static int Razmak(const Sat &s1, const Sat &s2){
        return s1.sekunde-s2.sekunde;
    };

};

int BrojSekundiIzmedju(const Sat &s1, const Sat &s2){
    int razlika=s1.sekunde-s2.sekunde;
    return razlika;
}


int main ()
{


	return 0;
}
