#pragma once
template<typename T>
class BSTUseable {
public :
	virtual bool operator<(const T &) = 0;
	virtual bool operator>(const T&) = 0;
	virtual bool operator<=(const T&) = 0;
	virtual bool operator>=(const T&) = 0;
	virtual bool operator==(const T&) = 0;
	virtual bool operator!=(const T&) = 0;

};