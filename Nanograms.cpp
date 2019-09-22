#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <bitset>
#include "Nanograms.h"
using namespace std;

Nanograms::Nanograms(string fileName) {
	cout << "started" << endl;
	string line;
	ifstream myfile(fileName);
	getline(myfile, line);
	istringstream issCol(line);
	issCol >> colSize;

	getline(myfile, line);
	istringstream issRow(line);
	issRow >> rowSize;

	for (int i = 0; i < colSize; i++) {
		getline(myfile, line);
		istringstream entry(line);
		vector<unsigned short int> thisCol;

		for (unsigned short int condition; entry >> condition;) {
			thisCol.push_back(condition);
		}
		colCondition.push_back(thisCol);
	}

	for (int i = 0; i < rowSize; i++) {
		getline(myfile, line);
		istringstream entry(line);
		vector<unsigned short int> thisRow;
		vector<unsigned short int> thismaxRowConditionStart;
		unsigned short int currentConditionStart = colSize + 1;

		for (unsigned short int condition; entry >> condition;) {
			thisRow.push_back(condition);
		}
		for (short int i = thisRow.size()-1; i >= 0; i--) {
			currentConditionStart -= thisRow.at(i) + 1;
			thismaxRowConditionStart.push_back(currentConditionStart);
		}
		reverse(thismaxRowConditionStart.begin(), thismaxRowConditionStart.end());
		maxRowConditionStart.push_back(thismaxRowConditionStart);
		rowCondition.push_back(thisRow);
		rowConditionStart.push_back(vector<unsigned short int>(thisRow.size(), -1));
	}
	filledAnswer = vector<vector<bool>>(rowSize, vector<bool>(colSize, false));
	myfile.close();
}

void Nanograms::printAll()
{
	cout << "colSize" << endl;
	cout << colSize << endl << endl;
	cout << "rowSize" << endl;
	cout << rowSize << endl << endl;
	cout << "colCondition" << endl;
	print(colCondition);
	cout << "rowCondition" << endl;
	print(rowCondition);
	cout << "rowConditionStart" << endl;
	print(rowConditionStart);
	cout << "thismaxRowConditionStart" << endl;
	print(maxRowConditionStart);
	cout << "filledAnswer" << endl;
	print(filledAnswer);
}

void Nanograms::printAllBit()
{
	cout << "colSize" << endl;
	cout << colSize << endl << endl;
	cout << "rowSize" << endl;
	cout << rowSize << endl << endl;
	cout << "colCondition" << endl;
	print(colCondition);
	cout << "rowCondition" << endl;
	print(rowCondition);
	cout << "rowConditionStart" << endl;
	print(rowConditionStart);
	cout << "thismaxRowConditionStart" << endl;
	print(maxRowConditionStart);
	cout << "filledAnswer" << endl;
	printBit(filledAnswer);
	
	
}

void Nanograms::printVariable(string variable)
{
	if (variable == "colSize") {
		cout << "colSize" << endl;
		cout << colSize << endl << endl;
	}
	else if (variable == "rowSize") {
		cout << "rowSize" << endl;
		cout << rowSize << endl << endl;
	}
	else if (variable == "colCondition") {
		cout << "colCondition" << endl;
		print(colCondition);
	}
	else if (variable == "rowConditionStart") {
		cout << "rowConditionStart" << endl;
		print(rowConditionStart);
	}
	else if (variable == "filledAnswer") {
		cout << "filledAnswer" << endl;
		print(filledAnswer);
	}
	else {
		cout << "no such variable" << endl << endl;
	}
}

void Nanograms::printBitVariable(string variable)
{
	if (variable == "colSize") {
		cout << "colSize" << endl;
		cout << colSize << endl << endl;
	}
	else if (variable == "rowSize") {
		cout << "rowSize" << endl;
		cout << rowSize << endl << endl;
	}
	else if (variable == "colCondition") {
		cout << "colCondition" << endl;
		print(colCondition);
	}
	else if (variable == "rowCondition") {
		cout << "rowCondition" << endl;
		print(rowCondition);
	}
	else if (variable == "rowConditionStart") {
		cout << "rowConditionStart" << endl;
		print(rowConditionStart);
	}
	else if (variable == "filledAnswer") {
		cout << "filledAnswer" << endl;
		printBit(filledAnswer);
	}
	else {
		cout << "no such variable" << endl << endl;
	}
}

void Nanograms::printBit(vector<long> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		cout << i << ": " << bitset<64>(toPrint.at(i)) << endl;
	}
	cout << "end." << endl << endl;
}

void Nanograms::printBit(vector<vector<long>> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		for (int j = 0; j < toPrint.at(i).size(); j++) {
			cout << bitset<64>(toPrint.at(i).at(j)) << ", ";
		}
		cout << endl;
	}
	cout << "end." << endl << endl;
}

void Nanograms::printBit(vector<vector<bool>> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		if (i < 10) {
			cout << 0;
		}
		cout << i << ": ";		
		for (int j = 0; j < toPrint.at(i).size(); j++) {
			cout << toPrint.at(i).at(j) << " ";
		}
		cout << endl;
	}
	cout << "end." << endl << endl;
}

void Nanograms::print(vector<vector<bool>> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		for (int j = 0; j < toPrint.at(i).size(); j++) {
			cout << toPrint.at(i).at(j) << " ";
		}
		cout << endl;
	}
	cout << "end." << endl << endl;
}

void Nanograms::print(vector<vector<unsigned short int>> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		for (int j = 0; j < toPrint.at(i).size(); j++) {
			cout << toPrint.at(i).at(j) << ", ";
		}
		cout << endl;
	}
	cout << "end." << endl << endl;
}

void Nanograms::print(vector<vector<long>> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		cout << i << ": ";
		for (int j = 0; j < toPrint.at(i).size(); j++) {
			cout << toPrint.at(i).at(j) << ", ";
		}
		cout << endl;
	}
	cout << "end." << endl << endl;
}

void Nanograms::print(vector<long> toPrint)
{
	int size = toPrint.size();
	for (int i = 0; i < size; i++) {
		cout << i << ": " << toPrint.at(i) << endl;
	}
	cout << "end." << endl << endl;
}
