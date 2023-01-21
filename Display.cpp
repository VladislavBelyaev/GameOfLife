#include "Display.h"

void display::Online::display(std::vector<std::string>comand, fild::Fild& fild)
{
	fild.ShowMt();
	while (true)
	{
		std::string option, argument;
		int value;
		std::cin >> option;
		if (option == golConstants::dump)
		{
			std::cin >> argument;
			fild.WriteFild(argument);
		}
		else if (option == golConstants::tick || option == golConstants::shortTick)
		{
			std::cin >> argument;
			try
			{
				if (argument[0] > '9' || argument[0] < '0' || stoi(argument) < 1)
					throw (std::string)"wrong argument\n";
			}
			catch(std::string err)
			{
				std::cout << err;
				continue;
			}
			value = stoi(argument);
			fild.Tick(value);
			system("CLS");
			fild.ShowMt();
		}
		else if (option == golConstants::ext)
		{
			break;
		}
		else if (option == golConstants::help)
		{
			std::cout << "dump <filename> - saving world in file\ntick <n> - calculating n iterations\nexit - stopping program\n";
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
			try
			{
				if (cmd[i + 1][0] > '9' || cmd[i + 1][0] < '0' || stoi(cmd[i + 1]) < 1)
					throw (std::string)"wrong argument\n";
			}
			catch (std::string err)
			{
				std::cout << err;
				break;
			}
			fild.Tick(stoi(cmd[i + 1]));
		}
		else if (cmd[i] == golConstants::iterationsShortKey)
		{
			try
			{
				if (cmd[i + 1][0] > '9' || cmd[i + 1][0] < '0' || stoi(cmd[i + 1]) < 1)
					throw (std::string)"wrong argument\n";
			}
			catch (std::string err)
			{
				std::cout << err;
				break;
			}
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
