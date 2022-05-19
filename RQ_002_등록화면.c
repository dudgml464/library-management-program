#define _CRT_SECURE_NO_WARNINGS// fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>// fopen, fread, fclose 함수가 선언된 헤더 파일>
#include <conio.h>// getch  엔터를 치치 않더라도 자동으로 줄변경
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#include "yn.h"

typedef struct _book {
	char name[SIZE];             //책이름 문구
	char author[SIZE];           //저자 문구
	char publisher[SIZE];       //출판사 문구
	char publication_date[SIZE]; //출판연도 문구
	int book_out;//대출 여부 1=대출상태, 0=반납상태
}Book;

FILE* fa;
Book b_list[1000];//책의 등록할 수 있는 공간
int b_index = 0;
int i, j;
int yn = 0;//(Y/N) 값 초기화
//void reg
int main() {
	char b_name[SIZE] = { 0, };             //책이름 문구
	char b_author[SIZE] = { 0, };           //저자 문구
	char b_publisher[SIZE] = { 0, };       //출판사 문구
	char b_publication_date[SIZE] = { 0, }; //출판연도 문구
	int book_out = 0;//대출 여부 1=대출상태, 0=반납상태
	int i, j = 0;

	fa = fopen("C:\\temp\\bk.txt", "a+");
	while (1)
	{
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("\t\t<등록 메뉴>\n\n");
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		//입력 문자열 길이 지정
			//입력 구간
		printf("등록할 책이름을 입력해 주세요.\n\n"); //책이름 암시 문구
		fputs("책이름 : ", stdout);
		fgets(b_name, sizeof(b_name), stdin); //책 이름 문구&입력

		printf("\n\n등록할 저자를 입력해 주세요.\n\n"); //저자 암시 문구
		fputs("저자 : ", stdout);
		fgets(b_author, sizeof(b_author), stdin); //저자 문구&입력

		printf("\n\n등록할 출판사를 입력해 주세요.\n\n"); //출판사 암시 문구
		fputs("출판사 : ", stdout);
		fgets(b_publisher, sizeof(b_publisher), stdin); //출판사  문구&입력

		printf("\n\n등록할 출판연도를 입력해 주세요.\n\n"); //출판연도 암시 문구
		fputs("출판연도 : ", stdout);
		fgets(b_publication_date, sizeof(b_publication_date), stdin); //출판연도 문구&입력

																			//출력 구간
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("\t\t<입력 결과>\n\n");
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("책이름 : %s\n저자: %s\n출판사 : %s\n출판연도 : %s\n\n", b_name, b_author, b_publisher, b_publication_date);

		printf("\n\n___________________________________________\n\n");
		printf("\n");

		fputs("등록 하겠습니까(Y/N)? -> ", stdout);
		if (YesNoK()) {
			puts("\nY-> 등록되었습니다");
			//문자열 저장
			strcpy(b_list[b_index].name, b_name);
			strcpy(b_list[b_index].author, b_author);
			strcpy(b_list[b_index].publisher, b_publisher);
			strcpy(b_list[b_index].publication_date, b_publication_date);
			b_list[b_index].book_out = 0;
			b_index++;

			fprintf(fa, "책이름 : %s\n저자: %s\n출판사 : %s\n출판연도 : %s\n", b_name, b_author, b_publisher, b_publication_date);
		}
		else if (yn == 0) {
			puts("\nN-> 메인화면으로 돌아가겠습니다");
			break;
		}

		printf("\n\n___________________________________________\n\n");
		//[이어서 책입력할때] (Y/N) 반환과정 변경
		puts("\n이어서 등록하시겠습니까(Y/N)? -> ");
		if (YesNo()) {
			printf("\n");
			puts("Y-> 이어서 등록하겠습니다");
		}
		else if (yn == 1) {
			printf("\n");
			puts("Y-> 입력화면으로 이동하겠습니다.");
		}
		else if (yn == 0) {
			printf("\n");
			puts("N-> 메인화면으로 돌아가겠습니다");
			break;
		}
		printf("\n\n___________________________________________\n\n");
	}
	fclose(fa);
}