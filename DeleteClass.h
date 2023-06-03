#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"


class DeleteClass : public UpdateInsertDeleteTemlateMethod
{
	int classId;

public:
	void prepareQuery();
	void prepareData();
};

