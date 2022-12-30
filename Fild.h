#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include "GOLConsts.h"

class Fild
{
private:
	std::vector<std::vector<bool>>_mt;
	std::vector<golConstants::Write> _rules;
	size_t _sizeX;
	size_t _sizeY;
	const size_t Before(size_t, golConstants::Axis);
	const size_t Here(size_t, golConstants::Axis);
	const size_t After(size_t, golConstants::Axis);
	golConstants::Write CheckCell(size_t, size_t);
public:
	Fild();
	std::vector<std::vector<bool>> ForTest();
	void MakeMt();
	void ShowMt();
	const size_t sizeOfAxis(golConstants::Axis);
	void WriteCell(size_t, size_t);
	bool ReadCell(size_t, size_t);
	void Tick();
	void Tick(size_t);
	void WriteFild(std::string);
	void ReadFild(std::string);
};
