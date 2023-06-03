#include "DataBaseConnection.h"



DataBaseConnection::DataBaseConnection() {

	libconfig::Config config;
	

	std::string res;

	
	config.readFile("dataBaseConfig.cfg");
	


	std::string conectionString;

	conectionString.append("dbname = " + std::string(config.lookup("dbname").c_str()));
	conectionString.append(" user = " + std::string(config.lookup("user").c_str()));
	conectionString.append(" password = " + std::string(config.lookup("password").c_str()));
	conectionString.append(" hostaddr = " + std::string(config.lookup("hostaddr").c_str()));
	conectionString.append(" port = " + std::string(config.lookup("port").c_str()));


	dataBase = new pqxx::connection(conectionString);


}


pqxx::connection* DataBaseConnection::getDataBase()
{
	return dataBase;
}

DataBaseConnection* DataBaseConnection::connectDataBase()
{

	if (!connection) {

		connection = new DataBaseConnection();
	}

	return connection;

}


DataBaseConnection* DataBaseConnection::connection = DataBaseConnection::connectDataBase();