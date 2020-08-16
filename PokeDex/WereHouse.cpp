#include "WereHouse.h"

WereHouse::WereHouse() {
	LoadData();
}

void WereHouse::LoadData() {

	std::fstream stream;
	stream.open("PokeGenOne.txt", std::ios::in);
	std::string data;
	if (stream.is_open()) {
		while (std::getline(stream, data)) {
			strvec.push_back(Slash(data));
		}
	}
	else {
		std::cout << "Error Occured while openning PokeGenOne.txt" << std::endl;;
	}
}

void WereHouse::Show() {
	LoadData();
	for (auto x : this->strvec) {
		int size = x.size();
		for (int i = 0; i < size; i++) {
			std::cout << x[i];
		}
		std::cout << "\n";
	}
}

std::vector<std::string> WereHouse::Slash(std::string data) {
	std::vector<std::string> vec; // nie tykaæ
	this->str = data;

	for (int i = 0; i < this->str.size()+1; i++) {
		if (this->str[i] == ',') {
			vec.push_back(this->tmp);
			this->tmp.clear();
		}
		else {
			this->tmp += this->str[i];
		}
	}
	return vec;
}

WereHouse::~WereHouse() {
	this->strvec.clear();
}