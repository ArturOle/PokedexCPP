#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL, wxID_ANY, title, pos, size)
{
	werehouse = new WereHouse;
	werehouse->strvec.resize(151);

	this->SetBackgroundColour(wxColor(*wxRED));

	wxBoxSizer* sizer_h = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* sizer_v = new wxBoxSizer(wxVERTICAL);

	poke_info = new wxStaticText(this,
		wxID_ANY,
		"text\ntext\ntext\ntext\ntext",
		wxDefaultPosition,
		wxDefaultSize,
		wxALIGN_CENTRE_HORIZONTAL);

	sizer_h->Add(poke_info, 1, wxLEFT, 10);
	poke_info->SetLabel("Sooooome\nThing\n");

	wxButton* PokeButt = new wxButton(this, 11, "Choose");
	wxButton* Evacuate = new wxButton(this, 12, "EXIT");

	std::vector<std::string> choice;
	for (auto& x : werehouse->strvec)
		choice.push_back(x[2]);

	poke_list = new wxListBox(this, 13, wxDefaultPosition, wxDefaultSize, 0, NULL);
	sizer_h->Add(poke_list, 1, wxRIGHT | wxEXPAND, 10);
	for (auto x : choice) {
		poke_list->AppendString(x);
	}
	//Connect(wxEVT_MOVE, wxMoveEventHandler(Move::OnMove));
	Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
		wxCommandEventHandler(MainFrame::UpdateInfo));
	Connect(11, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::UpdateInfo));
	Connect(12, wxEVT_COMMAND_BUTTON_CLICKED, wxCloseEventHandler(MainFrame::OnQuit));
	

	sizer_v->Add(sizer_h, 1, wxCENTER | wxEXPAND, 10);
	sizer_v->Add(PokeButt, 0, wxCENTER, 10);
	sizer_v->Add(Evacuate, 0, wxCENTER, 10);
	this->SetSizer(sizer_v);
	this->Layout();

	delete(werehouse);
}

void MainFrame::UpdateInfo(wxCommandEvent& event) {
	werehouse = new WereHouse;
	std::string label;
	
	int sel = poke_list->GetSelection();
	for (int i = 0; i < 4; i++) {
		std::string text[] = { "Pokedex Number: ", "\nName: ", "\nGeneration: ", "\nType: " };
		label.append(text[i]);
		label.append(werehouse->strvec[sel][i+1]);
	}
	
	if (werehouse->strvec[sel].size() == 5) {
		label.append(" ");
		label.append(werehouse->strvec[sel][4]);
	}
	
	poke_info->SetLabel(label);
	delete(werehouse);
}

void MainFrame::OnQuit(wxCloseEvent& event) {
	wxWindow::Close();
}
