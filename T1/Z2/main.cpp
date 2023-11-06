//TP 2016/2017: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>


int main ()
{
    double a,b,c;
    std::cout<<"Unesite tri broja: ";   //unos brojeva
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;

    if(a+b<=c || a+c<=b || c+b<=a){
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!";   //ispitivanje da li postoji trougao
        return 0;
    }

    double O, P, min_angle, S;

    O=a+b+c;

    S=O/2;

    P=std::sqrt(S*(S-a)*(S-b)*(S-c));

    double pi=std::atan(1)*4;

    double alfa, beta, gama;

    alfa=std::acos((b*b+c*c-a*a)/(2*b*c));   //izracunavanje svih uglova
    beta=std::acos((c*c+a*a-b*b)/(2*c*a));
    gama=std::acos((a*a+b*b-c*c)/(2*a*b));

    min_angle=alfa;
    if(beta<min_angle){
        min_angle=beta;
    }
    else if(gama<min_angle){
        min_angle=gama;
    }

    min_angle=(min_angle*180)/pi; //pronalazenje najmanjeg ugla i pretvaranje iz radijana u stepene

    int stepen, minuta, sekunda;

    stepen=static_cast<int>(min_angle);
    min_angle=min_angle-stepen;
    min_angle=min_angle*60;
    minuta=static_cast<int>(min_angle);
    min_angle=min_angle-minuta;
    min_angle=min_angle*60;
    sekunda=static_cast<int>(min_angle);

  
    std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi "<<O<<"."<<std::endl;
    std::cout<<"Njegova povrsina iznosi "<<P<<"."<<std::endl;
    std::cout<<"Njegov najmanji ugao ima "<<stepen<<" stepeni, "<<minuta<<" minuta i "<<sekunda<<" sekundi."<<std::endl;

    
	return 0;
}