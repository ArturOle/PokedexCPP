#include <wx/wx.h>
#include "WereHouse.h"


#pragma once
class ListPanel : virtual public wxPanel//, public MainFrame
{
	friend class MainFrame;

public:
	wxBoxSizer* sizer_v;
	wxBoxSizer* sizer_h;
	wxListBox* poke_list;
	wxPanel* m_parent;
	//WereHouse* werehouse;
	std::vector<std::string> choice;
	MainFrame* main_frame;

	void pointer_handler();
	void sizer_handler();
	std::vector<std::string> choice_getter();
	void choice_parser(std::vector<std::string> choice);

	ListPanel(wxPanel* parent);
	~ListPanel();
};

