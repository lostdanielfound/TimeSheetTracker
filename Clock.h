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
 * @brief Header file 
 * These are generic header functions that can be used to attempt to 
 * read/change/create the TIME_DATABASE file. 
 */

/// @brief Creates a new user slot within the TIME_DATEBASE file with the name at the beginning of the slot. 
/// This doesn't automaticly clock them in upon creation, and will fail under the following conditions. 
/// @exception name is not in the correct format, the size of the name must be at most 256 characters, 
/// must not include non-letter characters, the symbol "+", and numbers. 
/// @param name 
/// @return negative integer upon failure, 0 on success
int Create_New_user(const char* name);

/// @brief Attempts to clock-in user given it's username. Time stamp of the current time is added to the 
/// username's time slot along with the clock-in symbol '+' placed at the end of the username. 
/// @param user_name 
/// @return negative integer if user_name doesn't exist, 0 on success on clocking-in. 
int Clock_In(const char* user_name);

/// @brief Attempts to clock-out user given it's username Time stamp of the current time for clocking-out is added to the 
/// username's time slot along with the '+' being removed from the username. 
/// @param user_name 
/// @return negative integer if user_name doesn't exist or failed to clock-out, 0 on success on clocking-out.  
int Clock_Out(const char* user_name);

#endif //end CLOCK_H
