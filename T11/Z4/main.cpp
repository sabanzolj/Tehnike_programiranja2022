//TP 2022/2023: LV 11, Zadatak 4
#include <initializer_list>
#include <ios>
#include <iostream>
#include <cmath>
#include <cstring>
#include <new>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
/*
class Tim{
    char ime_tima[20];
    int broj_odigranih;
    int broj_pobjeda;
    int broj_nerijesenih;
    int broj_poraza;
    int broj_datih;
    int broj_primljenih;
    int broj_poena;

    public:

    Tim(const char ime[]){
        int duzina=strlen(ime);
        if(duzina>20)throw std::range_error("Predugacko ime tima");
        strcpy(ime_tima, ime);
        broj_odigranih=0;
        broj_pobjeda=0;
        broj_nerijesenih=0;
        broj_poraza=0;
        broj_datih=0;
        broj_primljenih=0;
        broj_poena=0;
    }

    void ObradiUtakmicu(int br_datih, int br_primljenih){
        if(br_datih<0 || br_primljenih<0)throw std::range_error("Neispravan broj golova");
        broj_datih=br_datih;
        broj_primljenih=br_primljenih;
        broj_odigranih++;
        if(br_primljenih<br_datih){
            broj_poena+=3;
            broj_pobjeda++;
        }
        else if(br_primljenih>br_datih){
            broj_poraza++;
        }
        else if(br_datih==br_primljenih){
            broj_poena+=1;
            broj_nerijesenih++;
        }
        
    }

    const char *DajImeTima()const {return ime_tima;}

    int DajBrojPoena() const{return broj_poena;}
    int DajGolRazliku() const{return broj_datih-broj_primljenih;}

    void IspisiPodatke(){
        std::cout<<std::left<<std::setw(20)<<DajImeTima()<<std::right<<std::setw(4)<<broj_odigranih<<std::right<<std::setw(4)<<broj_pobjeda<<std::right<<std::setw(4)<<broj_nerijesenih<<std::right<<std::setw(4)<<broj_poraza<<std::right<<std::setw(4)<<broj_datih<<std::right<<std::setw(4)<<broj_primljenih<<std::right<<std::setw(4)<<broj_poena<<std::endl;
    }

};


int main ()
{


	return 0;
}

*/
//greskom zadatak 3 uradio ovde

class Tim{
    char ime_tima[20];
    int broj_odigranih;
    int broj_pobjeda;
    int broj_nerijesenih;
    int broj_poraza;
    int broj_datih;
    int broj_primljenih;
    int broj_poena;

    public:

    Tim(const char ime[]){
        int duzina=strlen(ime);
        if(duzina>20)throw std::range_error("Predugacko ime tima");
        strcpy(ime_tima, ime);
        broj_odigranih=0;
        broj_pobjeda=0;
        broj_nerijesenih=0;
        broj_poraza=0;
        broj_datih=0;
        broj_primljenih=0;
        broj_poena=0;
    }

    void ObradiUtakmicu(int br_datih, int br_primljenih){
        if(br_datih<0 || br_primljenih<0)throw std::range_error("Neispravan broj golova");
        broj_datih+=br_datih;
        broj_primljenih+=br_primljenih;
        broj_odigranih++;
        if(br_primljenih<br_datih){
            broj_poena+=3;
            broj_pobjeda++;
        }
        else if(br_primljenih>br_datih){
            broj_poraza++;
        }
        else if(br_datih==br_primljenih){
            broj_poena+=1;
            broj_nerijesenih++;
        }
        
    }

    const char *DajImeTima()const {return ime_tima;}

    int DajBrojPoena() const{return broj_poena;}
    int DajGolRazliku() const{return broj_datih-broj_primljenih;}

    void IspisiPodatke(){
        std::cout<<std::left<<std::setw(20)<<DajImeTima()<<std::right<<std::setw(4)<<broj_odigranih<<std::right<<std::setw(4)<<broj_pobjeda<<std::right<<std::setw(4)<<broj_nerijesenih<<std::right<<std::setw(4)<<broj_poraza<<std::right<<std::setw(4)<<broj_datih<<std::right<<std::setw(4)<<broj_primljenih<<std::right<<std::setw(4)<<broj_poena<<std::endl;
    }

};

class Liga{

    int broj_timova;
    const int max_broj_timova;
    Tim **timovi;

    void Obrisi(){
        if(timovi==nullptr)return;
        for(int i=0;i<broj_timova;i++){
            delete timovi[i];
            delete[] timovi;
        }
    }

    int Pronadji(const char *ime_tima) const{
        for(int i=0;i<broj_timova;i++){
            if(std::strcmp(ime_tima, timovi[i]->DajImeTima())==0)return i;
        }
        return -5;
    }

    void Alociraj(int broj){
        timovi=nullptr;

        try{
            timovi=new Tim*[broj];
        }
        catch(...){
            Obrisi();
            throw;
        }
    }


    

    public:

    explicit Liga(int size):max_broj_timova(size), broj_timova(0),timovi(nullptr){
        Alociraj(size);

    }

    explicit Liga(std::initializer_list<Tim> lista):broj_timova(lista.size()), max_broj_timova(lista.size()), timovi(nullptr){
        int br=0;

        try{
            timovi=new Tim*[broj_timova];
            for(int i=0;i<broj_timova;i++)timovi[i]=nullptr;
            for(auto &temp:lista)timovi[br++]=new Tim(temp);
        }
        catch(...){
            Obrisi();
            throw;
        }
    }

    ~Liga(){
        if(timovi==nullptr)return;

        for(int i=0;i<broj_timova;i++){
            delete timovi[i];
        }
        delete [] timovi;
    }

    Liga(const Liga &liga):max_broj_timova(liga.broj_timova), broj_timova(liga.broj_timova), timovi(nullptr){
       
       Alociraj(max_broj_timova);
       try{
           for(int i=0;i<broj_timova;i++){
               timovi[i]=new Tim(*liga.timovi[i]);
           }
       }
       catch(...){
           Obrisi();
           throw;
       }
    }

    Liga(Liga &&liga):max_broj_timova(liga.broj_timova), broj_timova(liga.broj_timova), timovi(nullptr){
        timovi=liga.timovi;
        liga.timovi=nullptr;
    }

    Liga &operator =(const Liga &liga){
        if(&liga==this)return *this;
        if(max_broj_timova!=liga.max_broj_timova)throw std::logic_error("Nesaglasni kapaciteti liga");
        for(int i=0;i<broj_timova;i++)delete timovi[i];
        broj_timova=liga.broj_timova;


        try{
            for(int i=0;i<broj_timova;i++)timovi[i]=new Tim(*liga.timovi[i]);
        }
        catch(...){
            Obrisi();
            throw;
        }
        return *this;
    }

    Liga &operator =(Liga &&liga){
        if(&liga==this)return *this;
        if(max_broj_timova!=liga.max_broj_timova)throw std::logic_error("Nesaglasni kapaciteti liga");
        timovi=liga.timovi;
        broj_timova=liga.broj_timova;
        liga.timovi=nullptr;
        return *this;
    }

    void DodajNoviTim(const char ime_tima[]){
        int duzina=strlen(ime_tima);
        if(duzina>=20)throw std::logic_error("Predugacko ime tima");
        if(Pronadji(ime_tima)!=-5)throw std::logic_error("Tim vec postoji");
        if(broj_timova==max_broj_timova)throw std::range_error("Liga popunjena");

        try{
            timovi[broj_timova++]=new Tim(ime_tima);
        }
        catch(std::bad_alloc){
            broj_timova--;
            throw std::logic_error("Neuspjesno dodavanje tima u ligu");
        }
        catch(...){
            broj_timova--;
            throw;
        }
    }

    void RegistrirajUtakmicu(const char ekipa1[], const char ekipa2[], int rez_1, int rez_2){
        if(Pronadji(ekipa1)==-5 || Pronadji(ekipa2)==-5)throw std::logic_error("Tim nije nadjen");
        timovi[Pronadji(ekipa1)]->ObradiUtakmicu(rez_1, rez_2);
        timovi[Pronadji(ekipa2)]->ObradiUtakmicu(rez_2, rez_1);
    }

    void IspisiTabelu(){
        std::sort(timovi, timovi+broj_timova, [](Tim *a, Tim *b){
            if(a->DajBrojPoena()==b->DajBrojPoena()){
                if(a->DajGolRazliku()==b->DajGolRazliku()){
                    return std::strcmp(a->DajImeTima(), b->DajImeTima())<0;
                }
                else{
                    return a->DajGolRazliku()>b->DajGolRazliku();
                }
            }
            else{
                return a->DajBrojPoena()>b->DajBrojPoena();
            }
        });

        for(int i=0;i<broj_timova;i++){
            timovi[i]->IspisiPodatke();
        }

        }
    


};

int main(){
    return 0;
}