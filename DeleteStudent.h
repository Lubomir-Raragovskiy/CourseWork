#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"

class DeleteStudent : public UpdateInsertDeleteTemlateMethod
{

	int studentId;

public:
	void prepareQuery();
	void prepareData();

};

