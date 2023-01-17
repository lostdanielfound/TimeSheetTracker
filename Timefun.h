#ifndef PRO_MACROS
#define PRO_MACROS 

#define ENTRY_DATABASE "TIME_DATABASE"
#define CLOSE_FILE if (f_handle != NULL) { fclose(f_handle); }
#define FILE_APPEND_ERROR -5
#define FILE_READ_ERROR -6
#define INVAILD_INPUT -7
#endif //end PRO_MACROS

#ifndef TIMEFUN_H
#define TIMEFUN_H
#include <stdio.h>
#include <time.h>

int Time_Add(const time_t current_time);
double Time_Output(const double seconds_sum); 

#endif //end TIMEFUN_H