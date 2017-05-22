#pragma once
#include <string>
#include <map>
#include <vector>
#include<iostream>
#include <utility>



class BaseComponentPool{};

template <typename T>
class ComponentPool : public BaseComponentPool
{
public:
	void AddComponent(unsigned int entityID)
	{
		T comp;
		Components.insert(std::make_pair(entityID, comp));
	}

	T* GetComponent(unsigned int entityID)
	{
		return &Components.at(entityID);
	}

private:
	std::map<unsigned int, T> Components;
};

//------------------------------------------
// Holds a list of componet pools
//--------------------------------------------
class ComponentManager
{
public:
	
	template<typename T>
	void init()
	{
		BaseComponentPool* temp;
		temp = new ComponentPool<T>();
		PoolMap.insert(std::map<size_t, BaseComponentPool*>::value_type(typeid(T).hash_code(), temp));
	}
	//
	//Adds a componet to its corrisponding pool. 
	//Component must be derrived from BaseComponent
	//
	template<typename T>
	void AddComponent(unsigned int entity)
	{
		//if the component pool does not exitst, add a new one.
		auto iterator = PoolMap.find(typeid(T).hash_code());
		if (iterator == PoolMap.end())
		{
			BaseComponentPool* temp = new ComponentPool<T>();
			PoolMap.insert(std::map<size_t, BaseComponentPool*>::value_type(typeid(T).hash_code(), temp));
		}

		//Add componet to the correct pool
		BaseComponentPool* temp = PoolMap.at(typeid(T).hash_code());
		ComponentPool<T>* pool = static_cast<ComponentPool<T>*>(temp);
		pool->AddComponent(entity);

	}

	template<typename T>
	T* GetComponent(unsigned int entity)
	{
		BaseComponentPool* temp = PoolMap.at(typeid(T).hash_code());
		ComponentPool<T>* pool = static_cast<ComponentPool<T>*>(temp);
		return pool->GetComponent(entity);
	}

private:
	std::map<size_t, BaseComponentPool*> PoolMap;
};


//--------------------------------------
//
//-------------------------------------
//template<typename T> Component* CreateComponent() { return T; }
//
//
//class ComponentFactory
//{
//public:
//	typedef std::map<std::string, Component*(*)()> map_type;
//
//	static Component* CreateInstance(std::string const& s)
//	{
//		map_type::iterator it = getMap()->find(s);
//		if (it == getMap()->end())
//			return 0;
//
//		return it->second();
//	}
//
//
//protected:
//	static map_type* getMap()
//	{
//		if (!map) { map = new map_type; }
//		return map;
//	}
//private:
//	static map_type* map;
//	
//};