//#include "pollRateCalculator.c"
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

void update_screen(int *previous_width, int *previous_height, WINDOW *heading_win, WINDOW *output_win);
void screen_resize(WINDOW *heading_win, WINDOW *output_win);
WINDOW *create_window(int height, int width, int starty, int startx);
void destroy_window(WINDOW *local_win);

#define MAX_RPM 1000

int main() {

	initscr();
//	raw();
	char ch;
	WINDOW *heading_win = NULL;
	WINDOW *output_win = NULL;
	int *prev_width = calloc(1, sizeof(int));
	int *prev_height = calloc(1, sizeof(int));
	int cycle = 0;

	while(cycle <= 500) {
		update_screen(prev_width, prev_height, heading_win, output_win);
		napms(1000);
		printf("Cycle %d complete, looping\n", cycle);
		cycle++;
	}

	sleep(1);
	endwin();
	return 0;

}

void update_screen(int *previous_width, int *previous_height, WINDOW *heading_win, WINDOW *output_win) {
	// Check if screen size has changed
	int current_width, current_height;
	getmaxyx(stdscr, current_height, current_width);
	printf("%d %d", current_width, current_height);
	if (current_width != *previous_width || current_height != *previous_height) {
		printf("Resize!\n");
		screen_resize(heading_win, output_win);
		*previous_width = current_width;
		*previous_height = current_height;
	}

//	mvwprintw(heading_win, "This is a test!");
//	wrefresh(heading_win);
	sleep(1);
	return;

}

void screen_resize(WINDOW *heading_win, WINDOW *output_win) {
	WINDOW *temp_win;

	werase(heading_win);
	werase(output_win);
	temp_win = heading_win;
	heading_win = create_window(3, COLS, 0, 0);
	if(temp_win != NULL) destroy_window(temp_win);

	temp_win = output_win;
	output_win = create_window(10, COLS, 3, 0);
	if(temp_win != NULL) destroy_window(temp_win);
	return;
}

WINDOW *create_window(int height, int width, int starty, int startx) {
	WINDOW *new_window = newwin(height, width, starty, startx);
	box(new_window, 0, 0);
	wrefresh(new_window);
	return new_window;
}

void destroy_window(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
	return;
}
