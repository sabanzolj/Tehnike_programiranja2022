//TP 2022/2023: Zadaća 4, Zadatak 3
#include <iostream>
#include <cmath>

class Polazak{

    public:
    Polazak(std::string odrediste, std::string oznaka_voznje, int broj_perona,
int sat_polaska, int minute_polaska, int trajanje_voznje);
void PostaviKasnjenje(int kasnjenje);
bool DaLiKasni() const;
int DajTrajanje() const;
void OcekivanoVrijemePolaska(int &sati, int &minute) const;
void OcekivanoVrijemeDolaska(int &sati, int &minute) const;
void Ispisi() const;
};

int main ()
{


	return 0;
}
