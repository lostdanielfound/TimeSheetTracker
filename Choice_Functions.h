#ifndef CHOICE_FUN_H
#define CHOICE_FUN_H

/* These functions are used only to help display the options for the 
user interface through ncurses. Seperated functions that perform the manipulateing 
parsing of the TIME_DATEBASE are defined within Clock.h */

int Create_User_dialog();
int Clock_In_user();
int Clock_Out_user();
int Show_Timesheet();

#endif