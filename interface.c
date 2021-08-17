//#include "pollRateCalculator.c"
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TITLE "Rachel's "
#define TARGET_COUNT "Target winding count:\t"
#define CURRENT_COUNT "Current winding count:\t"

void draw_screen(WINDOW *heading_win, WINDOW *output_win);
void update_screen(int *previous_width, int *previous_height, WINDOW *heading_win, WINDOW *output_win);
void screen_resize(WINDOW *heading_win, WINDOW *output_win);
WINDOW *create_window(int height, int width, int starty, int startx);
void destroy_window(WINDOW *local_win);

#define MAX_RPM 1000

int main() {
	int titleLength = strlen(TITLE);
	int targetLength = strlen(TARGET_COUNT);
	int currentLength = strlen(CURRENT_COUNT);


	initscr();
//	raw();
	char ch;
	WINDOW *heading_win = create_window(3, 50, 0, 0);
	WINDOW *output_win = create_window(7, 50, 3, 0);
	draw_screen(heading_win, output_win);

	mvwprintw(output_win, 1, targetLength + 1, "10");
	int cycle = 0;

	while(cycle <= 10) {
		mvwprintw(output_win, 2, currentLength + 1, "%d", cycle);
		wrefresh(output_win);
		napms(100);
		cycle++;
	}

	sleep(1);
	endwin();
	return 0;

}

void draw_screen(WINDOW *heading_win, WINDOW *output_win) {
//	heading_win = create_window(3, 50, 0, 0);
//      output_win = create_window(7, 50, 3, 0);
	mvwprintw(heading_win, 1, 1, TITLE);
	wrefresh(heading_win);
	mvwprintw(output_win, 1, 1, TARGET_COUNT);
	mvwprintw(output_win, 2, 1, CURRENT_COUNT);
	wrefresh(output_win);

}

WINDOW *create_window(int height, int width, int starty, int startx) {
	WINDOW *new_window = newwin(height, width, starty, startx);
	box(new_window, 0, 0);
	wrefresh(new_window);
	return new_window;
}
