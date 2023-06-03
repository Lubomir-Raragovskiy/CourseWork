#pragma once

#include "UpdateInsertDeleteTemlateMethod.h"


class AddClass : public UpdateInsertDeleteTemlateMethod
{

protected:
	int teacherId;
	int formId;


	SqlQueryBuilder formSql;
	SqlQueryBuilder teacherSql;

	void prepareData();
	void prepareQuery();


public:

	AddClass(SqlQueryBuilder formSql);



};

