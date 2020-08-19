#include "ListPanel.h"
#include "MainFrame.h"


ListPanel::ListPanel(wxPanel* parent) : wxPanel(parent, wxID_ANY)//, MainFrame(this->title, this->pos, this->size)
{
	m_parent = parent;

	poke_list = new wxListBox(m_parent, 13, wxDefaultPosition, wxDefaultSize, 0, NULL);
	//sizer_h = new wxBoxSizer(wxHORIZONTAL);
	sizer_v = new wxBoxSizer(wxVERTICAL);

	std::vector<std::string> choice = choice_getter();
	choice_parser(choice);
	wxMessageBox(poke_list->GetString(2));
	//connector();
	sizer_handler();
	pointer_handler();
}


void ListPanel::pointer_handler()
{
	//this->SetSizer(this->sizer_v);
}


void ListPanel::sizer_handler()
{
	//this->sizer_h->Add(this->poke_list, 10, wxEXPAND, 0);
	this->sizer_v->Add(this->poke_list, 1, wxEXPAND);						
}

/*
void ListPanel::update_info(wxCommandEvent& event)
{
	main_frame = (MainFrame*)m_parent->GetParent();

	wxMessageBox(poke_list->GetString(69));

	int sel = poke_list->GetSelection();
	int max = main_frame->werehouse->strvec[sel].size() - 1;
	main_frame->info_panel->poke_data = "";
	for (int i = 0; i < max; i++) {
		std::string text[] = { "Pokedex Number: ", "\nName: ", "\nGeneration: ", "\nType: ", " & " };
		main_frame->info_panel->poke_data.append(text[i]);
		main_frame->info_panel->poke_data.append(main_frame->werehouse->strvec[sel][i + 1]);
	}

	main_frame->info_panel->update_image(main_frame->werehouse->strvec[sel][2]);
	main_frame->info_panel->poke_info->SetLabel(main_frame->info_panel->poke_data);
}

*/
std::vector<std::string> ListPanel::choice_getter()
{
	main_frame = (MainFrame*)m_parent->GetParent();
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
