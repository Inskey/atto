#include <string.h>

#include <curses.h>


class titlebar
{
	string atto_version;
	string project_name;
	string file_name;
	bool modified;
	bool writable;

	public:
		titlebar(string version);

		void draw();

		void file_loaded(const atto_file * const file);
		void file_modified();
		void project_loaded(string proj_name);
}

