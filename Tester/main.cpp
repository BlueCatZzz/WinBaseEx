#include <iostream>
#include "../WinBase/WinBase.h"

int main()
{
    setlocale(LC_ALL, "chs");

    std::string str = "你好 Hello";
    std::wstring wstr = L"你好 Hello";
    
    std::cout << WinBase::StrTest() << std::endl;
    std::wcout << WinBase::StrErrorDesc(2) << std::endl;
    std::wcout << WinBase::StrToUtf16(str) << std::endl;
    std::cout << WinBase::StrToAnsi(wstr) << std::endl;
    std::cout << WinBase::StrToUtf8(wstr) << std::endl;
    std::cout << WinBase::StrToUtf8(str) << std::endl;
    std::wcout << WinBase::StrUtf8ToUtf16(WinBase::StrToUtf8(wstr)) << std::endl;
    std::cout << WinBase::StrToAnsi(WinBase::StrToUtf8(str)) << std::endl;
    return 0;
}