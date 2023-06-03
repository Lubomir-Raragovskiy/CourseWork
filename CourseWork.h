#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CourseWork.h"
#include "DataBaseConnection.h"
#include "SqlQueryBuilder.h"
#include "PqxxToQTAdapter.h"
#include "FilterStringDecorator.h"
#include "FilterRegexDecorator.h"
#include "SortDecorator.h"
#include <QStringListModel>
#include <QSignalMapper>
#include <map>
#include <memory>
#include "AddStudent.h"
#include "AddTeacher.h"
#include "AddClass.h"
#include "AddGrade.h"
#include "AddForm.h"
#include "AddSubject.h"
#include "UpdateStudent.h"
#include "UpdateTeacher.h"
#include "UpdateClass.h"
#include "UpdateGrade.h"
#include "UpdateForm.h"
#include "UpdateSubject.h"
#include "DeleteStudent.h"
#include "DeleteTeacher.h"
#include "DeleteClass.h"
#include "DeleteGrade.h"
#include "DeleteSubject.h"
#include "DeleteForm.h"



class CourseWork : public QMainWindow
{
    Q_OBJECT

public:

    CourseWork(QWidget *parent = nullptr);
    ~CourseWork();

   
    const std::map<std::string, SqlQueryBuilder*> tables{

      {"students", &students},
      { "teachers", &teachers },
      { "classes", &classes },
      { "forms", &forms },
      { "subjects", &subjects },
      { "grades", &grades }


    };

    QAbstractItemModel* getModel(QTableView* table);

    QAbstractItemModel* getModel(std::string tableName);

    const SqlQueryBuilder* findQuery(std::string tableName);

   

public slots:

    void onFilterStudents();
    void onFilterTeachers();

    void onFilterClasses();

    void onFilterGrades();
    

    void insertUpdateDelete(QObject* object);

    //void commit(UpdateInsertDeleteTemlateMethod* operation);

    void onClear(QObject* widget);

   


    

private:
    Ui::CourseWorkClass ui;

    SqlQueryBuilder students = SqlQueryBuilder().select()
        .from("students")
        .join("forms")
        .using_("form_id");
       

    SqlQueryBuilder teachers = SqlQueryBuilder().select()
        .from("teachers")
        .join("subjects")
        .using_("subject_id");


    SqlQueryBuilder classes = SqlQueryBuilder().select("class_id, teacher_name , subject_name, form_name")
        .from("classes")
        .join("teachers")
        .using_("teacher_id")
        .join("forms")
        .using_("form_id")
        .join("subjects")
        .using_("subject_id");


   SqlQueryBuilder grades = SqlQueryBuilder().select("teacher_name, subject_name, student_name, form_name , first_semester_grade, second_semester_grade, year_grade, missed_classes")
        .from("grades")
        .join("students")
        .using_("student_id")
        .join("forms")
        .using_("form_id")
        .join("classes")
        .using_("class_id")
        .join("teachers")
        .using_("teacher_id")
        .join("subjects")
        .using_("subject_id");

    SqlQueryBuilder forms = SqlQueryBuilder().select("form_name")
        .from("forms");;

    SqlQueryBuilder subjects = SqlQueryBuilder().select("subject_name")
        .from("subjects");
    

   


};


QStringListModel* getHeaders(QStandardItemModel* model);

