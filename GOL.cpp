#include "GOL.h"

golConstants::Option GameOfLive::toHandle(std::string cmd)
{
	if (cmd.find(golConstants::dot) < cmd.size())
	{
		return golConstants::Option::ChangeToImport;
	}
	if (cmd == golConstants::nameKey
		|| cmd == golConstants::nameShortKey)
	{
		return golConstants::Option::ChangeToOffline;
	}
	return golConstants::Option::Nothing;
}

GameOfLive::GameOfLive(std::vector<std::string> cmd, fild::Fild*f)
{
	_comand = cmd;
	_fild = f;
}

GameOfLive::~GameOfLive()
{
	delete[]_builder, _display;
}


void GameOfLive::setStrategy()
{
	for (int i = 1; i < _comand.size(); i++)
	{
		switch (toHandle(_comand[i]))
		{
		case golConstants::Option::ChangeToOffline:{
			_display = new display::Offline;
			i++; }						//пропуск следующего параметра
		case golConstants::Option::ChangeToImport: {
			_builder = new builder::ImportFild; }
		default:
			continue;
		}
	}
	if (_display == nullptr)
	{
		_display = new display::Online;
	}
	if (_builder == nullptr)
	{
		_builder = new builder::CreateFild;
	}
}

void GameOfLive::Work()
{
	_builder->buildFild(_comand.size() > golConstants::sizeOfEmptyComand ? _comand[golConstants::name] : _comand[golConstants::path], *_fild);
	_display->display(_comand, *_fild);
}
