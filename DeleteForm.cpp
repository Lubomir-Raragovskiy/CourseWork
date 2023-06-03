#include "DeleteForm.h"

void DeleteForm::prepareData()
{
	getForeignKey(id, formSql, "Form");
}

void DeleteForm::prepareQuery()
{

	query = SqlQueryBuilder().delete_("").from("forms").where("form_id = " + std::to_string(id));
}


DeleteForm::DeleteForm(SqlQueryBuilder formSql) : formSql(formSql)
{
}
