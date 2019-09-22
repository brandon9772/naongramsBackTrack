#pragma once
#ifndef NANOGRAM_H
#define NANOGRAM_H
#endif
#include <string>
#include <vector>
using namespace std;

class Nanograms {

public:
	unsigned short int colSize;
	unsigned short int rowSize;
	vector<vector<unsigned short int>> colCondition;
	vector<vector<unsigned short int>> rowCondition;
	// a long where 1 is potential start for each condition
	vector<vector<unsigned short int>> rowConditionStart;
	vector<vector<unsigned short int>> maxRowConditionStart;
	vector<vector<bool>> filledAnswer;

	Nanograms(string fileName);
	void printAll();
	void printAllBit();
	void printVariable(string variable);
	void printBitVariable(string variable);
	void printBit(vector<vector<long>> toPrint);
	void printBit(vector<long> toPrint);
	void printBit(vector<vector<bool>> toPrint);
	void print(vector<vector<bool>> toPrint);
	void print(vector<vector<unsigned short int>> toPrint);
	void print(vector<vector<long>> toPrint);
	void print(vector<long> toPrint);
};