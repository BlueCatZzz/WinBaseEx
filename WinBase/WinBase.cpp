#include "WinBase.h"

#include "Core/String.h"

namespace WinBase
{
	std::string StrTest()
	{
		return String::Test();
	}

	std::wstring StrErrorDesc(DWORD code)
	{
		return String::ErrorDesc(code);
	}

	std::wstring StrToUtf16(const std::string& ansi)
	{
		return String::ToUtf16(ansi);
	}

	std::wstring StrUtf8ToUtf16(const std::string& utf8)
	{
		return String::Utf8ToUtf16(utf8);
	}

	std::string StrToAnsi(const std::wstring& utf16)
	{
		return String::ToAnsi(utf16);
	}

	std::string StrToAnsi(const std::string& utf8)
	{
		return String::ToAnsi(utf8);
	}

	std::string StrToUtf8(const std::wstring& utf16)
	{
		return String::ToUtf8(utf16);
	}

	std::string StrToUtf8(const std::string& ansi)
	{
		return String::ToUtf8(ansi);
	}
}