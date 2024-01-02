#pragma once
/*
	@author Kesavakumar Sivalingam Id: 1142701377
	This maze program is built using C++.

	This program has been added with some special features. An unknown secret boxes are placed in the maze.

	Functions that are defined below are the ones which prompts the user whenever the hero checks into one of the secret boxes
	This functions prompts the user with the riddle and checks the whether the answer given by the user is correct or not
*/
int riddle_1() {
	string x;
	cout << "What can travel around the world while staying in a corner?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {                              // converts the string to small letters before checking it with the correct answer 
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("stamp") == 0) {
		return 1;
	}
}

int riddle_2() {
	string x;
	cout << "If you have me, you want to share me. If you share me, you haven't got me. What am I?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("secret") == 0) {
		return 1;
	}
}
int riddle_3() {
	string x;
	cout << "Take off my skin , I won't cry, but you will! What am I?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("onion") == 0) {
		return 1;
	}
}
int riddle_4() {
	string x;
	cout << "If I drink, I die. If I eat, I am fine. What am I?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("fire") == 0) {
		return 1;
	}
}
int riddle_5() {
	string x;
	cout << "I run distances, often making many turns, yet I never move one foot. What am I?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("watch") == 0) {
		return 1;
	}
}
int riddle_6() {
	string x;
	cout << "You answer me, although I never ask you questions. What am I?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("phone") == 0) {
		return 1;
	}
}

int riddle_7() {
	string x;
	cout << "The more it dries, the wetter it gets. What is it?" << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i++) {
		if ((x[i] > 64) && (x[i] < 91)) {
			x[i] = x[i] + 32;
		}
	}
	if (x.compare("towel") == 0) {
		return 1;
	}
}

// This function differs from the previous as this is the one which returns integers to hero class.
// Increases the pointer which holds the address if riddle (responsible to change the question)
//
int solve_Riddle() {
	int x;
	int count = 0;
	char input;
	char input1;
	cout << "You are now about to enter a powerful zone!!" << endl;
	cout << "Do you want to access the secret box ?? <Y for yes and N for no> : ";
	cin >> input;
	if (input == 'Y' || input == 'y') {
		if (riddle == 1) {
			x = riddle_1();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
		if (riddle == 2) {
			x = riddle_2();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
		if (riddle == 3) {
			x = riddle_3();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
		if (riddle == 4) {
			x = riddle_4();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
		if (riddle == 5) {
			x = riddle_5();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
		if (riddle == 6) {
			x = riddle_6();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
		if (riddle == 7) {
			x = riddle_7();
			if (x == 1) {
				(*riddle3)++;
				return 1;
			}
			else {
				return 2;
			}
		}
	}
	else {
		return 0;
	}
}

