#include "Timefun.h" 

int Time_Review(const time_t current_time) {
    	
	FILE *f_handle = fopen(ENTRY_DATABASE, "r");

	if (f_handle == NULL) {
		printf("\tTime sheet has not been created yet!\n\tPlease Clock in to start a Time sheet\n");
		return FILE_READ_ERROR; 
	}

	time_t time_entry; 

	fscanf(f_handle, "IN %ld\n", &time_entry);
	printf("\tTime is: %s\n", ctime(&time_entry));
	fscanf(f_handle, "OUT %ld\n", &time_entry);
	printf("\tTime is: %s\n", ctime(&time_entry));
	
	struct tm time_struct; 

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