//TP 2022/2023: LV 9, Zadatak 4
#include <iostream>
#include <cmath>
#include <stdexcept>

class Sat{
    int sati,minute,sekunde;
    public:
    static bool DaLiJeIspravno(int hh,int mm,int ss);
    void Postavi(int hh,int mm,int ss){
                   if(!DaLiJeIspravno(hh,mm,ss))throw std::domain_error("Neispravno vrijeme");
                   Sat::sati=hh;Sat::minute=mm;Sat:sekunde=ss;};
    void PostaviNormalizirano(int hh,int mm,int ss);
    Sat &Sljedeci(){sekunde++;PostaviNormalizirano(sati, minute, sekunde);return *this;};
    Sat &Prethodni(){sekunde--;PostaviNormalizirano(sati, minute, sekunde);return *this;};
    Sat &PomjeriZa(int pomak){sekunde+=pomak;PostaviNormalizirano(sati, minute, sekunde);return *this;};
    void Ispisi()const{std::cout<<(sati<10?"0":"")<<sati<<":"<<(minute<10?"0":"")<<minute<<":"<<(sekunde<10?"0":"")<<sekunde;};
    int DajSate()const{return sati;};
    int DajMinute()const{return minute;};
    int DajSekunde()const{return sekunde;};
    friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2){
             int temp1=s1.DajSate()*3600+s1.DajMinute()*60+s1.DajSekunde();
             int temp2=s2.DajSate()*3600+s2.DajMinute()*60+s2.DajSekunde();
             return temp1-temp2;
    };
    static int Razmak(const Sat &s1, const Sat &s2){
             int temp1=s1.DajSate()*3600+s1.DajMinute()*60+s1.DajSekunde();
             int temp2=s2.DajSate()*3600+s2.DajMinute()*60+s2.DajSekunde();
             return temp1-temp2;
    };




};

bool Sat::DaLiJeIspravno(int hh, int mm, int ss){
    bool T=true;
    if(hh>23 || hh<0 || mm>59 || mm<0 || ss>59 || ss<0)T=false;
    return T;
}

void Sat::PostaviNormalizirano(int hh, int mm, int ss){
    int sati,minute,sekunde;
    sati=hh;
    minute=mm;
    sekunde=ss;

    while(sekunde>59){
        sekunde-=60;
        minute++;
    }

    while(minute>59){
        minute-=60;
        sati++;
    }

    while(sati>23){
        sati-=24;
    }

    while(sekunde<0){
        sekunde+=60;
        minute--;
    }

    while(minute<0){
        minute+=60;
        sati--;
    }

    while(sati<0){
        sati+=24;
    }

    Sat::sati=sati;Sat::minute=minute;Sat::sekunde=sekunde;
}






int main(){

    return 0;
}