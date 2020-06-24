#include<Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR IpszClass = "First";

//1���� : ���α׷��� �ν��ٽ� �ڵ�
//2���� : �ٷ� �տ� ����� ���� ���α׷��� �ν��ٽ� �ڵ�, ���� ����  NULL�� �Ǹ�
//WIN32������ �׻� NULL�̴�. ȣȯ���� ���ؼ��� �����ϴ� �μ��̹Ƿ� �Ű� x
//3���� : ��������� �Էµ� ���α׷� �μ�, ������ argv�μ��� �ش��Ѵ�.
//4���� : ���α׷��� ����� �����̸� �ּ�ȭ, ��������� ���� ��
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstace
	, LPSTR IpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;

	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	//������ ���� �����̴�. ������� ���������� ����ϸ� ���� Ư���� ������
	//���Ǵ� ������ �����̴�. ���� ������ ������� ���� ��쿡�� 0���� �����ϴ�.
	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	//�������� ������ / GetStockObject ������ �⺻���Լ�


	WndClass.hCursor = LoadCursor(NULL, IDC_NO);
	//�����쿡�� ����� ���콺 Ŀ��


	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//�ּ�ȭ�Ǿ��� ��� ��µ� ������
	WndClass.hInstance = hInstance;
	//�� ������ Ŭ������ ����ϴ� ���α׷��� ��ȣ / �� ���� WinMain�� �μ��� ���޵� 
	//hInstance���� �״�� �������ش�.
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = IpszClass;
	
	//������ Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;
	//�޴� ��� x = NULL
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	//(LPCTSTR)"My First Program
	hWnd = CreateWindow(IpszClass, "My First Program", WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		1300, 300, 300, 200,
		NULL, (HMENU)NULL, hInstance, NULL);
	//const ���� �� ��
	//�������� -> ���� ����
	//�ؼ� ��� -> �ƴϿ�
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}return Message.wParam;
}

//1���� : �޽����� ���� �������� �ڵ�
//2���� : � ������ �޽���, � ��ȭ�� �߻��Ѱ��� ���� (�������� ��ġ ����?, �����찡 �ı� ��?)

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