#pragma once

using namespace std;

class pureClassBase
{
public:
	virtual void func() = 0;

	virtual ~pureClassBase() = 0;
};

class driveClass : public pureClassBase
{
	void func() override;
};