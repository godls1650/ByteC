#pragma once
#include "BSTUseable.h"
class DataCls : public BSTUseable<DataCls>{ // �������̽� 
private:
	int x;

public:

	bool operator<(const DataCls &);
	bool operator>(const DataCls&) ;
	bool operator<=(const DataCls&);
	bool operator>=(const DataCls&);
	bool operator==(const DataCls&);
	bool operator!=(const DataCls&);
};



