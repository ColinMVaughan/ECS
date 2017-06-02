#include <gtest\gtest.h>
#include "ComponentManagerTest.h"
#include "SystemManagerTest.h"

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	//system("Pause");
	return 0;
}