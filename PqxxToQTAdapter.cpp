#include "PqxxToQTAdapter.h"

PqxxToQTAdapter::PqxxToQTAdapter(const pqxx::result& adaptee, QObject* parent ) : QStandardItemModel(parent) {



	for (int index(0); index < adaptee.columns(); ++index) {


		this->setHorizontalHeaderItem(index, new QStandardItem(adaptee.column_name(index)));

	}


	
	
	int rowIndex(0);

	for (pqxx::result::const_iterator row = adaptee.begin(); row != adaptee.end(); ++row) {
	
		
		int columnIndex(0);
		for (pqxx::const_row_iterator column : row) {

			

			QStandardItem* item = new QStandardItem(column.c_str());
			this->setItem(rowIndex, columnIndex, item);

			++columnIndex;
		}

		
		++rowIndex;
	}
		


}
