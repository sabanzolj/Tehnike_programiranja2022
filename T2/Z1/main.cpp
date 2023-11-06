//TP 2022/2023: LV 2, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>



bool DaLiJeProst(int n){
    double Korjen=std::sqrt(n);
    bool Test=true;
    if(n<=1){
        Test=false;
        return Test;
    }
    
    for(int i=2;i<=Korjen;i++){

        if(n%i==0){
            Test=false;
        }
    }
    return Test;

}



std::vector<int> ProstiBrojeviUOpsegu(int a, int b){
    std::vector<int> Niz;
    for(int i=a;i<=b;i++){
        if(DaLiJeProst(i)){
            Niz.push_back(i);

        }
        if(i==b){
            break;
        }
    }

    return Niz;

}


int main ()
{
    int a,b;
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    std::cin>>a>>b;

    std::vector<int> Niz;

    Niz=ProstiBrojeviUOpsegu(a, b);

    int size=Niz.size();

    if(size==0){
        std::cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!";
        return 0;
    }
    
    std::cout<<"Prosti brojevi u rasponu od "<<a<<" do "<<b<<" su: ";
    

    for(int i=0;i<size;i++){
        if(i!=size-1){
        std::cout<<Niz[i]<<", ";
        }
        else{
            std::cout<<Niz[i]<<" ";
        }
        
    }

    std::cout<<std::endl;




	return 0;
}