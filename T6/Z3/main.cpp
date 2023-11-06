//TP 2022/2023: LV 6, Zadatak 3
#include <iostream>
#include <cmath>
#include <new>
#include <stdexcept>


int **KreirajTrougao(int n){

    if(n<=0){
        throw std::domain_error("Broj redova mora biti pozitivan");
    }
    int **pok=nullptr;
    try {
    pok=new int*[n]{};
    }
    catch(std::bad_alloc){
        throw std::bad_alloc();
    }

    try{
    for(int i=0;i<n;i++){
        pok[i]=new int[2*i+1];
    for(int j=0;j<=i;j++){
        pok[i][j]=i+1-j;
    }
    for(int j=i+1;j<2*i+1;j++){
        pok[i][j]=j-i+1;
    }
    }


    } catch (...) {
    for(int i=0;i<n;i++){
        delete [] pok[i];
    }
    delete [] pok;
    throw std::bad_alloc();
    }
    

  return pok;
}


int main ()
{
    std::cout<<"Koliko zelite redova: ";
    int n;
    std::cin>>n;

    int **matrica=nullptr;

    try {
    matrica=KreirajTrougao(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<2*i+1;j++){
            std::cout<<matrica[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    for(int i=0;i<n;i++){
        delete [] matrica[i];
    }
    delete [] matrica;
    } catch (std::domain_error &greska) {
    std::cout<<"Izuzetak: "<<greska.what()<<std::endl;
    }
    catch(std::bad_alloc){
        std::cout<<"Izuzetak: Nedovoljno memorije!"<<std::endl;
    }

    


	return 0;
}
