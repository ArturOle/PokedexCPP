#include "InfoPanel.h"
#include "MainFrame.h"


InfoPanel::InfoPanel( wxPanel* parent ) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1))
{
	this->m_parent = parent;
	this->image = new wxBitmapButton();
	this->poke_info = new wxStaticText(this,
		wxID_ANY,
		"text\ntext\ntext\ntext\ntext",
		wxDefaultPosition,
		wxDefaultSize,
		wxALIGN_CENTRE_HORIZONTAL);
	this->poke_info->SetLabel("DoubleClick on pokemon name \nor\n Select pokemon and click \n\"Choose\" button");

	this->sizer_v = new wxBoxSizer(wxVERTICAL);

	connector();
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
		poke_image.LoadFile(this->path + "\\Images\\Mew.png");
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
	this->image = new wxBitmapButton(this, 13, this->get_image(pokemon_name));
	this->image->SetBackgroundColour(wxColor(*wxRED));
	this->image->SetWindowStyle(wxBORDER_DEFAULT);
}


void InfoPanel::poke_sound(wxCommandEvent& event)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 51);
	int file_index = dist(mt);
	std::string file_name = std::to_string(file_index);
	int i = file_name.size();

	while ( i < 3 ) {
		file_name = "0" + file_name;
		i = file_name.size();
	}
	wxSound* cries = new wxSound(this->path + "\\Sounds\\" + file_name + ".wav", false);
	std::string bolea = std::to_string(cries->IsOk());
	cries->Play(wxSOUND_ASYNC);
	delete(cries);
}


void InfoPanel::connector()
{
	Connect(13, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(InfoPanel::poke_sound));
}