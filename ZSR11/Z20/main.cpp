//TP 2022/2023: ZSR 11, Zadatak 20
#include <iostream>
#include <cmath>
#include <stdexcept>

class Poligon{
    double *x_kolekcija;
    double *y_kolekcija;
    int br_elemenata;
    public:
    explicit Poligon(int broj);
    ~Poligon();
    Poligon(const Poligon &p);
    Poligon &operator =(Poligon &&p);
    int DajBrojTjemena()const{return br_elemenata;}
    void PostaviKoordinate(int index,double x,double y);
    Tjeme operator[](int index);
    double DajPovrsinu(int index)const;
    bool Test(int index)const;

};

Poligon::Poligon(int broj){
    if(broj<3)throw std::domain_error("Pogresan broj tjemena");
    br_elemenata=broj;
    x_kolekcija=new double[broj]{};
    y_kolekcija=new double[broj]{};
}

Poligon::~Poligon(){
    delete x_kolekcija;
    delete y_kolekcija;
}

Poligon::Poligon(const Poligon &p){
    br_elemenata=p.br_elemenata;
    x_kolekcija=new double[br_elemenata];
    y_kolekcija=new double[br_elemenata];

    for(int i=0;i<br_elemenata;i++){
        x_kolekcija[i]=p.x_kolekcija[i];
        y_kolekcija[i]=p.y_kolekcija[i];
    }
}

Poligon &Poligon::operator=(Poligon &&p){
    delete x_kolekcija;
    delete y_kolekcija;

    x_kolekcija=p.x_kolekcija;
    p.x_kolekcija=nullptr;
    br_elemenata=p.br_elemenata;
    y_kolekcija=p.y_kolekcija;
    p.y_kolekcija=nullptr;

    return *this;

}




int main ()
{


	return 0;
}
