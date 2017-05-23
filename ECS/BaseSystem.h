#pragma once
#include<memory>
#include "ComponentManager.h"



//-----------------------------------------
//				BASE SYSTEM
// Derrive your system from this class to be able to submit it to the system manager.
// When derriving From base system, set component requirements by setting them as
// template arguments for BaseSystem.
//-----------------------------------------
class BaseSystem
{
public:
	virtual void Initalize() {};

	// PreUpdate:  runs one once per frame
	// Update:     runs once per applicable entity
	// PostUpdate: runs once per frame

	virtual void PreUpdate() {};
	virtual void Update(unsigned int entity) = 0;
	virtual void PostUpdate() {};

	virtual void UnInitalize() {};

	// returns true if the entity is registered with all the required components.
	virtual bool HasComponents(unsigned int entity);
};


template<typename C, typename... RequiredComponents>
class System
{
public:

	virtual void Initalize() {};

	// PreUpdate:  runs one once per frame
	// Update:     runs once per applicable entity
	// PostUpdate: runs once per frame

	virtual void PreUpdate() {};
	virtual void Update(unsigned int entity) {};
	virtual void PostUpdate() {};

	virtual void UnInitalize() {};

	// returns true if the entity is registered with all the required components.
	virtual bool HasComponents(unsigned int entity) final
	{
		return m_CManager->HasComponents<C, RequiredComponents...>(entity);
	}


private:
	ComponentManager* m_CManager;
};

class ExampleDerrivedSystem : public System<int, bool>
{
	void Update(unsigned int entity) override
	{
		return;
	}
};