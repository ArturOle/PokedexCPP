#include "main.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
	wxInitAllImageHandlers();
	MainFrame* frame = new MainFrame("PokeDex", wxPoint(20, 30), wxSize(450, 340));
	frame->Show();
	return true;
}