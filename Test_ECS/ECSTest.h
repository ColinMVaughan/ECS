#ifndef ECS_TEST_H
#define ECS_TEST_H

#include <gtest/gtest.h>
#include "ECS.h"

TEST(ECSTest, CreateEntity)
{
	std::shared_ptr<ComponentManager> CompMgr = std::make_shared<ComponentManager>();
	std::shared_ptr<SystemManager> SysMgr     = std::make_shared<SystemManager>(CompMgr.get());

	ECS Master(SysMgr, CompMgr);
	Entity entity1 = Master.CreateEntity();
	Entity entity2 = Master.CreateEntity();

	EXPECT_TRUE(entity2.GetID() != 0);
}

TEST(EcsTest, DestroyEntity)
{
	ECS Master;
	Entity entity1 = Master.CreateEntity();
	Entity entity2 = Master.CreateEntity();

	Master.AddComponent<int>(entity1);
	Master.AddComponent<bool>(entity1);




	Master.DestroyEntity(entity1);
	

	EXPECT_TRUE(false);
}



#endif