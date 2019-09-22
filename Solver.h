#pragma once
#include "Nanograms.h"

class Solver
{
private:
	unsigned short int currentRowConditionIndex = 0;
	unsigned short int currentRowConditionStart = 0;
	unsigned short int currentRowIndex = 0;
public:
	Solver();
	void updateNanogramsAdd(Nanograms* nanograms);
	void updateNanogramsRemove(Nanograms* nanograms);
	bool isPotentiallyVaild(Nanograms* nanograms, unsigned short int colStart, unsigned short int colEnd);
	bool SolveNanograms(Nanograms* nanograms);
};

