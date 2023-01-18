/* ---Hour Logging system---
 * Author: Daniel Guzman
 * Version: Alpha 0.2v
 * 
 * DISCLAMER: ANYONE RECERVES THE RIGHT TO USE THIS APPLICATION 
 * ACCORDING TO PUBLIC USES.
 * 
 * Main program that controls the logging system.
 * 
 * Author note: Current version is not ready
 * */

/*TODO:
- ensure if user exits with ctrl-C, the heap is freed
- Finish create_new_user() and test it
- Test database file as well. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // refer to man signal or https://en.cppreference.com/w/c/program/signal
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include "Clock.h"
#include "Time_Functions.h" 
#include "cursorSelection.h"

int main(void) {

	int choice;
	char* current_clockin_user = NULL; 
	char* default_options[3] = {"Create New User", "Clock-In User", "Show TimeSheet"};
	char* LoggedIn_options[3] = {"Create New User", "Clock-Out User", "Show TimeSheet"};
	
	while(1)
	{
		if (current_clockin_user != NULL) //THIS MAKES LITERALLY NO SENCE, BRUH i NEED TO CHANGE THIS 
		{
			choice = cursorSelection(LoggedIn_options, 3, "Time Logging System", current_clockin_user);
		}
		choice = cursorSelection(default_options, 3, "Time Logging System");

		swtich(choice)
		{
			case 0: //Create new User

				break; 
			case 1: //Clock-in User

				break; 
			case 2: //Clock-out User
				break; 
			case 3: //Show Timesheet
				break;
			default: 
				break;
		}
	}

	return 0;
}