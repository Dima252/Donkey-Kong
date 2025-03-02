#pragma once

//External includes
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <chrono>
//Objects
#include "board.h"
#include "mario.h"
#include "utils.h"
#include "barrels.h"
#include "ghost.h"
#include "Results.h"
#include "Steps.h"

using namespace std;
static constexpr int ESC = 27;
static constexpr int ENTER = 13;

class game_config {
private: 
	bool isLoad = false;
	bool isSave = false;
	bool isSilent = false;


public:
	void setSilent(bool silent) { isSilent = silent; }
	void setLoad(bool load) { isLoad = load; }
	//Setting the flags
	void start();
	bool new_game_load();
	bool new_game_save();
	void start_game_save(Board& b, char& last_key, int& lives, bool& won, bool& invalid_file, int num_of_screen, int& score, std::string filename, int& iteration); 
	void start_game_load(Board& b, char& last_key, int& lives, bool& won, bool& invalid_file, int num_of_screen, int& score, std::string filename, int& iteration);
	void reportResultError(const std::string& message, const std::string& filename, size_t iteration);

	//Game functions
	bool set_board(Board& b, Mario& m, barrels barr[], std::vector<ghost>& ghosts, int& Legend_x, int& Legend_y);						//This func sets the screen objects by the character pos 
	//Returns true if the screen is valid else false
	void make_files_v(std::vector<std::string>& fileNames);					//Creating the screen names vector
	void set_screen(Board& b, board_type t);								//Sets the screen of the game
	char handel_input(Mario& m, int& jumps, bool& fall, bool& on_ladder, char& Key_presse,bool hammer_found, barrels barr[], std::vector<ghost>& ghosts, int& score);
	void handel_input_load(Mario& m, int& jumps, bool& fall, bool& on_ladder, char& Key_pressed, bool hammer_found, barrels barr[], std::vector<ghost>& ghosts, int& score, char loadchar);
	void lives_counter(int& lives,int const Legend_x, int const Legend_y);											//Displays lives of mario on the screen
	void score_counter(int const score, int const Legend_x, int const Legend_y); 								    //Displays the score of the player on the screen
	void hammer_Legend(bool hammer_found, int const Legend_x, int const Legend_y);						//Displays the hammer on the screen
	void screen_counter(int& num_of_screen);								//Displays the screen number on the screen
	bool display_menu(Board& b,int& num_of_screen, int size_of_files);								//Screens handling 
	void game_pause(char key_pressed); 								//Pauses the game
	void handleHammerAction(bool hammer_found, char Key_pressed,Mario& m, barrels barr[], std::vector<ghost>& ghosts, int& score); //Handels the hammer action
	int get_screen_selection(int size_of_files);				//Gets the screen selection from the user
	//Enemy func
	bool mario_explosion(barrels& b, Mario& m);					//Checks if mario hit by explosion
	bool barrel_handling(Board& b, barrels barrel[], int& barrel_timer, int& barrel_index, Mario& m); 
	bool ghosts_handeling(Board& b, std::vector<ghost>& ghosts, Mario& m);
	//Handeling enemy movemnt and resetting the screen if mario hit
	//Or in range of explosion
	
	//Mario functions 
	void mario_redraw(Mario& m, int& jumps, bool& fall, bool& on_ladder, char& Key_pressed);  //Handels marios movement
	void checkJumps(Mario& m, int& jumps); 								//Handels jumping
	void checkFalls(Mario& m, int& jumps, bool& fall);						//Handels falling
	void redraw(Mario& m);													//Cycles marios location on the scrren with the direction on his movement			
	bool fallDamage(Mario& m);												//Checks for fall damage
};
