#pragma once
#include "AddForm.h"

class UpdateForm : public AddForm
{

	void prepareQuery();
	SqlQueryBuilder formSql;
	int id;


public:
	UpdateForm(SqlQueryBuilder formSql);
};

