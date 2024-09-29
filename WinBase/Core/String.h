#pragma once

#include <windows.h>
#include <string>

namespace WinBase
{
    namespace String
    {
        std::string Test();

        std::wstring ErrorDesc(DWORD code);

        std::wstring ToUtf16(const std::string& ansi);

        std::wstring Utf8ToUtf16(const std::string& utf8);

        std::string ToAnsi(const std::wstring& utf16);

        std::string ToAnsi(const std::string& utf8);

        std::string ToUtf8(const std::wstring& utf16);

        std::string ToUtf8(const std::string& ansi);
    }
}