#pragma once
#include <memory>
#include "SystemManager.h"
#include "ComponentManager.h"

struct Entity
{
	Entity(unsigned int a_id):m_ID(a_id){}
	unsigned int GetID() { return m_ID; }

private:
	unsigned int m_ID;
};


class ECS
{
public:
	ECS(){}

	Entity CreateEntity();
	void DestroyEntity();

	template<typename T>
	std::shared_ptr<T> AddComponent(Entity a_entity);

	template<typename T> 
	std::shared_ptr<T> AddSystem();


	void UpdateSystems();
	
private:
	std::shared_ptr<SystemManager>    m_SystemManager;
	std::shared_ptr<ComponentManager> m_ComponentManager;

	unsigned int EntityCounter;
};

//					IMPLEMENTATION
//------------------------------------------------------------------------------
template <typename T>
std::shared_ptr<T> ECS::AddComponent(Entity a_entity)
{
	return m_ComponentManager->AddComponent<T>(a_entity.GetID());
}

template <typename T>
std::shared_ptr<T> ECS::AddSystem()
{
	return m_SystemManager->AddSystem<T>();
}
