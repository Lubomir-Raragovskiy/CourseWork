#pragma once

#include "UpdateInsertDeleteTemlateMethod.h"

class AddTeacher : public UpdateInsertDeleteTemlateMethod
{
protected:
	std::string name;
	int age;
	std::string gender;
	float salary;
	int subjectId;


	SqlQueryBuilder subjectSql;

	virtual void prepareData();
	virtual void prepareQuery();

public:
	AddTeacher(SqlQueryBuilder subjectSql);
};

