# PasswordPwner

## Project Partners
1. [LeemuPaani](https://github.com/LeemuPaani/)
2. [adbullahh-exe](https://github.com/abdullahh-exe/)

## Introduction
The aim of the project was to design a system that can assist the user to avoid passwords that have been compromised before.

## Problem Analysis
The main problem of the project is the speed at which the data is accessed, and results are displayed to user's queries.

## Data Structure decision
Tree was decided to be the data structure used to store data and keeps references to child nodes. The child nodes contain ordered variations of their parents.

## Main data structures
1. Node
2. Tree
3. Array

## Classes
### Tree class
![Tree Class](https://user-images.githubusercontent.com/101589782/169654196-193fde2a-af2a-49d0-b979-2cccac1a0f86.png)

### Node class
![Node Class](https://user-images.githubusercontent.com/101589782/169654270-2100df53-f60f-45fb-ac59-c500b1201958.png)

## Key Development Challenges
1. Sanitizing data
2. Reading data into data structure
3. Performing operations while maintaining speed

## Solution Design
**C++** is used for development of this console application.

The data used in this project was taken from [Have i been pwned](https://haveibeenpwned.com/Passwords).

The solution is designed in the following steps:
1. Sanitization of data, into needed format (only included alphanumeric characters in English)
2. Division of data into multiple sub files ordered in alphabetical order


### When the program is executed:
1. The user is prompted to enter a password.
2. The password is used to open the corresponding data file and insert it into a tree.
3. Search operation is performed on the data.
4. Result is displayed as output to user.

Multiple utility functions are also included in addition to the classes.

## Executing the application:
1. Extract all the data using file `PasswordPwner_Data.zip.001`.
1. Run the `T6tree.exe` to start up the application.
2. Enter string to check.
3. Result and suggestions (if any) are displayed.

## Result and conclusion
Depending on the password entered by user, the program displays output.
* If a password is of less than 3 characters long, user is told that the password is too weak, and told to use another password.
* If a password is found in database, the user is notified, and a modified password is recommended to the user.
* If the password is not found in the database, the user is told that the password is unique and can be used.

The program successfully executes and performs desired functions with great speed, which accomplishes our initial project goal.

