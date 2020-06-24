#include "ElecProduct.h"
void ElecProduct::showProduct() {
	int n = 0;
	int p = this->m_nPdPrice;
	//12  400
	while ((p /= 1000) != 0) { n++; }

	int* parr = new int[n + 1];

	p = this->m_nPdPrice;
	for (int i = 0; i < n + 1; i++) {
		parr[i] = p % 1000;
		p /= 1000;
	}

	cout << setw(8) << setfill(' ') << left << this->m_nPdCode;
	cout << setw(20) << setfill(' ') << left << this->m_sPdName;
	cout << setw(8) << setfill(' ') << left << this->m_nVoltage <<"V";
	for (int i = n; i >= 0; i--) {
		if (i == n)cout << setw(3) << right << parr[i];
		else cout << "," << setw(3) << setfill('0') << parr[i];
	}
}
