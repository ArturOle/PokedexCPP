#include "WereHouse.h"

WereHouse::WereHouse() {
	LoadData();
}

void WereHouse::LoadData() {

	std::fstream file;
	file.open("PokeGenOne.txt", std::ios::in);
	std::string data;
	if (file.is_open()) {
		while (std::getline(file, data)) {
			strvec.push_back(Slash(data));
			//wxString text = GetInfo(data, 3).give();
		}
	}
	else {
		std::cout << "Error Occured while openning PokeGenOne.txt" << std::endl;;
	}
}

void WereHouse::Show() {
	LoadData();
	for (auto x : strvec) {
		int size = x.size();
		for (int i = 0; i < size; i++) {
			std::cout << x[i];
		}
		std::cout << "\n";
	}
}

std::vector<std::string> WereHouse::Slash(std::string data) {
	std::vector<std::string> vec;
	std::string str = data;
	std::string tmp;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			vec.push_back(tmp);
			tmp.clear();
		}
		else {
			tmp += str[i];
		}
	}
	return vec;
}

WereHouse::~WereHouse() {
	strvec.clear();
}