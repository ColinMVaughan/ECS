#pragma once
#include <SystemManager.h>
#include <ComponentManager.h>
#include <ECS.h>

class Map
{
public:
	char data[10][10];
};

class DrawMapSystem : public System<Map>
{
	virtual void Update(unsigned int entity)
	{
		Map* map = m_CManager->GetComponent<Map>(entity);

		system("cls");
		for(int y = 0; y < 10; y++)
		{
			std::cout << "\n";
			for(int x = 0; x < 10; x++)
			{
				std::cout << map->data[y][x];
			}
		}
	}
};


class Demo
{

public:
	void Initalize()
	{
		//Initalize ECS Managers
		m_CompMan = new ComponentManager;
		m_SysMan  = new SystemManager(m_CompMan);
		m_ECS     = new ECS(m_SysMan, m_CompMan);

		//Add Systems
		m_SysMan->AddSystem<DrawMapSystem>();


		//Add Components for Map
		m_ECS->AddComponent<Map>(m_Map);
		Map* map = m_CompMan->GetComponent<Map>(0);
		for(int y = 0; y< 10; y++)
		{
			for (int x = 0; x< 10; x++)
			{
				map->data[y][x] = '@';
			}
		}


	}
	void Update()
	{
		for(;;)
		{
			m_ECS->UpdateSystems();
		}
	}
	void Unload();

private:
	ECS*			  m_ECS;
	SystemManager*	  m_SysMan;
	ComponentManager* m_CompMan;

	Entity m_Map;
	Entity m_Player;
};