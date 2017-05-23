#pragma once
#include <gtest\gtest.h>
#include <ComponentManager.h>

TEST(ComponentManagerTest, HasComponent)
{
	ComponentManager CManager;
	CManager.AddComponent<int>(0);
	CManager.AddComponent<bool>(0);

	bool result = CManager.HasComponents<int, bool>(0);
	EXPECT_TRUE(result);
}