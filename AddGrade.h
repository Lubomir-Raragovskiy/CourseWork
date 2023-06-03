#pragma once
#include "UpdateInsertDeleteTemlateMethod.h"


class AddGrade : public UpdateInsertDeleteTemlateMethod
{
protected:
	int firstSemesterGrade;
	int secondSemesterGrade;
	int yearGrade;
	int missedClasses;
	int classId;
	int studentId;
	int subjectId;
	

	SqlQueryBuilder classSql;
	SqlQueryBuilder studentSql;


public:
	AddGrade();
	virtual void prepareData();
	virtual void prepareQuery();

};

