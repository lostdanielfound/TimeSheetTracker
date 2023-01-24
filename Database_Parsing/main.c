#include <stdio.h> 
#include <string.h> 
#include <malloc.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

#define USERNAME_LIMIT 50
#define USERNAME_MAX_SIZE 256

//Check to see if file exists 
//https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c

//Checks to see if the function exist
//Method does not work if file is 2GB in size
bool file_exists(char* filename) {
  struct stat buffer; 
  return (stat(filename, &buffer) == 0);
}

int read_usernames(char** buf) {

  FILE *database_file; 
  if ((database_file = fopen("TIME_DATABASE", "r")) == NULL) 
  {
    return(EXIT_FAILURE);
  }

  int i = 0;
  char buffer[USERNAME_MAX_SIZE];

  while (!feof(database_file))
  {
    fscanf(database_file, "%s", buffer);                          //scan the username within the database file
    buf[i] = malloc(strlen(buffer) * sizeof(char));               //Making enough memory for the username
    strcpy(buf[i], buffer);                                       //storing the username in buf
    while (fgetc(database_file) != '\n' && !feof(database_file)); //Skips to the next line
    i++;
  }

  fclose(database_file);

  return EXIT_SUCCESS;
}

int read_clocked_in(char** buf) {
  FILE *database_file; 
  if ((database_file = fopen("TIME_DATABASE", "r")) == NULL) 
  {
    return(EXIT_FAILURE);
  } 

  int i = 0;
  char buffer[USERNAME_MAX_SIZE];

  while (!feof(database_file))
  {
    fscanf(database_file, "%s", buffer);                          //scan the username within the database file
    printf("after username: %s, %c", buffer, fgetc(database_file));
  // buf[i] = malloc(strlen(buffer) * sizeof(char));               //Making enough memory for the username
  // strcpy(buf[i], buffer);                                       //storing the username in buf
    while (fgetc(database_file) != '\n' && !feof(database_file)); //Skips to the next line
    i++;
  }

  fclose(database_file);

  return EXIT_SUCCESS;
}

void list_usernames(char** buf) {
  for (int i = 0; i < 50; i++)
  {
    if (buf[i] == NULL) { break; }
    printf("%s\n", buf[i]);
  }  
}

void list_clocked_in(char** buf) {
}

int main(int argc, char** argv) {

  //Check to see if file exists
  if (!file_exists("TIME_DATABASE")) {
    printf("File doesn't exist\n");
    return -1;
  } //file doesn't exist

  /**Creates buffer allocation and file handle */
  char** buffer = malloc(USERNAME_LIMIT * sizeof(char *));
  FILE *database_file = fopen("TIME_DATABASE", "r");

  //Read and lists usernames within the database file
  read_usernames(buffer);
  printf("Users in the database are: \n");
  list_usernames(buffer);

  //Reads which usernames are clocked-in and lists out within the database file
  read_clocked_in(buffer);
  printf("\nUsers that are clocked-in: \n");
  list_clocked_in(buffer);

  //freeing
  free(buffer);
  fclose(database_file);

  return EXIT_SUCCESS;
}