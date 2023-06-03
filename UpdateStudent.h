#pragma once
#include "AddStudent.h"

class UpdateStudent : public AddStudent
{
protected:
	int studentId;

public:
	virtual void prepareQuery();

	UpdateStudent(SqlQueryBuilder formSql);

};

