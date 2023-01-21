#include "pch.h"
#include "../GOL.h"

TEST(TestGOL, TestTick) {
	fild::Fild first, second;
	first.ReadFild("Examples/Pentapole.lif");
	first.Tick(2);
	second.ReadFild("Examples/Pentapole.lif");
	EXPECT_EQ(first.ForTest(), second.ForTest());
}

TEST(TestGOL, TestWrite) {
	fild::Fild first, second, third;
	first.ReadFild("Examples/Glider.lif");
	second.ReadFild("Examples/Glider.lif");
	first.Tick(5);
	second.Tick(5);
	first.WriteFild("toTest.life");
	third.ReadFild("toTest.life");
	EXPECT_EQ(second.ForTest(), third.ForTest());
	remove("toTest.life");
}

TEST(TestGOL, TestCycle) {
	fild::Fild first, second;
	first.ReadFild("Examples/Brain.lif");
	second.ReadFild("Examples/Brain.lif");
	first.Tick(75);
	EXPECT_EQ(first.ForTest(), second.ForTest());
}
