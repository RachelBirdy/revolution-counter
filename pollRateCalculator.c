#include <math.h>
#include <stdio.h>

#define PINGS_PER_REVOLUTION 500

int calculatePollRate(int maxRPM) {
	int microsecondsPerRev = (60000000 / maxRPM); // The number of microseconds each revolution takes
	int microsecondsBetweenPolls = microsecondsPerRev / 500;
	return microsecondsBetweenPolls;
}
