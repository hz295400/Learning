#include "RegisterFactory.h"

/** BaseSolution */
BaseSolution::BaseSolution()
{
	initData();
}

BaseSolution::~BaseSolution()
{
}

void BaseSolution::initData()
{
	val = 123;
}

/** RegisterFactory */
shared_ptr<RegisterFactory> RegisterFactory::getInstance()
{
	static shared_ptr<RegisterFactory> g_Instance(new RegisterFactory());
	return g_Instance;
}

void RegisterFactory::registerSol(int nId, BaseSolution* sol)
{
	m_hashId2Sol[nId] = sol;
}

void RegisterFactory::clearSol()
{
	m_hashId2Sol.clear();
}

list<BaseSolution*> RegisterFactory::getSols()
{
	list<BaseSolution*>res;
	auto iter = m_hashId2Sol.begin();
	for (; iter != m_hashId2Sol.end(); iter++)
	{
		res.push_back(iter->second);
	}
	return res;
}
