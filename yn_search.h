//[이어서 책수정할때] (Y/N) 반환과정
int YesNo_search(void) {
	int yn;

	while ((yn = _getch()) != NULL) {
		if (yn == 'y' || yn == 'Y') {
			puts("Y");
			return 1; // 참을 반환
		}
		else if (yn == 'n' || yn == 'N') {
			puts("N");
			return 0; // 거짓을 반환
		}
	}
	return -1;
}