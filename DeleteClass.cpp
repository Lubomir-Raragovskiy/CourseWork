#include "DeleteClass.h"

void DeleteClass::prepareQuery()
{
	getNumber(classId, "ID");

	query = SqlQueryBuilder().delete_("").from("classes").where("class_id = " + std::to_string(classId));

}

void DeleteClass::prepareData()
{
}
