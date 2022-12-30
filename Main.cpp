#include "GOL.h"

int main(int argc, char* argv[])
{
	std::vector<std::string> cmd(argc);  //{ "1", "Examples/Brain.lif", "-o", "Exmp", "-i", "100" };
	for (int i = 0; i < argc; i++)
	{
		cmd[i] = argv[i];
	}
	Fild f;
	GameOfLive g(cmd, &f);
	g.setStrategy();
	g.Work();
	return 0;
}