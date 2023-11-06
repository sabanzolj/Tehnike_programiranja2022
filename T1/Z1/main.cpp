//TP 2016/2017: LV 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int duzina, sirina, dubina, d_plocice;
    std::cout<<"Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin>>duzina;
    std::cin>>sirina;
    std::cin>>dubina;
    std::cout<<"Unesite sirinu plocice u centimetrima: "<<std::endl;
    std::cin>>d_plocice;
    int P=0;
    P=2*(sirina*dubina+duzina*dubina)+(duzina*sirina);
    //std::cout<<P;

    P=P*10000;

    if((sirina*100)%d_plocice!=0){
        std::cout<<"Poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d_plocice<<"x"<<d_plocice<<"cm\nnije izvodljivo bez lomljenja plocica!"<<std::endl;
        return 0;
    }
    else if((dubina*100)%d_plocice!=0){
        std::cout<<"Poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d_plocice<<"x"<<d_plocice<<"cm\nnije izvodljivo bez lomljenja plocica!"<<std::endl;
        return 0;
    }
    else if((dubina*100)%d_plocice!=0){
        std::cout<<"Poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d_plocice<<"x"<<d_plocice<<"cm\nnije izvodljivo bez lomljenja plocica!"<<std::endl;
        return 0;
    }

    

    if(P%(d_plocice*d_plocice)==0){
        std::cout<<"Za poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d_plocice<<"x"<<d_plocice<<"cm\npotrebno je "<<P/(d_plocice*d_plocice)<<" plocica."<<std::endl;
    }
    else{
        std::cout<<"Poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m sa plocicama dimenzija "<<d_plocice<<"x"<<d_plocice<<"cm\nnije izvodljivo bez lomljenja plocica!"<<std::endl;
    }

    
	return 0;
}