#pragma once
#include <string>

class SqlQueryBuilder
{
	std::string query;

public:

	SqlQueryBuilder& select(const std::string& columns = "*");

	SqlQueryBuilder& from(const std::string& table);

	SqlQueryBuilder& where(const std::string& condition);

	SqlQueryBuilder& join(const std::string& table);

	SqlQueryBuilder& using_(const std::string& column);

	SqlQueryBuilder& orderBy(const std::string& columns);

	SqlQueryBuilder& insertInto(const std::string& table);

	SqlQueryBuilder& values(const std::string& table);

	SqlQueryBuilder& update(const std::string& table);

	SqlQueryBuilder& set(const std::string& table);

	SqlQueryBuilder& delete_(const std::string& table);

	SqlQueryBuilder& limit(int number);

	std::string getQuery() const;
};

