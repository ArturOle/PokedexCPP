#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/bitmap.h>

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
	wxString path = wxGetCwd();
	wxBitmapButton* image;
	std::string poke_data;
	wxStaticText* poke_info;
	MainFrame* main_frame;

	InfoPanel(wxPanel* parent);

	void pointer_handler();
	void update_image(std::string pokemon_name);
	void poke_sound(wxCommandEvent& event);
	void connector();
	wxBitmap get_image(std::string pokemon_name);
	void sizer_handler();

};

