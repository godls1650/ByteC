#include "framework.h"
#include "AdjacencyMatrix.h"
/*
������ ������ ���� ���� ����� ũ�⸦ �Ҵ��ϰ� 
PPT �� �׷��� ����ó�� ���� �ϴ� ADT ����

*/

int main() {
	char Vertex[7]= { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	AMGraph* graph = initMatrix(7);
	
	connectVertex(graph, getIndex(Vertex, 7, 'A') , getIndex(Vertex, 7, 'B'));
	connectVertex(graph, getIndex(Vertex, 7, 'A'), getIndex(Vertex, 7, 'D'));
	connectVertex(graph, getIndex(Vertex, 7, 'B'), getIndex(Vertex, 7, 'C'));
	connectVertex(graph, getIndex(Vertex, 7, 'C'), getIndex(Vertex, 7, 'D'));
	connectVertex(graph, getIndex(Vertex, 7, 'D'), getIndex(Vertex, 7, 'E'));
	connectVertex(graph, getIndex(Vertex, 7, 'D'), getIndex(Vertex, 7, 'F'));

	connectVertex(graph, getIndex(Vertex, 7, 'E'), getIndex(Vertex, 7, 'F'));
	connectVertex(graph, getIndex(Vertex, 7, 'F'), getIndex(Vertex, 7, 'G'));

	
	ShowGraphInfo(graph, Vertex, 7);

	printf("\n");
	printf("���� �켱 Ž��\n");
	DFSGraph(graph, Vertex, 7);

	return 0;
}


