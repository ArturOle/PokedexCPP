#include "Frame.h"

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "PokeDex")
{

}

Frame::~Frame()
{

}

bool Frame::OnInit()
{
	main_panel = new MainPanel();
	main_panel->Show();
	pokedex_panel = new UserPoke();
	pokedex_panel->Hide();

	return true;
}