#pragma once
#include "BuildFild.h"
#include "Display.h"

class GameOfLive
{
private:
	std::vector<std::string>_comand;
	Fild*_fild;
	BuildFild* _builder;
	Display* _display;
	golConstants::Option toHandle(std::string);
public: 
	GameOfLive(std::vector<std::string>, Fild*);
	~GameOfLive();
	void setStrategy();
	void Work();
};