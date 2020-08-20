#include "InfoPanel.h"
#include "MainFrame.h"


InfoPanel::InfoPanel( wxPanel* parent ) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1))
{
	this->m_parent = parent;
	this->image = new wxStaticBitmap();
	this->poke_info = new wxStaticText(this,
		wxID_ANY,
		"text\ntext\ntext\ntext\ntext",
		wxDefaultPosition,
		wxDefaultSize,
		wxALIGN_CENTRE_HORIZONTAL);
	this->poke_info->SetLabel("DoubleClick on pokemon name \nor\n Select pokemon and click \n\"Choose\" button");

	this->sizer_v = new wxBoxSizer(wxVERTICAL);

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
	this->main_frame = (MainFrame*)m_parent->GetParent();

	if (wxFile::Exists(poke_path))
	{
		poke_image.LoadFile(poke_path);
		poke_image.Rescale(96, 96, wxIMAGE_QUALITY_NEAREST);
		return poke_image;
	}
	else
	{
		wxMessageBox("File not occure at " + poke_path + "\n Probably name or file location is wrong");
		main_frame->on_quit();
		return poke_image;
	}
	delete(main_frame);
}


void InfoPanel::sizer_handler()
{
	this->sizer_v->Clear();
	this->sizer_v->Add(this->poke_info, 1, wxEXPAND | wxALL);
	this->sizer_v->Add(this->image, 1, wxCENTER | wxBOTTOM);
}


void InfoPanel::update_image(std::string pokemon_name)
{	
	delete(this->image);
	this->image = new wxStaticBitmap(this, wxID_ANY, this->get_image(pokemon_name) );
}
