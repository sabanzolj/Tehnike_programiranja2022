//TP 2022/2023: LV 3, Zadatak 8
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stdexcept>

std::string IzdvojiRijec(std::string Recenica, int redniBroj){

    std::string Rijec;
    bool space=false;
    int broj_rijeci=0;

    for(char c:Recenica){
       
            if(c==' '){
                space=false;

            }
            else{
                if(!space){
                    broj_rijeci++;
                    space=true;
                }
            }

             if(broj_rijeci==redniBroj && c!=' '){
            Rijec=Rijec+c;
        }
        }

return Rijec;

}


int main ()
{
    int n;
    std::string S;
    int space=1;
    try{
        std::cout<<"Unesite redni broj rijeci: ";
        std::cin>>n;
        std::cout<<"Unesite recenicu: ";
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::getline(std::cin, S);

        int broj_rijeci=0;
        bool space=false;

        for(char c:S){
            if(c==' '){
                space=false;

            }
            else{
                if(!space){
                    broj_rijeci++;
                    space=true;
                }
            }
        }

       

       
        
        if(n<=0 || n>broj_rijeci){
            throw n;
        }

        std::string rijec=IzdvojiRijec(S, n);

        std::cout<<"Rijec na poziciji "<<n<<" je "<<rijec;


    }
    catch(...){
        std::cout<<"IZUZETAK: Pogresan redni broj rijeci!"<<std::endl;
    }


	return 0;
}
