// TP 2022/2023: LV 8, Zadatak 3
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

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
  void UnesiUcenike(Ucenik **&pok_ucenici, const int &broj_ucenika);
  void ObradiUcenike(Ucenik **&pok_ucenici, const int &broj_ucenika);
  void IspisiIzvjestaj(Ucenik **&pok_ucenici, const int &broj_ucenika);
  void OslobodiMemoriju(Ucenik **&pok_ucenici, const int &broj_ucenika);
  int broj_ucenika;
  std::cout << "Koliko ima ucenika: ";
  std::cin >> broj_ucenika;
  Ucenik **pok_ucenici{nullptr};
  try {
    pok_ucenici=new Ucenik*[broj_ucenika];
    for(int i=0;i<broj_ucenika;i++){
        pok_ucenici[i]=nullptr;
    }
    try {
      UnesiUcenike(pok_ucenici, broj_ucenika); // Ovo može izazvati izuzetak!!!
    } catch (...) {
      OslobodiMemoriju(pok_ucenici, broj_ucenika);
      throw;
    }
    ObradiUcenike(pok_ucenici, broj_ucenika);
    IspisiIzvjestaj(pok_ucenici, broj_ucenika);
    OslobodiMemoriju(pok_ucenici, broj_ucenika);
  } catch (...) {
    std::cout << "Problemi sa memorijom...\n";
  }
  return 0;
}
void UnesiUcenike(Ucenik **&pok_ucenici, const int &broj_ucenika) {
  void UnesiJednogUcenika(Ucenik * p_ucenik);
  for (int i = 0; i < broj_ucenika; i++) {
    std::cout << "Unesite podatke za " << i + 1 << ". ucenika:\n";
    pok_ucenici[i] = new Ucenik;
    UnesiJednogUcenika(pok_ucenici[i]);
  }
}
void UnesiJednogUcenika(Ucenik *p_ucenik) {
  void UnesiDatum(Datum & datum);
  void UnesiOcjene(int ocjene[], int broj_predmeta);
  std::cout << " Ime: ";
  std::cin >> p_ucenik->ime;
  std::cout << " Prezime: ";
  std::cin >> p_ucenik->prezime;
  std::cout << " Datum rodjenja (D/M/G): ";
  UnesiDatum(p_ucenik->datum_rodjenja);
  UnesiOcjene(p_ucenik->ocjene, BrojPredmeta);
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
void ObradiUcenike(Ucenik **&pok_ucenici, const int &broj_ucenika) {
  void ObradiJednogUcenika(Ucenik * p_ucenik);
  for (int i=0;i<broj_ucenika;i++)
    ObradiJednogUcenika(pok_ucenici[i]);
  std::sort(pok_ucenici, pok_ucenici + broj_ucenika,
            [](const Ucenik *p_u1, const Ucenik *p_u2) {
              return p_u1->prosjek > p_u2->prosjek;
            });
}
void ObradiJednogUcenika(Ucenik *p_ucenik) {
  double suma_ocjena = 0;
  p_ucenik->prosjek = 1;
  p_ucenik->prolaz = false;
  for (int ocjena : p_ucenik->ocjene) {
    if (ocjena == 1)
      return;
    suma_ocjena += ocjena;
  }
  p_ucenik->prolaz = true;
  p_ucenik->prosjek = suma_ocjena / BrojPredmeta;
}
void IspisiIzvjestaj(Ucenik **&pok_ucenici, const int &broj_ucenika) {
  void IspisiJednogUcenika(const Ucenik *p_ucenik);
  std::cout << std::endl;
  for (int i=0;i<broj_ucenika;i++)
    IspisiJednogUcenika(pok_ucenici[i]);
}
void IspisiJednogUcenika(const Ucenik *p_ucenik) {
  void IspisiDatum(const Datum &datum);
  std::cout << "Ucenik " << p_ucenik->ime << " " << p_ucenik->prezime
            << " rodjen ";
  IspisiDatum(p_ucenik->datum_rodjenja);
  if (p_ucenik->prolaz)
    std::cout << " ima prosjek " << std::setprecision(3) << p_ucenik->prosjek;
  else
    std::cout << " mora ponavljati razred";
  std::cout << std::endl;
}
void IspisiDatum(const Datum &datum) {
  std::cout << datum.dan << "/" << datum.mjesec << "/" << datum.godina;
}
void OslobodiMemoriju(Ucenik **&pok_ucenici, const int &broj_ucenika) {

  for (int i=0;i<broj_ucenika;i++)
    delete pok_ucenici[i];
    delete [] pok_ucenici;
}