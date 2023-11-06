//TP 2022/2023: LV 10, Zadatak 2
#include <ios>
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <iomanip>

const double PI=4*atan(1);

class Krug{
    double r;

    public:
    explicit Krug(double x){
        if(x<=0)throw std::domain_error("Neispravan poluprecnik");
        r=x;
    }

    void Postavi(double x){
        if(x<=0)throw std::domain_error("Neispravan poluprecnik");
        r=x;
    }

    double DajPoluprecnik()const{return r;}
    double DajObim()const {return 2*r*PI;}
    double DajPovrsinu() const {return r*r*PI;}

    void Skaliraj(double x){
        if(x<=0)throw std::domain_error("Neispravan faktor skaliranja");
        r*=x;
    }

    void Ispisi()const{
        std::cout<<std::fixed<<std::setprecision(5)<<"R="<<DajPoluprecnik()<<" O="<<DajObim()<<" P="<<DajPovrsinu();
    }




};

class Valjak{
    Krug B;
    double H;

    public:
    explicit Valjak(double r, double h):B(r){
        if(h<=0)throw std::domain_error("Neispravna visina");
        H=h;
    }

    void Postavi(double r, double h){
        if(r<=0)throw std::domain_error("Neispravan poluprecnik");
        if(h<=0)throw std::domain_error("Neispravna visina");
        B.Postavi(r);
        H=h;
    }

    Krug DajBazu()const{return B;}
    double DajPoluprecnikBaze()const {return B.DajPoluprecnik();}
    double DajVisinu()const {return H;}
    double DajPovrsinu()const {return H*B.DajObim()+2*B.DajPovrsinu();}
    double DajZapreminu() const{return B.DajPovrsinu()*H;}
    
    void Skaliraj(double x){
        if(x<=0)throw std::domain_error("Neispravan faktor skaliranja");
        B.Skaliraj(x);
    }

    void Ispisi()const{
         std::cout<<std::fixed<<std::setprecision(5)<<"R="<<DajPoluprecnikBaze()<<" H="<<DajVisinu()<<" P="<<DajPovrsinu()<<" V="<<DajZapreminu();
    }



};


int main ()
{


	return 0;
}
