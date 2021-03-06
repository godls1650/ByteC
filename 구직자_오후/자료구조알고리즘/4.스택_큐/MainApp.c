#include "ArrayBaseStack.h"
#include "ListBaseStack.h"
#include "ArrayBaseQueue.h"
void StackEx();
void QueueEx();
/*
1. 기호는 STACK에 저장 한다.
2. 숫자값은 QUEUE에 저장 연속으로 숫자인경우 , 를 입력하지 않는다.
3. ( , + , - , * , / 은 스택에 입력된다.
4. 닫는 괄호가 읽혀진 경우 Stack의 여는 괄호 가 나올 때 까지 데이터를 빼낸다.
   여는 괄호'(' 를 제외한 나머지 기호는 Queue에 저장 시킨다.
5. +  , -  기호가 Stack에 입력되는 경우 
   Stack의 앞의 연산자가  * , / 이면   곱셈, 나눗셈 기호를 모두 Pop으로 빼낸 뒤
   덧셈 뺄셈 기호를 Push한다. 

6. 문자열의 모든데이터를 읽은 이후 Stack이 비어있지 않다면 
   스택이 비워질 때 까지 전부 Pop으로 빼내서 큐에 입력한다.

*/
int main() {
	char inorderText[128] = { 0 };
	int len = 0;
	printf("수식 입력 > ");
	gets(inorderText);
	
	a_queue* postOrder = initArrayQueue(len * 2);
	a_stack* operators = initArrayStack(len);

	len = strlen(inorderText);
	for (int i = 0; i <= len; i++) {
		if (inorderText[i] >= '0' && inorderText[i] <= '9') {
			if (i != 0 && (inorderText[i - 1] >= '0' && inorderText[i - 1] <= '9'))
				enQueue(postOrder, inorderText[i]);
		}
		else {
		
		}
	}

	return 0;
}




void QueueEx(){
	a_queue* que = initArrayQueue(5);

	enQueue(que, 10);
	printf("%d\n",seekFront(que));
	enQueue(que, 20);
	printf("%d\n", seekFront(que));
	enQueue(que, 30);
	printf("%d\n", seekFront(que));
	enQueue(que, 40);
	printf("%d\n", seekFront(que));

	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));
	enQueue(que, deQueue(que));printf("%d\n",seekFront(que));


}
void StackEx() {
	l_stack* listk = initStackList(5);

	a_stack* arStk = initArrayStack(5);

	Push_Back(listk, 10);   push(arStk, 10);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));
	Push_Back(listk, 20);   push(arStk, 20);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));
	Push_Back(listk, 30);   push(arStk, 30);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));
	Push_Back(listk, 40);   push(arStk, 40);
	printf("List_top : %d\nStack_top : %d\n", List_Seek(listk), Seek(arStk));

	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
	printf("PopListStack : %d\nPopArrayStack : %d\n", Pop_Back(listk), pop(arStk));
}

