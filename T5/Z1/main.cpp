//TP 2022/2023: ===TITLE===
#include <iostream>
#include <cmath>


int main ()
{

    std::cout<<"Unesite recenicu: ";
    char Recenica[1000];

    std::cin.getline(Recenica,sizeof(Recenica));

    char *pok=Recenica;

    while(*pok!='\0' && *pok==' '){
        pok++;
    }
    while(*pok!='\0' && *pok!=' '){
        pok++;
    }
    while(*pok!='\0' && *pok==' '){
        pok++;
    }

    std::cout<<"Recenica bez prve rijeci glasi: ";
    while(*pok!='\0'){
        std::cout<<*pok++;

    }
    std::cout<<std::endl;


	return 0;
}
