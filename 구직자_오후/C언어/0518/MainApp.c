#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INT_MAX 0x7FFFFFFF 
// 입력버퍼 : stdin
// 출력버퍼 : stdout

/* 원의 반지름을 입력하고 원 넓이를 구하는 프로그램 */
float Example1 () {
    float r = 4.0f;
    const float pi = 3.141592f;

    float result = r * r * pi;
    //print format : 출력 서식을 결정하고 출력시킨다.
    return result;
}
// 0111 1111   1111 1111    1111 1111    1111 1111
//    7    F      F    F       F   F       F    F
void Example2() {
    printf("int 범위 > %d ~ %d\n", ~INT_MAX  , INT_MAX);
    printf("long 범위 > %ld ~ %ld\n",~ 0x7FFFFFFFL, 0x7FFFFFFFL);
    printf("long long 범위 > %lld ~ %lld\n", ~0x7FFFFFFFFFFFFFFFi64, 0x7FFFFFFFFFFFFFFFi64);
    
    
    printf("unsgined int 범위 > %10u ~ %10u\n", ~0xFFFFFFFFu  ,0xFFFFFFFFu);
    printf("unsgined long 범위 > %10lu ~ %10lu\n", ~0xFFFFFFFFul, 0xFFFFFFFFul);
    printf("unsgined long long 범위 > %llu ~ %llu\n", ~0xFFFFFFFFFFFFFFFFUi64, 0xFFFFFFFFFFFFFFFFUi64);
    return;
}

int main(void) {
    Example2();
    printf("example1 > %.2f\n", Example1());
    
    
	return 0;
}

/*

Line 1 : 
  #         : 전처리 명령어 --> 컴파일 이전에 명령을 실행 
  include   : 다른 파일의 내용을 이 파일에 전체 복사 (포함)
  <>        : 이 프로젝트 외부의 경로 검색
  stdio.h   : STanDard Input Output. Header 
              표준     입력   출력  . 헤더 파일

헤더파일 : 특정 기능에 관련된 함수나 변수 리터럴상수 심벌릭 상수 , 구조체, 열거형, 공용체 등
         이 정의되어있는 파일 

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
    main() : 선언하지 않는다.
             호출하지 않는다.
    main() 함수는 콘솔(console) 프로그램에서 --> 현재 C언어 파일을 읽어서 실행 할 때
    가장 먼저 실행하게 되는 실행점 역할을 하는 함수 
    프로그램의 시작점 

    main()가 종료하면 --> Access Time 메모리만 남는다 --> ACCESS 소멸 --> 프로그램의 모든 메모리가
    할당 끝 --> 프로그램 종료 --> 콘솔 종료 
    
    
    
*/

/*
%d : 10진 정수로            
%o : 8진 정수 (Octal)      
%x : 16진 정수             
%c : 문자                 
%s : 문자열   
%f : float 타입 실수%lf : double 타입 실수 (long double)%e : 1.43235e004
%le : double을 부동소수점으로 출력
%p : 메모리 주소 값을 출력



*/



