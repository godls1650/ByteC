#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Block 내부의 코드 : Local Area
Block이 없는 부분 : Global Area
변수 , 함수 등을 사용한다.
1. 그 변수 or 함수가 이프로그램 내부에 존재하는지 확인이 되어야한다.
	변수 --> 선언 -> 사용 --> 메모리 소멸
	함수 --> 함수의 프로토타입을 기록한다.
					  ㄴ 함수의 명칭, 타입, 매개변수의 갯수와 종류
	조건부 컴파일
*/

// 비트를 코드화 
/*
	 IPv4 주소 . . . . . . . . . : 10.5.1.4(기본 설정)
								  0000 1010  .  0000 0101   .    0000 0001    .   0000 0100
								  1111 1111  .  1111 1111   .    0000 0000    .   0000 0000

								  0000 1010     0000 0101    .  00000000 . 00000000
								  10.5.0.0 : Network 주소

	0x0021 ~ 0x0072			0x  0000 00 [000] 010 0001
								0000 00 [000] 111 0010

	0x00A1 ~ 0x00FF             0000 00 [001] 010 0001
								0000 00 [001] 111 1111
				UNICODE MASK	0000 00  111  000 0000

				MASKING         0000 00  001  000 0000   ->RESULT
				RESULT >> 7		0000 0000 0000 0001



지점 코드  배치 코드  직책 코드 연번


--> 사원번호  867573856




	windows  KW_UP			0001
	windows  KW_DOWN		0010
	windows  KW_LEFT        0100
	windows  KHTW_RIG       1000

	KW_UP | KW_LEFT		==> 0101





	서브넷 마스크 . . . . . . . : 255.255.0.0

*/


#define LC_HeadOffice	0x01 // 본사
#define LC_INCHEON	0x02 // 인천지점
#define LC_DAEJEON	0x03 // 대전지점
#define LC_BUSAN	0x04 // 부산지점
#define LC_WOOLSAN	0x05 // 울산지점

#define OF_Admin	0x01 // 관리
#define OF_Sales	0x02 // 영업
#define OF_Personal	0x03 // 인사
#define OF_Affairs	0x04 // 총무
#define OF_Advertising	0x05 // 광고

#define ST_Staff	0x01 // 직원
#define ST_Senior	0x02 // 주임
#define ST_Assistant	0x03 // 대리
#define ST_DGManager	0x04 // 차장
#define ST_GManager	0x05 // 부장



void Example1(void);
void CharScanEx01(void);
int makeCompanyCode();


int main(void) {
	int Code = 0;
	Code = makeCompanyCode();
	printf("사원 Code : %d\n", Code);
	const int LC_mask = 0xFF000000;
	const int OF_mask = 0x00FF0000;
	const int ST_mask = 0x0000FF00;

	int lc = (Code & LC_mask) >> 24;
	int of = (Code & OF_mask) >> 16;
	int st = (Code & ST_mask) >> 8;

	printf("%d %d %d\n", lc, of, st);
	‬;
		return;
}
void CharScanEx01(void) {
	char text1 = 0;
	char text2 = 0;

	printf("문자 입력 > ");
	scanf("%c", &text1);
	printf("문자 입력 > ");
	scanf("%*c%c", &text2);

	printf("%c  |  %c\n", text1, text2);

}





void Example1(void) {
	int number = 100;
	char text = 'A';//  종료문자 (NULL문자)  ---> 0  '\0'   ' ' : 32
	float fData = 0.001234f;
	double dData = 0.0001235;
	printf("number : %d\n", number); //출력/ 확인 / 조회 / 비교  call by Value
	scanf("%d %*c %c", &number, &text); // 수정 / 삭제 / 입력 / 삽입 / 갱신 -->call by Reference
	/*account = godls1650  sitedomain = google

	//stdin => "100-A 3432 gfdjoisgads agjdfo"

	// number  =  100  <   %d   <   stdin

	//stdin => "-A 3432 gfdjoisgads agjdfo"

	//  -  <   %*c   <   stdin

	//stdin => "A 3432 gfdjoisgads agjdfo"

	// text =  A < stdin

	//stdin( )

	printf("%d, %c\n", number, text);
	scanf("%d", &number);

	printf("number : %d\n", number);


	while (getchar() != '\n');

	//010-9430-3626
	// %*c %d %*c %d %*c %d */
	// p1 = 10 ; p2 = -9430 ; p3 = 3626
	return;
}
int makeCompanyCode() {
	int Code = 0;
	int select = 0;
	static int cnt = 0;

	printf("지점 (1. 본사 2.인천 3.대전  4. 부산  5.울산 )  > ");
	scanf("%d", &select);
	Code = select;
	Code = Code << 8; // 8bit 밀어낸 값을 저장
	printf("소속팀 (1.관리 2.영업 3.인사  4.총무  5. 광고 )  > ");
	scanf("%d", &select);
	switch (select) {
	case 1: Code = Code + OF_Admin;  break;
	case 2: Code += OF_Sales; break;
	case 3: Code += OF_Personal; break;
	case 4: Code += OF_Affairs; break;
	case 5: Code += OF_Advertising; break;
	}

	Code = Code << 8;
	printf("직급 (1.사원 2.주임 3.대리 4.차장 5.부장  )  > ");
	scanf("%d", &select);
	Code += select;
	Code = Code << 8; // 8bit 밀어낸 값을 저장


	Code += ++cnt;
	return Code;
}