#include "MainFrame.h"


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
		  :wxFrame(NULL, wxID_ANY, title, pos, size)
{
	this->m_parent = new wxPanel(this, wxID_ANY);
	
	this->sizer_h = new wxBoxSizer(wxHORIZONTAL);
	this->sizer_v = new wxBoxSizer(wxVERTICAL);

	this->list_panel = new ListPanel(this->m_parent);
	this->info_panel = new InfoPanel(this->m_parent);

	this->poke_list = this->list_panel->poke_list;

	this->PokeButt = new wxButton(this, 11, "Choose");
	this->Evacuate = new wxButton(this, 12, "EXIT");

	connector();
	sizer_handler();
	pointer_handler();
}


void MainFrame::on_quit(wxCloseEvent& event) 
{
	delete(this->werehouse);
	delete(this->info_panel->image);
	wxWindow::Close();
}


void MainFrame::on_quit()
{
	delete(this->werehouse);
	wxWindow::Close();
}


void MainFrame::pointer_handler() 
{
	this->SetBackgroundColour(wxColor(*wxRED));
	this->SetSizer(this->sizer_v);
}

void MainFrame::sizer_handler() 
{
	this->sizer_h->Add(this->info_panel, 1, wxLEFT | wxEXPAND, 1);
	this->sizer_h->Add(this->list_panel->sizer_v, 1, wxRIGHT | wxEXPAND, 1);
	this->m_parent->SetSizer(this->sizer_h);
	this->sizer_v->Add(this->m_parent, 2, wxEXPAND | wxALL, 10);
	this->sizer_v->Add(this->PokeButt, 0, wxCENTER, 10);
	this->sizer_v->Add(this->Evacuate, 0, wxCENTER, 10);
}


void MainFrame::update_info(wxCommandEvent& event)
{

	int sel = this->poke_list->GetSelection();
	int max = this->werehouse->strvec[sel].size() - 1;
	this->info_panel->poke_data = "";

	for (int i = 0; i < max; i++) {
		std::string text[] = { "Pokedex Number: ", "\nName: ", "\nGeneration: ", "\nType: ", " & " };
		this->info_panel->poke_data.append(text[i]);
		this->info_panel->poke_data.append(this->werehouse->strvec[sel][i + 1]);
	}

	this->info_panel->poke_info->SetLabel(this->info_panel->poke_data);
	this->info_panel->update_image(this->werehouse->strvec[sel][2]);
	
	this->info_panel->sizer_handler();
	this->SetSizer(this->sizer_v);
	this->Layout();
}


void MainFrame::poke_sound(wxCommandEvent& event)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 148);
	int file_index = dist(mt);
	wxSound* cries = new wxSound(info_panel->path + "\\Sounds\\*" + std::to_string(file_index)+".mp3");
	cries->Play();
}


void MainFrame::connector() 
{
	//Connect(13, wxEVT_COMMAND_BUTTON_CLICKED,
	//	wxCommandEventHandler(MainFrame::poke_sound));
	Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
		wxCommandEventHandler(MainFrame::update_info));
	Connect(11, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::update_info));
	Connect(12, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCloseEventHandler(MainFrame::on_quit));
}
