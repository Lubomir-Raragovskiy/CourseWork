#include "DeleteGrade.h"

void DeleteGrade::prepareQuery()
{


	query = SqlQueryBuilder().delete_("").from("grades").where("class_id = " + std::to_string(classId) + "AND student_id = " + std::to_string(studentId));

}


