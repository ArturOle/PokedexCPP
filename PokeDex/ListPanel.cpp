#include "ListPanel.h"
#include "MainFrame.h"


ListPanel::ListPanel(wxPanel* parent) : wxPanel(parent, wxID_ANY)
{
	m_parent = parent;

	this->poke_list = new wxListBox(m_parent, 13, wxDefaultPosition, wxDefaultSize, 0, NULL);
	this->sizer_v = new wxBoxSizer(wxVERTICAL);

	std::vector<std::string> choice = choice_getter();
	choice_parser(choice);
	sizer_handler();

}


void ListPanel::sizer_handler()
{
	this->sizer_v->Add(this->poke_list, 1, wxEXPAND);						
}


std::vector<std::string> ListPanel::choice_getter()
{
	this->main_frame = (MainFrame*)m_parent->GetParent();
	for (auto& x : main_frame->werehouse->strvec)
		choice.push_back(x[2]);
	
	return choice;
}


void ListPanel::choice_parser(std::vector<std::string> choice)
{
	for (auto x : choice) {
		this->poke_list->AppendString(x);
	}
}
