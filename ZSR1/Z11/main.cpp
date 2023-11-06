//TP 2022/2023: Skriveni Z 2, Zadatak 5
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

const double PI=4*std::atan(1);
class ApstraktnaKlasa{

};

class Kvadar:public ApstraktnaKlasa{
    double spec_tezina;
    double a,b,c;
    public:
    double DajSpecTezinu()const{
        return spec_tezina;
    }
    double DajZapreminu()const{
        return a*b*c;
    }

    double DajTezinu()const{
        return DajSpecTezinu()*DajZapreminu();
    }



};

class Lopta:public ApstraktnaKlasa{
    double spec_tezina;
    double poluprecnik;
    public:
    double DajSpecTezinu()const{
        return spec_tezina;
    }
    double DajZapreminu()const{
        return 4*poluprecnik*poluprecnik*poluprecnik*PI/3;
    }

    double DajTezinu()const{
        return DajZapreminu()*DajSpecTezinu();
    }

};

class Valjak:public ApstraktnaKlasa{
    double spec_tezina;
    double poluprecnik_baze;
    double visina;
    public:
    double DajSpecTezinu()const{
        return spec_tezina;
    }
    double DajZapreminu()const{
        return visina*poluprecnik_baze*poluprecnik_baze*PI;
    }

};

class Lik{
    std::vector<std::shared_ptr<ApstraktnaKlasa>> kolekcija;
    public:


};


int main ()
{


	return 0;
}
