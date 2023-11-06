//TP 2022/2023: ZSR 12, Zadatak 4
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <stdexcept>

class VektorNd{
    int br_elemenata;
    double *kolekcija;
    public:
    VektorNd(int dimenzija, double inicijalno){
        br_elemenata=dimenzija;
        kolekcija=new double[dimenzija]{};
        for(int i=0;i<dimenzija;i++){
        kolekcija[i]=inicijalno;
        }
    }

    VektorNd(int dimenzija, double niz[]){
        br_elemenata=dimenzija;
        kolekcija=new double[dimenzija];
        for(int i=0;i<dimenzija;i++){
            kolekcija[i]=niz[i];
        }
    }

     ~VektorNd(){delete[] kolekcija;}

     VektorNd(const VektorNd &v){
         br_elemenata=v.br_elemenata;
         kolekcija=new double[v.br_elemenata];
         std::copy(v.kolekcija,v.kolekcija+br_elemenata,kolekcija);
     }

     VektorNd &operator =(const VektorNd &&v){
         if(this!=&v){
        delete [] kolekcija;
        kolekcija=v.kolekcija;
        br_elemenata=v.br_elemenata;
        delete [] v.kolekcija;
         }
         return *this;

     }

     int DajDimenziju()const{return br_elemenata;}

     double &operator [](int i){
         if(i<1 || i>br_elemenata)throw std::domain_error("Nedozvoljena dimenzija");

         return kolekcija[i-1];
     }

     void PostaviKoordinatu(int index, double value){
         if(index<1 || index>br_elemenata)throw std::domain_error("Nedozvoljena dimenzija");
         kolekcija[index-1]=value;
     }

     double DajDuzinuVektora(){
         double suma=0;
         for(int i=0;i<br_elemenata;i++){
             suma+=kolekcija[i]*kolekcija[i];
         }

         return std::sqrt(suma);
     }

     friend double DuzinaVektora(const VektorNd &v){
         double suma=0;
         for(int i=0;i<v.br_elemenata;i++){
             suma+=v.kolekcija[i]*v.kolekcija[i];
         }
     }

     int Rang()const{
         int brojac=0;
         for(int i=0;i<br_elemenata;i++){
             if(kolekcija[i]!=0)brojac++;
         }
         return brojac;
     }

     void PostaviDimenzionalnost(int dimenzija){
        double *novi=new double[dimenzija]{};
        for(int i=0;i<br_elemenata;i++){
            novi[i]=kolekcija[i];
        }
        for(int i=br_elemenata;i<dimenzija;i++){
            novi[i]=0;
        }
        kolekcija=novi;
        delete[] novi;
     }

     friend std::ostream &operator <<(std::ostream &ispis,const VektorNd &v){
           ispis<<'{';
           for(int i=0;i<v.br_elemenata-1;i++){
               ispis<<v.kolekcija[i]<<',';
           }
           ispis<<v.kolekcija[v.br_elemenata-1]<<'}';
           return ispis;

     }

     friend VektorNd operator +(const VektorNd &v1,const VektorNd &v2){
         if(v1.br_elemenata!=v2.br_elemenata)throw std::domain_error("Nije moguce sabirati vektore razlicitih dimenzija");
         VektorNd novi=v1;
         for(int i=0;i<v1.br_elemenata;i++){
             novi.kolekcija[i]=v1.kolekcija[i]+v2.kolekcija[i];
         }
        return novi; 

     }

     friend VektorNd operator -(const VektorNd &v1,const VektorNd &v2){
         if(v1.br_elemenata!=v2.br_elemenata)throw std::domain_error("Nije moguce sabirati vektore razlicitih dimenzija");
         VektorNd novi=v1;
         for(int i=0;i<v1.br_elemenata;i++){
             novi.kolekcija[i]=v1.kolekcija[i]-v2.kolekcija[i];
         }
        return novi;

     }




     

};


int main(){
    VektorNd novi(5,1);
    std::cout<<novi;
    return 0;
}