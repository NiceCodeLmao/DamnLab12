#include <Windows.h>
#include "Functions.h"

int main()
{
    int n;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    q:Menu(n);
    if (n!=0)
        goto q;
    system("pause");
    return 0;
}