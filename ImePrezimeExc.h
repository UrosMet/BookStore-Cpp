#pragma once
#include<iostream>
#include<exception>
class ImePrezimeExc : public std::exception {
	virtual const char* what() const throw() {
		return "Ime i prezime moraju biti samo slova";
	}
};

extern ImePrezimeExc ex;