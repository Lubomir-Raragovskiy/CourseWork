#include "UpdateInsertDeleteTemlateMethod.h"



void UpdateInsertDeleteTemlateMethod::getName(std::string& name, QString label)
{

    name = QInputDialog::getText(0, "Input" + label,
        "Name :", QLineEdit::Normal,"").toStdString();

    
}

void UpdateInsertDeleteTemlateMethod::getNumber(int& value, QString label, int maxValue)
{

    value = QInputDialog::getInt(0, "Input " + label,
        label + " :", 0, 1, maxValue);


}

void UpdateInsertDeleteTemlateMethod::getDecimal(float& value, QString label)
{

    value = QInputDialog::getDouble(0, "Input " + label, label + " :", 0.00, 0, std::numeric_limits<float>::max(), 2);


}

void UpdateInsertDeleteTemlateMethod::getGender(std::string& gender)
{

    QStringList genderSelect{ QString("Male"), QString("Female") };

    gender = QInputDialog::getItem(0, "Select Gender",
        "Gender :", genderSelect).toStdString();


}

void UpdateInsertDeleteTemlateMethod::getForeignKey(int& id, SqlQueryBuilder table, QString label)
{

    std::string value;

    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::transaction transaction(*connection->getDataBase());

    pqxx::result result(pqxx::result(transaction.exec(table.getQuery())));

    QStringList selection;

    for (pqxx::result::const_iterator row = result.begin(); row != result.end(); ++row) {



        for (pqxx::const_row_iterator column : row) {


            selection.emplaceBack(column.as<std::string>().c_str());

        }



    }


    value = QInputDialog::getItem(0, "Select " + label,
        label + " :", selection).toStdString();

    

    SqlQueryBuilder form = SqlQueryBuilder().select(label.toStdString() + "_id").from(label.toStdString() + "s").where(label.toStdString() +"_name = '" + value + "'");

    pqxx::result res(transaction.exec(form.getQuery()));

    id = res[0][0].as<int>();

}

void UpdateInsertDeleteTemlateMethod::commit()
{

    prepareData();
    prepareQuery();


    DataBaseConnection* connection = DataBaseConnection::connectDataBase();


    pqxx::work transaction(*connection->getDataBase());


    transaction.exec(query.getQuery());
    transaction.commit();
}


