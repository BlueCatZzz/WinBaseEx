#pragma once

/**
* @file         WinBase.h
* @brief        Win API 封装
* @copyright    Copyright (c) 2024 CH
*/

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
    /****************************************** String API ******************************************/
    /**
    * @brief 测试函数
    * @return std::string
    */
    std::string WIN_BASE_API StrTest();

    /**
    * @brief 获取WIN API错误描述
    * @param code 错误代码
    * @return 错误描述
    */
    std::wstring WIN_BASE_API StrErrorDesc(DWORD code);

    /**
    * @brief 将ANSI编码转换为UTF-16编码
    * @param ansi ANSI编码
    * @return UTF-16编码
    */
    std::wstring WIN_BASE_API StrToUtf16(const std::string& ansi);

    /**
    * @brief 将UTF-8编码转换为UTF-16编码
    * @param utf8 UTF-8编码
    * @return UTF-16编码
    */
    std::wstring WIN_BASE_API StrUtf8ToUtf16(const std::string& utf8);

    /**
    * @brief 将UTF-16编码转换为ANSI编码
    * @param utf16 UTF-16编码
    * @return ANSI编码
    */
    std::string WIN_BASE_API StrToAnsi(const std::wstring& utf16);

    /**
    * @brief 将UTF-8编码转换为ANSI编码
    * @param utf8 UTF-8编码
    * @return ANSI编码
    */
    std::string WIN_BASE_API StrToAnsi(const std::string& utf8);

    /**
    * @brief 将UTF-16编码转换为UTF-8编码
    * @param utf16 UTF-16编码
    * @return UTF-8编码
    */
    std::string WIN_BASE_API StrToUtf8(const std::wstring& utf16);

    /**
    * @brief 将ANSI编码转换为UTF-8编码
    * @param ansi ANSI编码
    * @return UTF-8编码
    */
    std::string WIN_BASE_API StrToUtf8(const std::string& ansi);
}