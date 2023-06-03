#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"

class AddSubject : public UpdateInsertDeleteTemlateMethod
{
protected:
	std::string name;

	virtual void prepareData();
	virtual void prepareQuery();

};

