#include <wx/wx.h>
#include <fstream>
//#include <iostream>


#pragma once
class WereHouse {
public:
	std::vector<std::vector<std::string>> strvec;
	std::fstream stream;
	std::string data;
	std::string str;
	std::string tmp;

	WereHouse();

	void LoadData();
	void Show();
	std::vector<std::string> Slash(std::string data);

	~WereHouse();
};
