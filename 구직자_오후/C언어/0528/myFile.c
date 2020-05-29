#include "myFile.h"

FILE* LoadFile(FILE* fp, const char* const fileName) {
	if (fp != NULL) {
		fclose(fp);
	}
	fp = fopen(fileName, "r");
	return fp;
}

size_t getFileLines(FILE* LoadedFile) {
	char src[256] = { 0 };
	size_t l = 0;
	while (!feof(LoadedFile)) {
		fgets(src, 255, LoadedFile);
		l++;
	}
	fseek(LoadedFile, 0, SEEK_SET);
	//rewind(LoadedFile);
	return l;
}