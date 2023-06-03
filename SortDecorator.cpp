#include "SortDecorator.h"


SortDecorator::SortDecorator(QSortFilterProxyModel* source, int columnIndex, const Qt::SortOrder order, QObject* parent)
	: QSortFilterProxyModel(parent) {


	this->setSourceModel(source);
	this->sort(columnIndex, order);

}