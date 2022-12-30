#include "BuildFild.h"

void CreateFild::buildFild(std::string world, Fild& mt)
{
	srand(time(NULL));
	world = golConstants::fileNames[rand() % 5];
	mt.ReadFild(world);
}

void ImportFild::buildFild(std::string world, Fild& mt)
{
	mt.ReadFild(world);
}