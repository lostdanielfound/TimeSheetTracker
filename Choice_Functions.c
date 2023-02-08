#include "Choice_Functions.h"
#include <ncurses.h>

/* These functions are used only to help display the options for the 
user interface through ncurses. Seperated functions that perform the manipulateing 
parsing of the TIME_DATEBASE are defined within Clock.h */

/**
 * @brief 
 * Shows user a dialog on creating the new user that they want to add to the database, 
 * Uses ncurses to provide a clean User interface 
 * @return 0 if User creation was a success, on error will return a negative error code, 
 * refer to program_macros for list of error codes 
 */
int Create_User_dialog() {

}

int Clock_In_user();
int Clock_Out_user();
int Show_Timesheet();
