// TP 2022/2023: LV 6, Zadatak 2
#include <cmath>
#include <iostream>
#include <iterator>
#include <new>
#include <stdexcept>
#include <type_traits>
#include <vector>


template <typename Tip>
auto KreirajIzvrnutiNiz(Tip start, Tip end)-> decltype(&*start) {

  int size = std::distance(start, end);

try {
auto niz=new typename std::remove_reference<decltype(*start)>::type[size];
for(int i=size-1;i>=0;i--){
    auto temp=*start;
    niz[i]=temp;
    start++;

}
return niz;
} catch (std::bad_alloc) {
throw std::bad_alloc();
}

}

int main() {

  try{
  std::cout << "Koliko zelite elemenata: ";
  int n;
  std::cin >> n;
  std::vector<double> Vektor(n);
  std::cout<<"Unesite elemente: ";
  for(int i=0;i<n;i++){
      double temp;
      std::cin>>temp;
      Vektor.push_back(temp);

  }

  
  auto niz=KreirajIzvrnutiNiz(std::begin(Vektor), std::end(Vektor));

  std::cout<<"Kreirani niz: "<<std::endl;
  for(int i=0;i<n;i++){
      std::cout<<niz[i]<<" ";
  }
   delete [] niz;
  } catch (std::bad_alloc greska) {
  std::cout<<"Nedovoljno memorije!";
  return 0;
  }
  



  return 0;
}
