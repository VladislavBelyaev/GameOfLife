#pragma once
#ifndef Fild
#include "Fild.h"
#endif

namespace builder
{
	class BuildFild
	{
	public:
		virtual void buildFild(std::string, fild::Fild&) = 0;
	};

	class ImportFild : public BuildFild
	{
	public:
		virtual void buildFild(std::string, fild::Fild&) override;
	};

	class CreateFild : public BuildFild
	{
	public:
		virtual void buildFild(std::string, fild::Fild&) override;
	};
}