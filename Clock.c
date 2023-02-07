#include "Clock.h"

/**
* @purpose: Creates a new user within the Datebase file TIME_DATABASE. 
*     simplly adds {USER_NAME} within the file and intializes it. 
* @return 0 if the new user has been created and negative integer if error occured. 
*/
int Create_New_user(const char* name) {
    FILE *f_handle = fopen(ENTRY_DATABASE, "a+"); // Opens file in APPEND EXTENDED mode 

    if (f_handle == NULL) //File could not be access 
    {
        perror("\tFile error: Could not open for reading\n");
        return -1;
    }

    fputs(name, f_handle); //append the new user

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

    /* Check to make sure that the user hasn't
    already clocked in, if the line before the 
    entry isn't an "OUT" then inform the user. */

    fseek(f_handle, -15L, SEEK_END); //Seek to the end of the file then back 17 bytes 
    
    char c; 
    fread(&c, sizeof(char), sizeof(char), f_handle);

    if (c == 'I')
    {
        /* User has already clocked in
        and thus can't do it twice in the row. */

        printf("\tInvaild Choice: Cannot clock out twice...\n");
        return INVAILD_INPUT;
    }

    //If all goes well, we can now append to the file
    fclose(f_handle);

    if ((f_handle = fopen(ENTRY_DATABASE, "a")) == NULL) {
        printf("\tFile error: Could not open for appending\n");
        return FILE_APPEND_ERROR;
    }

    fprintf(f_handle, "IN %ld\n", current_time); 
    printf("\tClocked In at %s", ctime(&current_time));

    CLOSE_FILE

    return 0;
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


    /* Check to make sure that the user hasn't 
    already clock out, if the line before the 
    entry isn't an "IN" then inform the User */
    fseek(f_handle, -16L, SEEK_END); //Seek to the end of the file then back 17 bytes 

    char c; 
    fread(&c, sizeof(char), sizeof(char), f_handle); //Finally read in one char from cursor position

    if (c == 'O')
    {
        /* User has already clocked out 
        and thus can't do it twice in the row. */
        printf("\tInvaild Choice: Cannot clock out twice...\n");
        return INVAILD_INPUT;
    }

    //If all goes well, we can now append to the file
    fclose(f_handle);
    
    if ((f_handle = fopen(ENTRY_DATABASE, "a")) == NULL) //open for appending
    {
        printf("\tFile error: Could not open for appending\n");
        return FILE_APPEND_ERROR; 
    }

    fprintf(f_handle, "OUT %ld\n", current_time);
    printf("\tClocked Out at %s", ctime(&current_time));

    CLOSE_FILE

    return 0;
}
