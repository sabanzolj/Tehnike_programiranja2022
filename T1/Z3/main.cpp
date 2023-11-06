//TP 2016/2017: LV 1, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>

void Linija(){                                          //funkcija za ispisivanje linije
    for(int i=0;i<45;i++){
        if(i==0 || i==10 || i==21 || i==32 || i==44){
            std::cout<<"+";
        }
        else{
            std::cout<<"-";
        }
    }
    std::cout<<std::endl;

}

int main ()
{
    double a,b;

    do{
        std::cout<<"Unesite pocetnu i krajnju vrijednost: "<<std::endl;  //unos vrijednosti
        std::cin>>a;
        std::cin>>b;

    }while(a>b || a<0 || a>9999 || b<0 || b>9999);


    Linija();

    std::cout<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |"<<std::endl;    //zaglavlje

    Linija();

    for(int i=a;i<=b;i++){
        std::cout<<"| "<<std::left<<std::setw(8)<<i<<"|"<<std::right<<std::setw(9)<<i*i<<" |"<<std::right<<std::setw(9)<<std::fixed<<std::setprecision(3)<<std::sqrt(i)<<" |"<<std::right<<std::setw(10)<<std::setprecision(5)<<std::log(i)<<" |"<<std::endl;
    }



    Linija();
    

	return 0;
}