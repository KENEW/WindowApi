//#include <windows.h>
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE g_hInst;
//LPSTR lpszClass = "Key";
//
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
//	, LPSTR lpszCmdParam, int nCmdShow)
//{
//	HWND hWnd;
//	MSG Message;
//	WNDCLASS WndClass;
//	g_hInst = hInstance;
//
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hInstance = hInstance;
//	WndClass.lpfnWndProc = (WNDPROC)WndProc;
//	WndClass.lpszClassName = lpszClass;
//	WndClass.lpszMenuName = NULL;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	RegisterClass(&WndClass);
//
//	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//		NULL, (HMENU)NULL, hInstance, NULL);
//	ShowWindow(hWnd, nCmdShow);
//
//	while (GetMessage(&Message, 0, 0, 0)) {
//		TranslateMessage(&Message);
//		//전달된 메시지가 WM_KEYDOWN인지와 눌려진 키가 문자키인지 검사해보고 조건이 맞을 경우 WM_CHAR 메시지를 만들어 메시지 큐에
//		//덧 붙이는 역활을 한다. 몰론 문자 입력이 아닐 경우 "아무 일"도 하지 않으며 이 메시지는 DIspatchMessage 함수에 의해
//		//WndProc으로 보내진다. 만약 메시지 루프에서 TranslateMessage 함수를 뺴 버리면 WM_CHAR 메시지는 절대로 WndProc으로 전달되지 
//		//않을 것이다.
//		DispatchMessage(&Message);
//	}
//	return Message.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	static int x = 100;
//	static int y = 100;
//
//	switch (iMessage)
//	{
//		case WM_KEYDOWN:
//			switch (wParam)
//			{
//				case VK_LEFT:
//					x -= 8;
//					break;
//				case VK_RIGHT:
//					x += 8;
//					break;
//				case VK_UP:
//					y -= 8;
//					break;
//				case VK_DOWN:
//					y += 8;
//					break;
//			}
//			InvalidateRect(hWnd, NULL, TRUE);
//			return 0;
//		case WM_PAINT:
//			hdc = BeginPaint(hWnd, &ps);
//			TextOut(hdc, x, y, "테스트", 6);
//			EndPaint(hWnd,&ps);
//			return 0;
//		case WM_DESTROY:
//			PostQuitMessage(0);
//			return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}