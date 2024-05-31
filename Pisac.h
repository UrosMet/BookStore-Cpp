#pragma once
#include "Osoba.h"
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>

using namespace std;

class Pisac : public Osoba {
private:
    string mestoRodjenja;

public:
    Pisac();
    Pisac(string ime, string prezime, string mestoRodjenja);

    void setIme(string ime);
    string getIme() const;

    void setPrezime(string prezime);
    string getPrezime() const;

    void setMestoRodjenja(string mestoRodjenja);
    string getMestoRodjenja() const;

    void info();

    static vector<unique_ptr<Pisac>> ucitajPisce(const string& filePath);

    friend ostream& operator<<(ostream& out, const Pisac& p);

    ~Pisac();
};
