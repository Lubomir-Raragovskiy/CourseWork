#pragma once
#include "AddSubject.h"

class UpdateSubject : public AddSubject
{
	void prepareQuery();
	SqlQueryBuilder subjectSql;
	int id;


public:
	UpdateSubject(SqlQueryBuilder subjectSql);

};

