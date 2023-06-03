#pragma once
#include <QSortFilterProxyModel>
class SortDecorator :
    public QSortFilterProxyModel
{
public:
    SortDecorator(QSortFilterProxyModel* source, int columnIndex, const Qt::SortOrder order = Qt::AscendingOrder, QObject* parent = 0);

};

