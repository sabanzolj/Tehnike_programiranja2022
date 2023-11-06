//TP 2022/2023: LV 5, Zadatak 7
#include <iostream>
#include <cmath>

template <typename Tip>

auto SumaBloka(Tip start, Tip end)->decltype(*start+*start){

    

    if(start==end){
        throw std::range_error("Blok je prazan");
    }
    decltype(*start+*start) S=*start++;

    while(start<end){
        S+=*start;

        start++;
    }

    

    return S;
}


int main ()
{


	return 0;
}
