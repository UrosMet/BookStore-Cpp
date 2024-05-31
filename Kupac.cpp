#include "Kupac.h"
#include<string>
#include<iostream>
void Kupac::info()
{
	std::cout << "Ime kupca: " << this->ime << "Prezime kupca: " << this->prezime << "Godine kupca: " << this->godine << "Broj telefona: " << this->brojTelefona << std::endl;
}
