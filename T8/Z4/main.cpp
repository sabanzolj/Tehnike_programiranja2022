//TP 2022/2023: LV 8, Zadatak 4
#include <iostream>
#include <cmath>
#include <string>
#include <map>

std::string ZamijeniPremaRjecniku(std::string Recenica,std::map<std::string,std::string> Mapa){

    std::string rez;

    for(int i=0;i<Recenica.length();i++){
        if(Recenica[i]!=' '){
            std::string temp_rijec;

            while(Recenica[i]!=' ' && i!=Recenica.length()-1){
                temp_rijec.push_back(Recenica[i]);
                i++;
            }

            auto poz_rijeci=Mapa.find(temp_rijec);

            if(poz_rijeci!=Mapa.end()){
                for(auto it=poz_rijeci->second.begin();it!=poz_rijeci->second.end();it++){
                    rez.push_back(*it);
                }
            }
            else{
                for(auto it=temp_rijec.begin();it!=temp_rijec.end();it++){
                    rez.push_back(*it);
                }
            }

        }
        rez.push_back(Recenica[i]);
    }
    return rez;
}


int main(){


    return 0;
}