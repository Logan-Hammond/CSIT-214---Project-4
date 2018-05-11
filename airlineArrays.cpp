// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: airlineArrays.cpp
// Description: Assigns passenger seats on an airplane and calculates total cost.
// IDE Used:	Microsoft Visual Studio 2017

#include <iostream>		// IO.
#include <string>		// String manipulations.
#include <iomanip>		// setw().
#include "array.h"		// Arrays from project description.
using namespace std;

// Function Declarations. 
void displayPlane(char[ROW][COL]);	// Displays seat layout and availability. 
void getData(int &, char &);		// Requests user input and processes request.
void displayReceipt();				// Displays sales report.


// Function Definitions. 
/*
	Displays seat layout and availability by printing formatted 2D array.
	@param char[ROW][COL] passesd anonymous 2d array.
	@return void.
*/
void displayPlane(char[ROW][COL]) {
	cout << "\n";
	for (int i = 0; i < ROW; i++) {
		cout << "\t" << (i + 1) << ": ";	// Row numbers.
		for (int j = 0; j < COL; j++) {
			cout << layout[i][j] << "  ";	// Spacing.
		}
		cout << "\n";
	}
}

/*
	Requests and processes user input.
	@param int &row reference to passed int - Row of seat the user is requesting [1, 9].
	@param int &col reference to passed char - Column of seat the user is requesting [A, D].
	@return void.
*/
void getData(int &row, char &col) {
	// Get row. Acceptable input: -1, [1, 9].
	cout << "\n\n\tEnter Row (-1 to stop): ";
	cin >> row;
	while (((row != -1) && !(row >= 1 && row <= 9))) {				// Verify input. Loops until input is acceptable.
		cout << "\n\tError: Invalid input: Please try again.";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\n\n\tEnter Row (-1 to stop): ";
		cin >> row;
	}

	// Get column. Only executes if row is not -1 (exit choice). Acceptable input: a, b, c, d, A, B, C, D. 
	if (row != -1) {
		cout << "\tEnter Seat            : ";
		cin >> col;
		while (!(toupper(col) == 'A' || toupper(col) == 'B' || toupper(col) == 'C' || toupper(col) == 'D')) {		// Verify input. Loops until input is acceptable.
			cout << "\n\tError: Invalid input: Please try again.";
			cout << "\n\tEnter Seat            : ";
			cin >> col;
		}
		col = toupper(col);						// Verify input char is capitalized.
		col -= 65;								// Subtract 65 from ASCII value of input. Turns char into usuable format for parsing 2D array.

		// Verify seat is not taken and update layout/counter arrays.
		if (layout[row - 1][col] == 'X') {
			cout << "\n\tError: Seat filled. Please choose another.";
		}
		else {
			layout[row - 1][col] = 'X';
			if (row == 1) {
				classCtr[0]++;
			}
			else if (row >= 2 && row <= 4) {
				classCtr[1]++;
			}
			else if (row >= 5) {
				classCtr[2]++;
			}
		}
	}
}

/*
	Displays flight and sale information.
	@return void.
*/
void displayReceipt() {
	// Various info for sales report.
	int seatsFilled = 0;
	double seatsFilledPercentage = 0.00, totalSales = 0.00;
	// For formatting output.
	cout << fixed;
	cout << setprecision(2);

	// Calculates number of seats sold (based on classCtr array) and occupation percentage.
	for (int i = 0; i < 3; i++) {																										// Magic # "3" comes from number of flight classes (# elements in classCtr[]). Can't use
		seatsFilled += classCtr[i];																										// sizeof(classes) or classes.size(). Not sure why. Possibly because I am referencing 
	}																																	// an array defined in a header and not defining it in this file.
	seatsFilledPercentage = ((static_cast<double>(seatsFilled) / static_cast<double>(ROW * COL)) * 100.00);

	// Displays sales report. 
	cout << "\n\tSeats Filled: " << seatsFilled << "\n\tOccupation Percentage: " << seatsFilledPercentage << "%";
	cout << "\n\n" << setw(48) << "Sales Report" << "\n" << setw(36) << "Ticket Price" << setw(23) << "Category Sales";
	for (int i = 0; i < 3; i++) {																										 // See comment ln.90-92.
		cout << "\n\t" << setw(16) << classes[i] + " $" << fare[i] << setw(17) << classCtr[i] << "\t$" << classCtr[i] * fare[i];
		totalSales += classCtr[i] * fare[i];
	}
	cout << "\n\n\tTotal Sales: $" << totalSales;
}

int main() {
	// Vars for getData(int, char).  
	int chosenRow = 0;
	char chosenCol = 0;

	// Main sequence.
	cout << "\n\n\tChesapeake Airlines\n\n";
	displayPlane(layout);						// Pretest start.
	getData(chosenRow, chosenCol);
	while (chosenRow != -1) {
		displayPlane(layout);
		getData(chosenRow, chosenCol);
	}											// Pretest end.
	
	// Final output.
	cout << "\n\tFinal Layout";
	displayPlane(layout);
	displayReceipt();

	cout << "\n\n\t";
	system("pause");
	return 0;
}