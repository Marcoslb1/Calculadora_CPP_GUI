#include "CalculadoraClass.h"

namespace securityClass {

	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	HINSTANCE hInst = NULL;
	char out[1000] = "";
	HWND idLabel = NULL;
	int firstSet = 0, Secondset = 0, Result = 0;
	char sinal = NULL;

	bool CalculadoraClass::screenLabel(HWND hwnd) {

		HFONT font = CreateFont(-46, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, L"Calibri");

		idLabel = CreateWindowEx(
			0,
			L"STATIC",
			NULL,
			WS_CHILDWINDOW | WS_VISIBLE | WS_BORDER | SS_RIGHT,
			03, 03, 275, 64,
			hwnd,
			NULL,
			NULL,
			NULL
		);

		SendMessage(idLabel, WM_SETFONT, (WPARAM)font, MAKELPARAM(true, 0));

		if (!idLabel) {
			return false;
		}

		return true;
	}

	bool CalculadoraClass::createButton(HWND hwnd)
	{
		std::vector<HWND> botoes = std::vector<HWND>();

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"%",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			3, 70, 65, 45,
			hwnd,
			(HMENU)PERCENTAGE,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"7",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			3, 120, 65, 45,
			hwnd,
			(HMENU)NUMBER_7,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"4",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			3, 170, 65, 45,
			hwnd,
			(HMENU)NUMBER_4,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"1",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			3, 220, 65, 45,
			hwnd,
			(HMENU)NUMBER_1,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"CE",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			73, 70, 65, 45,
			hwnd,
			(HMENU)CLEAR,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"8",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			73, 120, 65, 45,
			hwnd,
			(HMENU)NUMBER_8,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"5",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			73, 170, 65, 45,
			hwnd,
			(HMENU)NUMBER_5,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"2",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			73, 220, 65, 45,
			hwnd,
			(HMENU)NUMBER_2,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"0",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			3, 270, 136, 45,
			hwnd,
			(HMENU)NUMBER_0,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"<=",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			143, 70, 65, 45,
			hwnd,
			(HMENU)DELETE1,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"9",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			143, 120, 65, 45,
			hwnd,
			(HMENU)NUMBER_9,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"6",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			143, 170, 65, 45,
			hwnd,
			(HMENU)NUMBER_6,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"3",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			143, 220, 65, 45,
			hwnd,
			(HMENU)NUMBER_3,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L".",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			143, 270, 65, 45,
			hwnd,
			(HMENU)PONTO,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"-",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			213, 70, 65, 45,
			hwnd,
			(HMENU)SUB,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"+",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			213, 120, 65, 45,
			hwnd,
			(HMENU)SUM,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"*",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			213, 170, 65, 45,
			hwnd,
			(HMENU)MULTI,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"/",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			213, 220, 65, 45,
			hwnd,
			(HMENU)DIV,
			NULL,
			NULL
		));

		botoes.push_back(CreateWindowEx(
			0,
			L"BUTTON",
			L"=",
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			213, 270, 65, 45,
			hwnd,
			(HMENU)EQUAL,
			NULL,
			NULL
		));

		for (int i = 0; i < botoes.size(); i++) {
			if (!botoes[i]) {
				return false;
			}
		}
		return true;
	}

	WNDCLASSEX CalculadoraClass::windowStruct(HINSTANCE hThisInstance) {

		WNDCLASSEX wincl;
		HDC hdc;
		HWND myconsole;
		myconsole = GetConsoleWindow();

		hdc = GetDC(myconsole);
		/*estrutura Janela */
		wincl.hInstance = hThisInstance;
		wincl.lpszClassName = L"WindowsApp";
		wincl.lpfnWndProc = WindowProcedure;      /* Função chamada pelo Windows */
		wincl.style = CS_DBLCLKS;                 /* Pegar clique duas vezes */
		wincl.cbSize = sizeof(WNDCLASSEX);

		/* ícone padrão e ponteiro do mouse */
		wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
		wincl.lpszMenuName = NULL;                 /* sem menu */
		wincl.cbClsExtra = 0;
		wincl.cbWndExtra = 0;
		wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		wincl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

		RegisterClassEx(&wincl);

		return wincl;

	}

	HWND CalculadoraClass::identifyWindow(HINSTANCE hThisInstance)
	{
		hInst = hThisInstance;
		HWND hwnd;              /*identificador d janela */

		/* registro da classe*/
		hwnd = CreateWindowEx(
			0,
			L"WindowsApp",                                     /* Classname */
			L"Calculadora",                                   /* Titulo da janela */
			WS_SYSMENU | WS_EX_CLIENTEDGE | WS_EX_COMPOSITED | WS_EX_CONTEXTHELP | WS_EX_STATICEDGE | WS_EX_WINDOWEDGE,
			CW_USEDEFAULT,                                                /* posição horizontal */
			CW_USEDEFAULT,                                               /* posição vertical */
			298,                                              /* a largura do programa */
			360,                                             /* a altura do programa */
			HWND_DESKTOP,                               /* A janela é uma janela filho para o desktop */
			NULL,                                      /* sem menu */
			hThisInstance,                           /* manipulador de instância da janela */
			NULL
		);

		return hwnd;
	}

	bool CalculadoraClass::showWindow(int nFunsterStil, HINSTANCE hThisInstance)
	{
		HWND hwnd = identifyWindow(hThisInstance);
		/* Mostra a janela */
		if (!hwnd)
			return FALSE;
		ShowWindow(hwnd, nFunsterStil);
		UpdateWindow(hwnd);

		return true;
	}

	WPARAM CalculadoraClass::storageMsg()
	{
		MSG messages;    /* responsavel pelo armazenamento das mensagens */

		/* Executa o loop de mensagem. Ele será executado até GetMessage () retornar 0 */
		while (GetMessage(&messages, NULL, 0, 0))
		{
			TranslateMessage(&messages);
			/* Enviar mensagem para WindowProcedure */
			DispatchMessage(&messages);
		}

		/* O programa valor de retorno é 0 - O valor que PostQuitMessage () deu */
		return messages.wParam;
	}

	void CalculadoraClass::outOperations(HWND hwnd, WPARAM wParam) {

		if ((HIWORD(wParam) == BN_CLICKED))
		{
			switch (LOWORD(wParam))
			{

			case NUMBER_0:
			{
				char const* one = "0";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_1:
			{
				char one[] = "1";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_2:
			{
				char one[] = "2";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_3:
			{
				char one[] = "3";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_4:
			{
				char one[] = "4";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_5:
			{
				char one[] = "5";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_6:
			{
				char one[] = "6";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_7:
			{
				char one[] = "7";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_8:
			{
				char one[] = "8";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case NUMBER_9:
			{
				char one[] = "9";
				strcat_s(out, one);
				SetWindowTextA(idLabel, out);

				break;
			}

			case EQUAL:
			{
				Secondset = std::stoi(out);
				char clear[] = "";

				if (sinal == '%') {
					Result = (firstSet * Secondset) / 100;
					std::string show = std::to_string(Result);
					char const* chars = show.c_str();
					strcpy_s(out, chars);
					SetWindowTextA(idLabel, out);
				}

				if (sinal == '+')
				{
					Result = firstSet + Secondset;
					std::string show = std::to_string(Result);
					char const* chars = show.c_str();
					strcpy_s(out, chars);
					SetWindowTextA(idLabel, out);
				}

				if (sinal == '-')
				{
					Result = firstSet - Secondset;
					std::string show = std::to_string(Result);
					char const* chars = show.c_str();
					strcpy_s(out, chars);
					SetWindowTextA(idLabel, out);
				}

				if (sinal == '*')
				{
					Result = firstSet * Secondset;
					std::string show = std::to_string(Result);
					char const* chars = show.c_str();
					strcpy_s(out, chars);
					SetWindowTextA(idLabel, out);
				}

				if (sinal == '/')
				{

					if (Secondset == 0)
					{
						MessageBox(NULL, L"ERRO: Não é possível realizar divisão por zero", L"ERRO: Divisão por zero", MB_OK);
						strcpy_s(out, clear);
						SetWindowTextA(idLabel, out);
					}
					else {
						Result = firstSet / Secondset;
						std::string show = std::to_string(Result);
						char const* chars = show.c_str();
						strcpy_s(out, chars);
						SetWindowTextA(idLabel, out);
					}
				}

				break;
			}

			case SUM:
			{
				sinal = '+';
				firstSet = std::stoi(out);
				char clear[] = "";
				strcpy_s(out, clear);
				SetWindowTextA(idLabel, out);

				break;
			}

			case SUB:
			{
				sinal = '-';
				firstSet = std::stoi(out);
				char clear[] = "";
				strcpy_s(out, clear);
				SetWindowTextA(idLabel, out);

				break;
			}

			case MULTI:
			{
				sinal = '*';
				firstSet = std::stoi(out);
				char clear[] = "";
				strcpy_s(out, clear);
				SetWindowTextA(idLabel, out);

				break;
			}

			case DIV:
			{
				sinal = '/';
				firstSet = std::stoi(out);
				char clear[] = "";
				strcpy_s(out, clear);
				SetWindowTextA(idLabel, out);

				break;
			}

			case CLEAR:
			{
				char clear[] = "";
				strcpy_s(out, clear);
				SetWindowTextA(idLabel, out);

				break;
			}

			case PERCENTAGE:
			{
				sinal = '%';
				firstSet = std::stoi(out);
				char clear[] = "";
				strcpy_s(out, clear);
				SetWindowTextA(idLabel, out);

				break;
			}

			case DELETE1:
			{
				break;
			}

			case PONTO:
			{
				break;
			}

			}
		}
	}

	/* Função é chamada pela função DispatchMessage Windows ()  */
	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		securityClass::CalculadoraClass* calc = new securityClass::CalculadoraClass();
		//HDC hdc;
		//PAINTSTRUCT ps;
		//hdc = GetDC(NULL);

		switch (message)                  /* tratamento das mensagens */
		{
		case WM_CREATE:
		{
			if (!calc->createButton(hwnd)) {
				MessageBox(NULL, L"Ocorreu um erro inesperado", L"ERRO", MB_OKCANCEL);
			}
			if (!calc->screenLabel(hwnd)) {
				MessageBox(NULL, L"Ocorreu um erro inesperado", L"ERRO", MB_OKCANCEL);
			}
			break;
		}

		case WM_COMMAND:
		{
			calc->outOperations(hwnd, wParam);

			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);       /* enviar uma WM_QUIT para a fila de mensagens */
			break;
		}

		default:
		{
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		}
		return 0;
	}
}