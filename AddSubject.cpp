#include "AddSubject.h"

void AddSubject::prepareData()
{
	getName(name, "Subject");
}

void AddSubject::prepareQuery()
{
	if(!name.empty())
	query = SqlQueryBuilder().insertInto("subjects(subject_name)").values("('" + name + "')");
}
