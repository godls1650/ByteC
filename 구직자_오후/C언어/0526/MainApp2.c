#include "VLAlib.h"

int main() {
	vlarray * vlarr = allocVLA();
	vlarray* vlarr1[5] = { allocVLA() };
	for (int i = 0; i < 5; i++)
		setVLArray(vlarr1[i],10);



	setVLArray(vlarr, 10);
	for (int i = 0; i < 19; i++) {
		append(vlarr, (i + 1) * 10);
		printf("가변배열의 데이터 갯수 : %d\n가변배열의 용량 : %d\n", getSize(vlarr), getCapacity(vlarr));
		viewVLAarray(vlarr);

	}
	return 0;
}