#include <curses.h>
#include <stdlib.h>
#include "create_window.h"

#define TITLE "Rachel's "
#define TARGET_COUNT "Target winding count:\t"
#define CURRENT_COUNT "Current winding count:\t"

WINDOW **draw_screen() {
        WINDOW *heading_win = create_window(3, 50, 0, 0);
        WINDOW *output_win = create_window(7, 50, 3, 0);
        WINDOW **local_windows = malloc(sizeof(WINDOW *)*2);
        local_windows[0] = heading_win;
        local_windows[1] = output_win;
        mvwprintw(heading_win, 1, 1, TITLE);
        wrefresh(heading_win);
        mvwprintw(output_win, 1, 1, TARGET_COUNT);
        mvwprintw(output_win, 2, 1, CURRENT_COUNT);
        wrefresh(output_win);
        return local_windows;
}
