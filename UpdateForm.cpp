#include "UpdateForm.h"

void UpdateForm::prepareQuery()
{
	getForeignKey(id, formSql, "Form");

	if (!name.empty())
		query = SqlQueryBuilder().update("forms").set("form_name = '" + name + "'").where("form_id = " + std::to_string(id));
}


UpdateForm::UpdateForm(SqlQueryBuilder formSql) : formSql(formSql)
{
}
