int YesNoK(void);//등록 하겠습니까? 메인
int YesNo(void);//이어서 등록하겠습니까? 메인 
//[등록할때] (Y/N) 반환과정
int YesNoK(void) {
	int yn;

	while ((yn = _getch()) != NULL) {
		if (yn == 'y' || 'y' == 1 || yn == 'Y') {
			puts("Y");
			return 1; // 참을 반환
		}
		else if (yn == 'n' || 'n' == 1 || yn == 'N') {
			puts("N");
			return 0; // 거짓을 반환
		}
	}
	return -1;
}

//[이어서 책입력할때] (Y/N) 반환과정
int YesNo(void) {
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