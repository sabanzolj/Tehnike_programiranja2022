//TP 2022/2023: Zadaća 4, Zadatak 2
#include <cmath>
#include <iostream>
#include <math.h>
#include <new>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory>

const double E=0.0000000001;
const double PI=4*std::atan(1);

class NepreklapajuciKrug {
    std::pair<double,double> centar;
double R;
public:
  explicit NepreklapajuciKrug(double poluprecnik = 0);
  explicit NepreklapajuciKrug(const std::pair<double, double> &centar,
                double poluprecnik = 0);
  std::pair<double, double> DajCentar() const;
  double DajPoluprecnik() const;
  double DajObim() const;
  double DajPovrsinu() const;
  NepreklapajuciKrug &PostaviCentar(const std::pair<double, double> &centar);
  NepreklapajuciKrug &PostaviPoluprecnik(double poluprecnik);
  void Ispisi() const;
  NepreklapajuciKrug &Transliraj(double delta_x, double delta_y);
  NepreklapajuciKrug &Rotiraj(double alpha);
  NepreklapajuciKrug &Rotiraj(const std::pair<double, double> &centar_rotacije, double alpha);
  static double RastojanjeCentara(const NepreklapajuciKrug &k1, const NepreklapajuciKrug &k2){
    double X=k2.DajCentar().first-k1.DajCentar().first;
    double Y=k2.DajCentar().second-k1.DajCentar().second;

    double distance=std::sqrt(X*X+Y*Y);
    return distance;
};

  bool DaLiSadrzi(const NepreklapajuciKrug &k) const;
  friend NepreklapajuciKrug TransliraniKrug(const NepreklapajuciKrug &k, double delta_x, double delta_y);
  friend NepreklapajuciKrug RotiraniKrug(const NepreklapajuciKrug &k, double alpha);
  friend NepreklapajuciKrug RotiraniKrug(const NepreklapajuciKrug &k,
                           const std::pair<double, double> &centar_rotacije,
                           double alpha);
};

NepreklapajuciKrug::NepreklapajuciKrug(double r){
    if(r<0)throw std::domain_error("Nedozvoljen poluprecnik");
    centar.first=0;
    centar.second=0;
    R=r;

}

NepreklapajuciKrug::NepreklapajuciKrug(const std::pair<double,double> &centar_temp, double r){
    if(r<0)throw std::domain_error("Nedozvoljen poluprecnik");
    centar.first=centar_temp.first;
    centar.second=centar_temp.second;
    R=r;
}
std::pair<double,double> NepreklapajuciKrug::DajCentar()const{
 return centar;
}
double NepreklapajuciKrug::DajPoluprecnik()const{return R;}
double NepreklapajuciKrug::DajObim()const{return 2*R*PI;}
double NepreklapajuciKrug::DajPovrsinu()const{return R*R*PI;}

NepreklapajuciKrug &NepreklapajuciKrug::PostaviCentar(const std::pair<double, double> &centar_temp){
    centar.first=centar_temp.first;
    centar.second=centar_temp.second;
    return *this;
}

NepreklapajuciKrug &NepreklapajuciKrug::PostaviPoluprecnik(double poluprecnik){
    R=0;
    if(poluprecnik<0)throw std::domain_error("Nedozvoljen poluprecnik");
    R=poluprecnik;
    return *this;
}

void NepreklapajuciKrug::Ispisi()const{
    std::cout<<"{("<<centar.first<<","<<centar.second<<"),"<<R<<"}"<<std::endl;
}

NepreklapajuciKrug &NepreklapajuciKrug::Transliraj(double delta_x, double delta_y){
    centar.first+=delta_x;
    centar.second+=delta_y;
    return *this;
}

NepreklapajuciKrug &NepreklapajuciKrug::Rotiraj(double ugao){
    double x_temp=centar.first*std::cos(ugao)-centar.second*std::sin(ugao);
    double y_temp=centar.first*std::sin(ugao)+centar.second*std::cos(ugao);
    centar.first=x_temp;
    centar.second=y_temp;
    return *this;
}

NepreklapajuciKrug &NepreklapajuciKrug::Rotiraj(const std::pair<double,double> &centar_rotacije, double ugao){
    double x=centar.first-centar_rotacije.first;
    double y=centar.second-centar_rotacije.second;
    centar.first=x*std::cos(ugao)-y*std::sin(ugao)+centar_rotacije.first;
    centar.second=x*std::sin(ugao)+y*std::cos(ugao)+centar_rotacije.second;

    return *this;
}

 /*static double RastojanjeCentara(const Krug &k1, const Krug &k2){
    double X=k2.DajCentar().first-k1.DajCentar().first;
    double Y=k2.DajCentar().second-k1.DajCentar().second;

    double distance=std::sqrt(X*X+Y*Y);
    return distance;
}*/


/*static bool DaLiSuIdenticni(const Krug &k1, const Krug &k2){
bool X=fabs(k2.DajCentar().first-k1.DajCentar().first)<E;
bool Y=fabs(k2.DajCentar().second-k1.DajCentar().second)<E;
bool R=fabs(k2.DajPoluprecnik()-k1.DajPoluprecnik())<E;

return X && Y && R;
}*/

/*static bool DaLiSuPodudarni(const Krug &k1, const Krug &k2){
    return fabs(k2.DajPoluprecnik()-k1.DajPoluprecnik())<E;
}*/

/*static bool DaLiSuKoncentricni(const Krug &k1, const Krug &k2){
    return fabs(k2.DajCentar().first-k1.DajCentar().first)<E && fabs(k2.DajCentar().second-k1.DajCentar().second)<E;
}*/

/*static bool DaLiSeDodirujuIzvani(const Krug &k1, const Krug &k2){
    return fabs(RastojanjeCentara(k1, k2)-(k1.DajPoluprecnik()+k2.DajPoluprecnik()))<E;
}*/

/*static bool DaLiSeDodirujuIznutri(const Krug &k1, const Krug &k2){
    return fabs(RastojanjeCentara(k1,k2)-fabs(k2.DajPoluprecnik()-k1.DajPoluprecnik()))<E;
}*/

/*static bool DaLiSePreklapaju(const Krug &k1, const Krug &k2){
    return RastojanjeCentara(k1, k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik());
}*/

/*static bool DaLiSeSijeku(const Krug &k1,const Krug &k2){
    return std::sqrt(std::pow(k2.DajCentar().first-k1.DajCentar().first,2)+std::pow(k2.DajCentar().second-k1.DajCentar().second,2))<k1.DajPoluprecnik()+k2.DajPoluprecnik() && std::sqrt(std::pow(k2.DajCentar().first-k1.DajCentar().first,2)+std::pow(k2.DajCentar().second-k1.DajCentar().second,2))>k1.DajPoluprecnik()-k2.DajPoluprecnik();
}*/

bool NepreklapajuciKrug::DaLiSadrzi(const NepreklapajuciKrug &k)const{

    double X=k.centar.first-centar.first;
    double Y=k.centar.second-centar.second;

    double rastojanje=std::sqrt(X*X+Y*Y);

    if(rastojanje<fabs(R-k.R))return false;

    return true;
}

NepreklapajuciKrug TransliraniKrug(const NepreklapajuciKrug &k, double delta_x, double delta_y){
    NepreklapajuciKrug temp=k;
    return temp.Transliraj(delta_x,delta_y);
}

NepreklapajuciKrug RotiraniKrug(const NepreklapajuciKrug &k,double ugao){
    NepreklapajuciKrug temp=k;
    temp.Rotiraj(ugao);
    return temp;
}

NepreklapajuciKrug RotiraniKrug(const NepreklapajuciKrug &k, std::pair<double,double> &centar_rotacije, double ugao){
    NepreklapajuciKrug temp=k;
    temp.Rotiraj(centar_rotacije,ugao);
    return temp;
}


int main() {
    int n;
    try{
    std::cout<<"Unesite broj krugova: ";
    std::cin>>n;
    if(n<=0){
        std::cout<<"Uneseni broj nije prirodan!";
        return 0;
    }

    std::shared_ptr<NepreklapajuciKrug> *niz=new std::shared_ptr<NepreklapajuciKrug>[n];
    

    for(int i=0;i<n;i++){
        double x,y,r;
       try{
        std::cout<<"Unesite centar "<<i+1<<". kruga: ";
        std::cin>>x>>y;

        while(std::cin.fail()){
            std::cout<<"Neispravne koordinate centra! Pokusajte ponovo: "<<std::endl;
            std::cout<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesite centar "<<i+1<<". kruga: ";
            std::cin>>x>>y;
        }
         try{
        std::cout<<"Unesite poluprecnik "<<i+1<<". kruga: ";
        std::cin>>r;

        while(std::cin.fail() || r<0){
            std::cout<<"Neispravan poluprecnik! Pokusajte ponovo: "<<std::endl;
            std::cout<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            
            std::cout<<"Unesite centar "<<i+1<<". kruga: ";
        std::cin>>x>>y;

        while(std::cin.fail()){
            std::cout<<"Neispravne koordinate centra! Pokusajte ponovo: "<<std::endl;
            std::cout<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesite centar "<<i+1<<". kruga: ";
            std::cin>>x>>y;
        }

            std::cout<<"Unesite poluprecnik "<<i+1<<". kruga: ";
            std::cin>>r;
        }

        
        niz[i]=std::make_shared<NepreklapajuciKrug>();
        niz[i]->PostaviCentar({x,y});
        niz[i]->PostaviPoluprecnik(r);
    }catch(std::domain_error &e){
       std::cout<<e.what()<<std::endl;
       delete [] niz;
    }
       }
       catch(std::range_error &r){
           std::cout<<r.what()<<std::endl;
           delete [] niz;
       }
    }
    

    double delta_x, delta_y;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y): ";
    std::cin>>delta_x>>delta_y;

    std::cout<<"Unesite ugao rotacije oko tacke (0,0) u stepenima: ";
    double ugao;
    std::cin>>ugao;

    ugao=ugao*PI/180.0;

    std::transform(niz, niz+n, niz, [delta_x,delta_y,ugao](const std::shared_ptr<NepreklapajuciKrug> &krug){
        krug->Transliraj(delta_x,delta_y).Rotiraj(ugao);
        return std::move(krug);
    });


    std::sort(niz,niz+n,[](const std::shared_ptr<NepreklapajuciKrug> &k1, const std::shared_ptr<NepreklapajuciKrug> &k2){
        return k2->DajPovrsinu()>k1->DajPovrsinu();
    });

    
    std::cout<<"Parametri krugova nakon obavljene transformacije su: "<<std::endl;

    std::for_each(niz, niz+n, [](const std::shared_ptr<NepreklapajuciKrug> &krug){
        std::cout<<"{("<<krug->DajCentar().first<<","<<krug->DajCentar().second<<"),"<<krug->DajPoluprecnik()<<"}"<<std::endl;
    });

    auto obim_max=std::max_element(niz,niz+n,[](std::shared_ptr<NepreklapajuciKrug> &k1,std::shared_ptr<NepreklapajuciKrug> &k2){
        return k1->DajObim()<k2->DajObim();
    });

    std::cout<<"Krug sa najvecim obimom je: {("<<(*obim_max)->DajCentar().first<<","<<(*obim_max)->DajCentar().second<<"),"<<(*obim_max)->DajPoluprecnik()<<"}"<<std::endl;

    bool presjecaju=false;
    std::for_each(niz, niz+n, [niz,n,&presjecaju](const std::shared_ptr<NepreklapajuciKrug> k1){
        std::for_each(niz, niz+n, [niz,n,k1,&presjecaju](const std::shared_ptr<NepreklapajuciKrug> k2){
            if(k1>k2){
                std::cout<<"Presjecaju se krugovi: "<<std::endl;
                std::cout<<"{("<<k2->DajCentar().first<<","<<k2->DajCentar().second<<"),"<<k2->DajPoluprecnik()<<"} i {("<<k1->DajCentar().first<<","<<k1->DajCentar().second<<"),"<<k1->DajPoluprecnik()<<"}"<<std::endl;
                presjecaju=true;
                
            }
        });
    });

    if(!presjecaju)std::cout<<"Ne postoje krugovi koji se presjecaju!"<<std::endl;
    
    

    delete [] niz;
    }
    catch(std::bad_alloc){
        std::cout<<"Problemi sa alokacijom memorije!";
        return 0;
        
    }

return 0;
}