#pragma once
/*
	@author Kesavakumar Sivalingam Id: 1142701377
	This maze program is built using C++.

	This program has been added with some special features. An unknown secret boxes are placed in the maze.

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define SIZE 19

using namespace std;

int end_Row;                     // responsible for the ending of the game 
int end_Col;
int count_Monsters = 0;			// counts the number of monsters that has been killed
int count_Box = 0;					// counts the number of secret box that has been  opened
int* ptr_Monsters = &count_Monsters;
int* ptr_Box = &count_Box;
int* ptr_Row = &end_Row;
int* ptr_Col = &end_Col;
int solve_Riddle();
int riddle_1();
int riddle_2();
int riddle_3();
int riddle_4();
int riddle_5();
int riddle_6();
int riddle_7();
int riddle = 1;             // changes the riddle to the next one 
int* riddle3 = &riddle;


//design of the maze
char Maze_1[SIZE][SIZE] = {
				{'S',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},  //1
				{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
				{'#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#'},
				{'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
				{'#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#'},
				{'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#'},
				{'#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#'},
				{'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#'},
				{'#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#'},
				{'#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#'},
				{'#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
				{'#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#'},
				{'#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#'},
				{'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
				{'#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#'},
				{'#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
				{'#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#'},
				{'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' '},
				{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','E'}
};



// Class to print the maze
class Maze {
public:
	Maze() {
		m = 0;
	}
	void print_Maze(int energy = 100) {
		m = 0;
		srand(time(0));
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cout << " " << Maze_1[i][j];
			}
			cout << "\t" << m << endl;
			m++;
		}
		cout << "Energy of the hero: ";
		cout << energy << endl;
	}
private:
	int m;
};


class Hero : public Maze {

public:
	//Hero stands at the position by default
	Hero() {
		// default constructor which ensures that the HERO stands at the position that is set
		count_M = 8;
		count_Mons = 0;
		count = 0;
		count_2 = 1;
		Hsym = 'H';
		energy = 100;
		while (1) {
			cout << "Please enter the starting position of Hero(eg: 3 5): ";
			cin >> row >> col;
			save1 = row;
			save2 = col;
			if (Maze_1[row][col] == ' ') {
				Maze_1[row][col] = Hsym;
				break;
			}
			else {
				cout << "Invalid key" << endl;
			}
		}
	}


	// this function returns  integer when monsters are detected in the maze
	int check_Monsters(int row, int col, int aRow[], int aCol[], int count) {
		for (int m = 0; m <= count; m++) {
			if (row == aRow[m] && col == aCol[m]) {
				if (count_M == 0) {
					aRow[m] = aRow[count]; // saves the position of the monster that was attacked
					aCol[m] = aCol[count]; // prevents the monster from being attacked again when the hero uses the same path 
					count_M = 8;
					count--; // count decreases which means the array is only read until one index below its size
					return 1;
				}
				else {
					count_M--;
					return 1;
				}
			}
		}
	}

	// Function that ichecks the keyboard input from the user. Key W,A,S and D
	int Move() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (Maze_1[i][j] == 'M') {
					row_M[count] = i;
					col_M[count] = j;
					random_M = (rand() % 9) + 1;
					Maze_1[i][j] = (char)random_M + '0';
					count++;
				}
			}
		}
		cout << "W,A,S or D to move: ";
		cin >> move;
		cout << endl;

		if (move == 'W' || move == 'w') {
			row--;
			if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
				energy--;
				if (Maze_1[row][col] != '#') {
					int x = check_Monsters(row, col, row_M, col_M, count);
					if (x == 1) {
						(*ptr_Monsters)++;
						row++;
						cout << "You are attacking a monster" << endl;
						Maze_1[row][col] = Hsym;
						count_2++;
						// the monster is hit for 8 times before the hero passes by
						// monsters are given an additional 8 hitpoints
						if (count_2 == 10) {
							row--;
							char x = Maze_1[row][col];
							cout << "Monster died!!" << endl;
							energy -= (int)x - '0';
							energy++;
							Maze_1[row][col] = Hsym;
							Maze_1[row + 1][col] = ' ';
							count_2 = 1;
						}
						else {
							cout << "Hit the Monster!!!" << endl;
							cout << "Monster's health -> " << 10 - (count_2) << endl;
						}
					}
					else if (Maze_1[row][col] == '1' || Maze_1[row][col] == '2' || Maze_1[row][col] == '3' || Maze_1[row][col] == '4' || Maze_1[row][col] == '5' || Maze_1[row][col] == '6' || Maze_1[row][col] == '7' || Maze_1[row][col] == '8' || Maze_1[row][col] == '9') {

						char x = Maze_1[row][col];
						energy += (int)x - '0';
						energy++;
						Maze_1[row][col] = Hsym;
						Maze_1[row + 1][col] = ' ';
					}
					else if (Maze_1[row][col] == ' ') {
						Maze_1[row][col] = Hsym;
						Maze_1[row + 1][col] = ' ';
					}
					else if (Maze_1[row][col] == char(177)) {
						(*ptr_Box)++;
						int c = solve_Riddle();
						if (c == 1) {
							energy += 11;
							Maze_1[row][col] = Hsym;
							Maze_1[row + 1][col] = ' ';
						}
						else if (c == 0) {
							Maze_1[row][col] = Hsym;
							Maze_1[row + 1][col] = ' ';
						}
						else if (c == 2) {
							Maze_1[save1][save2] = Hsym;
							Maze_1[row + 1][col] = ' ';
							Maze_1[row][col] = ' ';
							row = save1;
							col = save2;
						}
					}
				}
				else {
					energy++;
					row++;
					Maze_1[row][col] = Hsym;
				}
			}
			else {
				energy++;
				row++;
				Maze_1[row][col] = Hsym;
			}
		}


		if (move == 'S' || move == 's') {
			row++;
			if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
				energy--;
				if (Maze_1[row][col] != '#') {
					int x = check_Monsters(row, col, row_M, col_M, count);
					if (x == 1) {
						(*ptr_Monsters)++;
						row--;
						cout << "You are attacking a monster" << endl;
						Maze_1[row][col] = Hsym;
						count_2++;
						if (count_2 == 10) {
							row++;
							char x = Maze_1[row][col];
							cout << "Monster died!!" << endl;
							energy -= (int)x - '0';
							energy++;
							Maze_1[row][col] = Hsym;
							Maze_1[row - 1][col] = ' ';
							count_2 = 1;
						}
						else {
							cout << "Hit the Monster!!!" << endl;
							cout << "Monster's health -> " << 10 - (count_2) << endl;
						}
					}
					else if (Maze_1[row][col] == '1' || Maze_1[row][col] == '2' || Maze_1[row][col] == '3' || Maze_1[row][col] == '4' || Maze_1[row][col] == '5' || Maze_1[row][col] == '6' || Maze_1[row][col] == '7' || Maze_1[row][col] == '8' || Maze_1[row][col] == '9') {

						char x = Maze_1[row][col];
						energy += (int)x - '0';
						energy++;
						Maze_1[row][col] = Hsym;
						Maze_1[row - 1][col] = ' ';
					}
					else if (Maze_1[row][col] == ' ') {
						Maze_1[row][col] = Hsym;
						Maze_1[row - 1][col] = ' ';
					}
					else if (Maze_1[row][col] == char(177)) {
						(*ptr_Box)++;
						int c = solve_Riddle();
						if (c == 1) {
							energy += 11;
							Maze_1[row][col] = Hsym;
							Maze_1[row - 1][col] = ' ';
						}
						else if (c == 0) {
							Maze_1[row][col] = Hsym;
							Maze_1[row - 1][col] = ' ';
						}
						else if (c == 2) {
							Maze_1[save1][save2] = Hsym;
							Maze_1[row - 1][col] = ' ';
							Maze_1[row][col] = ' ';
							row = save1;
							col = save2;
						}
					}
				}
				else {
					energy++;
					row--;
					Maze_1[row][col] = Hsym;
				}
			}
			else {
				energy++;
				row--;
				Maze_1[row][col] = Hsym;
			}
		}



		if (move == 'A' || move == 'a') {
			col--;
			if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
				energy--;
				if (Maze_1[row][col] != '#') {
					int x = check_Monsters(row, col, row_M, col_M, count);
					if (x == 1) {
						(*ptr_Monsters)++;
						col++;
						cout << "You are attacking a monster" << endl;
						Maze_1[row][col] = Hsym;
						count_2++;
						if (count_2 == 10) {
							col--;
							char x = Maze_1[row][col];
							cout << "Monster died!!" << endl;
							energy -= (int)x - '0';
							energy++;
							Maze_1[row][col] = Hsym;
							Maze_1[row][col + 1] = ' ';
							count_2 = 1;
						}
						else {
							cout << "Hit the Monster!!!" << endl;
							cout << "Monster's health -> " << 10 - (count_2) << endl;
						}
					}
					else if (Maze_1[row][col] == '1' || Maze_1[row][col] == '2' || Maze_1[row][col] == '3' || Maze_1[row][col] == '4' || Maze_1[row][col] == '5' || Maze_1[row][col] == '6' || Maze_1[row][col] == '7' || Maze_1[row][col] == '8' || Maze_1[row][col] == '9') {

						char x = Maze_1[row][col];
						energy += (int)x - '0';
						energy++;
						Maze_1[row][col] = Hsym;
						Maze_1[row][col + 1] = ' ';
					}
					else if (Maze_1[row][col] == ' ') {
						Maze_1[row][col] = Hsym;
						Maze_1[row][col + 1] = ' ';
					}
					else if (Maze_1[row][col] == char(177)) {
						(*ptr_Box)++;
						int c = solve_Riddle();
						if (c == 1) {
							energy += 11;
							Maze_1[row][col] = Hsym;
							Maze_1[row][col + 1] = ' ';
						}
						else if (c == 0) {
							Maze_1[row][col] = Hsym;
							Maze_1[row][col + 1] = ' ';
						}
						else if (c == 2) {
							Maze_1[save1][save2] = Hsym;
							Maze_1[row][col + 1] = ' ';
							Maze_1[row][col] = ' ';
							row = save1;
							col = save2;
						}
					}
					else if (Maze_1[row][col] == 'S') {
						energy++;
						col++;
						Maze_1[row][col] = Hsym;
					}
				}
				else {
					energy++;
					col++;
					Maze_1[row][col] = Hsym;
				}
			}
			else {
				energy++;
				col++;
				Maze_1[row][col] = Hsym;
			}
		}



		if (move == 'D' || move == 'd') {
			col++;
			if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
				energy--;
				if (Maze_1[row][col] != '#') {
					int x = check_Monsters(row, col, row_M, col_M, count);
					if (x == 1) {
						(*ptr_Monsters)++;
						col--;
						cout << "You are attacking a monster" << endl;
						Maze_1[row][col] = Hsym;
						count_2++;
						if (count_2 == 10) {
							col++;
							char x = Maze_1[row][col];
							cout << "Monster died!!" << endl;
							energy -= (int)x - '0';
							energy++;
							Maze_1[row][col] = Hsym;
							Maze_1[row][col - 1] = ' ';
							count_2 = 1;
						}
						else {
							cout << "Hit the Monster!!!" << endl;
							cout << "Monster's health -> " << 10 - (count_2) << endl;
						}
					}
					else if (Maze_1[row][col] == '1' || Maze_1[row][col] == '2' || Maze_1[row][col] == '3' || Maze_1[row][col] == '4' || Maze_1[row][col] == '5' || Maze_1[row][col] == '6' || Maze_1[row][col] == '7' || Maze_1[row][col] == '8' || Maze_1[row][col] == '9') {

						char x = Maze_1[row][col];
						energy += (int)x - '0';
						energy++;
						Maze_1[row][col] = Hsym;
						Maze_1[row][col - 1] = ' ';
					}
					else if (Maze_1[row][col] == ' ') {
						Maze_1[row][col] = Hsym;
						Maze_1[row][col - 1] = ' ';
					}
					else if (Maze_1[row][col] == char(177)) {
						(*ptr_Box)++;
						int c = solve_Riddle();
						if (c == 1) {
							energy += 11;
							Maze_1[row][col] = Hsym;
							Maze_1[row][col - 1] = ' ';
						}
						else if (c == 0) {
							Maze_1[row][col] = Hsym;
							Maze_1[row][col - 1] = ' ';
						}
						else if (c == 2) {
							Maze_1[save1][save2] = Hsym;
							Maze_1[row][col - 1] = ' ';
							Maze_1[row][col] = ' ';
							row = save1;
							col = save2;
						}
					}
				}
				else {
					energy++;
					col--;
					Maze_1[row][col] = Hsym;
				}
			}
			else {
				energy++;
				col--;
				Maze_1[row][col] = Hsym;
			}
		}
		while ((*ptr_Monsters) >= 9) {
			count_Mons++;
			(*ptr_Monsters) -= 9;
			(*ptr_Monsters) = count_Mons;
		}
		(*ptr_Row) = row;
		(*ptr_Col) = col;
		return energy;
	}



private:
	char Hsym;
	int row;
	int col;
	char move;
	int count;
	int row_M[10];
	int col_M[10];
	int random_M;
	int energy;
	int count_2;
	int save1;
	int save2;
	int count_Mons;
	int count_M;
};


class Food : public Maze {
public:
	Food() {
		symbol = 'F';
	}
	void random_Pos_H() {
		srand(time(0)); // function that make sure whether the numbers are shuffled properly before  generation
		for (int j = 0; j < 20; j++) {
			row[j] = rand() % 19;
		}
		for (int j = 0; j < 20; j++) {
			col[j] = rand() % 19;
		}
		for (int j = 0; j < 20; j++) {
			int row1 = row[j];
			int col2 = col[j];
			if (Maze_1[row1][col2] == ' ') {
				rand_F = (rand() % 9) + 1;
				Maze_1[row1][col2] = (char)rand_F + '0';
				cout << "Food\t" << j << " -> " << "\trow : " << row1 << "  " << "\tcol : " << col2 << endl;
			}
		}
	}

private:
	int symbol;
	int row[20], col[20];
	int rand_F;
};

class Monster : public Maze {
public:
	Monster() {
		symbol = 'M';
	}
	void random_Pos_M() {
		for (int j = 0; j < 20; j++) {
			row[j] = rand() % 19;
		}
		for (int j = 0; j < 20; j++) {
			col[j] = rand() % 19;
		}
		for (int j = 0; j < 20; j++) {
			int row1 = row[j];
			int col2 = col[j];
			if (Maze_1[row1][col2] == ' ') {
				rand_M = (rand() % 9) + 1;
				Maze_1[row1][col2] = symbol;
				cout << "Monster\t" << j << " -> " << "\trow : " << row1 << "  " << "\tcol : " << col2 << endl;
			}
		}
	}

private:
	int symbol;
	int row[20], col[20];
	int rand_M;
};

// Secret Boxes are generated in the maze
class secret_Item : public Maze {
public:
	secret_Item() {
		i = 0;
	}
	void place_IT() {
		while (1) {
			int row = rand() % 19;
			int col = rand() % 19;
			if (Maze_1[row][col] == ' ') {
				if (i == 6) {                             // three secret boxes are generated
					break;
				}
				row_R[i] = row;
				col_R[i] = col;
				i++;
			}
		}
		for (int j = 0; j < 6; j++) {
			int row = row_R[j];
			int col = col_R[j];
			Maze_1[row][col] = char(177); // special character that refers the secret box
		}
	}
private:
	int row_R[6];
	int col_R[6];
	int i;
};