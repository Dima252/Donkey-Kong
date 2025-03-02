
#include "game_config.h"

//Donkey Kong 
//By Shalev yosefashvili and Dimitry Todoseyev
//This project intend to implement OOP principles in c++ languge in order to create the Donkey Kong game . 

int main(int argc, char** argv) {
    game_config game;
	game.setLoad(argc > 1 && std::string(argv[1]) == "-load");
	game.setSilent(argc > 1 && std::string(argv[1]) == "-silent");
	//setting the flags

    game.start(); //executes the game
}
