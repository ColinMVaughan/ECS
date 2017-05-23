#pragma once

#include "ComponentManager.h"
#include "BaseSystem.h"

class SystemManager
{
public:
	SystemManager(ComponentManager* cManager): m_ComponentManager(cManager) {}

	template<typename T>
	void AddSystem()
	{
		static_assert(std::is_base_of<BaseSystem, T>::value, "");
		SystemList.push_back(new T);
	}

	//-------------------------------
	// Loop through each system and update its corrisponding entities.
	//We need to figure out how to efficiently register systems with componets
	//------------------------------
	void UpdateSystems(double deltaTime, unsigned int entity)
	{
		for (int i = 0; i < SystemList.size(); ++i)
		{
			SystemList[i]->PreUpdate();

			for (int x = 0; x < 1; ++x)
			{
				SystemList[i]->Update(0);
			}

			SystemList[i]->PostUpdate();
		}
	}
	
private:
	ComponentManager* m_ComponentManager;
	std::vector<BaseSystem<>*> SystemList;
};