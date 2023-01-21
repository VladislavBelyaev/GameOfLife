#include "BuildFild.h"

void builder::CreateFild::buildFild(std::string world, fild::Fild& mt)
{
	srand(time(NULL));
	world = golConstants::fileNames[rand() % 5];
	mt.ReadFild(world);
}

void builder::ImportFild::buildFild(std::string world, fild::Fild& mt)
{
	mt.ReadFild(world);
}