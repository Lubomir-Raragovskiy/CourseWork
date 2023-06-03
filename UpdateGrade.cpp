#include "UpdateGrade.h"

void UpdateGrade::prepareQuery()
{


	getNumber(firstSemesterGrade, "First semester grade", 12);
	getNumber(secondSemesterGrade, "Second semester grade", 12);
	getNumber(missedClasses, "Missed classes");

	yearGrade = firstSemesterGrade / secondSemesterGrade + (firstSemesterGrade % secondSemesterGrade != 0);


	query = SqlQueryBuilder().update("grades")
		.set( " first_semester_grade = " + std::to_string(firstSemesterGrade) +
			", second_semester_grade = " + std::to_string(secondSemesterGrade) + ", year_grade = " + std::to_string(yearGrade) + ", missed_classes = " + std::to_string(missedClasses))
		.where("class_id = " + std::to_string(classId) + "AND student_id = " + std::to_string(studentId));
}
