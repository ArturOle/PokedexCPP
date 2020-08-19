#include "ListPanel.h"
#include "MainFrame.h"


ListPanel::ListPanel(wxPanel* parent) : wxPanel(parent, wxID_ANY)//, MainFrame(this->title, this->pos, this->size)
{
	m_parent = parent;

	poke_list = new wxListBox(m_parent, 13, wxDefaultPosition, wxDefaultSize, 0, NULL);

	sizer_h = new wxBoxSizer(wxHORIZONTAL);
	sizer_v = new wxBoxSizer(wxVERTICAL);

	std::vector<std::string> choice = choice_getter();
	choice_parser(choice);
	sizer_handler();
	//pointer_handler();
}


void ListPanel::pointer_handler()
{
	this->SetSizer(this->sizer_v);
	this->Layout();
}


void ListPanel::sizer_handler()
{
	this->sizer_h->Add(this->poke_list, 10, wxEXPAND, 0);
	this->sizer_v->Add(this->sizer_h, 10, wxCENTRE, 1);
}


std::vector<std::string> ListPanel::choice_getter()
{
	main_frame = (MainFrame*)m_parent->GetParent();
	this->choice.clear();
	for (auto& x : main_frame->werehouse->strvec)
		choice.push_back(x[2]);
	
	return choice;
}


void ListPanel::choice_parser(std::vector<std::string> choice)
{
	for (auto x : choice) {
		poke_list->AppendString(x);
	}
}

ListPanel::~ListPanel()
{
	choice.clear();
}
