#pragma once

#include "AddClass.h"
class UpdateClass : public AddClass
{

protected:
	int classId;

public:
	virtual void prepareQuery();

	UpdateClass(SqlQueryBuilder formSql);


};

