#include "Solver.h"
#include <iostream>
Solver::Solver() {}

void Solver::updateNanogramsRemove(Nanograms* nanograms)
{
	unsigned short int thisConditionSize = nanograms->rowCondition.at(currentRowIndex).at(currentRowConditionIndex);
	for (unsigned short int i = currentRowConditionStart; i < currentRowConditionStart + thisConditionSize; i++) {
		nanograms->filledAnswer.at(currentRowIndex).at(i) = false;
	}
}

bool Solver::isPotentiallyVaild(Nanograms* nanograms, unsigned short int colStart, unsigned short int colEnd)
{
	if ((currentRowIndex == nanograms->rowSize - 1) & (currentRowConditionIndex == nanograms->rowCondition.at(currentRowIndex).size() - 1)) {
		colStart = 0;
		colEnd = nanograms->colSize;
	}
	for (unsigned short int i = colStart; i < colEnd; i++) {
		vector<unsigned short int> thisColStreak;
		unsigned short int streak = 0;
		for (unsigned short int j = 0; j < nanograms->rowSize; j++) {
			if (nanograms->filledAnswer.at(j).at(i)) {
				streak++;
			}
			else if (streak != 0) {
				thisColStreak.push_back(streak);
				streak = 0;
			}
		}
		if (streak != 0) {
			thisColStreak.push_back(streak);
		}		
		if (currentRowIndex == nanograms->rowSize - 1) {
			if (thisColStreak.size() != nanograms->colCondition.at(i).size()) {
				return false;
			}
			for (unsigned short int j = 0; j < thisColStreak.size(); j++) {
				if (thisColStreak.at(j) != nanograms->colCondition.at(i).at(j)) {
					return false;
				}
			}
		}
		else {
			if (thisColStreak.size() > nanograms->colCondition.at(i).size()) {
				return false;
			}
			for (unsigned short int j = 0; j < thisColStreak.size(); j++) {
				if (thisColStreak.at(j) > nanograms->colCondition.at(i).at(j)) {
					return false;
				}
			}
		}		
	}
	return true;
}

bool Solver::SolveNanograms(Nanograms* nanograms)
{
	unsigned short int rowSize = nanograms->rowSize;
	unsigned short int rowSizeMinusOne = nanograms->rowSize - 1;
	unsigned short int lastIndex = nanograms->rowCondition.at(rowSize - 1).size();
	int maxCounterRow = 0;
	
	while ((currentRowIndex < rowSizeMinusOne) | ((currentRowConditionIndex < lastIndex) & (currentRowIndex == rowSizeMinusOne))) {
		//nanograms->printVariable("filledAnswer");
		updateNanogramsAdd(nanograms);
		if (maxCounterRow < currentRowIndex) {
			maxCounterRow = currentRowIndex;
			cout << currentRowIndex << endl;
		}
		if (isPotentiallyVaild(nanograms, currentRowConditionStart, currentRowConditionStart + nanograms->rowCondition.at(currentRowIndex).at(currentRowConditionIndex))) {
			nanograms->rowConditionStart.at(currentRowIndex).at(currentRowConditionIndex) = currentRowConditionStart;
			currentRowConditionStart += nanograms->rowCondition.at(currentRowIndex).at(currentRowConditionIndex) + 1;
			currentRowConditionIndex++;
			while (currentRowConditionIndex >= nanograms->rowCondition.at(currentRowIndex).size()) {
				currentRowConditionStart = 0;
				currentRowConditionIndex = 0;
				currentRowIndex++;			
				if (currentRowIndex > rowSizeMinusOne) {
					return true;
				}
			}
			continue;
		}
		else {
			updateNanogramsRemove(nanograms);
			currentRowConditionStart++;
			while (currentRowConditionStart > nanograms->maxRowConditionStart.at(currentRowIndex).at(currentRowConditionIndex)) {
				while (currentRowConditionIndex == 0) {					
					if (currentRowIndex == 0) {
						return false;
					}
					currentRowIndex--;
					
					currentRowConditionIndex = nanograms->rowCondition.at(currentRowIndex).size();
				}
				currentRowConditionIndex--;
				currentRowConditionStart = nanograms->rowConditionStart.at(currentRowIndex).at(currentRowConditionIndex);
				updateNanogramsRemove(nanograms);
				currentRowConditionStart++;
			}
			continue;
		}
	}
	return false;
}

void Solver::updateNanogramsAdd(Nanograms* nanograms)
{
	if (currentRowConditionStart == -1) {
		return;
	}
	unsigned short int thisConditionSize = nanograms->rowCondition.at(currentRowIndex).at(currentRowConditionIndex);
	for (unsigned short int i = currentRowConditionStart; i < currentRowConditionStart + thisConditionSize; i++) {
		nanograms->filledAnswer.at(currentRowIndex).at(i) = true;
	}
}

