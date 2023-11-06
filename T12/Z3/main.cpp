//TP 2022/2023: LV 12, Zadatak 3
#include <iostream>
#include <cmath>
#include <ostream>

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
std::string pok[]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};

std::ostream &operator <<(std::ostream &ispis, Dani d){
    ispis<<pok[d];
    return ispis;
}

Dani &operator ++(Dani &d){
    return d=Dani((int(d)+1)%7);

}

Dani &operator ++(Dani &d,int){
    Dani novi(d);
    ++d;
    return novi;
}

Dani operator +(Dani d,int n){
   return d=Dani((int(d)+n)%7);
}





int main ()
{


	return 0;
}
