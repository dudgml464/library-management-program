#define _CRT_SECURE_NO_WARNINGS// fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>// fopen, fread, fclose �Լ��� ����� ��� ����>
#include <conio.h>// getch  ���͸� ġġ �ʴ��� �ڵ����� �ٺ���
#include <stdlib.h>
#include <string.h>
#define SIZE 30
#include "yn_search.h"

typedef struct _book {
	char name[SIZE];             //å�̸� ����
	char author[SIZE];           //���� ����
	char publisher[SIZE];       //���ǻ� ����
	char publication_date[SIZE]; //���ǿ��� ����
	int book_out;//���� ���� 1=�������, 0=�ݳ�����
}Book;

Book b_list[1000];//å�� ����� �� �ִ� ����
int i, j; //for���� ���
int yn = 0;//(Y/N) �� �ʱ�ȭ
void search_menu();
void search_b_name();
void search_b_author();
// å �˻� �޴� �Լ�

//void search_menu

int main() {
	char input[20] = { 0, }; //�޴� strcmp(���� ��)�� �� ���
	while (1)
	{
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");
		printf("\t\t<�˻� �޴�>\n\n");
		printf("\n\n___________________________________________\n\n");
		printf("\n\n");

		printf("\n\n1.å�̸� �˻�\n2.���� �˻�\n�Է�: ");
		gets(input);
		//�Է¹��� ���ڿ� ���ؼ� �޴�ȣ��
		if (!strcmp(input, "1"))
			search_b_name();
		else if (!strcmp(input, "2"))
			search_b_author();
		else
		{
			printf("\n\n �޴���ȣ�� �ٽ� �Է����ּ���.");
			_getch();
			continue;
		}

		printf("\n\n___________________________________________\n\n");

		//[�̾ �˻��Ҷ�] (Y/N) ��ȯ���� ����
		puts("\n�̾ �˻��Ͻðڽ��ϱ�(Y/N)? -> ");
		if (YesNo_search()) {
			printf("\n");
			puts("Y-> �̾ �˻��ϰڽ��ϴ�");
		}
		else if (yn == 1) {
			printf("\n");
			puts("Y-> �˻�ȭ������ �̵��ϰڽ��ϴ�.");
		}
		else if (yn == 0) {
			printf("\n");
			puts("N-> ����ȭ������ ���ư��ڽ��ϴ�");
			break;
		}

		printf("\n\n___________________________________________\n\n");
	}
}
// å�̸����� �˻�
void search_b_name()
{
	int b_index = 0;
	int b_length;    // �Է¹��� å�̸��� ����
	int compare;       // å�̸� �� ���ھ� ��, ������ 1�� ����
	int search_list = 0; // �� �˻��� ���� ����
	char b_name[SIZE] = { 0, }; //å�̸��Է¹޴� ����

	printf("\n\nå�̸��� �Է��ϼ��� : ");
	gets(b_name);
	//å�̸��� ���̸� ���� �� �ִ� ���Ҽ���
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
		//compare(�� ���ڿ� �� ��) == b_name_length(å�̸� ����)�� ���� �� ��� search_list(�˻��� ����)�� ++(�߰���)
		if (compare == b_length)
		{
			printf("\n\n___________________________________________\n\n");
			printf("å�̸� : %s\n", b_list[i].name);
			printf("��  �� : %s\n", b_list[i].author);
			printf("���ǻ� : %s\n", b_list[i].publisher);
			printf("������� : %s\n", (b_list[i].book_out == 1) ? "���� ���� å" : "���� ������ å");
			search_list++;
		}
	}
	//search_list(�˻��� ����)�� �ƹ��͵� �߰����� ���� �� ���� ����
	if (search_list)
		printf("\n\n___________________________________________\n\n");
	else
		printf("\n\n�˻������ �����ϴ�.");
	_getch();
}

// ���ڷ� �˻�
void search_b_author() {
	int b_index = 0;
	int b_length;
	int search_list = 0;
	char b_author[SIZE] = { 0, };

	printf("\n\n������ �̸��� �Է��ϼ��� : ");
	gets(b_author);

	b_length = strlen(b_author);

	printf("\n\n");

	for (i = 0; i < b_index; i++)
	{
		if (!strcmp(b_list[i].author, b_author))
		{
			printf("\n\n___________________________________________\n\n");
			printf("å�̸� : %s\n", b_list[i].name);
			printf("��  �� : %s\n", b_list[i].author);
			printf("���ǻ� : %s\n", b_list[i].publisher);
			printf("������� : %s\n", (b_list[i].book_out == 1) ? "���� ���� å" : "���� ������ å");
			search_list++;
		}
	}
	//���� ����
	if (search_list)
		printf("\n\n___________________________________________\n\n");
	else
		printf("\n\n�˻������ �����ϴ�.");
	_getch();
}
