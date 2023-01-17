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
	char* options[4] = {"Create New User", "Clock-In User", "Clock-Out User", "Show TimeSheet"};
	
	while(1)
	{
		choice = cursorSelection(options, 4, "Time Logging System");
	}

	return 0;
}