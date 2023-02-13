#include "Clock.h"
#include <stdio.h>
#include <stdbool.h>
// #include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <sys/stat.h>

int Create_New_user(const char* name) {
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

int Clock_In(const char* user_name) {
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