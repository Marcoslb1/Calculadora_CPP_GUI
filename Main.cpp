#include "CalculadoraClass.h"

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nFunsterStil)
{
    securityClass::CalculadoraClass *calc = new securityClass::CalculadoraClass();
  
    WNDCLASSEX wincl = calc->windowStruct(hThisInstance);
    calc->showWindow(nFunsterStil, hThisInstance);
    calc->storageMsg();
}



