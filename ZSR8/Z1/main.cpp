//TP 2022/2023: Zadaća 3, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

struct Roba{
std::string naziv_robe;
int broj_skladista;
int kolicina_robe_u_skladistu;
int min_kolicina;
double jedinicna_cijena_robe;
std::string ime_dobavljaca;
};


int main ()
{

std::vector<Roba> Inventura;

std::cout<<"Unesite broj stavki koji zelite unijeti: ";
int n;
std::cin>>n;
for(int i=0;i<n;i++){
    std::cout<<"\nUnesite podatke za "<<i+1<<". artikal: "<<std::endl;
    Roba artikal;
    std::cout<<"Unesite naziv robe: ";
    std::cin.ignore();
    std::getline(std::cin,artikal.naziv_robe);
    std::cout<<"Unesite broj skladista: ";
    std::cin>>artikal.broj_skladista;
    std::cout<<"Unesite kolicinu robe: ";
    std::cin>>artikal.kolicina_robe_u_skladistu;
    std::cout<<"Unesite minimalnu kolicinu robe: ";
    std::cin>>artikal.min_kolicina;
    std::cout<<"Unesite jedinicnu cijenu robe: ";
    std::cin>>artikal.jedinicna_cijena_robe;
    std::cin.ignore();
    std::cout<<"Unesite naziv dobavljaca: ";
    std::getline(std::cin,artikal.ime_dobavljaca);

    Inventura.push_back(artikal);

}

std::cout<<"\nIzvjestaj: "<<std::endl;
for(int i=0;i<n;i++){
    Roba temp=Inventura[i];

    if(temp.kolicina_robe_u_skladistu<temp.min_kolicina){
        std::cin.ignore();
        std::cout<<"Naziv robe: "<<temp.naziv_robe<<std::endl;
        std::cout<<"Broj skladista: "<<temp.broj_skladista<<std::endl;
        std::cout<<"Kolicina u skladistu: "<<temp.kolicina_robe_u_skladistu<<std::endl;
        std::cin.ignore();
        std::cout<<"Ime dobavljaca: "<<temp.ime_dobavljaca<<std::endl;
    }
}





	return 0;
}
