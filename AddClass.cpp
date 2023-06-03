#include "AddClass.h"

void AddClass::prepareData()
{
	getForeignKey(formId, formSql, "Form");
	getForeignKey(teacherId, teacherSql, "Teacher");

}

void AddClass::prepareQuery()
{

	query = SqlQueryBuilder().insertInto("classes(teacher_id, form_id) ").
		values("( " + std::to_string(teacherId) +  " , " + std::to_string(formId) + " )");

}

AddClass::AddClass(SqlQueryBuilder formSql) : formSql(formSql)
{

	teacherSql = SqlQueryBuilder().select("teacher_name").from("teachers");
}
