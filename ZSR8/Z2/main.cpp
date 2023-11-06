// TP 2022/2023: Zadaća 3, Zadatak 2
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

const int BrojPredmeta = 8;
struct Datum {
  int dan, mjesec, godina;
};
struct Ucenik {
  std::string ime, prezime;
  Datum datum_rodjenja;
  int ocjene[BrojPredmeta];
  double prosjek;
  bool prolaz;
};
int main() {
  void UnesiUcenike(std::vector<Ucenik> & ucenici);
  void ObradiUcenike(std::vector<Ucenik> & ucenici);
  void IspisiIzvjestaj(const std::vector<Ucenik> &ucenici);
  int broj_ucenika;
  std::cout << "Koliko ima učenika: ";
  std::cin >> broj_ucenika;
  try {
    std::vector<Ucenik> ucenici(broj_ucenika);
    UnesiUcenike(ucenici);
    ObradiUcenike(ucenici);
    IspisiIzvjestaj(ucenici);
  } catch (...) {
    std::cout << "Problemi sa memorijom...\n";
  }
  return 0;
}
void UnesiUcenike(std::vector<Ucenik> &ucenici) {
  void UnesiJednogUcenika(Ucenik & ucenik);
  for (int i = 0; i < ucenici.size(); i++) {
    std::cout << "Unesite podatke za " << i + 1 << ". učenika:\n";
    UnesiJednogUcenika(ucenici[i]);
  }
}
void UnesiJednogUcenika(Ucenik &ucenik) {
  void UnesiDatum(Datum & datum);
  void UnesiOcjene(int ocjene[], int broj_predmeta);
  std::cout << " Ime: ";
  std::cin >> ucenik.ime;
  std::cout << " Prezime: ";
  std::cin >> ucenik.prezime;
  std::cout << " Datum rođenja (D/M/G): ";
  UnesiDatum(ucenik.datum_rodjenja);
  UnesiOcjene(ucenik.ocjene, BrojPredmeta);
}
void UnesiDatum(Datum &datum) {
  char znak;
  std::cin >> datum.dan >> znak >> datum.mjesec >> znak >> datum.godina;
}
void UnesiOcjene(int ocjene[], int broj_predmeta) {
  void UnesiOcjenu(int &ocjena);
  for (int i = 0; i < broj_predmeta; i++) {
    std::cout << " Ocjena iz " << i + 1 << ". predmeta: ";
    UnesiOcjenu(ocjene[i]);
  }
}

void UnesiOcjenu(int &ocjena) { std::cin >> ocjena; }
void ObradiUcenike(std::vector<Ucenik> &ucenici) {
  void ObradiJednogUcenika(Ucenik & ucenik);
  for (Ucenik &ucenik : ucenici)
    ObradiJednogUcenika(ucenik);
  std::sort(ucenici.begin(), ucenici.end(),
            [](const Ucenik &u1, const Ucenik &u2) {
              return u1.prosjek > u2.prosjek;
            });
}
void ObradiJednogUcenika(Ucenik &ucenik) {
  double suma_ocjena = 0;
  ucenik.prosjek = 1;
  ucenik.prolaz = false;
  for (int ocjena : ucenik.ocjene) {
    if (ocjena == 1)
      return;
    suma_ocjena += ocjena;
  }
  ucenik.prolaz = true;
  ucenik.prosjek = suma_ocjena / BrojPredmeta;
}
void IspisiIzvjestaj(const std::vector<Ucenik> &ucenici) {
  void IspisiJednogUcenika(const Ucenik &ucenik);
  std::cout << std::endl;
  for (const Ucenik &ucenik : ucenici)
    IspisiJednogUcenika(ucenik);
}
void IspisiJednogUcenika(const Ucenik &ucenik) {
  void IspisiDatum(const Datum &datum);
  std::cout << "Učenik " << ucenik.ime << " " << ucenik.prezime << " rođen ";
  IspisiDatum(ucenik.datum_rodjenja);
  if (ucenik.prolaz)
    std::cout << " ima prosjek " << std::setprecision(3) << ucenik.prosjek;
  else
    std::cout << " mora ponavljati razred";
  std::cout << std::endl;
}
void IspisiDatum(const Datum &datum) {
  std::cout << datum.dan << "/" << datum.mjesec << "/" << datum.godina;
}