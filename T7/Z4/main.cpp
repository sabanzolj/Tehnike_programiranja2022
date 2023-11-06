//TP 2022/2023: LV 7, Zadatak 4
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

int main() {
    int br_recenica;
    std::unique_ptr<std::shared_ptr<std::string>[]> recenice=nullptr;   
  std::cout << "Koliko zelite recenica: ";
  
  try{
  std::cin >> br_recenica;
  std::cin.ignore(1000, '\n');
  }
  catch(...){
      std::cout<<"Problemi s memorijom!";
      return 0;
  }
  
   
    std::cout<<"Unesite recenice: "<<std::endl;
    try{
    recenice=std::make_unique<std::shared_ptr<std::string>[]>(br_recenica);
    }
    catch(...){
        std::cout<<"Problemi s memorijom!";
        return 0;
    }
    
    try{
    
    for(int i=0;i<br_recenica;i++){
        std::string temp;
        std::getline(std::cin, temp);
        recenice[i]=std::make_shared<std::string>(temp);
        
    }
    }
    catch(...){
        std::cout<<"Problemi s memorijom!";
        for(int i=0;i<br_recenica;i++){
            recenice[i].reset();
        }
        return 0;
    }
    
    


    std::sort(recenice.get(),recenice.get()+br_recenica,[](const std::shared_ptr<std::string> &a, const std::shared_ptr<std::string> &b){return *a<*b;});

  
  

    std::cout<<"Sortirane recenice: "<<std::endl;

    for(int i=0;i<br_recenica;i++){
        std::cout<<*recenice[i]<<std::endl;
    }

   

    





	return 0;
}