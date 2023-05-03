#include <iostream>
#include "DynamicArray.h"
#include <fstream>
#include <string>

using namespace std;

int main() {


	//Needed variables
	int commandNum;
	string command;
	int value;
	string temp;
	DynamicArray dArray;

	//open input file
	ifstream fin("commands.txt");

	//test input file
	if (!fin) {
		cout << "File doesn't exist" << endl;
		system("pause");
		return -1;
	}

	//Create output file
	ofstream fout("invalid.txt");

	//Read and process commands from input
	fout << "INVALID COMMANDS" << endl;

	//Loop to get inputs from file
	//Get first two inputs, command number and the command
	while (fin >> commandNum >> command) {
		
		//Check if Command is to POP value out of array
		if (command == "POP") {

			//Make sure array is not empty and delete value if so
			if (dArray.size() > 0) {
				dArray.popBack();
			}
			//If array is empty, write command number to file as invalid
			else {
				fout << commandNum << endl;
			}
		}
		
		//Check if command is to push value into array.
		if (command == "PUSH") {
			//Get value from file input
			fin >> value;
			//Check that value is a valid unsigned int and push into array if so.
			if (value >= 0) {
				dArray.pushBack(value);
			}
			//otherwise output command number to file as invalid.
			else {
				fout << commandNum << endl;
			}
		}
	}
	
	//Close files and exit
	fin.close();
	fout.close();
	return 0;
}