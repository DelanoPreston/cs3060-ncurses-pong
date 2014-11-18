/* 
 * File:   main.cpp
 * Author: mikewright
 *
 * Created on August 14, 2014, 8:57 AM
 */
#include "Game.h"
#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>                  
//#include <curses.h>
//#include <time.h>

#define EIGTH_SECOND_SLEEP 125000000

int main(void) {
    
    Game game;
    game.Play();
    return EXIT_SUCCESS;
    
    /*
    WINDOW * mainwin;

    //  Initialize ncurses 
    if ( (mainwin = initscr()) == NULL ) {
      fprintf(stderr, "Error initialising ncurses.\n");
	    exit(EXIT_FAILURE);
    }
    start_color();

    // Create colored pairs 
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    // Create our sleep timer (1/8 second) 
    struct timespec sleeptime, notused;
    sleeptime.tv_sec = 0;
    sleeptime.tv_nsec = EIGTH_SECOND_SLEEP;

    int input;
    for (int i = 0; i < 40; ++i) {
      // First clear off the screen 
      clear();

      // Set the color and output the text 
      int color = (i / 10)%2 + 1;
      attron(COLOR_PAIR(color));
      mvaddstr(13, 20+i, "Hello, world!");

      // Refresh the screen 
      refresh();

      // Sleep 
      nanosleep(&sleeptime, &notused);

      // Exit early if a key is pressed
      timeout(0);
      input = getch();
      if (input != -1) {
        break;
      }
    }

    // Clean up after ourselves 
    delwin(mainwin);
    endwin();
    refresh();

    printf("Key: %d %c\n", input, input); 
    return EXIT_SUCCESS; */
}
