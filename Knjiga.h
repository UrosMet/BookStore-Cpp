#pragma once
#include "Pisac.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

using namespace std;

class Knjiga {
private:
    string sifra;
    string imeKnjige;
    Pisac& pisac;
    float cena;
    int brojNaStanju;

public:
    Knjiga(const string sifra, const string imeKnjige, Pisac& pisac, float cena, int brojNaStanju);

    void setSifra(string sifra);
    string getSifra() const;

    void setImeKnjige(string imeKnjige);
    string getImeKnjige() const;

    void setPisac(Pisac& pisac);
    Pisac& getPisac() const;

    void setCena(float cena);
    float getCena() const;

    void setBrojNaStanju(int brojNaStanju);
    int getBrojNaStanju() const;

    static vector<unique_ptr<Knjiga>> listaKnjiga;

    static void dodajKnjigu(unique_ptr<Knjiga> knjiga);

    static void stampajListuKnjiga();

    static string imeKnjigePoSifri(const string& sifra);

    static float kupiKnjigu(int brojGodina, const string& sifra);

    static vector<unique_ptr<Knjiga>> ucitajKnjige(const string& filePath, const vector<unique_ptr<Pisac>>& pisci);

    friend ostream& operator<<(ostream& out, const Knjiga& k);

    ~Knjiga();
};
