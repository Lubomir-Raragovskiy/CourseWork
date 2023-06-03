#pragma once

#include "UpdateInsertDeleteTemlateMethod.h"

class DeleteSubject : public UpdateInsertDeleteTemlateMethod
{
	int id;
	SqlQueryBuilder subjectSql;

	virtual void prepareData();
	virtual void prepareQuery();

public:
	DeleteSubject(SqlQueryBuilder subjectSql);
};

