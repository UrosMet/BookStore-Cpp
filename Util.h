#pragma once
#include<string>
#include<iostream>
class Util
{
public:
	static bool samoSlova(std::string& str) {
		for (char c : str) {
			if (!isalpha(c))
			{
				return false;
			}
		}
		return true;
	}
	static bool samoBrojevi(std::string& str) {
		for (char c : str) {
			if (!isdigit(c))
			{
				return false;
			}
		}
		return true;
	}
};

