#include "FilterStringDecorator.h"



FilterStringDecorator::FilterStringDecorator(QSortFilterProxyModel* source, int columnIndex, const QString& filterString, QObject* parent)
    : QSortFilterProxyModel(parent) {


    
    this->setSourceModel(source);
    if (!filterString.isEmpty()) {
        this->setFilterKeyColumn(columnIndex);
        this->setFilterFixedString(filterString);
    }


}

