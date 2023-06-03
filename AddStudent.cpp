#include "AddStudent.h"

void AddStudent::prepareData()
{
    getName(name, "Student");
    getNumber(age, "Age" ,  18 );
    getGender(gender);
    getForeignKey(formId, formSql, "Form");


    
}

void AddStudent::prepareQuery()
{


    query  = SqlQueryBuilder().insertInto("students(student_name, student_age, student_gender, form_id) ").
        values("( " + (!name.empty() ? (" ' " + name  + "' , ") : " '',") + std::to_string(age) + " , '" + gender + "' , " + std::to_string(formId) + " )");

}



AddStudent::AddStudent(SqlQueryBuilder formSql) : formSql(formSql){}