#include <windows.h>

const double PI = 3.141592653;
void render_scene(HDC);
void paint_main_scene(HDC);
void oblako1(HDC);
void oblako2(HDC);
void oblako3(HDC);
void oblako4(HDC);
void oblako5(HDC);
void oblako6(HDC);
void oblako7(HDC);
void oblako8(HDC);
void oblako9(HDC);
void nusha(HDC);
void kroch(HDC);
void ioshik(HDC);



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int x, y;


int flag = 0;
int a = 0, b = 190, c = 250, count = 0, napr = 0;
int nu1 = 100, nu2 = 140, kr1 = 250, kr2 = 0, io1 = 400, io2 = -120;
int bn1 = 100, bn2 = 0, bk1 = 250, bk2 = 0, bi1 = 400, bi2 = -120, nn = 0,kk=1,ii=0;
int pix11=0, pix12 = 350,pix21=20,pix22 = 500,pix31=0,pix32 = 250, pix41 = 100, pix42 = 470, pix51 = 10, pix52 = 400,pix61 = 60, pix62 = 120, pix71 = 120, pix72 = 180, pix81 = 0, pix82 = 100, pix91 = 50, pix92 = 300;
char szClassName[] = "CG_WAPI_Template";
struct cor {
	int x;
	int y;
};
struct cor Arr[101];
////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS wc;

	// Заполняем структуру класса окна
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 190, 250)); //Радикально-синий цвет
	//wc.hbrBackground = (HBRUSH)GetStockObject(NULL);
	wc.hbrBackground = (HBRUSH)(COLOR_HIGHLIGHT + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;

	// Регистрируем класс окна
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, "Не могу зарегистрировать класс окна!", "Ошибка", MB_OK);
		return 0;
	}

	// Создаем основное окно приложения
	hWnd = CreateWindow(
		szClassName,                // Имя класса                   
		"SKY", // Текст заголовка
		WS_OVERLAPPEDWINDOW,        // Стиль окна                                             
		50, 50,                   // Позиция левого верхнего угла  
		600, 600,                  // Ширина и высота окна    
		(HWND)NULL,                // Указатель на родительское окно NULL    
		(HMENU)NULL,               // Используется меню класса окна              
		(HINSTANCE)hInstance,       // Указатель на текущее приложение
		NULL);                  // Передается в качестве lParam в событие WM_CREATE

	if (!hWnd)
	{
		MessageBox(NULL, "Не удается создать главное окно!", "Ошибка", MB_OK);
		return 0;
	}


	// Показываем наше окно
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	PAINTSTRUCT  ps;
	HDC          hdc;
	SetTimer(hWnd, 2, 100, NULL);
	// Выполняем цикл обработки сообщений до закрытия приложения
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
		
	}
	return (lpMsg.wParam);
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	//HDC hdc; //создаём контекст устройства
	//PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
	//PMainWindow pSelf;
	//HPEN hPen; //Объявляется кисть

	//HDC          hdcMem;
	//HBITMAP      hbmMem;
	//HANDLE       hOld;

	


	//Цикл обработки сообщений
	switch (messg)
	{

		//Сообщение таймера
	case WM_TIMER:
	{
		//hdc = GetDC(hWnd);
		//paint_main_scene(cdc);
		HDC hdc = GetDC(hWnd);
		HDC hMemDC = CreateCompatibleDC(hdc);
		HBITMAP hMemBmp = CreateCompatibleBitmap(hdc, 600, 600);
		HBITMAP hOldMemBmp = (HBITMAP)SelectObject(hMemDC, hMemBmp);

		paint_main_scene(hMemDC);
		BitBlt(hdc, 0, 0, 600, 600, hMemDC, 0, 0, SRCCOPY);

		SelectObject(hMemDC, hOldMemBmp);
		DeleteObject(hMemBmp);
		DeleteDC(hMemDC);
	}
		break;
	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
	}
	return 0;
}


void paint_main_scene(HDC hdc) {
	if ((a < 180) && (b > 10) && (c > 70) && (napr == 0)) {
		if (a == 0) {
			nu1 = 100;
			nu2 = 140;
			kr1 = 250;
			kr2 = 0;
			io1 = 400;
			io2 = -120;
			flag = 0;
		}
		//hdc = GetDC(hWnd);
		render_scene(hdc);
		

		a += 2;
		b -= 2;
		c -= 2;



	}
	if ((a > 44) && (b == 10) && (c < 138) && (napr == 0)) {

		//hdc = GetDC(hWnd);
		render_scene(hdc);
		a -= 2;
		//b -= 2;
		c += 1;



	}
	if ((count < 100) && (a == 44) && (b == 10) && (c == 138)) {

		//hdc = GetDC(hWnd); //Выделяем контекст отображения
		x = rand() % 600;
		Arr[count].x=x;
		y = rand() % 600;
		Arr[count].y = y;
		count++;
		render_scene(hdc);
		for (int i = 0; i < count; i++) {
			SetPixel(hdc, Arr[i].x, Arr[i].y, RGB(255, 255, 255)); //Выводим точку
			SetPixel(hdc, Arr[i].x + 1, Arr[i].y, RGB(255, 255, 255));
			SetPixel(hdc, Arr[i].x, Arr[i].y + 1, RGB(255, 255, 255));
			SetPixel(hdc, Arr[i].x + 1, Arr[i].y + 1, RGB(255, 255, 255));
		}
		
		if (count == 100) {
			if (napr == 0)   napr = 1;
			else napr = 1;
			count = 0;
			flag = 1;
		}

	}
	if ((a < 180) && (b == 10) && (c > 70) && (napr == 1)) {

		//hdc = GetDC(hWnd);
		render_scene(hdc);
		a += 2;
		//b -= 2;
		c -= 1;
		if (a == 180) {
			napr = 2; count = 0;

			/*pix11 = 0;
			pix12 = 500;
			pix21 = 20;
			pix22 = 250;
			pix31 = 0;
			pix32 = 350;
			pix41 = 100;
			pix42 = 470;
			pix51 = 10;
			pix52 = 400;
			pix61 = 60;
			pix62 = 120;
			pix71 = 120;
			pix72 = 180;
			pix81 = 0;
			pix82 = 80;
			pix91 = 50;
			pix92 = 300;*/
		}

	}

	if ((a > 0) && (b < 190) && (c < 250) && (napr == 2)) {

		//hdc = GetDC(hWnd);
		render_scene(hdc);
		a -= 2;
		b += 2;
		c += 2;
		if (a == 0) {
			napr = 0;
			pix11 = 0;
			pix12 = 500;
			pix21 = 20;
			pix22 = 250;
			pix31 = 0;
			pix32 = 350;
			pix41 = 100;
			pix42 = 470;
			pix51 = 10;
			pix52 = 400;
			pix61 = 60;
			pix62 = 120;
			pix71 = 120;
			pix72 = 180;
			pix81 = 0;
			pix82 = 80;
			pix91 = 50;
			pix92 = 300;
		}

	}
	
	oblako1(hdc);
	pix11 += 5;
	oblako2(hdc);
	pix21 += 6;
	oblako3(hdc);
	pix31 += 7;
	oblako4(hdc);
	pix41 += 4;
	oblako5(hdc);
	pix51 += 6;
	oblako6(hdc);
	pix61 += 6;
	oblako7(hdc);
	pix71 += 6;
	oblako8(hdc);
	pix81 += 5;
	oblako9(hdc);
	pix91 += 7;
	
	if (flag ==1) {

		nusha(hdc);
		nu2 += 4;
		if (nn == 0) {
			nu1 += 8;
			if (nu1 == bn1 + 64) nn = 1;
		}
		if (nn == 1) {
			nu1 -= 8;
			if (nu1 == bn1 - 64) nn = 0;
		}
	
			kroch(hdc);
		kr2 += 4;
		if (kk == 0) {
			kr1 += 8;
			if (kr1 == bk1 + 64) kk = 1;
		}
		if (kk == 1) {
			kr1 -= 8;
			if (kr1 == bk1 - 64) kk = 0;
		}


		ioshik(hdc);
		io2 += 4;
		if (ii == 0) {
			io1 += 8;
			if (io1 == bi1 + 64) ii = 1;
		}
		if (ii== 1) {
			io1 -= 8;
			if (io1 == bi1 - 64) ii = 0;
		}
	}
}

void render_scene(HDC dc){
	RECT r; //объявляем экзмепляр структуры RECT - координаты прямоугольника.
	r.left = 0; //левый верхний угол
	r.top = 600;
	r.right = 200; //правый нижний
	r.right = 600;
	HBRUSH hbrush = CreateSolidBrush(RGB(a, b, c));
	//Заполняем прямоугольник
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));
	
}

void drawpixw(HDC dc,int x,int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x+4; //правый нижний
	r.bottom = y+4;
	HBRUSH hbrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}
void drawpixb(HDC dc, int x,int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y+ 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(131, 206, 250));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));
	
}

void drawpixp(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(221, 160, 221));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixg(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(169, 169, 169));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixbl(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixp1(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(238, 130, 238));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}
void drawpixp2(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 255));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixp3(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(250, 128, 114));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixsb(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(30, 144, 255));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixr1(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(199, 20, 147));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}

void drawpixr2(HDC dc, int x, int y) {

	RECT r;
	r.left = x; //левый верхний угол
	r.top = y;
	r.right = x + 4; //правый нижний
	r.bottom = y + 4;
	HBRUSH hbrush = CreateSolidBrush(RGB(138, 43, 226));
	FillRect(dc, &r, hbrush);
	DeleteObject(SelectObject(dc, hbrush));

}
///////////////////4 oblako////////////////////////
void oblako4(HDC dc) {
	int x = pix41, y = pix42;
	//1 row
	for (int i = 0; i < 32; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i < 8; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 8; i < 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i < 24; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 24; i < 32; i++) {
		drawpixw(dc, x + i * 4, y );
	}
	y -= 4;
	//3 row
	for (int i = 4; i <= 6; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 22; i <= 22; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 23; i <= 30; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 3; i <= 5; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 28; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
		for (int i = 3; i <= 4; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 5; i <= 22; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 23; i <= 24; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 25; i <= 26; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//6 row
		for (int i = 4; i <= 5; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 6; i <= 10; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 11; i <= 12; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 13; i <= 23; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 24; i <= 25; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		y -= 4;
	//7 row
		for (int i = 5; i <= 7; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 8; i <= 9; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 10; i <= 11; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 12; i <= 23; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		
		y -= 4;
	//8 row
		for (int i = 6; i <= 11; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 12; i <= 16; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 17; i <= 17; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 18; i <= 23; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//9 row
		for (int i = 8; i <= 10; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 11; i <= 16; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 17; i <= 17; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 18; i <= 23; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//10 row
		for (int i = 9; i <= 10; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 11; i <= 16; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 17; i <= 18; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 19; i <= 22; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//11 row
		for (int i = 7; i <= 11; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 12; i <= 17; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 18; i <= 19; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 20; i <= 21; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//12 row
		for (int i = 7; i <= 8; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i =9; i <= 10; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 11; i <= 12; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 13; i <= 18; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//13 row
		for (int i = 7; i <= 7; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 8; i <= 11; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		for (int i = 12; i <= 12; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 13; i <= 18; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//14 row
		for (int i = 8; i <= 8; i++) {
			drawpixp(dc, x + i * 4, y);
		}
		for (int i = 9; i <= 17; i++) {
			drawpixw(dc, x + i * 4, y);
		}
		y -= 4;
	//15 row
		for (int i = 9; i <= 16; i++) {
			drawpixp(dc, x + i * 4, y);

		}
}
///////////////////1 oblako////////////////////////
void oblako1(HDC dc) {
	int x = pix11, y = pix12;
	//1 row
	for (int i = 0; i < 32; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i < 8; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 8; i < 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i < 24; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 24; i < 32; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 4; i <= 6; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 22; i <= 22; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 23; i <= 30; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 3; i <= 5; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 28; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 3; i <= 4; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 23; i <= 24; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 25; i <= 26; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//6 row
	for (int i = 4; i <= 5; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 24; i <= 25; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	y -= 4;
	//7 row
	for (int i = 5; i <= 7; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 9; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//8 row
	for (int i = 6; i <= 11; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//9 row
	for (int i = 8; i <= 10; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//10 row
	for (int i = 9; i <= 10; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 18; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//11 row
	for (int i = 7; i <= 11; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 19; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 20; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//12 row
	for (int i = 7; i <= 8; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 18; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//13 row
	for (int i = 7; i <= 7; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 18; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//14 row
	for (int i = 8; i <= 8; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//15 row
	for (int i = 9; i <= 16; i++) {
		drawpixb(dc, x + i * 4, y);

	}
}






void oblako7(HDC dc) {
	int x = pix71, y = pix72;
	//1 row
	for (int i = 0; i < 32; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i < 8; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 8; i < 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i < 24; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 24; i < 32; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 4; i <= 6; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 22; i <= 22; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 23; i <= 30; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 3; i <= 5; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 28; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 3; i <= 4; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 23; i <= 24; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 25; i <= 26; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//6 row
	for (int i = 4; i <= 5; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 24; i <= 25; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	y -= 4;
	//7 row
	for (int i = 5; i <= 7; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 9; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//8 row
	for (int i = 6; i <= 11; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//9 row
	for (int i = 8; i <= 10; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 23; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//10 row
	for (int i = 9; i <= 10; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 18; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//11 row
	for (int i = 7; i <= 11; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 19; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 20; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//12 row
	for (int i = 7; i <= 8; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 18; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//13 row
	for (int i = 7; i <= 7; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 18; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//14 row
	for (int i = 8; i <= 8; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//15 row
	for (int i = 9; i <= 16; i++) {
		drawpixg(dc, x + i * 4, y);

	}
}

///////////////////2 oblako////////////////////////
void oblako2(HDC dc) {
	int x = pix21, y = pix22;
	//1 row
	for (int i = 0; i <= 22; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i <=3; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <=9; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 17; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 2
		; i <= 2; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 18; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//4 row
	for (int i = 7; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 18; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 9; i <= 11; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 19; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	
	y -= 4;
	//6 row
	for (int i = 10; i <= 11; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 19; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	
	y -= 4;
	//7 row
	for (int i = 11; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	// 8 row
	for (int i = 12; i <= 12; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixw(dc, x + i * 4, y);
	}

}






void oblako8(HDC dc) {
	int x = pix81, y = pix82;
	//1 row
	for (int i = 0; i <= 22; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i <= 3; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 9; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 17; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 2
		; i <= 2; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 18; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//4 row
	for (int i = 7; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 18; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 9; i <= 11; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 19; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//6 row
	for (int i = 10; i <= 11; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 19; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//7 row
	for (int i = 11; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	// 8 row
	for (int i = 12; i <= 12; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixw(dc, x + i * 4, y);
	}

}
///////////////////5 oblako////////////////////////
void oblako5(HDC dc) {
	int x = pix51, y = pix52;
	//1 row
	for (int i = 0; i <= 17; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i <= 3; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 5; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 2; i <= 2; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 6; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 3; i <= 3; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 13; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 7; i <= 7; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	
	y -= 4;
	//6 row
	for (int i = 9; i <= 9; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	
}
///////////////////3 oblako////////////////////////
void oblako3(HDC dc) {
	int x = pix31, y = pix32;
	//1 row
	for (int i = 0; i <= 17; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i <= 3; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 5; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 2; i <= 2; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 6; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 3; i <= 3; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 13; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 7; i <= 7; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//6 row
	for (int i = 9; i <= 9; i++) {
		drawpixb(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}

}

void oblako9(HDC dc) {
	int x = pix91, y = pix92;
	//1 row
	for (int i = 0; i <= 17; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i <= 3; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 5; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 17; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 2; i <= 2; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 6; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 3; i <= 3; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 13; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 7; i <= 7; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//6 row
	for (int i = 9; i <= 9; i++) {
		drawpixg(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}

}

void oblako6(HDC dc) {
	int x = pix61, y = pix62;
	//1 row
	for (int i = 0; i <= 22; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 1; i <= 3; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 9; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 17; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 22; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//3 row
	for (int i = 2
		; i <= 2; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 18; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//4 row
	for (int i = 7; i <= 12; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 16; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 18; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 19; i <= 21; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 9; i <= 11; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 19; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//6 row
	for (int i = 10; i <= 11; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 19; i++) {
		drawpixw(dc, x + i * 4, y);
	}

	y -= 4;
	//7 row
	for (int i = 11; i <= 12; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 15; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	// 8 row
	for (int i = 12; i <= 12; i++) {
		drawpixp(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixw(dc, x + i * 4, y);
	}

}

void nusha(HDC dc) {
	int x = nu1, y = nu2;
	//1 row
	for (int i = 6; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 6; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//3 row
	for (int i = 6; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 8; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 4; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 12; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 0; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 14; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 18; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//6 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 1; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 7; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 15; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 18; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//7 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 1; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 13; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 18; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//8 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 6; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 7; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//9 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 6; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 11; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 14; i <=16; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//10 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 8; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixp2(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//11 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//12 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 16; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 17; i <= 17; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//13 row
	
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 8; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 12; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//14 row

	for (int i = 0; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 5; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 15; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 18; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//15 row

	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 17; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 18; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//16 row

	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 3; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 17; i++) {
		drawpixp1(dc, x + i * 4, y);
	}
	for (int i = 18; i <= 18; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//17 row

	for (int i = 1; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 14; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 17; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//18 row

	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 13; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//19 row

	for (int i = 5; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//20 row

	for (int i = 8; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//21 row

	for (int i = 7; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//22 row

	for (int i = 7; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//23 row

	for (int i = 8; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 13; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//24 row

	for (int i = 10; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;

	

}
void kroch(HDC dc) {
 	int x = kr1, y = kr2;
	//1 row
	for (int i = 5; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i =8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//3 row
	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 11; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//4 row
	for (int i = 0; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 6; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i =10; i <= 12; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 1; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 6; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 13; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//6 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 5; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 15; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//7 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 15; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//8 row
	for (int i = 0; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 14; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//9 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 3; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <=11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//10 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 3; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 6; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//11 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 3; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 11; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 14; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//12 row
	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 4; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 14; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//13 row
	
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 13; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//14 row

	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i =12; i <= 13; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//15 row

	for (int i = 3; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 11; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//16 row

	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i =9; i <= 10; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//17 row

	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//18 row

	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}


	y -= 4;
	//19 row

	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	
	y -= 4;
	//20 row

	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 11; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//21 row

	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 12; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//22 row

	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 7; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 12; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}


	y -= 4;
	//23 row

	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 6; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 12; i++) {
		drawpixsb(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//24 row

	for (int i = 3; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;

	
}


void ioshik(HDC dc) {
	int x = io1, y = io2;
	//1 row
	for (int i = 7; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//2 row
	for (int i = 6; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 7; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//3 row
	for (int i = 3; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 7; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i =9; i <= 9; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//4 row
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//5 row
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 10; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//6 row
	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 12; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//7 row
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 6; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i =10; i <= 13; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//8 row
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 7; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 13; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//9 row
	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 5; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixp3(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <=13; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//10 row
	for (int i = 1; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//11 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 1; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 2; i <=2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixw(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 13; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//12 row
	for (int i = 0; i <= 0; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 1; i <= 1; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 2; i <=2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 5; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 13; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 16; i <= 16; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//13 row

	for (int i = 1; i <= 1; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 2; i <= 2; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 12; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 13; i <=13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 15; i <= 15; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
	y -= 4;
	//14 row

	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 5; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 7; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 10; i++) {
		drawpixr1(dc, x + i * 4, y);
	}
	for (int i = 11; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	y -= 4;
	//15 row

	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 4; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 5; i <= 11; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <=13; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//16 row

	for (int i = 2; i <= 2; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 3; i <= 3; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 4; i <= 4; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 6; i <= 6; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 9; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 10; i <= 10; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 12; i <= 12; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 14; i <= 14; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//17 row

	for (int i = 3; i <= 3; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 7; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 13; i <= 13; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//18 row

	for (int i = 7; i <= 7; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	for (int i = 8; i <= 8; i++) {
		drawpixr2(dc, x + i * 4, y);
	}
	for (int i = 9; i <= 9; i++) {
		drawpixbl(dc, x + i * 4, y);
	}

	y -= 4;
	//19 row

	for (int i = 8; i <= 8; i++) {
		drawpixbl(dc, x + i * 4, y);
	}
	
}
