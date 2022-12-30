#include <string>

namespace golConstants
{
	enum class Axis { Ox, Oy };
	enum class Write { Errase, DoNotChange, Paint };
	enum class Option { Nothing, ChangeToOffline, ChangeToImport };
	const char dot = '.';
	const int step = 1;
	const int sizeOfEmptyComand = 1;
	const int path = 0;
	const int name = 1;
	const std::string dump = "dump";
	const std::string tick = "tick";
	const std::string shortTick = "t";
	const std::string ext = "exit";
	const std::string help = "help";
	const std::string nameKey = "--output";
	const std::string nameShortKey = "-o";
	const std::string iterationsKey = "--iterations";
	const std::string iterationsShortKey = "-i";
	const std::string extensionOne = ".life";
	const std::string extensionTwo = ".lif";
	const std::string beacon = "Examples/Beacon.lif";
	const std::string brain = "Examples/Brain.lif";
	const std::string glider = "Examples/Glider.lif";
	const std::string pentapole = "Examples/Pentapole.lif";
	const std::string spaceship = "Examples/Spaceship.lif";
	const std::string fileNames[] = { beacon, brain, glider, pentapole, spaceship };
}