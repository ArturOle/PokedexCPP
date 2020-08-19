#include "InfoPanel.h"
#include "MainFrame.h"

InfoPanel::InfoPanel( wxPanel* parent ) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1))
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

	sizer_v = new wxBoxSizer(wxVERTICAL);

	sizer_handler();
	pointer_handler();
}

void InfoPanel::pointer_handler()
{
	this->SetSizer(this->sizer_v);
}


wxBitmap InfoPanel::get_image(std::string pokemon_name)
{
	wxString poke_path = (this->path + "\\Images\\" + pokemon_name + ".png");
	wxImage poke_image;

	if (wxFile::Exists(poke_path))
	{
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
	this->sizer_v->Clear();
	//this->sizer_h->Add(this->poke_info, 1, wxEXPAND | wxALL, 1);
	this->sizer_v->Add(this->poke_info, 1, wxEXPAND | wxALL);
	this->sizer_v->Add(this->image, 1, wxCENTER | wxBOTTOM);
}

void InfoPanel::update_image(std::string pokemon_name)
{
	image = new wxStaticBitmap(this, wxID_ANY, this->get_image(pokemon_name) );
}
