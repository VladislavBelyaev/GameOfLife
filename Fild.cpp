#include "Fild.h"


fild::Fild::Fild()
{
	_sizeX = 0;
	_sizeY = 0;
	_rules = { golConstants::Write::Errase, golConstants::Write::Errase, golConstants::Write::Errase, golConstants::Write::Errase,
				golConstants::Write::Errase, golConstants::Write::Errase, golConstants::Write::Errase, golConstants::Write::Errase };
}

std::vector<std::vector<bool>> fild::Fild::ForTest()
{
	return _mt;
}

const size_t fild::Fild::sizeOfAxis(golConstants::Axis axis)
{
	if (axis == golConstants::Axis::Ox)
	{
		return this->_sizeX;
	}
	else
	{
		return this->_sizeY;
	}
}

void fild::Fild::MakeMt()
{
	_mt = std::vector<std::vector<bool>>(_sizeX, std::vector<bool>(_sizeY));
	for (int i = 0; i < _sizeX; i++)
	{
		for (int j = 0; j < _sizeY; j++)
		{
			_mt[i][j] = 0;
		}
	}

}

const size_t fild::Fild::Before(size_t pos, golConstants::Axis axis)
{
	if ((int)pos - golConstants::step < 0)
	{
		return sizeOfAxis(axis) - golConstants::step;
	}
	else
	{
		return pos - golConstants::step;
	}
}

const size_t fild::Fild::Here(size_t pos, golConstants::Axis axis)
{
	return pos;
}

const size_t fild::Fild::After(size_t pos, golConstants::Axis axis)
{
	if (pos + golConstants::step >= sizeOfAxis(axis))
	{
		return 0;
	}
	else
	{
		return pos + golConstants::step;
	}
}

void fild::Fild::WriteCell(size_t x, size_t y)
{
	_mt[x][y] = 1;
}

void fild::Fild::ShowMt()
{
	for (int i = 0; i < _sizeX; i++)
	{
		for (int j = 0; j < _sizeY; j++)
		{
			std::cout << _mt[i][j];
		}
		std::cout << std::endl;
	}
}

bool fild::Fild::ReadCell(size_t x, size_t y)
{
	return this->_mt[x][y];
}

void fild::Fild::Tick()
{
	std::vector<std::vector<bool>> cpy = this->_mt;
	golConstants::Write flag = golConstants::Write::DoNotChange;
	for (size_t i = 0; i < _sizeX; i++)
	{
		for (size_t j = 0; j < _sizeY; j++)
		{
			flag = CheckCell(i, j);
			if (flag == golConstants::Write::Errase)
			{
				cpy[i][j] = 0;
			}
			else if (flag == golConstants::Write::Paint)
			{
				cpy[i][j] = 1;
			}
		}
	}
	_mt = cpy;
}

void fild::Fild::WriteFild(std::string fileName)
{
	if (fileName.find(golConstants::extensionOne) > fileName.size() || fileName.find(golConstants::extensionTwo) > fileName.size())
	{
		fileName.insert(fileName.size(), golConstants::extensionOne);
	}
	std::ofstream out;
	out.open(fileName, 'w');
	try
	{
		if (!out.is_open())
			throw (std::string)"Unexpected error\n";
	}
	catch(std::string err)
	{
		std::cout << err;
		return;
	}
	out << "#Life 1.06" << std::endl << "#R B";
	for (int i = 0; i < this->_rules.size(); i++)
	{
		if (this->_rules[i] == golConstants::Write::Paint)
		{
			out << i;
		}
	}
	out << "/S";
	for (int i = 0; i < this->_rules.size(); i++)
	{
		if (this->_rules[i] == golConstants::Write::DoNotChange)
		{
			out << i;
		}
	}
	out << std::endl << this->_sizeX << " " << this->_sizeY << std::endl;
	for (int i = 0; i < this->sizeOfAxis(golConstants::Axis::Ox); i++)
	{
		for (int j = 0; j < this->sizeOfAxis(golConstants::Axis::Oy); j++)
		{
			if (this->ReadCell(i, j))
			{
				out << i << " " << j << std::endl;
			}
		}
	}
	out.close();
}

void fild::Fild::Tick(size_t value)
{
	for (size_t i = 0; i < value; i++)
	{
		Tick();
	}
}

golConstants::Write fild::Fild::CheckCell(size_t x, size_t y)
{
	size_t cells = 0;
	std::vector<const size_t(Fild::*)(size_t, golConstants::Axis)> positionFounder = { &Fild::Before, &Fild::Here, &Fild::After };
	for (const size_t(Fild::* changePositionAlongX)(size_t, golConstants::Axis) : positionFounder)
	{
		for (const size_t(Fild::* changePositionAlongY)(size_t, golConstants::Axis) : positionFounder)
		{
			if (changePositionAlongX != &Fild::Here || changePositionAlongY != &Fild::Here)
			{
				cells += _mt[(this->*(changePositionAlongX))(x, golConstants::Axis::Ox)][(this->*(changePositionAlongY))(y, golConstants::Axis::Oy)];
			}
		}
	}
	return _rules[cells];
}

void fild::Fild::ReadFild(std::string world)
{
	std::ifstream file(world);
	try
	{
		if (file.fail())
		{
			throw "File doesnt exist";
		}
		if (world.find(golConstants::extensionOne) > world.size() && world.find(golConstants::extensionTwo) > world.size())
		{
			throw "Wrong extension";
		}
	}
	catch (const char* expt)
	{
		std::cout << expt;
		exit(0);
	}
	std::string line;
	getline(file, line);
	getline(file, line);
	for (int i = line.find('S') + 1; i < line.size(); i++)
	{
		this->_rules[line[i] - '0'] = golConstants::Write::DoNotChange;
	}
	for (int i = line.find('B') + 1; i < line.find('/'); i++)
	{
		this->_rules[line[i] - '0'] = golConstants::Write::Paint;
	}
	getline(file, line);
	this->_sizeX = stoi(line);
	this->_sizeY = stoi(line.substr(line.find(' ') + 1));
	this->MakeMt();
	std::string positionX, positionY;
	while (getline(file, positionX))
	{
		positionY = &positionX[positionX.find(' ') + 1];
		this->WriteCell(stoi(positionX), stoi(positionY));
	}
	file.close();
}
