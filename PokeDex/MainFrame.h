#include <wx/wx.h>
#include <wx/file.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/windowptr.h>
#include <iostream>
#include <string>
#include "WereHouse.h"
#include "InfoPanel.h"
#include "ListPanel.h"


#pragma once
class MainFrame : public wxFrame
{
public:
	friend class InfoPanel;
	friend class ListPanel;

	wxPanel* m_parent;
	InfoPanel* info_panel; 
	//wxWindowPtr<InfoPanel> info_parent;
	ListPanel* list_panel;
	wxListBox* poke_list;
	wxBoxSizer* sizer_v;
	wxBoxSizer* sizer_h;
	wxBoxSizer* sizer_h1;
	wxBoxSizer* sizer_h2;
	wxButton* PokeButt;
	wxButton* Evacuate;
	WereHouse* werehouse = new WereHouse;

	const wxString& title = title;
	const wxPoint& pos = pos;
	const wxSize& size = size;

	void pointer_handler();
	void sizer_handler();
	void update_info(wxCommandEvent& event);
	void connector();
	void on_quit(wxCloseEvent& event);

	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};
