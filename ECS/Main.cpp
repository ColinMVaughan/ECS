#include "ComponentManager.h"
#include "SystemManager.h"
#include "BaseSystem.h"

int main()
{
	ComponentManager CManager;
	CManager.AddComponent<int>(0);
	CManager.AddComponent<bool>(0);

	CManager.AddComponent<int>(1);
	CManager.AddComponent<int>(2);

	
	if (CManager.HasComponents<int, bool>(0))
		std::cout << "YAAY";


	return 0;
}