#include "myList.h"

int main() {
	list* book = initList("../resource/골든메이지01.txt");
	setList(book);
	viewList(book);


	return 0;
}