//TP 2022/2023: LV 7, Zadatak 2
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>

int main() {
    int br_recenica;
    char **recenice=nullptr;
    
  std::cout << "Koliko zelite recenica: ";
  
  try{
  std::cin >> br_recenica;
  std::cin.ignore(1000, '\n');
  }
  catch(...){
      std::cout<<"Problemi s memorijom!";
      return 0;
  }
  
   try{
    std::cout<<"Unesite recenice: "<<std::endl;
    recenice=new char*[br_recenica]{};
    try{
    for(int i=0;i<br_recenica;i++){
        char temp[1000];
        std::cin.getline(temp, sizeof temp);
        recenice[i]=new char[std::strlen(temp)+1];
        std::strcpy(recenice[i],temp);
    }
    }
    catch(...){
        for(int i=0;i<br_recenica;i++){
            delete [] recenice[i];
        }
        delete [] recenice;
        throw;

    }

    std::sort(recenice,recenice+br_recenica,[](const char *a, const char *b){return std::strcmp(a,b)<0;});

  }
  catch(...){
      std::cout<<"Problemi s memorijom!";

      return 0;
  }

    std::cout<<"Sortirane recenice: "<<std::endl;

    for(int i=0;i<br_recenica;i++){
        std::cout<<recenice[i]<<std::endl;
    }

    for(int i=0;i<br_recenica;i++){
        delete[] recenice[i];
    }

    delete [] recenice;





	return 0;
}