#include <curses.h>

#include "colors.h"

using namespace std;


static void colors::init_colors()
{
	start_color();

	for (uint8_t fg = 0; fg < 8; fg++)
	{
		for (uint8_t bg = 0; bg < 8; bg++)
		{
			init_pair(fg & (bg * 8), fg, bg);
		}
	}
}

static void colors::set_current_style(style s)
{
	if (s.bright)
	{
		attron(A_BOLD);
	}
	else
	{
		attroff(A_BOLD);
	}
	attron(COLOR_PAIR(s.fg & (s.bg * 8)));
}
