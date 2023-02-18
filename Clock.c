#include "Clock.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/stat.h>

int Create_New_user(const char* name) {
    FILE *f_handle = fopen(DATABASE, "a");

    if (f_handle == NULL)
    {
        perror("File error: Could not open for appending\n");
        CLOSE_FILE
        return FILE_OPEN_ERROR;
    }

    /**
     * Check string to ensure it follows format
     * - Size is at most 256 characters
     * - Does not include non-letter characters 
     * - Can't include "+" and numbers
     */
    if ((strchr(name, '+') != NULL) || strpbrk(name, "0123456789")) 
    {
        perror("Error: New name can't have the '+' symbol or have any digits\n");
        CLOSE_FILE
        return FILE_APPEND_ERROR;
    }
    else if (strlen(name) > 256)
    {
        perror("Error: New name can't be over 256 in length\n");
        CLOSE_FILE
        return FILE_APPEND_ERROR;
    }


    /* Write the new user's name at the file */
    if (fwrite(name, sizeof(char), strlen(name), f_handle) < strlen(name))
    {
        perror("File Error: Username was written incorrectly, aborting\n");
        CLOSE_FILE
        return FILE_APPEND_ERROR;
    }

    CLOSE_FILE
    return EXIT_SUCCESS;
}

int Clock_In(const char* user_name) {
    FILE *f_handle = fopen(DATABASE, "r+");
    time_t current_time = time(NULL); //Get upmost current time when calling function

    if (f_handle == NULL)
    {
        printf("\tFile error: Could not open for writing\n");
        return FILE_OPEN_ERROR;
    }

    /* Search for the username within the file */
    char buffer[USERNAME_MAX_SIZE];
    while (!feof(f_handle))
    {
        fscanf(f_handle, "%s", buffer);                     //scan the username within the database file
        if (!strcmp(user_name, buffer)) { break; }          //Break once we found the username
        while (fgetc(f_handle) != '\n' && !feof(f_handle)); //Skips to the next line
    }

    /* Insert '+' directly after username */
    fwrite("+ ", sizeof(char), 3, f_handle);

    /* Append timestamp at the end of timesheet */
    while (fgetc(f_handle) != '\n' && !feof(f_handle)); //Get to the end of the line
    fseek(f_handle, -1L, f_handle);                     //seek backwards by one
    fwrite(&current_time, sizeof(time_t), 1, f_handle); //appending to file

    CLOSE_FILE
    return EXIT_SUCCESS;
}

int Clock_Out(const char* user_name) {
    FILE *f_handle = fopen(DATABASE, "r");
    time_t current_time = time(NULL);
    if (f_handle == NULL) 
    {
        printf("\tFile error: Could not open for reading\n");
        return FILE_READ_ERROR;
    }

    //Write code...

    CLOSE_FILE
}

bool file_exists(char* filename) {
    struct stat buffer; 
    return (stat(filename, &buffer) == 0);
}

int read_usernames(char** buf) {
    FILE *f_handle = fopen(DATABASE, "r"); 
    if (f_handle == NULL) 
    {
        return FILE_READ_ERROR;
    }

    int i = 0;
    char buffer[USERNAME_MAX_SIZE];

    while (!feof(f_handle))
    {
        fscanf(f_handle, "%s", buffer);                     //scan the username within the database file
        buf[i] = malloc(strlen(buffer) * sizeof(char));     //Making enough memory for the username
        strcpy(buf[i], buffer);                             //storing the username in buf
        while (fgetc(f_handle) != '\n' && !feof(f_handle)); //Skips to the next line
        i++;
    }

    CLOSE_FILE

    return i;
}

int read_clocked_in(char** buf) {
    FILE *f_handle = fopen(DATABASE, "r"); 
    if (f_handle == NULL) 
    {
        return FILE_READ_ERROR;
    } 

    int i = 0;
    char buffer[USERNAME_MAX_SIZE];

    while (!feof(f_handle))
    {
        fscanf(f_handle, "%s", buffer);                     //scan the username within the database file
        if (strchr(buffer, '+') != NULL) 
        {
        buf[i] = malloc(strlen(buffer) * sizeof(char));     //Making enough memory for the username
        strcpy(buf[i], buffer);                             //storing the username in buf
        i++;
        }
        while (fgetc(f_handle) != '\n' && !feof(f_handle)); //Skips to the next line
    }

    CLOSE_FILE

    return i;
}

void list_usernames(int size, char** buf) {
    for (int i = 0; i < size; i++)
    {
        if (buf[i] == NULL) { break; }
        printf("%s\n", buf[i]);
    }  
}