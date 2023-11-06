//TP 2022/2023: Zadaća 5, Zadatak 4
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>

template <typename TipEl> class Matrica{
    int br_redova;
    int br_kolona;
    char ime_matrice;
    TipEl **elementi;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DelocirajMemoriju(TipEl **elementi,int br_redova);
    void KopirajElemente(TipEl **elementi);

    public:
    Matrica(int br_redova, int br_kolona, char imeM = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    ~Matrica(){DelocirajMemoriju(elementi, br_redova);}
    template <typename Tip2>
    friend std::istream& operator >>(std::istream& ulaz, Matrica<Tip2> &m1);
    template<typename Tip2>
    friend std::ostream& operator <<(std::ostream& izlaz, Matrica<Tip2> m1);
    template<typename Tip2>
    friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template<typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1,int broj);
    template <typename Tip2>
    friend inline Matrica<Tip2> operator *(int broj,const Matrica<Tip2> &m1);
    Matrica &operator +=(const Matrica &m1);
    Matrica &operator -=(const Matrica &m1);
    Matrica &operator *=(const Matrica &m1);
    Matrica &operator *=(int broj);
    TipEl* operator[](int i)const;
    TipEl& operator()(int i, int j)const;
    operator std::string() const;

    Matrica(std::string ime_datoteke, bool tipUcitavanja){
        if(tipUcitavanja)ObnoviIzBinarneDatoteke(ime_datoteke);
        else ObnoviIzTekstualneDatoteke(ime_datoteke);
    };
    template<typename Tip2>
    friend std::ofstream& operator <<(std::ofstream& izlaz, Matrica<Tip2> m1);
    void SacuvajUTekstualnuDatoteku(std::string ime_datoteke);
    void ObnoviIzTekstualneDatoteke(std::string ime_datoteke);
    void SacuvajUBinarnuDatoteku(std::string ime_datoteke);
    void ObnoviIzBinarneDatoteke(std::string ime_datoteke);
};

template <typename TipEl> Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char imeM):br_redova(br_redova), br_kolona(br_kolona), ime_matrice(imeM), elementi(AlocirajMemoriju(br_redova,br_kolona)){}

template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona){
    TipEl **elementi=new TipEl*[br_redova]{};

    try{
        for(int i=0;i<br_redova;i++)elementi[i]=new TipEl[br_kolona];
    }
    catch(...){
        DelocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DelocirajMemoriju(TipEl **elementi, int br_redova){
    if(elementi==nullptr)return;
    for(int i=0;i<br_redova;i++)delete[] elementi[i];
    delete[] elementi;
}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi){
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            Matrica::elementi[i][j]=elementi[i][j];
        }
    }
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m):br_redova(m.br_redova),br_kolona(m.br_kolona),ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova,m.br_kolona)){
    KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m):br_redova(m.br_redova),br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),elementi(m.elementi){
    m.br_redova=0;
    m.elementi=nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m){

    if(br_redova<m.br_redova || br_kolona<m.br_kolona){
        TipEl **novi_prostor=AlocirajMemoriju(m.br_redova,m.br_kolona);
        DelocirajMemoriju(elementi, br_redova);
        elementi=novi_prostor;
    }

    else if(br_redova>m.br_redova){
        for(int i=m.br_redova;i<br_redova;i++)delete elementi[i];
    }
        ime_matrice=m.ime_matrice;
        br_redova=m.br_redova;
        br_kolona=m.br_kolona;
        KopirajElemente(m.elementi);

        return *this;
    
}

template<typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m){
    std::swap(br_redova,m.br_redova);
    std::swap(br_kolona,m.br_kolona);
    std::swap(ime_matrice,m.ime_matrice);
    std::swap(elementi,m.elementi);
    return *this;
}

template <typename TipEl>
std::istream& operator >>(std::istream& ulaz,Matrica<TipEl> &m1){
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            std::cout<<m1.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            ulaz>>m1.elementi[i][j];
        }
    }
    return ulaz;
}

template<typename TipEl>
std::ostream& operator <<(std::ostream& izlaz, Matrica<TipEl> m1){
    int S=izlaz.width();

    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++)izlaz<<std::setw(S)<<m1.elementi[i][j];
        izlaz<<std::endl;
    }
    return izlaz;
}

template <typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona){
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }

    Matrica<TipEl> m3(m1.br_redova,m2.br_kolona);

    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator-(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona){
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }

    Matrica<TipEl> m3(m1.br_redova,m2.br_kolona);

    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator*(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
    if((m1.br_redova==0 || m2.br_kolona==0) || m1.br_kolona!=m2.br_redova){
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }

    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);

    TipEl c=0;

    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            for(int k=0;k<m2.br_kolona;++k){
                c+=(m1.elementi[i][k]*m2.elementi[k][j]);
            }
            m3.elementi[i][j]=c;
            c=0;
        }
    }
    return m3;
}

template<typename TipEl>
Matrica<TipEl> operator*(const Matrica<TipEl> &m1,int broj){
    Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);

    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]*broj;
        }
    }

    return m3;
}

template<typename TipEl>
inline Matrica<TipEl> operator *(int broj,const Matrica<TipEl> &m1){
    return m1*broj;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator +=(const Matrica<TipEl> &m2){
    if(this->br_redova!=m2.br_redova || this->br_kolona!=m2.br_kolona){
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }

    for(int i=0;i<this->br_redova;i++){
        for(int j=0;j<this->br_kolona;j++){
            this->elementi[i][j]+=m2.elementi[i][j];
        }
    }

    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator -=(const Matrica<TipEl> &m2){
    if(this->br_redova!=m2.br_redova || this->br_kolona!=m2.br_kolona){
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }

    for(int i=0;i<this->br_redova;i++){
        for(int j=0;j<this->br_kolona;j++){
            this->elementi[i][j]-=m2.elementi[i][j];
        }
    }

    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator *=(const Matrica<TipEl> &m2){
    if((br_redova==0 || m2.br_kolona==0) || br_kolona!=m2.br_redova){
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }

    TipEl c=0;
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
        for(int k=0;k<m2.br_kolona;++k){
            c+=(elementi[i][k]*m2.elementi[k][j]);
        }
        elementi[i][j]=c;
        c=0;
    }
    }
   return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator *=(int broj){

    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            elementi[i][j]*=broj;
        }
    }

    return *this;
}

template <typename TipEl>
TipEl* Matrica<TipEl>::operator[](int i)const{
    return elementi[i];
}

template <typename TipEl>
TipEl& Matrica<TipEl>::operator()(int i,int j)const{
    if((i==0 || i>br_redova) || (j==0 || j>br_kolona)){
        throw std::range_error("Neispravan indeks");
    }
    return elementi[i-1][j-1];
}

template <typename TipEl>
Matrica<TipEl>::operator std::string()const {
    std::stringstream ss1;
    ss1<<"{";
    int j=0;
    for(int i=0;i<br_redova;++i){
        ss1<<"{";
        for(j=0;j<br_kolona-1;++j){
            ss1<<elementi[i][j]<<",";
        }
        ss1<<elementi[i][j]<<"}";
        if(i!=br_redova-1){
            ss1<<",";
        }
    }

    ss1<<"}";

    return ss1.str();
}



template <typename TipEl>
std::ofstream &operator <<(std::ofstream &izlaz, Matrica<TipEl> m1){
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            izlaz<<m1.elementi[i][j];
            if(j<m1.br_kolona-1)izlaz<<",";

            if(izlaz.bad())throw std::logic_error("Problemi sa upisom u datoteku");
        }

        if(i<m1.br_redova-1)izlaz<<std::endl;
    }

    return izlaz;
}

/*template <typename TipEl>
Matrica<TipEl>::Matrica(std::string ime_datoteke,bool tip){
    std::ifstream ulazBrojanje(ime_datoteke,std::ios::in);

    if(!ulazBrojanje){
        throw std::logic_error("Trazena datoteka ne postoji");
    }

    TipEl element;
    int brKolona=0;
    int brRedova;
    int validnaVelicina=0;

    while(!ulazBrojanje.eof()){
        char zarez=',';

        while(true){
            if(!(ulazBrojanje>>element)){
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }

            if((zarez=ulazBrojanje.peek())==','){
                ulazBrojanje.get();
            }
            else{
                if(zarez==EOF)ulazBrojanje.clear();
                break;
            }

            brKolona++;

            if(ulazBrojanje.bad())throw std::logic_error("Problemi pri citanju datoteke");

        }
        if(zarez==EOF)break;
        if(brRedova==0)validnaVelicina=brKolona;
        if(brKolona!=validnaVelicina)throw std::logic_error("Datoteka sadrzi besmislene podatke");
        brRedova++;
        br_kolona=0;
    }
    AlocirajMemoriju(brRedova,brKolona);

    std::ifstream ulaz(ime_datoteke,std::ios::in);

    if(!ulaz)throw std::logic_error("Trazena datoteka ne postoji");

    TipEl elementMatrice;
    int i=0;
    int j=0;

    while(!ulaz.eof()){
        char zarez=',';

        while(true){
            if(!(ulaz>>elementMatrice))throw std::logic_error("Problemi pri citanju datoteke");

            elementi[i][j]=elementMatrice;

            if((zarez=ulaz.peek())==','){
                ulaz.get();
            }
            else{
                if(zarez==EOF)ulaz.clear();
                break;
            }

            j++;

            if(ulaz.bad())throw std::logic_error("Problemi pri citanju datoteke");
        }

        if(zarez==EOF)break;
        i++;
        j=0;
    }
}*/

template <typename TipEl>
void Matrica <TipEl>::SacuvajUTekstualnuDatoteku(std::string ime_datoteke)
{
    std::ofstream izlazni_tok(ime_datoteke);
    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
    else
    {
        for(int i=0; i<br_redova; i++)
        {
            for(int j=0; j<br_kolona; j++)
            {
                izlazni_tok << elementi[i][j];
                if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
                if(j!=br_kolona-1)
                {
                    izlazni_tok << ",";
                    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
                }
            }
            if(i!=br_redova-1)
            {
                izlazni_tok<<std::endl;
                if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
            }    
        }
    }
}


template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string ime_datoteke)
{
    std::ofstream izlazni_tok(ime_datoteke, std::ios::binary | std::ios::out);
    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
    else
    {
        izlazni_tok.write((char*)&br_redova, sizeof(int));

        if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");

        izlazni_tok.seekp(sizeof(int));
        izlazni_tok.write((char*)&br_kolona, sizeof(int));

        if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");

        int pozicija = 2*sizeof(int);

        for(int i=0; i<br_redova; i++)
        {
            for(int j=0; j<br_kolona; j++)
            {
                izlazni_tok.seekp(pozicija);
                izlazni_tok.write((char*)&elementi[i][j], sizeof(TipEl));
                
                if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
                pozicija = pozicija + sizeof(TipEl);
            }
        }

    }
}
template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string ime_datoteke)
{
    std::ifstream ulazni_tok(ime_datoteke, std::ios::binary | std::ios::in);

    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    
    DelocirajMemoriju(elementi, br_redova);

    int redovi, kolone;
    ulazni_tok.read((char*)&redovi, sizeof(int));

    if(!ulazni_tok) throw std::logic_error("Problemi pri citanju datoteke");

    ulazni_tok.seekg(sizeof(int));
    ulazni_tok.read((char*)&kolone, sizeof(int));

    if(!ulazni_tok) throw std::logic_error("Problemi pri citanju datoteke");
    int pozicija = 2*sizeof(int);

    this->elementi = AlocirajMemoriju(redovi, kolone);

    for(int i=0; i<redovi; i++)
    {
        for(int j=0; i<kolone; j++)
        {
            ulazni_tok.seekg(pozicija);
            ulazni_tok.read((char*) &(this->elementi[i][j]), sizeof(TipEl));

            if(!ulazni_tok) throw std::logic_error("Problemi pri citanju datoteke");

            pozicija = pozicija + sizeof(TipEl);
        }
    }
}
    
template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string ime_datoteke)
{
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");

    else
    {
        DelocirajMemoriju(elementi, br_redova);
        std::vector<std::vector<TipEl>> v;
        std::vector<TipEl> pomocni;
        TipEl element;
        char c;

        while(ulazni_tok >> element)
        {
            pomocni.push_back(element);
            if(ulazni_tok.peek() == ',')
            {
                ulazni_tok >> c;
                continue;
            }
            else if(ulazni_tok.peek() == '\n')
            {
                v.push_back(pomocni);
                pomocni.resize(0);
                continue;
            }
            else if(ulazni_tok.eof())
            {
                v.push_back(pomocni);
                break;
            }
            
             if(!ulazni_tok.good()) throw std::logic_error("Datoteka sadrzi besmislene podatke");

        }
        if(ulazni_tok.eof());
        else

        throw std::logic_error("Datoteka sadrzi besmislene podatke");
        //throw std::Logic_error("Problemi pri citanju datoteke");
        elementi = AlocirajMemoriju(v.size(), v[0].size());

        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[0].size(); j++)
            {
                if(v[0].size() != v[i].size())
                if(!ulazni_tok.good()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                
                elementi[i][j] = v[i][j];
                    }            
        }
    }
}





int main ()
{

    Matrica<double> a(2,2);

    a[0][0]=1;
    a[0][1]=2;
    a[1][0]=3;
    a[1][1]=4;

    std::cout<<a;

    a.SacuvajUBinarnuDatoteku("test.dat");
    a.ObnoviIzBinarneDatoteke("test.dat");


	return 0;
}
