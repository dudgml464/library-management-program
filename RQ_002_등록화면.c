#define _CRT_SECURE_NO_WARNINGS// fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>// fopen, fread, fclose �Լ��� ����� ��� ����>
#include <conio.h>// getch  ���͸� ġġ �ʴ��� �ڵ����� �ٺ���
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#include "yn.h"

typedef struct _book {
	char name[SIZE];             //å�̸� ����
	char author[SIZE];           //���� ����
	char publisher[SIZE];       //���ǻ� ����
	char publication_date[SIZE]; //���ǿ��� ����
	int book_out;//���� ���� 1=�������, 0=�ݳ�����
}Book;

FILE* fa;
Book b_list[1000];//å�� ����� �� �ִ� ����
int b_index = 0;
int i, j;
int yn = 0;//(Y/N) �� �ʱ�ȭ
//void reg
int main() {
	char b_name[SIZE] = { 0, };             //å�̸� ����
	char b_author[SIZE] = { 0, };           //���� ����
	char b_publisher[SIZE] = { 0, };       //���ǻ� ����
	char b_publication_date[SIZE] = { 0, }; //���ǿ��� ����
	int book_out = 0;//���� ���� 1=�������, 0=�ݳ�����
	int i, j = 0;

	fa = fopen("C:\\temp\\bk.txt", "a+");
	while (1)
	{
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("\t\t<��� �޴�>\n\n");
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		//�Է� ���ڿ� ���� ����
			//�Է� ����
		printf("����� å�̸��� �Է��� �ּ���.\n\n"); //å�̸� �Ͻ� ����
		fputs("å�̸� : ", stdout);
		fgets(b_name, sizeof(b_name), stdin); //å �̸� ����&�Է�

		printf("\n\n����� ���ڸ� �Է��� �ּ���.\n\n"); //���� �Ͻ� ����
		fputs("���� : ", stdout);
		fgets(b_author, sizeof(b_author), stdin); //���� ����&�Է�

		printf("\n\n����� ���ǻ縦 �Է��� �ּ���.\n\n"); //���ǻ� �Ͻ� ����
		fputs("���ǻ� : ", stdout);
		fgets(b_publisher, sizeof(b_publisher), stdin); //���ǻ�  ����&�Է�

		printf("\n\n����� ���ǿ����� �Է��� �ּ���.\n\n"); //���ǿ��� �Ͻ� ����
		fputs("���ǿ��� : ", stdout);
		fgets(b_publication_date, sizeof(b_publication_date), stdin); //���ǿ��� ����&�Է�

																			//��� ����
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("\t\t<�Է� ���>\n\n");
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("å�̸� : %s\n����: %s\n���ǻ� : %s\n���ǿ��� : %s\n\n", b_name, b_author, b_publisher, b_publication_date);

		printf("\n\n___________________________________________\n\n");
		printf("\n");

		fputs("��� �ϰڽ��ϱ�(Y/N)? -> ", stdout);
		if (YesNoK()) {
			puts("\nY-> ��ϵǾ����ϴ�");
			//���ڿ� ����
			strcpy(b_list[b_index].name, b_name);
			strcpy(b_list[b_index].author, b_author);
			strcpy(b_list[b_index].publisher, b_publisher);
			strcpy(b_list[b_index].publication_date, b_publication_date);
			b_list[b_index].book_out = 0;
			b_index++;

			fprintf(fa, "å�̸� : %s\n����: %s\n���ǻ� : %s\n���ǿ��� : %s\n", b_name, b_author, b_publisher, b_publication_date);
		}
		else if (yn == 0) {
			puts("\nN-> ����ȭ������ ���ư��ڽ��ϴ�");
			break;
		}

		printf("\n\n___________________________________________\n\n");
		//[�̾ å�Է��Ҷ�] (Y/N) ��ȯ���� ����
		puts("\n�̾ ����Ͻðڽ��ϱ�(Y/N)? -> ");
		if (YesNo()) {
			printf("\n");
			puts("Y-> �̾ ����ϰڽ��ϴ�");
		}
		else if (yn == 1) {
			printf("\n");
			puts("Y-> �Է�ȭ������ �̵��ϰڽ��ϴ�.");
		}
		else if (yn == 0) {
			printf("\n");
			puts("N-> ����ȭ������ ���ư��ڽ��ϴ�");
			break;
		}
		printf("\n\n___________________________________________\n\n");
	}
	fclose(fa);
}