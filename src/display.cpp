/*************************************************************
                     Lab MATCHSTICK SORTING

            Source file for display.cpp

    ------------------------------------------------------

 Authors: ALGOR Teaching Team
 Date: 21/04/2009 (last modified on 28/11/2024)
 File: display.cpp
 Purpose: Set of functions for pseudo-graphically displaying
          matchsticks to be sorted.

*************************************************************/

#include <curses.h>    // For pseudo-graphical display
#include <ctime>       // For handling delays in display
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "matchstick.h"
#include "display.h"

// Internal Macros (Do not modify)
#define gotoxy(x, y) move(y, x)
#define textcolor(color) attrset(COLOR_PAIR(color))

// Enable or disable graphical display
bool DISPLAY = true;

// Number of display levels
int NbLevel = NbLevel;

// Function to set the number of display levels
void setLevelDisplay(int n) 
{
    NbLevel = n + 1;
}

// Enable or disable display
void setDisplay(bool b) 
{
    DISPLAY = b;
}

// Activate display
void activateDisplay()
{
    DISPLAY = true;
}

// Deactivate display
void deactivateDisplay()
{
    DISPLAY = false;
}

// Returns whether the display is active
bool isDisplayActive() {
    return DISPLAY;
}

// Displays the message `s` and continues execution
void displayInfo(const std::string &s)
{
    if (DISPLAY) 
    {
        textcolor(9);
        gotoxy(0, NbLevel + 1);
        printw("\n%s\n", s.c_str());
        refresh();
    }
    else
    {
        cout << s << endl;
    }
}

// Displays the message `s`, waits for a key press, and continues
void displayInfoWait(const std::string &s)
{
    if (DISPLAY) 
    {
        textcolor(9);
        gotoxy(0, NbLevel + 1);
        printw("\n%s: Press a key to continue\n", s.c_str());
        refresh();
        getchar();
        gotoxy(0, NbLevel + 1);
        printw("\n\n");
        refresh();
    }
    else
    {
        cout << s << endl;
    }
}

// Function init
// Purpose: Initializes pseudo-graphical display
void finish()
{
    if (DISPLAY) 
    {
        textcolor(9);
        gotoxy(0, NbLevel + 1);
        printw("\nEnd: Press a key to exit\n");
        refresh();

        getchar();
        endwin();
    }
}

// Function finish
// Purpose: Properly exits pseudo-graphical mode
void init(int n)
{
    NbLevel = n + 1;
    if (DISPLAY) 
    {
        initscr();                // Initialize the curses library
        keypad(stdscr, TRUE);     // Enable keyboard mapping
        nonl();                   // Prevent NL->CR/NL on output
        cbreak();                 // Take input characters one at a time
        noecho();                 // Do not echo input
        nodelay(stdscr, TRUE);    // getch() does not wait for input
        if (has_colors())
        {
            start_color();

            // Initialize colors
            // Only the background changes to display different colors
            init_pair(0, COLOR_BLACK, COLOR_BLACK);
            init_pair(1, COLOR_BLACK, COLOR_WHITE);
            init_pair(2, COLOR_BLACK, COLOR_RED);
            init_pair(3, COLOR_BLACK, COLOR_YELLOW);
            init_pair(4, COLOR_BLACK, COLOR_BLUE);
            init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
            init_pair(6, COLOR_BLACK, COLOR_GREEN);

            // One color for text: white on black background
            init_pair(9, COLOR_WHITE, COLOR_BLACK);
        }
        else
        {
            printw("The terminal does not support colors!\n");
            finish();
        }
    }
}

// Function display
// Displays a vector of matchsticks provided as a parameter
void display(const std::vector<Matchstick> &A)
{
    if (DISPLAY) 
    {
        int i, j;
        int waitComplete = 0;
        static unsigned int displayDelay = 50; // Initial delay, in microseconds

        textcolor(0);
        for (j = 0; j < NbLevel; j++) 
        {
            gotoxy((i * 2), NbLevel - j);
            printw(" ");  // Displays a space with background color
        }

        for (i = 0; i < A.size(); i++) {
            if ((A[i].size > NbLevel) || (A[i].size < 1)) 
            {
                gotoxy(1, NbLevel + 1);
                printw("Matchstick no %u has an invalid size: %u\n", i, A[i].size);
            }

            if ((A[i].color < WHITE) || (A[i].color > GREEN)) 
            {
                gotoxy(1, 22);
                printw("Matchstick no %u has an invalid color: %u\n", i, A[i].color);
            }
            else
            {
                textcolor(A[i].color);
            }

            for (j = 0; j < A[i].size; j++) 
            {
                gotoxy(1 + (i * 2), NbLevel - j);
                printw(" ");
            }

            textcolor(0);
            for (j = 0; j < A[i].size; j++) 
            {
                gotoxy(2 + (i * 2), NbLevel - j);
                printw("_");
            }

            for (j = A[i].size; j < NbLevel; j++) 
            {
                gotoxy(1 + (i * 2), NbLevel - j);
                printw("__");
            }
        }

        refresh();

        time_t time = clock();
        while (!waitComplete) 
        {
            int key = getch();
            if (key == KEY_UP) 
            {
                if (displayDelay > 100)
                    displayDelay -= 100;
                else if (displayDelay > 10)
                    displayDelay--;
            }
            if (key == KEY_DOWN) 
            {
                if (displayDelay < 100)
                    displayDelay++;
                else if (displayDelay < 5000)
                    displayDelay += 100;
            }

            waitComplete = ((clock() - time) * 5000 / CLOCKS_PER_SEC) > displayDelay;
        }
    }
}
