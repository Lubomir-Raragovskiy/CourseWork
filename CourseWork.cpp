#include "CourseWork.h"




CourseWork::CourseWork(QWidget *parent)
    : QMainWindow(parent)
{
   
    ui.setupUi(this);
    connect(ui.filterStudents, &QPushButton::clicked, this, &CourseWork::onFilterStudents);
    connect(ui.filterTeachers, &QPushButton::clicked, this, &CourseWork::onFilterTeachers);
    connect(ui.filterClasses, &QPushButton::clicked, this, &CourseWork::onFilterClasses);
    connect(ui.filterGrades, &QPushButton::clicked, this, &CourseWork::onFilterGrades);
    

    QSignalMapper* clearMapper = new QSignalMapper(this);

    connect(ui.clearStudents, SIGNAL(clicked()), clearMapper, SLOT(map()));
    clearMapper->setMapping(ui.clearStudents, ui.students);

    connect(ui.clearTeachers, SIGNAL(clicked()), clearMapper, SLOT(map()));
    clearMapper->setMapping(ui.clearTeachers, ui.teachers);

    connect(ui.clearClasses, SIGNAL(clicked()), clearMapper, SLOT(map()));
    clearMapper->setMapping(ui.clearClasses, ui.classes);

    connect(ui.clearGrades, SIGNAL(clicked()), clearMapper, SLOT(map()));
    clearMapper->setMapping(ui.clearGrades, ui.grades);

    connect(ui.refreshForms, SIGNAL(clicked()), clearMapper, SLOT(map()));
    clearMapper->setMapping(ui.refreshForms, ui.forms);

    connect(ui.refreshSubjects, SIGNAL(clicked()), clearMapper, SLOT(map()));
    clearMapper->setMapping(ui.refreshSubjects, ui.subjects);

    connect(clearMapper, &QSignalMapper::mappedObject, this, &CourseWork::onClear);


    QSignalMapper* mapper = new QSignalMapper(this);
    
    connect(ui.addClass, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.addClass, ui.addClass);

    connect(ui.addTeacher, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.addTeacher, ui.addTeacher);

    connect(ui.addStudent, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.addStudent, ui.addStudent);

    connect(ui.addGrade, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.addGrade, ui.addGrade);

    connect(ui.addSubject, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.addSubject, ui.addSubject);

    connect(ui.addForm, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.addForm, ui.addForm);

    connect(ui.updateClass, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.updateClass, ui.updateClass);

    connect(ui.updateTeacher, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.updateTeacher, ui.updateTeacher);

    connect(ui.updateStudent, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.updateStudent, ui.updateStudent);

    connect(ui.updateGrade, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.updateGrade, ui.updateGrade);

    connect(ui.updateSubject, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.updateSubject, ui.updateSubject);

    connect(ui.updateForm, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.updateForm, ui.updateForm);

    connect(ui.deleteClass, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.deleteClass, ui.deleteClass);

    connect(ui.deleteTeacher, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.deleteTeacher, ui.deleteTeacher);

    connect(ui.deleteStudent, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.deleteStudent, ui.deleteStudent);

    connect(ui.deleteGrade, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.deleteGrade, ui.deleteGrade);

    connect(ui.deleteSubject, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.deleteSubject, ui.deleteSubject);

    connect(ui.deleteForm, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui.deleteForm, ui.deleteForm);

    connect(mapper, &QSignalMapper::mappedObject, this, &CourseWork::insertUpdateDelete);


    DataBaseConnection* connection = DataBaseConnection::connectDataBase();
    
    
    pqxx::transaction transaction(*connection->getDataBase());

    PqxxToQTAdapter* adapter;


    adapter = new PqxxToQTAdapter(pqxx::result(transaction.exec(forms.getQuery())));
    
    ui.forms->setModel(adapter);

    ui.studentForms->setModel(adapter);
    ui.studentForms->insertItem(0, "");
    ui.classForms->setModel(adapter);
    ui.gradeForms->setModel(adapter);

    adapter = new PqxxToQTAdapter(pqxx::result(transaction.exec(subjects.getQuery())));

    ui.subjects->setModel(adapter);

    ui.teacherSubjects->setModel(adapter);
    ui.teacherSubjects->insertItem(0, "");
    ui.classSubjects->setModel(adapter);
    ui.gradeSubjects->setModel(adapter);

    adapter = new PqxxToQTAdapter(pqxx::result(transaction.exec(students.getQuery())));

    ui.students->setModel(adapter);

    ui.studentSortBy->setModel(getHeaders(adapter));


    adapter = new PqxxToQTAdapter(pqxx::result(transaction.exec(teachers.getQuery())));

    ui.teachers->setModel(adapter);

    ui.teacherSortBy->setModel(getHeaders(adapter));
    


    adapter = new PqxxToQTAdapter(pqxx::result(transaction.exec(classes.getQuery())));

    ui.classes->setModel(adapter);

    ui.classSortBy->setModel(getHeaders(adapter));

    adapter = new PqxxToQTAdapter(pqxx::result(transaction.exec(grades.getQuery())));

    ui.grades->setModel(adapter);

    ui.gradeSortBy->setModel(getHeaders(adapter));

}

CourseWork::~CourseWork()
{}

void CourseWork::onFilterStudents() {


    

    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = pqxx::result(transaction.exec(students.getQuery()));

    PqxxToQTAdapter*  adapter = new PqxxToQTAdapter(result);


    
    QSortFilterProxyModel* filter = new QSortFilterProxyModel();
    filter->setSourceModel(adapter);

    filter = new FilterStringDecorator(filter, result.column_number("student_gender"), ui.studentGender->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("form_name"), ui.studentForms->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("student_age"), (ui.studentAge->text()));
    filter = new FilterStringDecorator(filter, result.column_number("student_name"), (ui.studentSearch->text()));
    filter = new SortDecorator(filter, result.column_number(ui.studentSortBy->currentText().toStdString()));

    ui.students->setModel(filter);
}

void CourseWork::onFilterTeachers() {



    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = pqxx::result(transaction.exec(teachers.getQuery()));

    PqxxToQTAdapter* adapter = new PqxxToQTAdapter(result);



    QSortFilterProxyModel* filter = new QSortFilterProxyModel();
    filter->setSourceModel(adapter);

    filter = new FilterStringDecorator(filter, result.column_number("teacher_gender"), ui.teacherGender->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("subject_name"), ui.teacherSubjects->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("teacher_age"), (ui.teacherAge->text()));
    filter = new FilterStringDecorator(filter, result.column_number("teacher_name"), (ui.teacherSearch->text()));
    filter = new SortDecorator(filter, result.column_number(ui.teacherSortBy->currentText().toStdString()));

    ui.teachers->setModel(filter);
}

void CourseWork::onFilterClasses() {



    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = pqxx::result(transaction.exec(classes.getQuery()));

    PqxxToQTAdapter* adapter = new PqxxToQTAdapter(result);



    QSortFilterProxyModel* filter = new QSortFilterProxyModel();
    filter->setSourceModel(adapter);

 
    filter = new FilterStringDecorator(filter, result.column_number("subject_name"), ui.classSubjects->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("form_name"), ui.classForms->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("teacher_name"), (ui.classSeach->text()));
    filter = new SortDecorator(filter, result.column_number(ui.classSortBy->currentText().toStdString()));

    ui.classes->setModel(filter);
}

void CourseWork::onFilterGrades() {



    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result = pqxx::result(transaction.exec(grades.getQuery()));

    PqxxToQTAdapter* adapter = new PqxxToQTAdapter(result);



    QSortFilterProxyModel* filter = new QSortFilterProxyModel();
    filter->setSourceModel(adapter);


    filter = new FilterStringDecorator(filter, result.column_number("subject_name"), ui.gradeSubjects->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("form_name"), ui.gradeForms->currentText());
    filter = new FilterStringDecorator(filter, result.column_number("teacher_name"), (ui.gradeTeacherSearch->text()));
    filter = new FilterStringDecorator(filter, result.column_number("student_name"), (ui.gradeStudentSearch->text()));
    filter = new SortDecorator(filter, result.column_number(ui.gradeSortBy->currentText().toStdString()));

    ui.grades->setModel(filter);
}

void CourseWork::onClear(QObject* widget) {

    QTableView* table = qobject_cast<QTableView*>(widget);

    

    table->setModel(getModel(table));

}

QAbstractItemModel* CourseWork::getModel(QTableView* table) {

    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());



    return new PqxxToQTAdapter(pqxx::result(transaction.exec((findQuery(table->objectName().toStdString())->getQuery()))));
}

QAbstractItemModel* CourseWork::getModel(std::string tableName) {

    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());



    return new PqxxToQTAdapter(pqxx::result(transaction.exec((findQuery(tableName)->getQuery()))));
}




const SqlQueryBuilder* CourseWork::findQuery(std::string tableName)
{

   

    return tables.find(tableName)->second;
}




QStringListModel* getHeaders(QStandardItemModel* model) {

    QStringList headers;

    for (int index(0); index < model->columnCount(); ++index) {
        headers.emplaceBack(model->horizontalHeaderItem(index)->text());
    }

    return  new QStringListModel(headers);

}




void CourseWork::insertUpdateDelete(QObject* object) {

   std::unique_ptr<UpdateInsertDeleteTemlateMethod> operation;

    QPushButton* button = qobject_cast<QPushButton*>(object);

    if (button->objectName() == "addStudent") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new AddStudent(forms));
    }
    if (button->objectName() == "updateStudent") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new UpdateStudent(forms));
    }
    if (button->objectName() == "deleteStudent") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new DeleteStudent());
    }
    if (button->objectName() == "addTeacher") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>( new AddTeacher(subjects));
    }
    if (button->objectName() == "updateTeacher") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new UpdateTeacher(subjects));
    }
    if (button->objectName() == "deleteTeacher") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new DeleteTeacher());
    }
    if (button->objectName() == "addGrade") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new AddGrade());
    }
    if (button->objectName() == "updateGrade") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new UpdateGrade());
    }
    if (button->objectName() == "deleteGrade") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new DeleteGrade());
    }
    if (button->objectName() == "addClass") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new AddClass(forms));
    }
    if (button->objectName() == "updateClass") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new UpdateClass(forms));
    }
    if (button->objectName() == "deleteClass") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new DeleteClass());
    }
    if (button->objectName() == "addForm") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new AddForm());
    }
    if (button->objectName() == "updateForm") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new UpdateForm(forms));
    }
    if (button->objectName() == "deleteForm") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new DeleteForm(forms));
    }
    if (button->objectName() == "addSubject") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new AddSubject());
    }
    if (button->objectName() == "updateSubject") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new UpdateSubject(subjects));
    }
    if (button->objectName() == "deleteSubject") {

        operation = std::unique_ptr<UpdateInsertDeleteTemlateMethod>(new DeleteSubject(subjects));
    }

    operation->commit();
}
