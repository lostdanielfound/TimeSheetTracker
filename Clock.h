#ifndef PRO_MACROS
#define PRO_MACROS 

#define DATABASE "TIME_DATABASE"
#define MAX_CLOCKED_IN 50
#define USERS_MAX_SIZE 50
#define USERNAME_MAX_SIZE 256

#define CLOSE_FILE if (f_handle != NULL) { fclose(f_handle); }
#define FILE_OPEN_ERROR -3
#define FILE_WRITE_ERROR -4 
#define FILE_APPEND_ERROR -5
#define FILE_READ_ERROR -6
#define INVAILD_INPUT -7
#endif //end PRO_MACROS

#ifndef CLOCK_H
#define CLOCK_H
#include <stdbool.h>

/**
 * @brief Header file 
 * These are generic header functions that can be used to attempt to 
 * read/change/create the TIME_DATABASE file. 
 */

/** 
 * @brief Creates a new user slot within the TIME_DATEBASE file with the name at the beginning of the slot. 
 * This doesn't automaticly clock them in upon creation, and will fail under the following conditions. 
 * @exception name is not in the correct format, the size of the name must be at most 256 characters, 
 * must not include non-letter characters, the symbol "+", and numbers. 
 * @param name 
 * @return negative integer upon failure, 0 on success
 */
int Create_New_user(const char* name);

/** 
 * @brief Attempts to clock-in user given it's username. Time stamp of the current time is added to the 
 * username's time slot along with the clock-in symbol '+' placed at the end of the username. 
 * @param user_name 
 * @return negative integer if user_name doesn't exist, 0 on success on clocking-in. 
 */
int Clock_In(const char* user_name);

/** 
 * @brief Attempts to clock-out user given it's username Time stamp of the current time for clocking-out is added to the 
 * username's time slot along with the '+' being removed from the username. 
 * @param user_name 
 * @return negative integer if user_name doesn't exist or failed to clock-out, 0 on success on clocking-out.  
 */
int Clock_Out(const char* user_name);

/**
 * @brief Simply checks to see if the given file exists within the current directory of the application.
 * 
 * @param filename 
 * @return true if file exist, false if not 
 */
bool file_exists(char * filename);

/**
 * @brief Reads in all usernames from TIME_DATABASE file and fills buf with them. 
 * 
 * @warning Make sure to free buf after usage. 
 * @param buf, intialized with malloc beforehand
 * @return amount of usernames on success, -1 on failure 
 */
int read_usernames(char** buf);

/**
 * @brief Reads in usernames that are currently clocked-in from TIME_DATABASE file and fills buf with them. 
 *
 * @warning Make sure to free buf after usage.  
 * @param buf, intialized with malloc beforehand. 
 * @return amount of usernames on success, -1 on failure. 
 */
int read_clocked_in(char** buf);

/**
 * @brief Lists out usernames given and the size and buf 
 * @deprecated 
 * 
 * @param size 
 * @param buf 
 */
void list_usernames(int size, char** buf);

#endif //end CLOCK_H
