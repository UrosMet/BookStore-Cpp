#pragma once
#include<iostream>
#include<exception>
class BrojTelefonaExc : public std::exception {
	virtual const char* what() const throw() {
		return "U broju telefona smeju biti samo cifre";
	}
};

extern BrojTelefonaExc exb;