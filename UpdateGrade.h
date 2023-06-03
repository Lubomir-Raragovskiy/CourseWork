#pragma once
#include "AddGrade.h"


class UpdateGrade : public AddGrade
{

protected:
	int gradeId;

public:
	virtual void prepareQuery();


};

