int YesNoK(void);//��� �ϰڽ��ϱ�? ����
int YesNo(void);//�̾ ����ϰڽ��ϱ�? ���� 
//[����Ҷ�] (Y/N) ��ȯ����
int YesNoK(void) {
	int yn;

	while ((yn = _getch()) != NULL) {
		if (yn == 'y' || 'y' == 1 || yn == 'Y') {
			puts("Y");
			return 1; // ���� ��ȯ
		}
		else if (yn == 'n' || 'n' == 1 || yn == 'N') {
			puts("N");
			return 0; // ������ ��ȯ
		}
	}
	return -1;
}

//[�̾ å�Է��Ҷ�] (Y/N) ��ȯ����
int YesNo(void) {
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