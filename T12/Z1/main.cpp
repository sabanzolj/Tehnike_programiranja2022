//TP 2022/2023: LV 12, Zadatak 1
#include <iostream>
#include <cmath>
#include <ostream>
#include <stdexcept>


class Sat {

    int h, m, s;
    static const int D = 86400;

    public:
    Sat():h(0),m(0),s(0){};
    Sat(int hh, int mm, int ss){PostaviNormalizirano(hh, mm, ss);}
    static bool DaLiJeIspravno(int sati, int min, int sek){
        if(sati<0 || sati>23 || min<0 || min>59 || sek<0 || sek>59) return false;
        else return true;
    }
    
    void Postavi(int sati, int min, int sek){
        try{
        bool Ispravan = DaLiJeIspravno(sati, min, sek);
        if(Ispravan){
            h = sati;
            m = min; 
            s = sek;
        }else{
            throw std::domain_error("Neispravno vrijeme");
        }
    }catch(...){
        throw;
    }
    }
    
    void PostaviNormalizirano(int sati, int min, int sek){
        while(sek<0){
            sek+=60;
            min--;
        }
        while(min<0){
            min+=60;
            sati--;
        }
        while(sati<0){
            sati+=24;
        }
        while(sek>59){
            min++;
            sek-=60;
        }
        while(min>59){
            sati++;
            min-=60;
        }
        while(sati>23){
            sati-=24;
        }
        h=sati; m=min; s=sek;
    }

    Sat &operator ++(){s++; PostaviNormalizirano(h, m, s); return *this;};
    Sat operator ++(int){Sat novi(*this);++(*this);return novi;};
    Sat &operator --(){s--;PostaviNormalizirano(h, m, s); return *this;};
    Sat operator --(int){Sat novi(*this);--(*this);return novi;};

    Sat &operator +=(int pomak){s+=pomak;PostaviNormalizirano(h, m, s); return *this;};
    Sat &operator -=(int pomak){s-=pomak;PostaviNormalizirano(h, m, s); return *this;};

    friend std::ostream &operator <<(std::ostream &tok,const Sat &s1){
        tok.width(2);
        tok.fill('0');
        tok<<s1.DajSate()<<":";
        tok.width(2);
        tok.fill('0');
        tok<<s1.DajMinute()<<":";
        tok.width(2);
        tok.fill('0');
        return tok<<s1.DajSekunde();
    };

    friend int operator -(const Sat &v1,const Sat &v2){
        return int(v1.h*3600+v1.m*60+v1.s)-(v2.h*3600+v2.m*60+v2.s);
    }

    Sat operator +(int pomak);
    Sat operator -(int pomak);
    Sat operator +=(int pomak)const;
    Sat operator -=(int pomak)const;

    
    //Sat &Sljedeci(){s++; PostaviNormalizirano(h, m, s); return *this;};
    
    //Sat &Prethodni(){s--; PostaviNormalizirano(h, m, s); return *this;};
    
    /*Sat &PomjeriZa(int sek){
        s+=sek;
        PostaviNormalizirano(h, m, s);
        return *this;
    }*/
    
    void Ispisi() const{
        std::cout.fill('0');std::cout.width(2);std::cout<<h<<":";
        std::cout.fill('0');std::cout.width(2);std::cout<<m<<":";
        std::cout.fill('0');std::cout.width(2);std::cout<<s;
    }

    int DajSate() const { return h; };
    
    int DajMinute() const { return m; };
    
    int DajSekunde() const { return s; };
    
    //friend int BrojSekundiIzmedju(const Sat &v1, const Sat &v2);
    
    /*static int Razmak(Sat &v1, Sat &v2){
        return v1.s+60*v1.m+3600*v1.h-v2.s-60*v2.m-3600*v2.h;
    }*/
};

/*int BrojSekundiIzmedju(const Sat &v1, const Sat &v2){
    return v1.s+60*v1.m+3600*v1.h-v2.s-60*v2.m-3600*v2.h;
}*/

Sat Sat::operator +(int pomak){
    Sat novi(*this);
    novi+=pomak;
    return novi;
}

Sat Sat::operator +=(int pomak)const{
    Sat novi(*this);
    novi+=pomak;
    return novi;
}

Sat Sat::operator -(int pomak)
{
    Sat novi(*this);
    novi -= pomak;
    return novi;
}
Sat Sat::operator -=(int pomak) const
{
    Sat novi(*this);
    novi - pomak;
    return novi;

}

int main ()
{
	return 0;
}