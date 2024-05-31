#pragma once
#include"Osoba.h"
#include<string>
class Kupac : public Osoba
{
private:
	int godine;
	std::string brojTelefona;
public:
	Kupac() {
		this->godine = 0;
		this->brojTelefona = "";
	}
	Kupac(std::string ime, std::string prezime, int godine, std::string brojTelefona) : Osoba(ime, prezime), godine(godine), brojTelefona(brojTelefona) {}

	void setIme(std::string ime) {
		this->ime = ime;
	}
	std::string getIme() {
		return this->ime = ime;
	}

	void setPrezime(std::string prezime) {
		this->prezime = prezime;
	}
	std::string getPrezime() {
		return this->prezime = prezime;
	}

	void setGodine(int godine) {
		this->godine = godine;
	}
	int getGodine() {
		return this->godine = godine;
	}

	void setBrojTelefona(std::string brojTelefona) {
		this->brojTelefona = brojTelefona;
	}
	std::string getBrojTelefona() {
		return this->brojTelefona = brojTelefona;
	}


	void info();
	~Kupac() {};
};

