#pragma once

#include <QStandardItemModel>
#include <pqxx/pqxx>

class PqxxToQTAdapter : public QStandardItemModel
{
	Q_OBJECT

public:
   

	PqxxToQTAdapter(const pqxx::result& adaptee, QObject* parent = 0);


};

