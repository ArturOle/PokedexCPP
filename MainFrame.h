#include <wx/wx.h>
#include "WereHouse.h"

#pragma once
class MainFrame :public wxFrame
{
public:
	
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	WereHouse* werehouse;
	wxStaticText* poke_info;
	wxListBox* poke_list;

	void UpdateInfo(wxCommandEvent& event );
	//WereHouse& were, wxStaticText& text
	
	void OnQuit(wxCloseEvent& event);

};

