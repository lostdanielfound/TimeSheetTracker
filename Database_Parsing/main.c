#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

//Check to see if file exists 
//https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c

//Checks to see if the function exist
//Method does not work if file is 2GB in size
bool file_exists(char* filename) {
  struct stat buffer; 
  return (stat(filename, &buffer) == 0);
}

int read_usernames(char** buf) {
  FILE *database_file = fopen("TIME_DATABASE", "r");

  for (int i = 0; i < 50-1; i++)
  {

  }

  
  

  fclose(database_file);
}

int read_clocked_in(char** buf) {
  FILE *database_file = fopen("TIME_DATABASE", "r");

  fclose(database_file);
}

void list_usernames(char** buf) {

}

void list_clocked_in(char** buf) {

}
int main() {

  //Check to see if file exists
  if (!file_exists("TIME_DATABASE")) {
    printf("File doesn't exist\n");
    return -1;
  } //file doesn't exist

  char** buffer = (char**)calloc(50, 256);
  FILE *database_file = fopen("TIME_DATABASE", "r");

  read_usernames(buffer);
  printf("Users in the database are: \n");
  list_usernames(buffer);

  read_clocked_in(buffer);
  printf("\nUsers that are clocked-in: \n");
  list_clocked_in(buffer);

  //freeing
  free(buffer);
  fclose(database_file);

  return EXIT_SUCCESS;
}