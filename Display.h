#pragma once
#ifndef Fild
#include "Fild.h"
#endif

namespace display
{
	class Display
	{
	public:
		virtual void display(std::vector<std::string>, fild::Fild& fild) = 0;
	};
	
	class Online : public Display
	{
	public:
		virtual void display(std::vector<std::string>, fild::Fild& fild) override;
	};

	class Offline : public Display
	{
	public:
		virtual void display(std::vector<std::string>, fild::Fild& fild) override;
	};
}
