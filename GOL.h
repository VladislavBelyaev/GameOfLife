#pragma once
#include "BuildFild.h"
#include "Display.h"

class GameOfLive
{
private:
	std::vector<std::string>_comand;
	fild::Fild*_fild;
	builder::BuildFild* _builder;
	display::Display* _display;
	golConstants::Option toHandle(std::string);
public: 
	GameOfLive(std::vector<std::string>, fild::Fild*);
	~GameOfLive();
	void setStrategy();
	void Work();
};