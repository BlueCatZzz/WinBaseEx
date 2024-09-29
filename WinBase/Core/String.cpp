#include "String.h"

namespace WinBase
{
    namespace String
    {
        std::string Test()
        {
            return "Test String Api";
        }

        std::wstring ErrorDesc(DWORD code)
        {
            DWORD locale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);
            HLOCAL hLocal = NULL;
            std::wstring desc;

            do
            {
                bool ok = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS, NULL, code, locale, (LPWSTR)&hLocal, 0, NULL);

                if (ok && hLocal)
                    desc = (LPWSTR)hLocal;
            }
            while (false);

            if (hLocal)
            {
                LocalFree(hLocal);
                hLocal = NULL;
            }

            return desc;
        }

        std::wstring ToUtf16(const std::string& ansi)
        {
            std::wstring utf16;

            do
            {
                if (ansi.empty())
                    break;

                int len = MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), -1, NULL, 0);
                if (len <= 0)
                    break;

                utf16.resize(len);
                MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), -1, &utf16[0], len);
            }
            while (false);

            return utf16;
        }

        std::wstring Utf8ToUtf16(const std::string& utf8)
        {
            std::wstring utf16;

            do
            {
                if (utf8.empty())
                    break;

                int len = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
                if (len <= 0)
                    break;

                utf16.resize(len);
                MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &utf16[0], len);
            } while (false);

            return utf16;
        }

        std::string ToAnsi(const std::wstring& utf16)
        {
            std::string ansi;

            do
            {
                if(utf16.empty())
                    break;

                int len = WideCharToMultiByte(CP_ACP, 0, utf16.c_str(), -1, NULL, 0, NULL, NULL);
                if (len <= 0)
                    break;

                ansi.resize(len);
                WideCharToMultiByte(CP_ACP, 0, utf16.c_str(), -1, &ansi[0], len, NULL, NULL);
            } while (false);

            return ansi;
        }

        std::string ToAnsi(const std::string& utf8)
        {
            std::string ansi;

            do
            {
                if (utf8.empty())
                    break;

                std::wstring utf16 = Utf8ToUtf16(utf8);
                ansi = ToAnsi(utf16);
            } while (false);

            return ansi;
        }

        std::string ToUtf8(const std::wstring& utf16)
        {
            std::string utf8;

            do
            {
                if (utf16.empty())
                    break;

                int len = WideCharToMultiByte(CP_UTF8, 0, utf16.c_str(), -1, NULL, 0, NULL, NULL);
                if (len <= 0)
                    break;

                utf8.resize(len);
                WideCharToMultiByte(CP_UTF8, 0, utf16.c_str(), -1, &utf8[0], len, NULL, NULL);
            } while (false);

            return utf8;
        }

        std::string ToUtf8(const std::string& ansi)
        {
            std::string utf8;

            do
            {
                if (ansi.empty())
                    break;

                std::wstring utf16 = ToUtf16(ansi);
                utf8 = ToUtf8(utf16);
            } while (false);

            return utf8;
        }
    }
}