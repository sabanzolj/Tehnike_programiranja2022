//TP 2022/2023: Zadaća 5, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>

const double PI=4*atan(1);

class Sinusoida{
    double A;
    double f;
    double fi;
    static void TestParametara(double &amplituda, double &frekvencija, double &faza);

    public:

    Sinusoida(double amplituda, double frekvencija, double faza);
    double DajFrekvenciju()const{return f;}
    double DajAmplitudu()const{return A;}
    double DajFazu()const{return fi;}

    Sinusoida &PostaviFrekvenciju(double frekvencija);
    Sinusoida &PostaviAmplitudu(double amplituda);
    Sinusoida &PostaviFazu(double faza);

    friend Sinusoida operator+(const Sinusoida &a, const Sinusoida &b);
    Sinusoida operator-()const;
    friend Sinusoida operator-(const Sinusoida &a, const Sinusoida &b);
    friend Sinusoida &operator +=(Sinusoida &a,Sinusoida &b);//
    friend Sinusoida &operator-=(Sinusoida &a,Sinusoida &b);//
    friend Sinusoida operator*(const Sinusoida &a, double broj);
    friend Sinusoida operator*(double broj, const Sinusoida &a);//
    friend Sinusoida &operator*=(Sinusoida &a,double broj);
    friend Sinusoida operator/(const Sinusoida &a, double broj);
    friend Sinusoida &operator/=(Sinusoida &a, double broj);

    double operator()(double a);
    double operator[](std::string)const;
    double &operator[](std::string);

    std::tuple<double,double,double> DajParametre()const{
        std::tuple<double,double,double> temp={A,f,fi};
        return temp;
    }
    Sinusoida &PostaviParametre(std::tuple<double,double,double> P);

    

};

void Sinusoida::TestParametara(double &amplituda, double &frekvencija, double &faza){

   
   if(amplituda<0){
       faza=faza+PI;
       amplituda=std::fabs(amplituda);
       
   }

   if(frekvencija<0){
       frekvencija=std::fabs(frekvencija);
       faza*=(-1);
       faza=faza+PI;
   }

   while(faza<-PI){
       faza=faza+2*PI;
   }

   while(faza>PI){
      faza=faza-2*PI;
   }
}

Sinusoida::Sinusoida(double amplituda, double frekvencija, double faza){
    TestParametara(amplituda, frekvencija, faza);
    A=amplituda;
    f=frekvencija;
    fi=faza;
}

Sinusoida &Sinusoida::PostaviFrekvenciju(double frekvencija){
    TestParametara(A, frekvencija, fi);
    f=frekvencija;
    return *this;
}

Sinusoida &Sinusoida::PostaviAmplitudu(double amplituda){
    TestParametara(amplituda,f,fi);
    A=amplituda;
    return *this;
}

Sinusoida &Sinusoida::PostaviFazu(double faza){
    TestParametara(A, f, faza);
    fi=faza;
    return *this;

}

Sinusoida operator+(const Sinusoida &a, const Sinusoida &b){

    if(a.DajFrekvenciju()!=b.DajFrekvenciju())throw std::domain_error("Razlicite frekvencije");

    double Re=a.A*std::cos(a.fi)+b.A*std::cos(b.fi);
    double Im=a.A*std::sin(a.fi)+b.A*std::sin(b.fi);

    double amplituda=std::sqrt(Re*Re+Im*Im);
    double faza=std::atan2(Im,Re);

    Sinusoida temp={amplituda,a.f,faza};
    return temp;
}

Sinusoida Sinusoida::operator-()const{
    Sinusoida temp={-A,f,fi};
    return temp;
}

Sinusoida operator-(const Sinusoida &a, const Sinusoida &b){
    Sinusoida temp=a+b.operator-();
    return temp;
}

Sinusoida &operator+=(Sinusoida &a,Sinusoida &b){
    a=a+b;
    return a;
}

Sinusoida &operator-=(Sinusoida &a,Sinusoida &b){
    a=a-b;
    return a;
}

Sinusoida operator*(const Sinusoida &a, double broj){
    Sinusoida b=a;
    b.PostaviAmplitudu(b.DajAmplitudu()*broj);
    return b;
}

Sinusoida operator*(double broj,const Sinusoida &a){
    Sinusoida b=a*broj;
    return b;
}

Sinusoida &operator*=(Sinusoida &a, double broj){
    a=a*broj;
    return a;
}

Sinusoida operator/(const Sinusoida &a, double broj){
    Sinusoida b=a;
    b.PostaviAmplitudu(b.DajAmplitudu()/broj);
    return b;
}

Sinusoida &operator/=(Sinusoida &a,double broj){
    a=a/broj;
    return a;
}

double Sinusoida::operator()(double a){
    double temp=DajAmplitudu()*std::sin(DajFazu()+DajFrekvenciju()*a);
    return temp;
}

double Sinusoida::operator[](std::string P)const{
    if(P=="A"){
        return DajAmplitudu();
    }
    else if(P=="fi" || P=="phi"){
        return DajFazu();
    }
    else if(P=="omega" || P=="w"){
        return DajFrekvenciju();
    }
    else{
        throw std::domain_error("Neispravan naziv parametra");
    }
}

double &Sinusoida::operator[](std::string P){
    if(P=="A"){
        return A;
    }
    else if(P=="fi" || P=="phi"){
        return fi;
    }
    else if(P=="omega" || P=="w"){
        return f;
    }
    else{
        throw std::domain_error("Neispravan naziv parametara");
    }
}

Sinusoida &Sinusoida::PostaviParametre(std::tuple<double, double, double> P){
    double amplituda=std::get<0>(P);
    double frekvencija=std::get<1>(P);
    double faza=std::get<2>(P);

    TestParametara(amplituda, frekvencija, faza);

    A=amplituda;
    f=frekvencija;
    fi=faza;

    return *this;
}





int main ()
{


	return 0;
}
