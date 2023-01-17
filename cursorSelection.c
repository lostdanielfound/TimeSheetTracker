#include "cursorSelection.h"
#include <ncurses.h> 
//https://www.codedrome.com/an-introduction-to-ncurses-in-c/
//Cursor positioning: https://rosettacode.org/wiki/Terminal_control/Cursor_positioning#C/C++
//When using this function, you must include -nlncurses tag upon compiling
#define INITAL_X 25
#define INITAL_Y 5

/* 
 * cursorSelection is ncurses.h dependent and 
 * Should not be used along with stdio functions
 * due to the inability to view put outputs at 
 * the same time.
*/
int cursorSelection(char** selectionList, int listSize, char* title) {
  initscr(); //initalize screen noecho();
  //Move cursor intially to the middle of the terminal. 

  if (title != NULL)
  {
    move(INITAL_Y - 2, INITAL_X - 5);
    printw("%s\n", title);
  }
  
  int x, y; 
  
  x = INITAL_X; y = INITAL_Y; 
  move(y, x); 
  printw("Please choose an option below\n");

  /* Loop each time a user moves cursor using arrow key
  will stop loop once the user hits [Enter] */
  int option = 0;
  char key;

  //Starting coord for the list, this is important to keep track
  x -= 5;
  y += 2;

  int x_list, y_list;
  x_list = x; y_list = y;

  for (int i = 0; i < listSize; i++)
  {
    move(y_list + i, x_list);
    printw("  %s\n", selectionList[i]);
  }
  move(y_list, x_list);

  noecho(); //omits any user buffer input from showing onto the window screen
  while(1) 
  {
    printw(">");
    refresh();

    //Check to see if either getch is 10 [Enter]
    key = getch(); 
    if (key == 10) { endwin(); return option; }
    key = getch(); 
    if (key == 10) { endwin(); return option; }
    key = getch();

    switch(key)
    {
      case 65: 
        move(y_list, x_list); 
        printw(" "); 
        refresh(); 
        if (y_list != y) { y_list -= 1; option -= 1; } break; 
      case 66: 
        move(y_list, x_list); 
        printw(" "); 
        refresh(); 
        if (y_list != (y + (listSize - 1))) { y_list += 1; option += 1; } break; 
      case 67: break; 
      case 68: break; 
      default: break;
    }

    move(y_list, x_list);
  }

  //Should never reach here 
  endwin();
  return -1;
}