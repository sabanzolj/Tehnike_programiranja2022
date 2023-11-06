// TP 2022/2023: LV 4, Zadatak 5
#include <cmath>
#include <iostream>
#include <vector>


template <typename NekiTip>

std::vector<NekiTip> Presjek(std::vector<NekiTip> v1, std::vector<NekiTip> v2) {

  std::vector<NekiTip> v3;

  int size1 = v1.size();
  int size2 = v2.size();
  bool Isti;

  for (int i = 0; i < size1; i++) {
    Isti = false;
    for (int j = 0; j < size2; j++) {
      if (v1[i] == v2[j]) {
        for (int z = 0; z < v3.size(); z++) {

          if (v1[i] == v3[z]) {
            Isti = true;
          }
        }
        if (Isti == false) {
          v3.push_back(v1[i]);
        }
      }
    }
  }

  return v3;
}

int main() {

  std::vector<int> v1;
  std::vector<int> v2;
  std::vector<int> v3;
  std::vector<std::string> v4;
  std::vector<std::string> v5;
  std::vector<std::string> v6;
  std::cout << "Test za realne brojeve..." << std::endl;
  std::cout << "Unesite broj elemenata prvog vektora: ";
  int br_1, br_2;
  std::cin >> br_1;
  std::cout << "Unesite elemente prvog vektora: ";
  for (int i = 0; i < br_1; i++) {
    int n;
    std::cin >> n;
    v1.push_back(n);
  }

  std::cout << "Unesite broj elemenata drugog vektora: ";
  std::cin >> br_2;
  std::cout << "Unesite elemente drugog vektora: ";
  for (int i = 0; i < br_2; i++) {
    int n;
    std::cin >> n;
    v2.push_back(n);
  }

  v3 = Presjek(v1, v2);
  std::cout << "Zajednicki elementi su: ";
  for (int i = 0; i < v3.size(); i++) {
    std::cout << v3[i] << " ";
  }

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Test za stringove..." << std::endl;

  std::cout << "Unesite broj elemenata prvog vektora: ";
  std::cin >> br_1;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
  for (int i = 0; i < br_1; i++) {
    std::string S;
    std::getline(std::cin, S);
    v4.push_back(S);
    // std::cin.clear();
    // std::cin.ignore(1000,'\n');
  }

  /*for(int i=0;i<v4.size();i++){
      std::cout<<v4.[i]<<std::endl;
  }*/

  std::cout << std::endl;

  std::cout << "Unesite broj elemenata drugog vektora: ";
  std::cin >> br_2;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
  for (int i = 0; i < br_2; i++) {
    std::string S;
    std::getline(std::cin, S);
    v5.push_back(S);
    // std::cin.clear();
    // std::cin.ignore(1000,'\n');
  }

  v6 = Presjek(v4, v5);
  std::cout << std::endl;
  std::cout << "Zajednicki elementi su: " << std::endl;
  for (int i = 0; i < v6.size(); i++) {
    std::cout << v6[i] << std::endl;
  }

  std::cout << std::endl;

  return 0;
}