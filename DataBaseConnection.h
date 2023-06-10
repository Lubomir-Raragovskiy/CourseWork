#pragma once

#include <pqxx/pqxx>
#include <libconfig.h++>


class DataBaseConnection
{

private:
	static DataBaseConnection* connection;
	pqxx::connection* dataBase;
	DataBaseConnection();
	~DataBaseConnection();

public:
	pqxx::connection* getDataBase();
	static DataBaseConnection* connectDataBase();

};

