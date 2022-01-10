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
#include <time.h>
#include "Clock.h"
#include "Timefun.h" 

int main(void) {

	printf("\n\n\t-------------------------------\n"); 
	printf("\t------Time Logging System------\n"); 
	printf("\t-------------------------------\n"); 

	int c; /* ASCII character input from STDIN */
	
	while(1) 
	{
		printf("\n\t1) Clock In\n"); 
		printf("\t2) Clock Out\n"); 
		printf("\t3) Review\n"); 
		printf("\t4) Add\n"); 
		printf("\t5) Delete\n"); 
		printf("\n\t6) Exit\n\t: ");

		do { c = getchar(); /* I should implement select() here... */ } while (isdigit(c) == 0); /* Keep lopping until user input's a number */  

		time_t current_time = time(NULL); /* Gather current system time */

		int status_code = 0; 
		switch (c) {
			case '1': status_code = Clock_In(current_time); break; 
			case '2': status_code = Clock_Out(current_time); break;
			case '3': status_code = Time_Review(current_time); break;
			case '4': status_code = Time_Add(current_time); break;
			case '5': status_code = Time_Delete(current_time); break;
			case '6': return 0; 
			default: return 0; 
		}

		printf("\n\t-------------------------------\n");

		/* If error occured, then report on stdio 
		( idk how to report on stderr ) */
		if (status_code < 0) { return status_code; }
	}
} 