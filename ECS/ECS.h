//-------------------------------------------------
//					Colin Vaughan
// ECS class is used to
//--------------------------------------------------



#pragma once
#include <memory>
#include "SystemManager.h"
#include "ComponentManager.h"

struct Entity
{
public:
	Entity(unsigned int a_id):m_ID(a_id){}
	unsigned int GetID() { return m_ID; }

private:
	unsigned int m_ID;
};


class ECS
{

public:
	ECS(SystemManager* a_systemMgr, ComponentManager* a_compMgr)
	: m_SystemManager(a_systemMgr) , m_ComponentManager(a_compMgr){}

	Entity CreateEntity();
	void DestroyEntity(Entity a_entity);

	template<typename T>
	std::shared_ptr<T> AddComponent(Entity a_entity);

	template<typename T> 
	std::shared_ptr<T> AddSystem();

	template<typename T>
	std::shared_ptr<T> GetComponent(Entity a_entity);

	void UpdateSystems();
	
private:
	SystemManager*    m_SystemManager;
	ComponentManager* m_ComponentManager;

	unsigned int EntityCounter;
};


//					IMPLEMENTATION
//------------------------------------------------------------------------------

inline Entity ECS::CreateEntity()
{
	EntityCounter++;
	return Entity(EntityCounter);
}

////Destroys all components associated with the entity and remove it from the list
//inline void ECS::DestroyEntity(Entity a_entity)
//{
//}
//
//template <typename T>
//std::shared_ptr<T> ECS::AddComponent(Entity a_entity)
//{
//	return 0;
//}
//
//template <typename T>
//std::shared_ptr<T> ECS::AddSystem()
//{
//	return m_SystemManager->AddSystem<T>();
//}
