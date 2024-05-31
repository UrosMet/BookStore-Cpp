#include "Knjiga.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

using namespace std;

vector<unique_ptr<Knjiga>> Knjiga::listaKnjiga;

Knjiga::Knjiga(const string sifra, const string imeKnjige, Pisac& pisac, float cena, int brojNaStanju)
    : sifra(sifra), imeKnjige(imeKnjige), pisac(pisac), cena(cena), brojNaStanju(brojNaStanju) {}

void Knjiga::setSifra(string sifra) {
    this->sifra = sifra;
}

string Knjiga::getSifra() const {
    return this->sifra;
}

void Knjiga::setImeKnjige(string imeKnjige) {
    this->imeKnjige = imeKnjige;
}

string Knjiga::getImeKnjige() const {
    return this->imeKnjige;
}

void Knjiga::setPisac(Pisac& pisac) {
    this->pisac = pisac;
}

Pisac& Knjiga::getPisac() const {
    return this->pisac;
}

void Knjiga::setCena(float cena) {
    this->cena = cena;
}

float Knjiga::getCena() const {
    return this->cena;
}

void Knjiga::setBrojNaStanju(int brojNaStanju) {
    this->brojNaStanju = brojNaStanju;
}

int Knjiga::getBrojNaStanju() const {
    return this->brojNaStanju;
}

void Knjiga::dodajKnjigu(unique_ptr<Knjiga> knjiga) {
    listaKnjiga.push_back(move(knjiga));
}

void Knjiga::stampajListuKnjiga() {
    for (const auto& knjiga : listaKnjiga) {
        cout << *knjiga << endl;
    }
}

string Knjiga::imeKnjigePoSifri(const string& sifra) {
    for (const auto& knjiga : listaKnjiga) {
        if (knjiga->getSifra() == sifra) {
            return knjiga->getImeKnjige();
        }
    }
    return "";
}

float Knjiga::kupiKnjigu(int brojGodina, const string& sifra) {
    float cenaKnjige = 0.0f;

    for (auto& knjiga : listaKnjiga) {
        if (knjiga->getSifra() == sifra) {
            cenaKnjige = knjiga->getCena();

            if (brojGodina <= 16) {
                cenaKnjige *= 0.7f;
            }
            else if (brojGodina >= 17 && brojGodina <= 24) {
                cenaKnjige *= 0.9f;
            }
            else if (brojGodina >= 25 && brojGodina <= 30) {
                cenaKnjige *= 0.95f;
            }

            int brojNaStanju = knjiga->getBrojNaStanju();
            if (brojNaStanju > 0) {
                knjiga->setBrojNaStanju(brojNaStanju - 1);
            }

            break;
        }
    }

    return cenaKnjige;
}

vector<unique_ptr<Knjiga>> Knjiga::ucitajKnjige(const string& filePath, const vector<unique_ptr<Pisac>>& pisci) {
    vector<unique_ptr<Knjiga>> knjige;
    ifstream infile(filePath);
    string line;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream iss(line);
            string sifra, naziv, imePisca, prezimePisca;
            float cena;
            int kolicina;
            if (iss >> sifra >> naziv >> imePisca >> prezimePisca >> cena >> kolicina) {
                Pisac* pisacPtr = nullptr;
                for (const auto& pisac : pisci) {
                    if (pisac->getIme() == imePisca && pisac->getPrezime() == prezimePisca) {
                        pisacPtr = pisac.get();
                        break;
                    }
                }
                if (pisacPtr) {
                    knjige.push_back(make_unique<Knjiga>(sifra, naziv, *pisacPtr, cena, kolicina));
                }
            }
        }
        infile.close();
    }
    else {
        cerr << "NEPOSTOJI FAJL: " << filePath << endl;
    }

    return knjige;
}

ostream& operator<<(ostream& out, const Knjiga& k) {
    out << k.sifra << " " << k.imeKnjige << " Napisao: " << k.pisac.getIme() << " " << k.pisac.getPrezime() << " - " << k.cena << " RSD (" << k.brojNaStanju << " dostupno)";
    return out;
}

Knjiga::~Knjiga() {}
