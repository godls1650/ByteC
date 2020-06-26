#pragma once
#include "BSTUseable.h"
class DataCls : public BSTUseable<DataCls>{ // 인터페이스 
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



