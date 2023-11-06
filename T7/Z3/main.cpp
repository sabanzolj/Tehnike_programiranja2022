//TP 2022/2023: LV 7, Zadatak 3
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

int main() {
    int br_recenica;
    std::string *recenice=nullptr;   
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
    recenice=new std::string[br_recenica]{};

    for(int i=0;i<br_recenica;i++){
        std::getline(std::cin, recenice[i]);
        
    }


    std::sort(recenice,recenice+br_recenica,[](const std::string &a, const std::string &b){return a<b;});

  }
  catch(...){
      std::cout<<"Problemi s memorijom!";
      delete [] recenice;

      return 0;
  }

    std::cout<<"Sortirane recenice: "<<std::endl;

    for(int i=0;i<br_recenica;i++){
        std::cout<<recenice[i]<<std::endl;
    }

   

    delete [] recenice;





	return 0;
}