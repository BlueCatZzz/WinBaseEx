#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#include <windows.h>
#include <string>

#ifndef BUILD_STATIC
# ifdef WIN_BASE_EXPORTS
#  define WIN_BASE_API __declspec(dllexport)
# else
#  define WIN_BASE_API __declspec(dllimport)
# endif
#else
# define WIN_BASE_API
#endif

namespace WinBase
{
    std::string WIN_BASE_API StrTest();
}