#pragma once
#include <string>
#include <QInputDialog>
#include <QString>
#include "DataBaseConnection.h"
#include "SqlQueryBuilder.h"

class UpdateInsertDeleteTemlateMethod
{
protected:

	SqlQueryBuilder query;

	
	virtual void getName(std::string& name, QString label);
	virtual void getNumber(int& value, QString label, int maxValue = std::numeric_limits<int>::max());
	virtual void getDecimal(float& value, QString label);
	virtual void getGender(std::string& gender);
	virtual void getForeignKey(int& id, SqlQueryBuilder table, QString label);
	virtual void prepareData() = 0;
	virtual void prepareQuery() = 0;


public:
	virtual void commit();

	

};

