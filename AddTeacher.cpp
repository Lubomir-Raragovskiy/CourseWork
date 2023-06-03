#include "AddTeacher.h"

void AddTeacher::prepareData()
{

    getName(name, "Teacher");
    getNumber(age, "Age", 90);
    getGender(gender);
    getForeignKey(subjectId, subjectSql, "Subject");
    getDecimal(salary, "Salary");

}

void AddTeacher::prepareQuery()
{

    query = SqlQueryBuilder().insertInto("teachers(teacher_name, teacher_age, teacher_gender, subject_id, salary) ").
        values("( " + (!name.empty() ? (" ' " + name + "' , ") : " '',") + std::to_string(age) + " , '" + gender + "' , " + std::to_string(subjectId) + " , " + std::to_string(salary) + " )");

}

AddTeacher::AddTeacher(SqlQueryBuilder subjectSql) : subjectSql(subjectSql)
{
}
