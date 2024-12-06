/*************************************************************
                     MATCHSTICK SORTING

               Header file for display.cpp

    ------------------------------------------------------

 Authors: ALGOR Teaching Team
 Date: 21/04/2009 (last modified on 28/11/2024)
 File: display.h
 Purpose: Prototypes of functions for pseudo-graphically
          displaying matchsticks to be sorted.

*************************************************************/

#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <string>
#include <vector>
#include "matchstick.h"

// Colors
#define BLACK  0
#define WHITE  1
#define RED    2
#define YELLOW 3
#define BLUE   4
#define MAGENTA 5
#define GREEN  6

// Activates or deactivates display using a boolean
void setDisplay(bool b);
// Activates display
void activateDisplay();
// Deactivates display
void deactivateDisplay();
// Returns whether the display is active or not
bool isDisplayActive();

// Specifies the number of display lines
void setDisplayLevel(int n);

// Displays the message "s" on the screen and continues execution
void displayInfo(const std::string & s);
// Displays the message "s" on the screen, then waits for the user to press a key
void displayInfoWait(const std::string & s);

// Initializes the pseudo-graphic display (20 lines by default)
void init(int n = 20);
// Exits pseudo-graphic mode cleanly
void finish();
// Displays a vector of matchsticks
void display(const std::vector<Matchstick> &A);

#endif // DISPLAY_H_INCLUDED
