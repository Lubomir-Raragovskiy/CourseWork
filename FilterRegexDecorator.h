#pragma once
#include <QSortFilterProxyModel>

class FilterRegexDecorator :
    public QSortFilterProxyModel
{
    public:
    FilterRegexDecorator(QSortFilterProxyModel* source, int columnIndex, const QRegularExpression& regex, QObject* parent = 0);

};

