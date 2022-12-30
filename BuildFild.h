#pragma once
#ifndef Fild
#include "Fild.h"
#endif

class BuildFild
{
public:
	virtual void buildFild(std::string, Fild&) = 0;
};

class ImportFild : public BuildFild
{
public:
	virtual void buildFild(std::string, Fild&) override;
};

class CreateFild : public BuildFild
{
public:
	virtual void buildFild(std::string, Fild&) override;
};
