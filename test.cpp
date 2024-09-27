#include "test.h"
#include <iostream>

void pureClassBase::func()
{};

pureClassBase::~pureClassBase()
{};

void driveClass::func()
{
	cout << "driveClass" << endl;
}
