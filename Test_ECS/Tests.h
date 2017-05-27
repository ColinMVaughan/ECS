#pragma once
#include <gtest\gtest.h>
#include <ComponentManager.h>

TEST(ComponentManagerTest, HasComponent)
{
	//----------------------------------------------
	{
		//ComponentManager CManager;
		//CManager.AddComponent<int>(0);
		//CManager.AddComponent<bool>(0);
		//
		//bool result = CManager.HasComponents<int, bool>(0);
		//EXPECT_TRUE(result);
	}
	//------------------------------------------
	{
		ComponentManager CManager;
		CManager.AddComponent<int>(0);

		bool Result = CManager.HasComponents<int, bool>(0);
		EXPECT_FALSE(Result);
	}

}

TEST(ComponentManagerTest, AddComponent)
{
	{
		ComponentManager CManager;
		CManager.AddComponent<bool>(0);

		bool* result = CManager.GetComponent<bool>(0);
		*result = true;

		EXPECT_TRUE(result);
	}

	{
		ComponentManager CManager;
		CManager.AddComponent<bool>(0);

		bool* result = CManager.GetComponent<bool>(0);
		*result = false;

		EXPECT_FALSE(result);
	}
}