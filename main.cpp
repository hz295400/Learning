#include<list>
#include "RegisterFactory.h"

int main()
{
	list<BaseSolution*> lstSols= RegisterFactory::getInstance()->getSols();
	for (auto sol : lstSols)
	{
		sol->exec();
	}
	return 0;
}