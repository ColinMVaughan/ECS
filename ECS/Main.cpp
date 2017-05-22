#include "ComponentManager.h"

int main()
{
	ComponentManager CManager;
	CManager.AddComponent<int>(0);
	CManager.AddComponent<int>(1);
	CManager.AddComponent<int>(2);

	int* collector = CManager.GetComponent<int>(0);
	*collector = 5;

	collector = CManager.GetComponent<int>(1);
	*collector = 6;

	collector = CManager.GetComponent<int>(2);
	*collector = 7;



	collector = CManager.GetComponent<int>(1);

	return 0;
}