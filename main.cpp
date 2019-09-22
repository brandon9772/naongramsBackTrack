
#include <ctime>
#include <iostream>
#include "Nanograms.h"
#include "Solver.h"
using namespace std;

int main()
{
	vector<string> allQuestion = {
		"question1_5x5.txt",
		"question1_10x10.txt", "question2_10x10.txt", "question3_10x10.txt",
		"question1_15x15.txt"
	};
	vector<int> failCount;
	vector<float> timeTaken;
	for (int i = 0; i < allQuestion.size(); i++) {
		clock_t begin_time = clock();
		Nanograms nanograms = Nanograms(allQuestion.at(i));
		Solver solver = Solver();
		nanograms.printAllBit();
		bool solveAble = solver.SolveNanograms(&nanograms);
		if (solveAble) {
			nanograms.printAllBit();
			cout << " solved" << endl;
		}
		else {
			nanograms.printAllBit();
			failCount.push_back(i);
			cout << "unsolvable" << endl;
		}
		timeTaken.push_back(float(clock() - begin_time) / CLOCKS_PER_SEC);
	}
	cout << "failed:";
	for (int i = 0; i < failCount.size(); i++) {
		cout << failCount.at(i) << ", ";
	}
	cout << endl;
	for (int i = 0; i < timeTaken.size(); i++) {
		cout << i << ": " << timeTaken.at(i) << " sec" << endl;
	}
	if (failCount.size() == 0) {
		cout << "all pass" << endl;
	}
	cout << endl;
}