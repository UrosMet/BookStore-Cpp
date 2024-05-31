#pragma once
#include<string>
class Osoba
{
protected:
	std::string ime;
	std::string prezime;
public:
	Osoba() {
		this->ime = "";
		this->prezime = "";
	}
	Osoba(std::string ime, std::string prezime) : ime(ime), prezime(prezime) {}


	virtual void info() = 0;
	~Osoba() {};
};

