#define _CRT_SECURE_NO_WARNINGS// fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>// fopen, fread, fclose 함수가 선언된 헤더 파일>
#include <conio.h>// getch  엔터를 치치 않더라도 자동으로 줄변경
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#include "yn_search.h"

typedef struct _book {
	char name[SIZE];             //책이름 문구
	char author[SIZE];           //저자 문구
	char publisher[SIZE];       //출판사 문구
	char publication_date[SIZE]; //출판연도 문구
	int book_out;//대출 여부 1=대출상태, 0=반납상태
}Book;

Book b_list[1000];//책의 등록할 수 있는 공간
int i, j; //for문에 사용
int yn = 0;//(Y/N) 값 초기화
void search_menu();
void search_b_name();
void search_b_author();
// 책 검색 메뉴 함수

//void search_menu

int main() {
	char input[20] = { 0, }; //메뉴 strcmp(문자 비교)할 때 사용
	while (1)
	{
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("\t\t<검색 메뉴>\n\n");
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");

		printf("\n\n1.책이름 검색\n2.저자 검색\n입력: ");
		gets(input);
		//입력받은 문자와 비교해서 메뉴호출
		if (!strcmp(input, "1"))
			search_b_name();
		else if (!strcmp(input, "2"))
			search_b_author();
		else
		{
			printf("\n\n 메뉴번호를 다시 입력해주세요.");
			_getch();
			continue;
		}

		printf("\n\n___________________________________________\n\n");

		//[이어서 검색할때] (Y/N) 반환과정 변경
		puts("\n이어서 검색하시겠습니까(Y/N)? -> ");
		if (YesNo_search()) {
			printf("\n");
			puts("Y-> 이어서 검색하겠습니다");
		}
		else if (yn == 1) {
			printf("\n");
			puts("Y-> 검색화면으로 이동하겠습니다.");
		}
		else if (yn == 0) {
			printf("\n");
			puts("N-> 메인화면으로 돌아가겠습니다");
			break;
		}

		printf("\n\n___________________________________________\n\n");
	}
}
// 책이름으로 검색
void search_b_name()
{
	int b_index = 0;
	int b_length;    // 입력받은 책이름의 길이
	int compare;       // 책이름 한 글자씩 비교, 같으면 1씩 증가
	int search_list = 0; // 총 검색된 도서 개수
	char b_name[SIZE] = { 0, }; //책이름입력받는 역할

	printf("\n\n책이름을 입력하세요 : ");
	gets(b_name);
	//책이름의 길이를 비교할 수 있는 역할선언
	b_length = strlen(b_name);
	printf("\n\n");

	for (i = 0; i < b_index; i++)
	{
		compare = 0;
		for (j = 0; j < b_length; j++)
		{
			if (b_name[j] == b_list[i].name[j])
				compare++;
			else
				break;
		}
		//compare(한 문자열 씩 비교) == b_name_length(책이름 길이)가 같을 때 출력 search_list(검색된 도서)로 ++(추가함)
		if (compare == b_length)
		{
			printf("\n\n___________________________________________\n\n");
			printf("책이름 : %s\n", b_list[i].name);
			printf("저  자 : %s\n", b_list[i].author);
			printf("출판사 : %s\n", b_list[i].publisher);
			printf("대출상태 : %s\n", (b_list[i].book_out == 1) ? "대출 중인 책" : "대출 가능한 책");
			search_list++;
		}
	}
	//search_list(검색된 도서)에 아무것도 추가되지 않을 떄 에러 문자
	if (search_list)
		printf("\n\n___________________________________________\n\n");
	else
		printf("\n\n검색결과가 없습니다.");
	_getch();
}

// 저자로 검색
void search_b_author() {
	int b_index = 0;
	int b_length;
	int search_list = 0;
	char b_author[SIZE] = { 0, };

	printf("\n\n저자의 이름을 입력하세요 : ");
	gets(b_author);

	b_length = strlen(b_author);

	printf("\n\n");

	for (i = 0; i < b_index; i++)
	{
		if (!strcmp(b_list[i].author, b_author))
		{
			printf("\n\n___________________________________________\n\n");
			printf("책이름 : %s\n", b_list[i].name);
			printf("저  자 : %s\n", b_list[i].author);
			printf("출판사 : %s\n", b_list[i].publisher);
			printf("대출상태 : %s\n", (b_list[i].book_out == 1) ? "대출 중인 책" : "대출 가능한 책");
			search_list++;
		}
	}
	//에러 문자
	if (search_list)
		printf("\n\n___________________________________________\n\n");
	else
		printf("\n\n검색결과가 없습니다.");
	_getch();
}
