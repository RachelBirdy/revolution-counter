#include "pollRateCalculator.c"
#include <curses.h>

#define MAX_RPM 1000

int main() {
	calculatePollRate(MAX_RPM);
	return 0;

}
