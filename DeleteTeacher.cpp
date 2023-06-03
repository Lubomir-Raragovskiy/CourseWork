#include "DeleteTeacher.h"

void DeleteTeacher::prepareQuery()
{

	getNumber(teacherId, "ID");

	query = SqlQueryBuilder().delete_("").from("teachers").where("teacher_id = " + std::to_string(teacherId));

}

void DeleteTeacher::prepareData()
{}
