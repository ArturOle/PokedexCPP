#pragma once

#include "wx/wx.h"
#include "UserPoke.h"
#include "MainPanel.h"


class Frame: public wxFrame
{
public:
	Frame();

	~Frame();

private:
	MainPanel* main_panel = nullptr;
	UserPoke* pokedex_panel = nullptr;

public:
	virtual bool OnInit();
};

