#include "Clock.h"

int Clock_In(const time_t current_time) {
    FILE *f_handle = fopen(ENTRY_DATABASE, "r");

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

int Clock_Out(const time_t current_time) {
    FILE *f_handle = fopen(ENTRY_DATABASE, "r");

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