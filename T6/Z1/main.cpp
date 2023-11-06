// TP 2022/2023: LV 6, Zadatak 1
#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <new>
#include <stdexcept>

template <typename NekiTip>
NekiTip *GenerirajStepeneDvojke(int n){

        if(n<=0)throw std::domain_error("Broj elemenata mora biti pozitivan");

        NekiTip *pok=nullptr;

        try{
            pok=new NekiTip[n];

        }catch(...){
            throw std::runtime_error("Alokacija nije uspjela");
        }

        NekiTip temp=1;
        
        for(int i=0;i<n;i++){
            if(i!=n-1 && temp>=std::numeric_limits<NekiTip>::max()/2){
                delete[] pok;
                throw std::overflow_error("Prekoracen dozvoljeni opseg");
            }
            *(pok+i)=temp;
            temp*=2;
        }
    

 return pok;
}


int main(){

    std::cout<<"Koliko zelite elemenata: ";
    int n;
    std::cin>>n;
    unsigned long int *a=nullptr;

    try{
        a=GenerirajStepeneDvojke<unsigned long int>(n);
        for(int i=0;i<n;i++){
            std::cout<<*(a+i)<<" ";
        }
    }
    catch(std::exception &greska){
        std::cout<<"Izuzetak: "<<greska.what();
    }

    delete[] a;



    return 0;
}