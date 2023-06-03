#include "FilterRegexDecorator.h"

FilterRegexDecorator::FilterRegexDecorator(QSortFilterProxyModel* source, int columnIndex, const QRegularExpression& regex, QObject* parent)
	: QSortFilterProxyModel(parent) {

	this->setSourceModel(source);
	if (regex.isValid()) {
		this->setFilterKeyColumn(columnIndex);
		this->setFilterRegularExpression(regex);
	}



}