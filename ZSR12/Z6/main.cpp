//TP 2022/2023: ZSR 12, Zadatak 6
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>


class Polinom{
    std::vector<double> kolekcija;
    int stepen;
    public:
    explicit Polinom(int step):stepen(step),kolekcija(step+1){};
    double operator [](int index)const{
        if(index<0 || index>stepen)throw std::domain_error("Neispravan indeks");
        return kolekcija[index];
    }
    double &operator [](int index){
        if(index<0 || index>stepen)throw std::domain_error("Neispravan indeks");
        return kolekcija[index];
    }
    double operator ()(double x){
        double rez=0;
        for(int i=0;i<=stepen;i++){
            rez+=kolekcija[i]*std::pow(x,i);

        }
        return rez;
    }

    friend Polinom operator+(const Polinom &a, const Polinom &b);
  Polinom &operator+=(const Polinom &a);
  friend Polinom operator-(const Polinom &a, const Polinom &b);
  Polinom &operator-=(const Polinom &a);
  friend Polinom operator*(const Polinom &a, const Polinom &b);
  Polinom &operator*=(const Polinom &a);
  friend Polinom operator/(const Polinom &a, const Polinom &b);
  Polinom &operator/=(const Polinom &a);
  friend Polinom operator%(const Polinom &a, const Polinom &b);
  Polinom &operator%=(const Polinom &a);
  friend bool operator==(const Polinom &a, const Polinom &b);
  friend bool operator!=(const Polinom &a, const Polinom &b);
  friend Polinom operator-(Polinom a);
  friend std::ostream &operator<<(std::ostream &tok, const Polinom &a);




};

Polinom &Polinom::operator +=(const Polinom &a){
    if(a.stepen>stepen)kolekcija.resize(a.stepen);
    for(int i=0;i<=a.stepen;i++){
        kolekcija[i]+=a.kolekcija[i];
    }
    return *this;
}

Polinom operator -(Polinom a){
    for(int i=0;i<=a.stepen;i++){
        a.kolekcija[i]*=(-1);
    }
    return a;
}

Polinom &Polinom::operator-=(const Polinom &a){
    if(a.stepen>stepen)kolekcija.resize(a.stepen);
    for(int i=0;i<=a.stepen;i++){
        kolekcija[i]-=a.kolekcija[i];
    }
    return *this;
}

Polinom operator +(const Polinom &a,const Polinom &b){
    Polinom c(a.stepen);
    c.kolekcija=a.kolekcija;
    c+=b;
    return c;
}

Polinom operator -(const Polinom &a,const Polinom &b){
    Polinom c(a.stepen);
    c.kolekcija=a.kolekcija;
    c-=b;
    return c;
}




int main ()
{


	return 0;
}
