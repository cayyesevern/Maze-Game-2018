/*
	@author Kesavakumar Sivalingam Id: 1142701377
	This maze program is built using C++.

	This program has been added with some special features. An unknown secret boxes are placed in the maze.

*/
#include <iostream>
#include "maze.h"
#include "riddle.h"

int main() {
	int energy;
	char move;

	Maze p1;    // starting position of Hero
	p1.print_Maze();

	Hero p2;
	Food p3;
	Monster p4;
	secret_Item p5;
	system("cls");
	p3.random_Pos_H();
	p4.random_Pos_M();
	p5.place_IT();
	p1.print_Maze();

	while (1) {
		energy = p2.Move();
		p2.print_Maze(energy);
		if (energy == 0) {
			cout << "The Hero dies!!!!" << endl;
			cout << "Please try next time!!!!" << endl;
			break;
		}
		if (Maze_1[end_Row + 1][end_Col] == 'E') {
			cout << "\n\nHero wins!!!" << endl;
			cout << "Congratulations!! You have successfully finished the Maze!!!!!" << endl;
			cout << "You were able to kill " << count_Monsters << " Monsters " << endl;
			cout << "You have accessed " << count_Box << " secret box " << endl;
			cout << "Hope to see you again!!!" << endl;
			break;
		}
	}
}

