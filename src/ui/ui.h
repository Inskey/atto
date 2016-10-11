#include <string.h>
#include <vector>

#include <curses.h>

//#include "../project.h"


enum class cursor_move : int8_t
{
	UP, DOWN, LEFT, RIGHT,
	HOME, END,
	PGUP, PGDN
}

class atto_ui
{
	WINDOW *wnd;
	int rows, cols;
	//struct atto_project * project;
	unique_ptr<titlebar>	tb;
	unique_ptr<editor>	ed;
	unique_ptr<infobar>	ib;
	unique_ptr<helpbar>	hb;
	unique_ptr<filemenu>	fm;

	public:
		atto_ui();
		~atto_ui();

		void input_char(char c); // also changes titlebar (modified marker)
		void load_project(const atto_project * const proj); // also changes titlebar (project name)
		void load_file(const atto_file * const file); // also changes titlebar (writable status, file name)
		vector<string> get_editor_contents();
		void move_cursor(cursor_move where); // arrow keys + home/end + pgup/pgdn
		//void jump_cursor(int line, int col);
		//vector<char> get_line();
		//void del_line();
		// TO DO: cut and paste

		void display_message(string message);

		//const atto_file * const get_selected_file();
		//void menu_up();
		//void menu_dn();
}
