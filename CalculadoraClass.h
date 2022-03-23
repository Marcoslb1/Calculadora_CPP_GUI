#include <windows.h>
#include <vector>
#include <WinBase.h>
#include <xiosbase>
#include "Operacoes.h"
#include <string>
#pragma once

namespace securityClass {

	class CalculadoraClass
	{

	private:
		HINSTANCE g_inst;
		HWND identifyWindow(HINSTANCE hThisInstance);

	public:
		bool showWindow(int nFunsterStil, HINSTANCE hThisInstance);
		WPARAM storageMsg();
		bool createButton(HWND hwnd);
		bool screenLabel(HWND hwnd);
		void outOperations(HWND hwnd, WPARAM wParam);
		WNDCLASSEX windowStruct(HINSTANCE hThisInstance);
	};

}