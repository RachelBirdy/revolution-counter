#include <curses.h>

WINDOW *create_window(int height, int width, int starty, int startx) {
        WINDOW *new_window = newwin(height, width, starty, startx);
        box(new_window, 0, 0);
        wrefresh(new_window);
        return new_window;
}
