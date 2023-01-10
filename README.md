[![C/C++ CI](https://github.com/lostdanielfound/TimeSheetTracker/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/lostdanielfound/TimeSheetTracker/actions/workflows/c-cpp.yml)

# TimeSheetTracker
This program is to represent a Time Sheet Tracker in that it will record when a user Clocks-in or Clocks-Out and output a Cumliative Time review of all the hours recorded. 
This program was made as practice, this program has been written entirly in C.

## Setup
To run the application after cloning from Github, make sure you are running on a device that is able to run a **Makefile** such as a linux system. 

### run `make`
Should compile the C files using the compile **gcc** and will output the executable called TimeLogger

### run `make clean` 
Will remove out any *.o or *.gch files, along with removing the executable.

### run `make submit`
Will create a zip folder and fill it with the compiled executable along with the *.c and *.h files. 

## Start 
Upon starting the application you will be greeted with a menu, if a timesheet datebase called `TIME_DATABASE` has not yet been created within the directory as the application it will create one. 

### Menu
You will be given the following options: 

- Create New User
- Clock-In User (If not already Clock in)
- Clock-Out User (If Clock in)
- Show TimeSheet

### Creating New User
Creating a new user will allow you to create a new User to keep track of their times within the Timesheet.
You will only be asked to enter the name of the user. Creating the user will allow you to clock them in.

### Clocking-In
This will give you a list of available users to clock in. Select which user by selecting them with your cursor and hit [Enter].

[Picture Coming soon]

### Clocking-Out
This will give you a list of available users that are clocked in that can be clocked out. Select which user by selecting them with your cursor and hit [Enter].

[Picture Coming soon]

### Showing TimeSheet
Shows a list of all Users within the database and their times. 

[Picture Coming soon]
