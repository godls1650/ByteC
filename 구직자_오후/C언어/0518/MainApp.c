#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INT_MAX 0x7FFFFFFF 
// �Է¹��� : stdin
// ��¹��� : stdout

/* ���� �������� �Է��ϰ� �� ���̸� ���ϴ� ���α׷� */
float Example1 () {
    float r = 4.0f;
    const float pi = 3.141592f;

    float result = r * r * pi;
    //print format : ��� ������ �����ϰ� ��½�Ų��.
    return result;
}
// 0111 1111   1111 1111    1111 1111    1111 1111
//    7    F      F    F       F   F       F    F
void Example2() {
    printf("int ���� > %d ~ %d\n", ~INT_MAX  , INT_MAX);
    printf("long ���� > %ld ~ %ld\n",~ 0x7FFFFFFFL, 0x7FFFFFFFL);
    printf("long long ���� > %lld ~ %lld\n", ~0x7FFFFFFFFFFFFFFFi64, 0x7FFFFFFFFFFFFFFFi64);
    
    
    printf("unsgined int ���� > %10u ~ %10u\n", ~0xFFFFFFFFu  ,0xFFFFFFFFu);
    printf("unsgined long ���� > %10lu ~ %10lu\n", ~0xFFFFFFFFul, 0xFFFFFFFFul);
    printf("unsgined long long ���� > %llu ~ %llu\n", ~0xFFFFFFFFFFFFFFFFUi64, 0xFFFFFFFFFFFFFFFFUi64);
    return;
}

int main(void) {
    Example2();
    printf("example1 > %.2f\n", Example1());
    
    
	return 0;
}

/*

Line 1 : 
  #         : ��ó�� ��ɾ� --> ������ ������ ����� ���� 
  include   : �ٸ� ������ ������ �� ���Ͽ� ��ü ���� (����)
  <>        : �� ������Ʈ �ܺ��� ��� �˻�
  stdio.h   : STanDard Input Output. Header 
              ǥ��     �Է�   ���  . ��� ����

������� : Ư�� ��ɿ� ���õ� �Լ��� ���� ���ͷ���� �ɹ��� ��� , ����ü, ������, ����ü ��
         �� ���ǵǾ��ִ� ���� 

printf()
scanf()
puts() 
gets()
putc()  getc()
getch()
getchar()


fprintf(stdout, "hello")   printf("hello")
fscanf(stdin, "%d")    scanf("%d")    
fputs()     puts()     
fgets()     gets()     


sprintf()
sscanf()
sputs()
sgets()

*/
/*
Line 7 :
    main() : �������� �ʴ´�.
             ȣ������ �ʴ´�.
    main() �Լ��� �ܼ�(console) ���α׷����� --> ���� C��� ������ �о ���� �� ��
    ���� ���� �����ϰ� �Ǵ� ������ ������ �ϴ� �Լ� 
    ���α׷��� ������ 

    main()�� �����ϸ� --> Access Time �޸𸮸� ���´� --> ACCESS �Ҹ� --> ���α׷��� ��� �޸𸮰�
    �Ҵ� �� --> ���α׷� ���� --> �ܼ� ���� 
    
    
    
*/

/*
%d : 10�� ������            
%o : 8�� ���� (Octal)      
%x : 16�� ����             
%c : ����                 
%s : ���ڿ�   
%f : float Ÿ�� �Ǽ�%lf : double Ÿ�� �Ǽ� (long double)%e : 1.43235e004
%le : double�� �ε��Ҽ������� ���
%p : �޸� �ּ� ���� ���



*/



