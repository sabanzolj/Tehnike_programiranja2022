// TP 2022/2023: LV 10, Zadatak 4
#include <cmath>
#include <iostream>


class Ugao {
public:
  Ugao(double radijani = 0);
  Ugao(int stepeni, int minute, int sekunde);
  void Postavi(double radijani);
  void Postavi(int stepeni, int minute, int sekunde);
  double DajRadijane() const;
  void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde);
  int DajStepene() const;
  int DajMinute() const;
  int DajSekunde() const;
  void Ispisi() const;
  void IspisiKlasicno() const;
  Ugao &SaberiSa(const Ugao &u);
  Ugao &PomnoziSa(double x);
  friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
  friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};

int main() { return 0; }
