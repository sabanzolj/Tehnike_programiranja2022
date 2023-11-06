// TP 2022/2023: LV 8, Zadatak 1
#include <cmath>
#include <iostream>
#include <stdexcept>

struct Vrijeme{
  int sati,minute,sekunde;
};

void TestirajVrijeme(const Vrijeme &t){
    if(t.sekunde<0 || t.sekunde>59 || t.minute<0 || t.minute>59 || t.sati<0 || t.sati>23){
        throw std::domain_error("Neispravno vrijeme");
    }
   
}

void IspisiVrijeme(const Vrijeme &t){
    try{
    TestirajVrijeme(t);
    std::cout<<(t.sati<10?"0":"")<<t.sati<<":"<<(t.minute<10?"0":"")<<t.minute<<":"<<(t.sekunde<10?"0":"")<<t.sekunde<<std::endl;
    }
    catch(std::domain_error greska){
        std::cout<<greska.what()<<std::endl;
    }
}

Vrijeme SaberiVrijeme(const Vrijeme &t1,const Vrijeme &t2){
    try{
        TestirajVrijeme(t1);
        TestirajVrijeme(t2);
        int ss,mm,hh;

        ss=t1.sekunde+t2.sekunde;
        mm=t1.minute+t2.minute+ss/60;
        hh=t1.sati+t2.sati+mm/60;

        Vrijeme t3;

        t3.sati=hh%24;
        t3.minute=mm%60;
        t3.sekunde=ss%60;

        return t3;

    }
   catch(std::domain_error greska){
    std::cout<<greska.what()<<std::endl;
}
}




int main(){

    try{
    std::cout<<"Unesite prvo vrijeme (h m s): ";
    Vrijeme t1;
    std::cin>>t1.sati>>t1.minute>>t1.sekunde;
    TestirajVrijeme(t1);
    std::cout<<"Unesite drugo vrijeme (h m s): ";
    Vrijeme t2;
    std::cin>>t2.sati>>t2.minute>>t2.sekunde;
    TestirajVrijeme(t2);

    std::cout<<"Prvo vrijeme: ";
    IspisiVrijeme(t1);
    std::cout<<"Drugo vrijeme: ";
    IspisiVrijeme(t2);
    std::cout<<"Zbir vremena: ";
    Vrijeme t3;
    t3=SaberiVrijeme(t1, t2);
    IspisiVrijeme(t3);
    }
    catch(std::domain_error greska){
        std::cout<<greska.what()<<std::endl;
    }



    return 0;
}