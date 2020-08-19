#include <wx/wx.h>
#include <wx/panel.h>
#include "WereHouse.h"
#include "ListPanel.h"


#pragma once
class InfoPanel : public wxPanel //, public MainFrame
{
	friend class MainFrame;
	friend class ListPanel;

public:

	wxPanel* m_parent;
	wxBoxSizer* sizer_v;
	wxBoxSizer* sizer_h;
	wxString path = wxGetCwd();
	wxStaticBitmap* image;
	std::string poke_data;
	wxStaticText* poke_info;
	//WereHouse* werehouse;
	MainFrame* main_frame;

	void update_info(wxCommandEvent& event);
	void pointer_handler();
	void update_image(std::string pokemon_name);
	void connector();
	wxBitmap get_image(std::string pokemon_name);
	void sizer_handler();

	InfoPanel(wxPanel* parent);
	~InfoPanel();
};

