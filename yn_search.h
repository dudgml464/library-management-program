//[�̾ å�����Ҷ�] (Y/N) ��ȯ����
int YesNo_search(void) {
	int yn;

	while ((yn = _getch()) != NULL) {
		if (yn == 'y' || yn == 'Y') {
			puts("Y");
			return 1; // ���� ��ȯ
		}
		else if (yn == 'n' || yn == 'N') {
			puts("N");
			return 0; // ������ ��ȯ
		}
	}
	return -1;
}