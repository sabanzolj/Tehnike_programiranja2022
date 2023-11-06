//TP 2022/2023: LV 2, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>

bool TestPerioda(std::vector<double> Niz, int p){
    if(p==0 || Niz.size()<=p){
        return false;
    }

    for(int i=0;i<Niz.size()-p;i++){
        if(Niz[i]!=Niz[i+p]){
            return false;
        }
    }
    
    return true;

}

int OdrediOsnovniPeriod(std::vector<double> Niz){
    for(int i=1;i<Niz.size();i++){
        if(TestPerioda(Niz, i)){
            return i;
        }
    }

    return 0;
}


int main ()
{
   std::vector<double> Niz;
   std::cout<<"Unesite slijed brojeva (0 za kraj): ";
   double broj;
   
   for(;;){
       std::cin>>broj;
       if(broj==0){
           break;
       }
       Niz.push_back(broj);
   }
   

   int period;
   period=OdrediOsnovniPeriod(Niz);

   if(period==0){
       std::cout<<"Slijed nije periodican!";
   }
   else if(period>0){
       std::cout<<"Slijed je periodican sa osnovnim periodom "<<period<<".";
   }

   
   

	return 0;
}
