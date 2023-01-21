#include "Display.h"

void display::Online::display(std::vector<std::string>comand, fild::Fild& fild)
{
	fild.ShowMt();
	while (true)
	{
		std::string option, argument;
		std::cin >> option;
		if (option == golConstants::dump)
		{
			std::cin >> argument;
			fild.WriteFild(argument);
		}
		else if (option == golConstants::tick || option == golConstants::shortTick)
		{
			std::cin >> argument;
			fild.Tick(stoi(argument));
			system("CLS");
			fild.ShowMt();
		}
		else if (option == golConstants::ext)
		{
			break;
		}
		else if (option == golConstants::help)
		{
			std::cout << "dump <filename> - saving world in file \n tick <n> - calculating n iterations \n exit - stopping program\n";
		}
		else
		{
			std::cout << "help?\n";
		}
	}
}

void display::Offline::display(std::vector<std::string>cmd, fild::Fild& fild)
{
	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i] == golConstants::iterationsKey)
		{
			fild.Tick(stoi(cmd[i + 1]));
		}
		else if (cmd[i] == golConstants::iterationsShortKey)
		{
			fild.Tick(stoi(cmd[i + 1]));
		}
		if (cmd[i] == golConstants::nameKey)
		{
			fild.WriteFild(cmd[i + 1]);
		}
		else if (cmd[i] == golConstants::nameShortKey)
		{
			fild.WriteFild(cmd[i + 1]);
		}
	}
}
