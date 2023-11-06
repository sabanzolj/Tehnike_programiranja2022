//TP 2022/2023: Skriveni Z 4, Zadatak 4
#include <iostream>
#include <cmath>

enum Pravci{Sjever, Istok, Jug, Zapad};
class Robot{
    int x,y;
    Pravci orijentacija;
    public:
    void Postavi(int x, int y, Pravci p){Robot::x=x;Robot::y=y;Robot::orijentacija=p;};
    void PomjeriSe(int korak);
    void OkreniSeNalijevo();
    void OkreniSeNadesno();
    int DajPozicijuX() const{return Robot::x;};
    int DajPozicijuY() const{return Robot::y;};
    Pravci DajOrijentaciju() const{return Robot::orijentacija;};
    void Ispisi() const{std::cout<<"Robot se nalazi na poziciji ("<<DajPozicijuX()<<","<<DajPozicijuY()<<") i  gleda na "<<DajOrijentaciju()<<".";};

};

void Robot::PomjeriSe(int korak){
    switch (Robot::orijentacija) {
    case Sjever:
    x+=korak;
    case Istok:
    y+=korak;
    case Jug:
    x-=korak;
    case Zapad:
    y-=korak;
    }
}

void Robot::OkreniSeNalijevo(){
    switch (Robot::orijentacija) {
    case Sjever:
    Robot::orijentacija=Zapad;
    case Istok:
    Robot::orijentacija=Sjever;
    case Jug:
    Robot::orijentacija=Istok;
    case Zapad:
    Robot::orijentacija=Jug;
    }
}

void Robot::OkreniSeNadesno(){
    switch (Robot::orijentacija) {
    case Sjever:
    Robot::orijentacija=Istok;
    case Istok:
    Robot::orijentacija=Jug;
    case Jug:
    Robot::orijentacija=Zapad;
    case Zapad:
    Robot::orijentacija=Sjever;
    }
    }





int main ()
{
  Robot r1;
  r1.Postavi(5, 2, Sjever);
  r1.Ispisi();



	return 0;
}
