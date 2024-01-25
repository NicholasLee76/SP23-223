/*
Implementations for core functions for Game of Life assignment in CPSC 223 fall 2024

Author: Alan Weide
Modified by: Nicholas Lee
Changelog:
 */

#include "life.h"

#include <stdio.h>

bool is_alive(int field[ROWS][COLS], size_t i, size_t j)
{
    /*
    TODO: Implement this function. This line here only so starter code compiles
    */
    if (field[i][j] == 0) {
        return false;
    } else { return true; }
}

unsigned int num_living_neighbors(int field[ROWS][COLS], size_t i, size_t j)
{
    /*
    TODO: Implement this function. This line here only so starter code compiles
    */
    int ret = 0;
    if (i > 0 && field[i-1][j] == 1) { ret++; }
    if (i < ROWS - 1 && field[i+1][j] == 1) { ret++; }
    if (j > 0 && field[i][j-1] == 1) { ret++; }
    if (j < COLS - 1 && field[i][j+1] == 1) { ret++; }
    if (i > 0 && j > 0 && field[i-1][j-1] == 1) { ret++; }
    if (i < ROWS - 1 && j < COLS - 1 && field[i+1][j+1] == 1) { ret++; }
    if (i > 0 && j < COLS - 1 && field[i-1][j+1] == 1) { ret++; }
    if (i < ROWS - 1 && j > 0 && field[i+1][j-1] == 1) { ret++; }
    return ret;

}

int get_next_state(int field[ROWS][COLS], size_t i, size_t j)
{
    /*
    TODO: Implement this function. This line here only so starter code compiles
    */
    int curr = field[i][j];
    int num_live = num_living_neighbors(field, i, j);
    if (curr == 1) {
        if (num_live < 2 || num_live > 3) { return DEAD; }
        else { return ALIVE; }
    }
    else {
        if (num_live == 3) { return ALIVE; } 
        else { return DEAD; }
    } 
}

void compute_next_gen(int cur_field[ROWS][COLS], int next_field[ROWS][COLS])
{
    /*
    TODO: Implement this function.
     */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            next_field[i][j] = get_next_state(cur_field, i, j);
        }
    }
}
