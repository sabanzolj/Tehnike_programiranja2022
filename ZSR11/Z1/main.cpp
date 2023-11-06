//TP 2022/2023: ZSR 11, Zadatak 1
#include <iostream>
#include <cmath>
#include <new>
#include <algorithm>

class  Temperature{
    double *niz_temperatura;
    const int max_br_elemenata;
    int br_elemenata;
    void AlocirajNiz(int br){
        niz_temperatura=nullptr;
        try{
            niz_temperatura=new double[br];

        }
        catch(...){
            delete[] niz_temperatura;
            throw;
        }
    }

    
    public:
    explicit Temperature(int t):max_br_elemenata(t),br_elemenata(0){
        AlocirajNiz(t);
    };
    ~Temperature(){delete[] niz_temperatura;};
    Temperature(const Temperature &t):max_br_elemenata(t.max_br_elemenata),br_elemenata(t.br_elemenata){
        try{
            AlocirajNiz(max_br_elemenata);
        }
        catch(...){
            delete[] niz_temperatura;
            throw;
        }

        std::copy(t.niz_temperatura,t.niz_temperatura+br_elemenata,niz_temperatura);
    };
    Temperature &operator=(Temperature &&t){
        if(this!=&t){
            delete[] niz_temperatura;
            niz_temperatura=t.niz_temperatura;
            t.niz_temperatura=nullptr;
            br_elemenata=t.br_elemenata;
        }
        return *this;

    };
    void DodajTemperaturu(double t){
        if(br_elemenata==max_br_elemenata)throw std::range_error("Unesen je maksimalan broj temperatura");
        niz_temperatura[br_elemenata++]=t;
    };
    void ObrisiSve(){
        niz_temperatura=nullptr;
        br_elemenata=0;
    };
    double DajProsjecnu()const{
        int br=1;
        int Suma=0;
        for(br=1;br<=br_elemenata;br++){
            Suma+=niz_temperatura[br];

        }

        return Suma/br;
    };
    double DajMaksimalnu()const{
        double max=niz_temperatura[0];
        for(int i=0;i<br_elemenata;i++){
            if(niz_temperatura[i]>max)max=niz_temperatura[i];
        }
        return max;
    };
    double DajMinimalnu()const{
        double min=niz_temperatura[0];
        for(int i=0;i<br_elemenata;i++){
            if(niz_temperatura[i]<min)min=niz_temperatura[i];
        }
        return min;
    };;
    void Ispisi()const{
  for (int i = 0; i < br_elemenata; i++)
    std::cout << niz_temperatura[i] << " ";
};






};


int main ()
{
    Temperature t(4);
  t.DodajTemperaturu(1); t.DodajTemperaturu(2); t.DodajTemperaturu(3);
  std::cout << t.DajMaksimalnu() << " " << t.DajMinimalnu() << " " << t.DajProsjecnu() << "\n";
  t.ObrisiSve();
  t.Ispisi();


	return 0;
}
