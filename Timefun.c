#include <stdlib.h>
#include "Timefun.h"
#define SECONDS_PER_HOUR 3600

double Time_Output(const double seconds_sum) {
	return seconds_sum / SECONDS_PER_HOUR;
}

int Time_Review(const time_t current_time) {
    	
	FILE *f_handle = fopen(ENTRY_DATABASE, "r");

	if (f_handle == NULL) { /* Could not open/obtain file handle */
		printf("\tTime sheet has not been created yet!\n\tPlease Clock in to start a Time sheet\n");
		return FILE_READ_ERROR; 
	}

	if (fseek(f_handle, 0L, SEEK_SET) < 0) { /* Error in seeking file */
		printf("\tFile scanning Error\n");
		return FILE_READ_ERROR;
	}

	time_t t1, t2; //time entry stamps when scanning the file
	double seconds_sum; //sum of all the second collect from diff t1 and t2

	while(!feof(f_handle)) { /* while we are not EOF, keep scanning  */
		fscanf(f_handle, "IN %ld\n", &t1);
		if (feof(f_handle)) { break; } //if the user hasn't clocked out from last IN then don't record 
		fscanf(f_handle, "OUT %ld\n", &t2);
		seconds_sum += difftime(t2, t1);
	}

	printf("\tThe total amount of hours: %.5lf\n", Time_Output(seconds_sum));

	CLOSE_FILE

	return 0; 
}

int Time_Add(const time_t current_time) {
	
	FILE *f_handle = fopen(ENTRY_DATABASE, "a");

	if (f_handle == NULL) {
		printf("\tTime sheet has not been created yet!\n\tPlease Clock in to start a Time sheet\n"); 
		return FILE_APPEND_ERROR; 
	}

	CLOSE_FILE

	return 0;
}

int Time_Delete(const time_t current_time) {

	FILE *f_handle = fopen(ENTRY_DATABASE, "a");

	if (f_handle == NULL) {
		printf("File error"); 
		return FILE_APPEND_ERROR; 
	}

	CLOSE_FILE

	return 0;
}