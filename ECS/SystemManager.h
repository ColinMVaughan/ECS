#pragma once
#include "ComponentManager.h"


class BaseSystem 
{
public:
	virtual void Initalize() {};
	virtual void Update(unsigned int entity, ComponentManager* cManager) = 0;
	virtual void UnInitalize() {};

private:

};



class SystemManager
{
public:
	SystemManager(ComponentManager* cManager);

	template<typename T>
	void AddSystem()
	{
		static_assert(std::is_base_of<BaseSystem, T>::value, "");
		SystemList.push_back(new T);
	}

	void UpdateSystem(double deltaTime, unsigned int entity);

private:
	ComponentManager* m_ComponentManager;
	std::vector<BaseSystem*> SystemList;
};