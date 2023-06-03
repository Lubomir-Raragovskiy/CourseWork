#include "AddForm.h"


void AddForm::prepareData()
{
	getName(name, "Form");
}

void AddForm::prepareQuery()
{
	if (!name.empty())
		query = SqlQueryBuilder().insertInto("forms(form_name)").values("('" + name + "')");
}