#include "Product.h"
template<typename CodeType> Product<CodeType>::Product()
	:m_tPdCode(T(0)), m_sPdName("(NULL)"), m_nPdPrice(0){}

template<typename CodeType> CodeType Product<CodeType>::getCode() {
	return m_tPdCode;
}