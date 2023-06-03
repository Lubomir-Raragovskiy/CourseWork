#include "DeleteSubject.h"

void DeleteSubject::prepareData()
{
	getForeignKey(id, subjectSql, "Subject");

}

void DeleteSubject::prepareQuery()
{


	query = SqlQueryBuilder().delete_("").from("subjects").where("subject_id = " + std::to_string(id));
}

DeleteSubject::DeleteSubject(SqlQueryBuilder subjectSql) : subjectSql(subjectSql)
{
}
