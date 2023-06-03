#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"



class AddForm : public UpdateInsertDeleteTemlateMethod
{
protected:
	std::string name;

	virtual void prepareData();
	virtual void prepareQuery();
};

