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

#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>
#include <time.h>
#include "Clock.h"
#include "Timefun.h" 
#include "cursorSelection.h"

int main(void) {

	int choice;
	char* Logout_options[4] = {"Create New User", "Clock-In User", "Clock-Out User", "Show TimeSheet"};
	char* LoggedIn_options[3] = {"Create New User", "Clock-Out User", "Show TimeSheet"};
	
	while(1)
	{
		if (LOGGEDIN) 
		{
			choice = cursorSelection(LoggedIn_options, 3, "Time Logging System");
		}
		else 
		{
			choice = cursorSelection(Logout_options, 4, "Time Logging System");
		}

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