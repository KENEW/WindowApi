#include<Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR IpszClass = "First";

//1인자 : 프로그램의 인스텐스 핸들
//2인자 : 바로 앞에 실행된 현재 프로그램의 인스텐스 핸들, 없을 경우는  NULL이 되며
//WIN32에서는 항상 NULL이다. 호환성을 위해서만 존재하는 인수이므로 신경 x
//3인자 : 명령행으로 입력된 프로그램 인수, 도스의 argv인수에 해당한다.
//4인자 : 프로그램이 실행될 형태이며 최소화, 보통모양등이 전달 됨
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstace
	, LPSTR IpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;

	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	//일종의 예약 영역이다. 윈도우즈가 내부적으로 사용하며 아주 특수한 목적에
	//사용되는 여분의 공간이다. 예약 영역을 사용하지 않을 경우에는 0으로 지정하다.
	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	//윈도우의 배경색상 / GetStockObject 윈도우 기본적함수


	WndClass.hCursor = LoadCursor(NULL, IDC_NO);
	//윈도우에서 사용할 마우스 커서


	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//최소화되었을 경우 출력될 아이콘
	WndClass.hInstance = hInstance;
	//이 윈도우 클래스를 사용하는 프로그램의 번호 / 이 값은 WinMain의 인수로 전달된 
	//hInstance값을 그대로 대입해준다.
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = IpszClass;
	
	//윈도우 클레스 이름
	WndClass.lpszMenuName = NULL;
	//메뉴 사용 x = NULL
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	//(LPCTSTR)"My First Program
	hWnd = CreateWindow(IpszClass, "My First Program", WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		1300, 300, 300, 200,
		NULL, (HMENU)NULL, hInstance, NULL);
	//const 오류 뜰 시
	//문자집합 -> 설정 안함
	//준수 모드 -> 아니요
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}return Message.wParam;
}

//1인자 : 메시지를 받을 윈도우의 핸들
//2인자 : 어떤 종류의 메시지, 어떤 변화가 발생한가에 정보 (윈도우의 위치 변경?, 윈도우가 파괴 됨?)

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}