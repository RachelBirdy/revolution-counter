#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "draw_interface.h"

#define TITLE "Rachel's Incredible Pickup Winder!"
#define TARGET_COUNT "Target winding count:\t"
#define CURRENT_COUNT "Current winding count:\t"
#define COUNTS_PER_MINUTE "Current RPM: \t"

#define MAX_RPM 1000

int main(int argc, char *argv[]) {
	int titleLength = strlen(TITLE);
	int targetLength = strlen(TARGET_COUNT);
	int currentLength = strlen(CURRENT_COUNT);
	int rpmLength = strlen(COUNTS_PER_MINUTE);
	char *targetCount;
	if (argc > 1) {
		sprintf(targetCount, "%s", argv[1]);
	} else {
		sprintf(targetCount, "N/A");
	}


	initscr();
//	raw();
	char ch;
	WINDOW **local_windows = draw_screen();
	WINDOW *heading_win = local_windows[0];
	WINDOW *output_win = local_windows[1];

	mvwprintw(output_win, 1, targetLength + 1, "%s", targetCount);
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
