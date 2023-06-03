#include "AddGrade.h"

AddGrade::AddGrade()
{

	studentSql = SqlQueryBuilder().select("student_name").from("students");

}

void AddGrade::prepareData()
{

	getForeignKey(studentId, studentSql, "Student");

	DataBaseConnection* connection = DataBaseConnection::connectDataBase();


	pqxx::transaction transaction(*connection->getDataBase());


	SqlQueryBuilder formSql = SqlQueryBuilder().select("form_id").from("students").where("student_id = " + std::to_string(studentId));


	pqxx::result form(pqxx::result(transaction.exec(formSql.getQuery())));

	int formId = form[0][0].as<int>();

	SqlQueryBuilder subjectSql = SqlQueryBuilder().select("DISTINCT subject_name").
		from("classes").
		join("teachers").
		using_("teacher_id").
		join("subjects")
		.using_("subject_id")
		.where("form_id = " + std::to_string(formId));


	transaction.abort();

	getForeignKey(subjectId, subjectSql, "Subject");

	SqlQueryBuilder classSql = SqlQueryBuilder().select("class_id")
		.from("classes")
		.join("teachers")
		.using_("teacher_id")
		.join("forms")
		.using_("form_id")
		.where("form_id = " + std::to_string(formId) + " AND teacher_id = (")
		.select("teacher_id")
		.from("teachers")
		.where("subject_id = " + std::to_string(subjectId) + " )")
		.limit(1);

	pqxx::transaction classTransaction(*connection->getDataBase());

	pqxx::result class_(pqxx::result(classTransaction.exec(classSql.getQuery())));

	classId = class_[0][0].as<int>();

	

}

void AddGrade::prepareQuery()
{
	getNumber(firstSemesterGrade, "First semester grade", 12);
	getNumber(secondSemesterGrade, "Second semester grade", 12);
	getNumber(missedClasses, "Missed classes");

	yearGrade = firstSemesterGrade / secondSemesterGrade + (firstSemesterGrade % secondSemesterGrade != 0);


	query = SqlQueryBuilder().insertInto("grades( class_id , student_id , first_semester_grade , second_semester_grade , year_grade , missed_classes ) ").
		values("( " + std::to_string(classId) + " , " + std::to_string(studentId) + " , " + std::to_string(firstSemesterGrade) + " , " +
		std::to_string(secondSemesterGrade) + " , " + std::to_string(yearGrade) + " , " + std::to_string(missedClasses) + " )");

}
