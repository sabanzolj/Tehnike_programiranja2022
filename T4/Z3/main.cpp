// TP 2022/2023: LV 4, Zadatak 3
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::string Transfer(std::string rijec){
    for(int i=0;i<rijec.length();i++){
        if(rijec[i]>=97 && rijec[i]<=122)rijec[i]=rijec[i]-32;
    }
    return rijec;
        }

void IzdvojiKrajnjeRijeci(std::vector<std::string> &Rijeci,std::string &prvi,std::string &drugi){
 if(Rijeci.size()==0){
     prvi="";
     drugi="";
 }
 else{
     prvi=Rijeci[0];
     drugi=Rijeci[0];

     for(int i=0;i<Rijeci.size();i++){
        if(Transfer(Rijeci[i])<Transfer(prvi))prvi=Rijeci[i];
        else if(Transfer(Rijeci[i])>Transfer(drugi))drugi=Rijeci[i];
     }
 }



}

void Ukloni(std::vector<std::string> temp,int indeks){
    for(int i=indeks;i<temp.size()-1;i++){
        temp[i]=temp[i+1];
    }
    temp.resize(temp.size()-1);

}

void ZadrziDuplikate(std::vector<std::string> &Recenica){
    if(Recenica.size()==0)return;

    for(int i=0;i<Recenica.size();i++){
        int brojac=1;
        for(int j=i+1;j<Recenica.size();j++){
            if(Recenica[i]==Recenica[j])brojac++;

        }
        if(brojac==1)Ukloni(Recenica, i);
    }
    

}



int main(){

    return 0;
}