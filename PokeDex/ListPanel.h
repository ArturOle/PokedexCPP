#include <wx/wx.h>
#include "WereHouse.h"


#pragma once
class ListPanel : public wxPanel
{
	friend class MainFrame;

public:
	wxBoxSizer* sizer_v;
	wxPanel* m_parent;
	std::vector<std::string> choice;
	MainFrame* main_frame;
	wxListBox* poke_list;

	void sizer_handler();
	std::vector<std::string> choice_getter();
	void choice_parser(std::vector<std::string> choice);

	ListPanel(wxPanel* parent);
};

