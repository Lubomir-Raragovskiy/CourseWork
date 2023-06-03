#pragma once
#include "AddTeacher.h"

class UpdateTeacher : public AddTeacher
{

protected:
	int teacherId;

public:
	virtual void prepareQuery();

	UpdateTeacher(SqlQueryBuilder formSql);
};

