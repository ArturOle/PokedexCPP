#include <wx/wx.h>
#include "WereHouse.h"


#pragma once
class ListPanel : public wxPanel//, public MainFrame
{
	friend class MainFrame;

public:
	wxBoxSizer* sizer_v;
	
	wxPanel* m_parent;
	//WereHouse* werehouse;
	std::vector<std::string> choice;
	MainFrame* main_frame;
	wxListBox* poke_list;

	void pointer_handler();
	void sizer_handler();
	//void connector();
	//void update_info(wxCommandEvent& event);
	std::vector<std::string> choice_getter();
	void choice_parser(std::vector<std::string> choice);

	ListPanel(wxPanel* parent);
	//~ListPanel();
};

