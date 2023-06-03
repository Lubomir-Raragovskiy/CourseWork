#include "SqlQueryBuilder.h"

SqlQueryBuilder& SqlQueryBuilder::select(const std::string& colums)
{

    query.append(" SELECT " + colums);
    
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::from(const std::string& table)
{

    query.append(" FROM " + table);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::where(const std::string& condition)
{
    query.append(" WHERE " + condition);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::join(const std::string& table)
{
    query.append(" JOIN " + table);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::using_(const std::string& column)
{
    query.append(" USING (" + column + ")");
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::orderBy(const std::string& columns)
{
    query.append(" ORDER BY " + columns);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::insertInto(const std::string& table)
{
    query.append(" INSERT INTO " + table);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::values(const std::string& table)
{
    query.append(" VALUES " + table);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::update(const std::string& table)
{
    query.append(" UPDATE " + table);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::set(const std::string& values)
{
    query.append(" SET " + values);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::delete_(const std::string& value)
{
    query.append(" DELETE " + value);
    return *this;
}

SqlQueryBuilder& SqlQueryBuilder::limit(int number)
{
    query.append(" LIMIT " + std::to_string(number));
    return *this;
}

std::string SqlQueryBuilder::getQuery() const
{

    return query;
}
