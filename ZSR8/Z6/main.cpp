//TP 2022/2023: Zadaća 3, Zadatak 6
#include <iostream>
#include <cmath>
#include <string>
#include <map>

std::string Funkcija(const std::string &Recenica,std::map<char,char> Mapa){

    std::string NovaRecenica;

    for(int i=0;i<Recenica.length();i++){
        char temp;
        temp=Recenica[i];
        auto it=Mapa.find(temp);

        if(it!=Mapa.end()){
            NovaRecenica.push_back(it->second);
        }
        else{
            NovaRecenica.push_back(temp);
        }
    }
    return NovaRecenica;
}




int main ()
{

std::string Recenica;

std::map<char,char> Mapa={
    {'a','x'},
    {'b','c'},
    {'c','a'}
};

std::cout<<"Unesite recenicu koju zelite sifrirati: ";
std::getline(std::cin,Recenica);
std::string SifriranaRecenica;
SifriranaRecenica=Funkcija(Recenica,Mapa);

std::cout<<"Sifrirana recenica glasi: ";
std::cout<<SifriranaRecenica;

	return 0;
}
