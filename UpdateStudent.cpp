#include "UpdateStudent.h"

void UpdateStudent::prepareQuery()
{

	getNumber(studentId, "ID");

	query = SqlQueryBuilder().update("students")
		.set( "student_name = ' " + (!name.empty() ? (name) : "") + "', student_age = " + std::to_string(age) + " , student_gender = '" + gender + "', form_id = " + std::to_string(formId))
		.where(" student_id = " + std::to_string(studentId));


}

UpdateStudent::UpdateStudent(SqlQueryBuilder formSql) : AddStudent(formSql) {}