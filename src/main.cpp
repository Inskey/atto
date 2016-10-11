#include <iostream>
#include <signal.h>

#include <curses.h>

using namespace std;


int 	r, c,
	trows, tcols,
	erows, ecols;

void read_loop();
void handle_exit(int signum);

int main()
{
	// handle ctrl-c
	struct sigaction interrupt;
	interrupt.sa_handler = handle_exit;
	interrupt.sa_flags = 0;
	sigemptyset(& interrupt.sa_mask);
	sigaction(SIGINT, &interrupt, NULL);

	WINDOW *wnd;

	wnd = initscr();
	start_color();
	cbreak();
	noecho();
	getmaxyx(wnd, trows, tcols);			// macro, not necessary to pass reference
	clear();
	refresh();

	r = 0; c = 0;
	move(r, c);
	while (1)
	{
		char d = getch();
		
	}

	endwin();
}

void read_loop()
{
	
}

void handle_exit(int signum)
{
	//if (file.is_modified())
	//{
	//	
	endwin();
	exit(0);
}
