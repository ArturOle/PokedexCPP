#include <wx/wx.h>
#include <fstream>

#pragma once
class WereHouse {
public:
	std::vector<std::vector<std::string>> strvec;

	WereHouse();

	void LoadData(); 
	void Show();
	std::vector<std::string> Slash(std::string data);

	~WereHouse();
};
