#include "UpdateTeacher.h"

void UpdateTeacher::prepareQuery()
{

	getNumber(teacherId, "ID");

	query = SqlQueryBuilder().update("teachers")
		.set((!name.empty() ? ("teacher_name = ' " + name + "',") : "") + " teacher_age = " + std::to_string(age) + " , teacher_gender = '" + gender +
		"', subject_id = " + std::to_string(subjectId) + " , salary = " + std::to_string(salary))
		.where(" teacher_id = " + std::to_string(teacherId));

}

UpdateTeacher::UpdateTeacher(SqlQueryBuilder formSql) : AddTeacher(formSql)
{
}
