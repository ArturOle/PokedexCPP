#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL, wxID_ANY, title, pos, size)
{
	werehouse = new WereHouse;
	werehouse->strvec.shrink_to_fit();

	sizer_h = new wxBoxSizer(wxHORIZONTAL);
	sizer_v = new wxBoxSizer(wxVERTICAL);
	poke_info = new wxStaticText(this,
		wxID_ANY,
		"text\ntext\ntext\ntext\ntext",
		wxDefaultPosition,
		wxDefaultSize,
		wxALIGN_CENTRE_HORIZONTAL);
	poke_info->SetLabel("DoubleClick on pokemon name \nor\n Select pokemon and click \n\"Choose\" button");

	PokeButt = new wxButton(this, 11, "Choose");
	Evacuate = new wxButton(this, 12, "EXIT");
	poke_list = new wxListBox(this, 13, wxDefaultPosition, wxDefaultSize, 0, NULL);

	std::vector<std::string> choice = choice_getter();
	choice_parser(choice);
	connector();
	sizer_handler();
	pointer_handler();
	delete(werehouse);
}

void MainFrame::UpdateInfo(wxCommandEvent& event) {
	werehouse = new WereHouse;

	int sel = poke_list->GetSelection();
	int max = werehouse->strvec[sel].size()-1;
	this->poke_data = "";
	for (int i = 0; i < max; i++) {
		std::string text[] = { "Pokedex Number: ", "\nName: ", "\nGeneration: ", "\nType: ", " & " };
		this->poke_data.append(text[i]);
		this->poke_data.append(werehouse->strvec[sel][i+1]);
		this->get_image(werehouse->strvec[sel][2]);
	}

	this->poke_info->SetLabel(this->poke_data);
	delete(werehouse);
}

void MainFrame::OnQuit(wxCloseEvent& event) {
	wxWindow::Close();
}

void MainFrame::pointer_handler() {
	this->SetBackgroundColour(wxColor(*wxRED));
	this->SetSizer(this->sizer_v);
	this->Layout();
}

void MainFrame::sizer_handler() {
	this->sizer_h->Add(this->poke_info, 1, wxLEFT, 10);
	this->sizer_h->Add(this->poke_list, 1, wxRIGHT | wxEXPAND, 10);
	this->sizer_v->Add(this->sizer_h, 1, wxCENTER | wxEXPAND, 10);
	this->sizer_v->Add(this->PokeButt, 0, wxCENTER, 10);
	this->sizer_v->Add(this->Evacuate, 0, wxCENTER, 10);
}

void MainFrame::connector() {
	Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
		wxCommandEventHandler(MainFrame::UpdateInfo));
	Connect(11, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::UpdateInfo));
	Connect(12, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCloseEventHandler(MainFrame::OnQuit));
}

std::vector<std::string> MainFrame::choice_getter() {
	std::vector<std::string> choice;
	for (auto& x : werehouse->strvec)
		choice.push_back(x[2]);
	return choice;
}

void MainFrame::choice_parser(std::vector<std::string> choice) {
	for (auto x : choice) {
		poke_list->AppendString(x);
	}
}

wxImage MainFrame::get_image(std::string pokemon_name) {

	this->path.Append("\\Images\\" + pokemon_name + ".png");
	wxImage poke_image;
	if (wxFile::Exists(path)) {
		wxMessageBox("File exists at location " + path);
		poke_image.LoadFile(path);
		return poke_image;
	}
	else {
		wxMessageBox("File not occure at " + path);
	}
}
