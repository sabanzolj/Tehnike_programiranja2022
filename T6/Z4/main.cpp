//TP 2022/2023: LV 6, Zadatak 4
#include <iostream>
#include <cmath>
#include <new>

int **KreirajTrougao(int n){

    if(n<=0){
        throw std::domain_error("Broj redova mora biti pozitivan");
    }
    int **pok=nullptr;

    try {
    pok=new int*[n*(2*n+1)];
    for(int i=0;i<n;i++){
    pok[i]=new int[2*i+1];
    }
    } catch (std::bad_alloc) {
    throw std::bad_alloc();
    }
}




int main (){
    
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
