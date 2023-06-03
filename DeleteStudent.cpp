#include "DeleteStudent.h"


void DeleteStudent::prepareQuery() {




	getNumber(studentId, "ID");

	query = SqlQueryBuilder().delete_("").from("students").where("student_id = " + std::to_string(studentId));


}
void DeleteStudent::prepareData() {}