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

void CtlC_switch(char** usernames) { free(usernames); exit(0); }

int main(void) {

	//Variables that are created at the beginning of Runtime
	//NOTE, any variables that are considered LARGE in C standard should 
	//be created here instead of being created within another function
	//to prevent overusage of heap memory.
	//(Bruh don't use so much memory, this is C)
	//-----------------------------------------------------------------------------------	
	int choice = 0;
	int res;
	char** usernames = (char**)calloc(MAX_CLOCKED_IN, USERNAME_MAX); //array of strings that hold the current the names of the clocked-in users
	char* default_options[4] = {"Create New User", "Clock-In User", "Clock-Out User", "Show TimeSheet"};
	//-----------------------------------------------------------------------------------	


	//Signal defines will be placed here	
	//-----------------------------------------------------------------------------------	
	signal(SIGINT, CtlC_switch);
	//-----------------------------------------------------------------------------------	

	while(1) 	
	{
		//First want to check which users are currently Clocked-In
		ListClockedIn(usernames);

		//Displays a list of choices that the user can choose from, will also display the
		//current users that are clocked-in 
		choice = cursorSelection(default_options, 4, "Hour Logging System", usernames); 

		switch(choice) 
		{
		case 0: //Create new User
			res = Create_New_user() //Creates a new WINDOW to allow the user to enter the username for new user
			break; 
		case 1: //Clock-in User
			res = Clock_In()
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