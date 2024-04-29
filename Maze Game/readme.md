C++ Assignment
==============


Basically, there are five different versions which are Phase 1 to Phase 5. The program is improved gradually through each phase. Here's a brief explanation about the program where the program is designed with a hardcoded maze which consists of HERO, FOOD, MONSTERS.
 
Hero >>
	The program prompts the user for the position of the hero, the user just have to put in the row and column numbers.
	Hero has to complete the maze by eating the foods and attacking the monsters.
	He is given with energy of 100, he must plan properly before each moves as each step reduces the energy by one unit,especially 		when attacking the monster(will be discussed later). Hero will loss alot of energy when he attacks a monster but it doesn't mean that 	he can't win the game.
	He must complete the maze without finishing all the energy in order to win the game. 
	He can open the secret boxes that he steps onto if he wants to gain some energy.

Monsters>>
	Monsters are static(don't move), will have a fixed energy and some hitpoints. 
	

Food>>
	Food has its own energy. Hero can gain energy if he consumes the food. 


Instructions that need to be taken before running the program: 
	1) This program is fully implemented in WINDOWS, system calls aren't the same if you are trying to run it in LINUX. Change it to 		system("clear") for linux or system("cls") for windows and system("clc") for microsoft visual studio.
	2)Maze program that fits in your terminal. To compile g++ <program_file>.cpp 
	3)If you want to change the maze, just create an multidimensional array and design it based on your preferences. Make 			sure, start position "S" is at position(0,0) and ending position "E" is at position (18,18).
	4) If you want to change the symbol, you can do it by adding the new symbol to all the conditions which holds the previous 			symbol that i've used.
	5) W,A,S & D keys to move the hero.


