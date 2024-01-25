/*
Driver for Game of Life assignment in CPSC 223 Fall 2023

Author: Nicholas Lee
*/

#include <stdlib.h>
#include <stdio.h>

#include "constants.h"
#include "life.h"
#include "helpers.h"

int main(int argc, char *argv[])
{
    /*
     * TODO: Accept two command-line arguments, which will appear in the
     * following order:
     * time_steps:
     *      a positive integer describing how many "generations" the simulation
     *      will run for.
     * init:
     *      a string consisting of the characters '0' and '1', of length ROWS * COLS,
     *      representing the initial state for this run of Game of Life.
     */
    int time_steps = atoi(argv[1]);
    char* init = argv[2];

    /*
     * TODO: Create a new statically-allocated array of size ROWS x COLS
     */
    int field[ROWS][COLS];

    /*
     * TODO: Print the initial values held in the field
     */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int x = init[i * ROWS + j] - '0';
            field[i][j] = x;
        }
    }
    print_initial(field);

    /*
     * TODO: Run the game time_steps times, printing the field at the end of
     * each step
     */
    for (int i = 0; i < time_steps; i++) {
        int placeholder[ROWS][COLS];
        compute_next_gen(field, placeholder);
        print_generation(placeholder, i+1);
        
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                field[i][j] = placeholder[i][j];
            }
        } 
    }
    
    /*
     * Print "Done." then exit.
     */
    printf("Done.\n");
    return 0;
}
