#include "MainFrame.h"



MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL, wxID_ANY, title, pos, size)
{
	//InfoPanel* info_parent = new InfoPanel(this);
	//werehouse = new WereHouse;
	m_parent = new wxPanel(this, wxID_ANY);

	sizer_h1 = new wxBoxSizer(wxHORIZONTAL);
	sizer_h2 = new wxBoxSizer(wxHORIZONTAL);
	
	sizer_h = new wxBoxSizer(wxHORIZONTAL);
	sizer_v = new wxBoxSizer(wxVERTICAL);

	list_panel = new ListPanel(m_parent);
	info_panel = new InfoPanel(m_parent);

	poke_list = list_panel->poke_list;

	sizer_h->Add(info_panel, 1,  wxLEFT, 1);
	sizer_h->Add(list_panel->sizer_v, 1,  wxRIGHT | wxBOTTOM | wxEXPAND, 1);

	m_parent->SetSizer(sizer_h);
	//m_parent->Layout();

	PokeButt = new wxButton(this, 11, "Choose");
	Evacuate = new wxButton(this, 12, "EXIT");
	connector();
	sizer_handler();
	pointer_handler();
}

void MainFrame::on_quit(wxCloseEvent& event) 
{
	delete(werehouse);
	wxWindow::Close();
}


void MainFrame::pointer_handler() 
{
	this->SetBackgroundColour(wxColor(*wxRED));
	this->SetSizer(this->sizer_v);
	this->Layout();
}

void MainFrame::sizer_handler() 
{
	//this->sizer_h->Add(this->m_parent, 1, wxEXPAND);
	//this->sizer_h->Add(this->list_panel->sizer_h, 1, wxEXPAND | wxRIGHT, 10);
	this->sizer_v->Add(this->m_parent, 2, wxEXPAND | wxALL, 10);
	this->sizer_v->Add(this->PokeButt, 0, wxCENTER, 10);
	this->sizer_v->Add(this->Evacuate, 0, wxCENTER, 10);
}


void MainFrame::update_info(wxCommandEvent& event)
{
	wxMessageBox(list_panel->poke_list->GetString(69));

	int sel = poke_list->GetSelection();
	int max = werehouse->strvec[sel].size() - 1;
	info_panel->poke_data = "";
	for (int i = 0; i < max; i++) {
		std::string text[] = { "Pokedex Number: ", "\nName: ", "\nGeneration: ", "\nType: ", " & " };
		info_panel->poke_data.append(text[i]);
		info_panel->poke_data.append(werehouse->strvec[sel][i + 1]);
	}

	info_panel->update_image(werehouse->strvec[sel][2]);
	info_panel->poke_info->SetLabel(info_panel->poke_data);
}


void MainFrame::connector() 
{
	Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
		wxCommandEventHandler(MainFrame::update_info));
	Connect(11, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::update_info));
	Connect(12, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCloseEventHandler(MainFrame::on_quit));
}
