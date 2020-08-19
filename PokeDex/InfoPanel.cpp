#include "InfoPanel.h"
#include "MainFrame.h"

InfoPanel::InfoPanel( wxPanel* parent ) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1))
										//, MainFrame(this->title, this->pos, this->size)
{
	m_parent = parent;
	image = new wxStaticBitmap();
	poke_info = new wxStaticText(this,
		wxID_ANY,
		"text\ntext\ntext\ntext\ntext",
		wxDefaultPosition,
		wxDefaultSize,
		wxALIGN_CENTRE_HORIZONTAL);
	poke_info->SetLabel("DoubleClick on pokemon name \nor\n Select pokemon and click \n\"Choose\" button");

	//sizer_h = new wxBoxSizer(wxHORIZONTAL);
	sizer_v = new wxBoxSizer(wxVERTICAL);

	sizer_handler();
	pointer_handler();
}


void InfoPanel::update_info(wxCommandEvent& event)
{
	main_frame = (MainFrame*)m_parent->GetParent();

	int sel = main_frame->poke_list->GetSelection();
	int max = main_frame->werehouse->strvec[sel].size() - 1;
	this->poke_data = "";
	for (int i = 0; i < max; i++) {
		std::string text[] = { "Pokedex Number: ", "\nName: ", "\nGeneration: ", "\nType: ", " & " };
		this->poke_data.append(text[i]);
		this->poke_data.append(main_frame->werehouse->strvec[sel][i + 1]);
	}
	
	update_image(main_frame->werehouse->strvec[sel][2]);
	this->poke_info->SetLabel(this->poke_data);
}


void InfoPanel::pointer_handler()
{
	this->SetSizer(this->sizer_v);
	//this->Layout();
}


wxBitmap InfoPanel::get_image(std::string pokemon_name)
{
	wxString poke_path = (this->path + "\\Images\\" + pokemon_name + ".png");
	wxImage poke_image;

	if (wxFile::Exists(poke_path))
	{
		wxMessageBox("File exists at location " + poke_path);
		poke_image.LoadFile(poke_path);
		wxBitmap poke_bitmap(poke_image, wxBITMAP_TYPE_PNG);
		return poke_image;
	}
	else
	{
		wxMessageBox("File not occure at " + poke_path);
		return poke_image;
	}
}

void InfoPanel::sizer_handler()
{
	//this->sizer_h->Add(this->poke_info, 1, wxEXPAND | wxALL, 1);
	this->sizer_v->Add(this->poke_info, 1, wxEXPAND | wxALL);
}

void InfoPanel::update_image(std::string pokemon_name)
{
	image = new wxStaticBitmap(this, wxID_ANY, this->get_image(pokemon_name) );
}

InfoPanel::~InfoPanel() {
}
