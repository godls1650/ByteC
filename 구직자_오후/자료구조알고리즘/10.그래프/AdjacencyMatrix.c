#include "AdjacencyMatrix.h"

AMGraph* initMatrix(int _GraphSize) {
	
	AMGraph* pGraph = (AMGraph*)malloc(sizeof(AMGraph));				// �׷��� ����ü �Ҵ�
	pGraph->matrix = (int**)malloc(sizeof(int*) * _GraphSize);			// �׷��� �� ũ�� ��ŭ matrix ������ �迭�Ҵ�
	for (int i = 0; i < _GraphSize; i++) {								//�׷��� �� ũ�� ��ŭ matrix�� �� �ε����� �Ҵ�.
		pGraph->matrix[i] = (int*)malloc(sizeof(int) * _GraphSize);
		memset(pGraph->matrix[i], 0, sizeof(int) * _GraphSize);				// �� �ε����� ���� 0���� �ʱ�ȭ
	}/*���� ����� ������ matrix 2���� �迭�Ҵ�*/
	return pGraph;
}

void connectVertex(AMGraph* _block, int StartVertexIndex, int ArrivalVertexIndex) {
	_block->matrix[StartVertexIndex][ArrivalVertexIndex] = 
		_block->matrix[ArrivalVertexIndex][StartVertexIndex] = 1;

	return;
}

void ShowGraphInfo(const AMGraph* _block, const char* VertexGroup, int _Size) {
	for (int i = 0; i < _Size; i++) {
		printf("START[%c] ==> ", VertexGroup[i]);
		for (int k = 0; k < _Size; k++) {
			if(_block->matrix[i][k] != 0)
				printf("V[%c] -> ", VertexGroup[k]);
		}
		printf("END\n");
	}
}

int getIndex(char* VertexGroup, int Size, char VertexName) {
	for (int i = 0; i < Size; i++) {
		if (VertexGroup[i] == VertexName) {
			return i;
		}
	}
	return -1;
}
bool isAllVisit(const int* VWhether, int _Size) {
	int n = 0;
	for (int i = 0; i < _Size; i++) {
		n += VWhether[i];
	}
	if (n == _Size)  return true;
	else return false;
}

void DFSGraph(const AMGraph* _block, const char* VertexGroup, int _Size) {
	int* VisitWhether = (int*)calloc(_Size, sizeof(int));	// �湮 ���θ� ������ �迭
	l_stack * VisitLog = initStackList(_Size);				// �湮 ������ ����� ����
	int index = 0;
	bool bCheck = false;
	while (!isAllVisit(VisitWhether, _Size)) {
		bCheck = false;
		printf("%c ", VertexGroup[index]);
		VisitWhether[index] = 1;
		Push_Back(VisitLog, index);

		for (int i = 0; i < _Size; i++) {
			if (_block->matrix[index][i] == 1 && VisitWhether[i] != 1) {
				index = i;
				bCheck = true;
				break;
			}
		}
		if (!bCheck) {
			if(VisitLog->m_pHead->m_pNext != VisitLog->m_pTail)
				index = Pop_Back(VisitLog);
		}
	}
	free(VisitWhether);
	return;
}

void BFSGraph(const AMGraph* _block, const char* VertexGroup, int _Size) {
	int* VisitWhether = (int*)calloc(_Size, sizeof(int));	// �湮 ���θ� ������ �迭
	l_queue* visitLog = initQueue(_Size);
	int index = 0;
	QPush_Back(visitLog, index);
	VisitWhether[index] = 1;

	while (visitLog->m_pHead->m_pNext != visitLog->m_pTail) {
		index = QPop_front(visitLog);
		printf("%c", VertexGroup[index]);
		for (int i = 0; i < _Size; i++) {
			if (VisitWhether[i] == 0 && _block->matrix[index][i] != 0) {
				VisitWhether[i] = 1;
				QPush_Back(visitLog, _block->matrix[index][i]);
			}	
		}
	}
}