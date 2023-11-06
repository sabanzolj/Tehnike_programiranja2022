//TP 2022/2023: ZSR 11, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>

class Temperature{
    double *temperature;
    const int max_br_elemenata;
    int br_elemenata;
    public:
    explicit Temperature(int max):max_br_elemenata(max),br_elemenata(0),temperature(new double[max]){}
    ~Temperature(){delete[] temperature;}
    Temperature(const Temperature &t):max_br_elemenata(t.max_br_elemenata),br_elemenata(t.br_elemenata),temperature(new double[t.br_elemenata]){
        for(int i=0;i<br_elemenata;i++){
            temperature[i]=t.temperature[i];
        }
    }
    Temperature &operator =(Temperature &&t){
        if(this!=&t){
            delete [] temperature;
            temperature=t.temperature;
            t.temperature=nullptr;
            br_elemenata=t.br_elemenata;



        }
        return *this;
    }

    void DodajTemperaturu(double temp){
        if(br_elemenata==max_br_elemenata)throw std::range_error("Dostignut je maksimalan broj temperatura");
        temperature[br_elemenata++]=temp;
    }

    void ObrisiSve(){
        delete [] temperature;
        temperature=nullptr;
        br_elemenata=0;
    }

    

    


};


int main ()
{


	return 0;
}
