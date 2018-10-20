#ifndef _GAME_H_
#define _GAME_H_

// Runs the whole program, including init and loop
void game_run(int argc, char **argv);

// Run once at game startup to handle initialization
void game_init(int argc, char **argv);

// Runs continuously
void game_loop(void);

// Can be called by loop to update the status of the game board.
void game_draw(void);

#endif