#pragma once
#ifndef Fild
#include "Fild.h"
#endif

class Display
{
public:
	virtual void display(std::vector<std::string>, Fild& fild) = 0;
};

class Online : public Display
{
public:
	virtual void display(std::vector<std::string>, Fild& fild) override;
};

class Offline : public Display
{
public:
	virtual void display(std::vector<std::string>, Fild& fild) override;
};
