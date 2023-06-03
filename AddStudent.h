#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"

class AddStudent : public UpdateInsertDeleteTemlateMethod
{
protected:
	std::string name;
	int age;
	std::string gender;
	int formId;


	SqlQueryBuilder formSql;

	void prepareData();
	void prepareQuery();


public:

	AddStudent(SqlQueryBuilder formSql);


};

