/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_string_c.h
 * @brief		iris unit test ï∂éöóÒëÄçÏ
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_STRING_C_H_E22B02D7_E9E7_412C_B609_DC3D9C66895D_
#define INCG_IRIS_IUTEST_STRING_C_H_E22B02D7_E9E7_412C_B609_DC3D9C66895D_

/* include ===========================================================*/
#include "iutest_compiler_c.h"
#include "iutest_libc_c.h"

#if defined(__MWERKS__)
#  define _MBSTATE_T
#endif

#if IUTEST_C_HAS_WCHAR_T
#  include <wchar.h>
#  include <wctype.h>
#endif

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
#if IUTEST_C_HAS_LIBC

#define iu_strstr	strstr
#define iu_strchr	strchr
#define iu_strcmp	strcmp
#define iu_toupper	toupper

#endif

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

IUTEST_ATTRIBUTE_UNUSED_ char * iu_strcpy(char *dst, const char *src);
IUTEST_ATTRIBUTE_UNUSED_ char * iu_strcat(char *dst, const char *src);
IUTEST_ATTRIBUTE_UNUSED_ size_t iu_strlen(const char *str);

#if IUTEST_C_HAS_WCHAR_T
IUTEST_ATTRIBUTE_UNUSED_ size_t iu_wcslen(const wchar_t *str);
#endif

#if IUTEST_C_HAS_LIBC

#else

IUTEST_ATTRIBUTE_UNUSED_ int iu_strcmp(const char* str1, const char* str2);
IUTEST_ATTRIBUTE_UNUSED_ const char * iu_strstr(const char *str1, const char *str2);
IUTEST_ATTRIBUTE_UNUSED_ const char * iu_strchr(const char *str, char ch);
IUTEST_ATTRIBUTE_UNUSED_ int iu_toupper(int ch);

#endif

/* function ==========================================================*/
/**
 * @internal
 * @brief	stricmp
*/
IUTEST_ATTRIBUTE_UNUSED_ int iu_stricmp(const char* str1, const char* str2);

#if IUTEST_C_HAS_WCHAR_T

/**
 * @internal
 * @brief	wcsicmp
*/
IUTEST_ATTRIBUTE_UNUSED_ int iu_wcsicmp(const wchar_t * str1, const wchar_t * str2);

#endif

IUTEST_ATTRIBUTE_UNUSED_ char * iu_strrev_self(char* str);
IUTEST_ATTRIBUTE_UNUSED_ char * iu_strrev(char* dst, const char* src);
IUTEST_ATTRIBUTE_UNUSED_ char * iu_itoa(int value, char* dst, int radix);

IUTEST_ATTRIBUTE_UNUSED_ int iuString_ToInt(const char *src);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsSpace(char ch);
IUTEST_ATTRIBUTE_UNUSED_ const char*	iuString_SkipSpace(const char* p);
IUTEST_ATTRIBUTE_UNUSED_ const char*	iuString_FindComma(const char* p);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsStringEqual(const char* str1, const char* str2);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsStringCaseEqual(const char* str1, const char* str2);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsDisabledTestName(const char* name);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsNullOrEmpty(const char* str);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsWhitespace(char c);
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsValidXmlCharacter(char c);
IUTEST_ATTRIBUTE_UNUSED_ char iuString_ToHex(int half_byte);

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_string_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
