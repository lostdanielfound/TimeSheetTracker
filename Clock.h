#ifndef PRO_MACROS
#define PRO_MACROS 

#define ENTRY_DATABASE "TIME_DATABASE"
#define LOGGEDIN 1
#define CLOSE_FILE if (f_handle != NULL) { fclose(f_handle); }
#define FILE_APPEND_ERROR -5
#define FILE_READ_ERROR -6
#define INVAILD_INPUT -7
#endif //end PRO_MACROS

#ifndef CLOCK_H
#define CLOCK_H
#include <stdio.h>
#include <time.h>

int Create_New_user(const char* name);
int Clock_In(const char* user_name);
int Clock_Out(const char* user_name);

#endif //end CLOCK_H