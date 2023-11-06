//TP 2022/2023: LV 5, Zadatak 2
#include <iostream>
#include <cmath>

template <typename Tip1, typename Tip2>
Tip2 RazmijeniBlokove(Tip1 a, Tip1 b, Tip2 c){
    while(a<b){
    auto Temp=*a;
    *a=*c;
    *c=Temp;
    a++;
    c++;
    }

 return c;
}


int main ()
{



	return 0;
}
