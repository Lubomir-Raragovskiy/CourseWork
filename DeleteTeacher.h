#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"

class DeleteTeacher : public UpdateInsertDeleteTemlateMethod
{

	int teacherId;

public:
	void prepareQuery();
	void prepareData();
};

