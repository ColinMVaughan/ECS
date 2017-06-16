#ifndef SYS_MANAGER_TEST_H
#define SYS_MANAGER_TEST_H


#include <gtest/gtest.h>
#include "SystemManager.h"
class TestSystem : public System<bool, int>
{
public:
	TestSystem(ComponentManager* a_cmanager) 
	: System(a_cmanager){}

	void Update(unsigned int entity) override
	{
		//bool* updated = m_CManager->GetComponent<bool>(entity);
		//*updated = true;
		
		HasUpdated = true;
	}

	bool HasUpdated = false;
};

TEST(SystemManagerTest, AddSystem)
{
	ComponentManager CManager;
	SystemManager SysManager(&CManager);

	TestSystem* testSys = SysManager.AddSystem<TestSystem>();

	EXPECT_TRUE(testSys != nullptr);
}

TEST(SystemManagerTest, DoesUpdateSystems)
{
	ComponentManager CManager;
	SystemManager SysManager(&CManager);

	TestSystem* testSys = SysManager.AddSystem<TestSystem>();
	SysManager.UpdateSystems(0.0, 0);


	EXPECT_TRUE(testSys->HasUpdated);
}

TEST(SystemManagerTest, UpdatesCorrectEntities)
{
	ComponentManager CManager;
	SystemManager SysManager(&CManager);

	CManager.AddComponent<bool>(0);
	CManager.AddComponent<bool>(1);
	CManager.AddComponent<int>(1);
	CManager.AddComponent<bool>(2);

	EXPECT_TRUE(false);
}

#endif