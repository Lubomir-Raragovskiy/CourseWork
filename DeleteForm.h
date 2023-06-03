#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"

class DeleteForm : public UpdateInsertDeleteTemlateMethod
{
	int id;
	SqlQueryBuilder formSql;

	virtual void prepareData();
	virtual void prepareQuery();

public:
	DeleteForm(SqlQueryBuilder formSql);
};