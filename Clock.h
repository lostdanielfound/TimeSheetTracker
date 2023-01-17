#ifndef PRO_MACROS
#define PRO_MACROS 

#define ENTRY_DATABASE "TIME_DATABASE"
#define CLOSE_FILE if (f_handle != NULL) { fclose(f_handle); }
#define FILE_APPEND_ERROR -5
#define FILE_READ_ERROR -6
#define INVAILD_INPUT -7
#endif //end PRO_MACROS

#ifndef CLOCK_H
#define CLOCK_H
#include <stdio.h>
#include <time.h>

int Clock_In(const time_t current_time);
int Clock_Out(const time_t current_time);

#endif //end CLOCK_H