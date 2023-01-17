#include <stdlib.h>
#include "Timefun.h"
#define SECONDS_PER_HOUR 3600

double Time_Output(const double seconds_sum) {
	return seconds_sum / SECONDS_PER_HOUR;
}

int Time_Add(const time_t current_time) {

}