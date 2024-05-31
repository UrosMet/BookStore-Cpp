#include "Kupac.h"
#include <iostream>
#include <string>

using namespace std;

Kupac::Kupac() {
    this->godine = 0;
    this->brojTelefona = "";
}

Kupac::Kupac(string ime, string prezime, int godine, string brojTelefona)
    : Osoba(ime, prezime), godine(godine), brojTelefona(brojTelefona) {}

void Kupac::setIme(string ime) {
    this->ime = ime;
}

string Kupac::getIme() const {
    return this->ime;
}

void Kupac::setPrezime(string prezime) {
    this->prezime = prezime;
}

string Kupac::getPrezime() const {
    return this->prezime;
}

void Kupac::setGodine(int godine) {
    this->godine = godine;
}

int Kupac::getGodine() const {
    return this->godine;
}

void Kupac::setBrojTelefona(string brojTelefona) {
    this->brojTelefona = brojTelefona;
}

string Kupac::getBrojTelefona() const {
    return this->brojTelefona;
}

void Kupac::info() {
    cout << "Ime kupca: " << this->ime << ", Prezime kupca: " << this->prezime
        << ", Godine kupca: " << this->godine << ", Broj telefona: " << this->brojTelefona << endl;
}

Kupac::~Kupac() {}
