#include "UpdateClass.h"

void UpdateClass::prepareQuery()
{
	getNumber(classId, "ID");

	query = SqlQueryBuilder().update("classes")
		.set("teacher_id = " + std::to_string(teacherId) +  ", form_id = " + std::to_string(formId))
		.where(" class_id = " + std::to_string(classId));

}

UpdateClass::UpdateClass(SqlQueryBuilder formSql) : AddClass(formSql)
{
}
