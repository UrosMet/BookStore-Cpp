#pragma once
#include "Osoba.h"
#include <string>

using namespace std;

class Kupac : public Osoba {
private:
    int godine;
    string brojTelefona;

public:
    Kupac();
    Kupac(string ime, string prezime, int godine, string brojTelefona);

    void setIme(string ime);
    string getIme() const;

    void setPrezime(string prezime);
    string getPrezime() const;

    void setGodine(int godine);
    int getGodine() const;

    void setBrojTelefona(string brojTelefona);
    string getBrojTelefona() const;

    void info();
    ~Kupac();
};
