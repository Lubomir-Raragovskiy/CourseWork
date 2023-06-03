#include "UpdateSubject.h"

void UpdateSubject::prepareQuery()
{

	getForeignKey(id, subjectSql, "Subject");

	if(!name.empty())
	query = SqlQueryBuilder().update("subjects").set("subject_name = '" + name + "'").where("subject_id = " + std::to_string(id));
}

UpdateSubject::UpdateSubject(SqlQueryBuilder subjectSql) : subjectSql(subjectSql)
{
}
