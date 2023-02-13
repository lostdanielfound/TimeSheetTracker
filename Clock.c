#include "Clock.h"

/**
* @purpose: Creates a new user within the Datebase file TIME_DATABASE. 
*     simplly adds {USER_NAME} within the file and intializes it. 
* @return 0 if the new user has been created and negative integer if error occured. 
*/
int Create_New_user(const char* name) {
    FILE *f_handle = fopen(ENTRY_DATABASE, "r");
    time_t current_time = time(NULL);
    if (f_handle == NULL)
    {
        printf("\tFile error: Could not open for reading\n");
        return FILE_READ_ERROR;
    }

    CLOSE_FILE
}

/**
* @purpose: Attempts Clocks in the user that is passed-in
* @return: On success 0 is return, negative error code when failure, refer to 
* program_macros for error codes.   
*/
int Clock_In(const char* user_name) {
    FILE *f_handle = fopen(ENTRY_DATABASE, "r");
    time_t current_time = time(NULL);
    if (f_handle == NULL)
    {
        printf("\tFile error: Could not open for reading\n");
        return FILE_READ_ERROR;
    }

    CLOSE_FILE
}

/**
* @purpose: Attempts Clock out the user that is passed-in
* @return: returns 0 on success, negative error code if failure, please see
* Program_macros for error codes 
*/
int Clock_Out(const char* user_name) {
    FILE *f_handle = fopen(ENTRY_DATABASE, "r");
    time_t current_time = time(NULL);
    if (f_handle == NULL) 
    {
        printf("\tFile error: Could not open for reading\n");
        return FILE_READ_ERROR;
    }

    CLOSE_FILE
}
