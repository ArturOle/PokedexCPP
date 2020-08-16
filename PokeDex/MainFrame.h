#include <wx/wx.h>
#include <wx/file.h>
#include <wx/msgdlg.h>
#include <iostream>
#include <string>
#include "WereHouse.h"

#pragma once
class MainFrame : public wxFrame
{
	wxString path = wxGetCwd();
	wxBoxSizer* sizer_v;
	wxBoxSizer* sizer_h;
	wxButton* PokeButt;
	wxButton* Evacuate;
	WereHouse* werehouse;
	wxStaticText* poke_info;
	wxListBox* poke_list;
	std::string poke_data;
	//int xImageSize, yImageSize = 64;
	//int PngImageSize = xImageSize * yImageSize * 16;
	//byte* bpImage = (byte*)malloc(PngImageSize);

	void UpdateInfo(wxCommandEvent& event);
	void pointer_handler();
	void sizer_handler();
	void connector();
	wxImage get_image(std::string pokemon_name);
	std::vector<std::string> choice_getter();
	void choice_parser(std::vector<std::string> choice);

	void OnQuit(wxCloseEvent& event);

public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

};
