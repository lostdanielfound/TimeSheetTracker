#ifndef PRO_MACROS
#define PRO_MACROS 

#define ENTRY_DATABASE "TIME_DATABASE"
#define MAX_CLOCKED_IN 50
#define USERNAME_MAX 30
#define CLOSE_FILE if (f_handle != NULL) { fclose(f_handle); }
#define FILE_APPEND_ERROR -5
#define FILE_READ_ERROR -6
#define INVAILD_INPUT -7
#endif //end PRO_MACROS

#ifndef CLOCK_H
#define CLOCK_H
#include <stdio.h>
#include <time.h>

/**
 * @brief 
 * These are generic header functions that can be used to attempt to 
 * read/change/create the TIME_DATABASE file. 
 */

int Create_New_user(const char* name);
int Clock_In(const char* user_name);
int Clock_Out(const char* user_name);
char** ListClockedIn(char**);

#endif //end CLOCK_H