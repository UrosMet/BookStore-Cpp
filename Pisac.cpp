#include "Pisac.h"
#include <iostream>
#include <string>

using namespace std;

Pisac::Pisac() {
    this->mestoRodjenja = "";
}

Pisac::Pisac(string ime, string prezime, string mestoRodjenja)
    : Osoba(ime, prezime), mestoRodjenja(mestoRodjenja) {}

void Pisac::setIme(string ime) {
    this->ime = ime;
}

string Pisac::getIme() const {
    return this->ime;
}

void Pisac::setPrezime(string prezime) {
    this->prezime = prezime;
}

string Pisac::getPrezime() const {
    return this->prezime;
}

void Pisac::setMestoRodjenja(string mestoRodjenja) {
    this->mestoRodjenja = mestoRodjenja;
}

string Pisac::getMestoRodjenja() const {
    return this->mestoRodjenja;
}

void Pisac::info() {
    cout << "Ime: " << ime << ", Prezime: " << prezime << ", Mesto Rodjenja: " << mestoRodjenja << endl;
}

vector<unique_ptr<Pisac>> Pisac::ucitajPisce(const string& filePath) {
    vector<unique_ptr<Pisac>> pisci;
    ifstream infile(filePath);
    string line;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream iss(line);
            string ime, prezime, mestoRodjenja;
            if (iss >> ime >> prezime >> mestoRodjenja) {
                pisci.push_back(make_unique<Pisac>(ime, prezime, mestoRodjenja));
            }
        }
        infile.close();
    }
    else {
        cerr << "NEPOSTOJI FAJL: " << filePath << endl;
    }

    return pisci;
}

ostream& operator<<(ostream& out, const Pisac& p) {
    out << "Ime: " << p.ime << ", Prezime: " << p.prezime << ", Mesto Rodjenja: " << p.mestoRodjenja;
    return out;
}

Pisac::~Pisac() {}
