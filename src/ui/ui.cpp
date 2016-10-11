#include <string.h>
#include <iostream>

#include <curses.h>

//#include "colors.h"
#include "ui.h"
//#include "../project.h"

using namespace std;


atto_ui::atto_ui()
{
	wnd = initsrc();
	cbreak();
	noecho();
	getmaxyx(wnd, cols, rows);
	//cout << cols << " " << rows << endl; // DEBUG
	clear();

	//colors.init_colors();

	//project = proj;
	tb.reset(new titlebar);
	ed.reset(new editor);
	ib.reset(new infobar);
	hb.reset(new helpbar);
	fm.reset(new filemenu);
}

atto_ui::~atto_ui()
{
	delete project;
}

void atto_ui::input_char(char c)
{
	ed->input(c);
}

void atto_ui::backspace()
{
	ed->backspace();
}

void atto_ui::del()
{
	ed->del();
}

/*void atto_ui::load_file(const string * const name, vector<string> contents, bool writable)
{
	tb->new_file(name, writable);
	ed->new_file(name, contents);
}*/
