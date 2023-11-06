//TP 2016/2017: LV 1, Zadatak 4
#include <cctype>
#include <iostream>
#include <cmath>
int main ()
{
    double broj;
    double S;
    for(;;){
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        
        if(!(std::cin>>broj)){
             std::cout<<"Niste unijeli prirodan broj!"<<std::endl;
             std::cin.clear();
             std::cin.ignore(1000,'\n');
            continue;
        }
        if(broj<0 || (int(broj)==broj)==false ){
            std::cout<<"Niste unijeli prirodan broj!"<<std::endl;
            continue;
        }
        if(broj==0){
            std::cout<<"Dovidjenja!"<<std::endl;
            return 0;
        }

        
        S=0;
        for(int i=1;i<broj;i++){
            if(int(broj)%i==0){
                S=S+i;
            }
        }

        if(S>broj){
            std::cout<<"Broj "<<broj<<" je obilan!"<<std::endl;
        }
        else if(S<broj){
            std::cout<<"Broj "<<broj<<" je manjkav!"<<std::endl;
        }
        else if(S==broj){
            std::cout<<"Broj "<<broj<<" je savrsen!"<<std::endl;
        }
    }
	return 0;
}