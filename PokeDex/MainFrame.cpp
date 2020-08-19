#include "MainFrame.h"


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
		  :wxFrame(NULL, wxID_ANY, title, pos, size)
{
	//InfoPanel* info_parent = new InfoPanel(this);
	//werehouse = new WereHouse;
	m_parent = new wxPanel(this, wxID_ANY);
	sizer_h = new wxBoxSizer(wxHORIZONTAL);
	//sizer_info = new wxBoxSizer(wxHORIZONTAL);
	sizer_v = new wxBoxSizer(wxVERTICAL);

	list_panel = new ListPanel(m_parent);
	info_panel = new InfoPanel(m_parent);

	//poke_info->SetLabel("DoubleClick on pokemon name \nor\n Select pokemon and click \n\"Choose\" button");

	PokeButt = new wxButton(this, 11, "Choose");
	Evacuate = new wxButton(this, 12, "EXIT");
	//poke_list = new wxListBox(this, 13, wxDefaultPosition, wxDefaultSize, 0, NULL);

	//std::vector<std::string> choice = choice_getter();
	//choice_parser(choice);
	connector();
	sizer_handler();
	pointer_handler();
}


void MainFrame::on_quit(wxCloseEvent& event) 
{
	//delete(info_panel);
	//delete(list_panel);
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
	this->sizer_h->Add(this->info_panel, 0, wxEXPAND | wxLEFT, 10);
	this->sizer_h->Add(this->list_panel, 0, wxEXPAND | wxRIGHT, 10);
	this->sizer_v->Add(this->sizer_h, 1, wxCENTER | wxEXPAND, 10);
	this->sizer_v->Add(this->PokeButt, 0, wxCENTER, 10);
	this->sizer_v->Add(this->Evacuate, 0, wxCENTER, 10);
}


void MainFrame::connector() 
{
	Connect(12, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCloseEventHandler(MainFrame::on_quit));
}
