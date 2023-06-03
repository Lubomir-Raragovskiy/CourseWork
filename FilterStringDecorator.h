#pragma once
#include <QSortFilterProxyModel>


class FilterStringDecorator :
    public QSortFilterProxyModel
{

    public:

    FilterStringDecorator(QSortFilterProxyModel* source, int columnIndex, const QString& filterString , QObject* parent = 0);


};

