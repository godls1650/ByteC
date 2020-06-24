#include "ProductList.h"
ProductList::ProductList(size_t capacity)
:Capacity(capacity), index(0)
{this->m_pStorage = new Product[Capacity];}


ProductList::~ProductList() {
	delete[] m_pStorage;
}
int ProductList::getSize() {
	return this->index;
}
int ProductList::capacity() {
	return this->Capacity;
}

void ProductList::append(key code, const char* name, price Price) {
	this->m_pStorage[index] = Product(name, code, Price);
	index++;
}
void ProductList::append(key code, string name, price Price) {
	for (int i = 0; i < index - 1; i++) {
		if (this->m_pStorage[index].isSameCode(code))
			return;
	}
	
	this->m_pStorage[index] = Product(name, code, Price);
	index++;
	return;
}
void ProductList::append(const Product& product) {
	this->m_pStorage[index] = Product(product);
	index++;
}

ostream& operator<<(ostream& os, const ProductList& phandle) {
	for (int i = 0; i < phandle.index; i++) {
		os << phandle.m_pStorage[i];
	}
	return os;
}
