/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_string_c.inl
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
#ifndef INCG_IRIS_IUTEST_STRING_C_INL_E22B02D7_E9E7_412C_B609_DC3D9C66895D_
#define INCG_IRIS_IUTEST_STRING_C_INL_E22B02D7_E9E7_412C_B609_DC3D9C66895D_

/* include ===========================================================*/
#include "../internal/iutest_string_c.h"

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()

#if IUTEST_C_HAS_LIBC

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_strcpy(char *dst, const char *src)
{
	if( src == NULL || dst == NULL ) return dst;
	return strcpy(dst, src);
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_strcat(char *dst, const char *src)
{
	if( src == NULL || dst == NULL ) return dst;
	return strcat(dst, src);
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ size_t iu_strlen(const char *str)
{
	if( str == NULL ) return 0;
	return strlen(str);
}

#if IUTEST_C_HAS_WCHAR_T
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ size_t iu_wcslen(const wchar_t *str)
{
	if( str == NULL ) return 0;
	return wcslen(str);
}
#endif

#else

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iu_strcmp(const char* str1, const char* str2)
{
	const char* l = str1;
	const char* r = str2;
	while(*l)
	{
		if( *l < *r ) return -1;
		if( *l > *r ) return 1;
		++l;
		++r;
	}
	if( *l < *r ) return -1;
	if( *l > *r ) return 1;
	return 0;
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_strcpy(char *dst, const char *src)
{
	char *ret = dst;
	if( dst == NULL ) return NULL;
	if( src == NULL ) return NULL;
	while(*src)
	{
		*dst = *src;
		++dst;
		++src;
	}
	*dst = '\0';
	return ret;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_strcat(char *dst, const char *src)
{
	char *ret = dst;
	if( dst == NULL ) return NULL;
	if( src == NULL ) return NULL;
	while(*dst)
	{
		++dst;
	}
	iu_strcpy(dst, src);
	return ret;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ size_t iu_strlen(const char *str)
{
	size_t len = 0;
	if( str != NULL )
	{
		while(*str++ != '\0')
		{
			++len;
		}
	}
	return len;
}

#if IUTEST_C_HAS_WCHAR_T
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ size_t iu_wcslen(const wchar_t *str)
{
	size_t len = 0;
	if( str != NULL )
	{
		while(*str++ != L'\0')
		{
			++len;
		}
	}
	return len;
}
#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ const char * iu_strstr(const char *str1, const char *str2)
{
	const char *p = str2;
	const char *find = NULL;
	if( str1 == NULL ) return find;
	if( str2 == NULL ) return find;
	if( *str2 == '\0' ) return str1;

	while(*str1)
	{
		if( *str1 != *p )
		{
			find = NULL;
			p = str2;
		}
		if( *str1 == *p )
		{
			if( find == NULL ) find = str1;
			++p;
			if( !(*p) )
			{
				return find;
			}
		}
		++str1;
	}
	return find;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ const char * iu_strchr(const char *str, char ch)
{
	if( str == NULL ) return NULL;
	while(*str)
	{
		if( *str == ch ) return str;
		++str;
	}
	return NULL;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iu_toupper(int ch)
{
	if( ch >= 'a' && ch <= 'z' )
	{
		return ch - 'a' + 'A';
	}
	return ch;
}

#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iu_stricmp(const char* str1, const char* str2)
{
#if		defined(_MSC_VER)
	return _stricmp(str1, str2);
#elif	defined(__ARMCC_VERSION) || (defined(IUTEST_OS_LINUX))
	return strcasecmp(str1, str2);
#elif	IUTEST_C_HAS_LIBC
	return stricmp(str1, str2);
#else
	const char* l = str1;
	const char* r = str2;
	while(*l)
	{
		char ul = (char)iu_toupper(*l);
		char ur = (char)iu_toupper(*r);
		if( ul < ur ) return -1;
		if( ul > ur ) return 1;
		++l;
		++r;
	}
	if( *l < *r ) return -1;
	if( *l > *r ) return 1;
	return 0;
#endif
}

#if IUTEST_C_HAS_WCHAR_T

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iu_wcsicmp(const wchar_t * str1, const wchar_t * str2)
{
#if		defined(_MSC_VER)
	return _wcsicmp(str1, str2);
#elif	defined(IUTEST_OS_LINUX) && !defined(IUTEST_OS_LINUX_ANDROID)
	return wcscasecmp(str1, str2);
#else
	const wchar_t* l = str1;
	const wchar_t* r = str2;
	while(*l)
	{
		wchar_t ul = (wchar_t)towupper(*l);
		wchar_t ur = (wchar_t)towupper(*r);
		if( ul < ur ) return -1;
		if( ul > ur ) return 1;
		++l;
		++r;
	}
	if( *l < *r ) return -1;
	if( *l > *r ) return 1;
	return 0;
#endif
}

#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_strrev_self(char* str)
{
	size_t len = iu_strlen(str);
	char* ps = str;
	char* pe = str + len - 1;
	while( ps < pe )
	{
		char tmp = *ps;
		*ps = *pe;
		*pe = tmp;
		++ps;
		--pe;
	}
	return str;
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_strrev(char* dst, const char* src)
{
	if( dst != NULL )
	{
		if( dst == src )
		{
			return iu_strrev_self(dst);
		}
		else
		{
			size_t len = iu_strlen(src);
			const char* p = src + len - 1;
			while( p >= src )
			{
				*dst = *p;
				--p;
			}
			*dst = '\0';
		}
	}
	return dst;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuString_ToInt(const char *src)
{
#if IUTEST_C_HAS_LIBC
	char* end = NULL;
	long value = strtol(src, &end, 0);
	return (int)value;
#else
	int value=0;
	while(*src != '\0')
	{
		char ch = *src++;
		if( ch >= '0' && ch <= '9' )
		{
			value *= 10;
			value += '9' - ch;
		}
		else
		{
			break;
		}
	}
	return value;
#endif
}


IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsSpace(char ch)	{ return ch == ' ' || ch =='\t'; }
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ const char*	iuString_SkipSpace(const char* p)
{
	return p == NULL ? NULL : (iuString_IsSpace(*p) ? iuString_SkipSpace(++p) : p);
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ const char*	iuString_FindComma(const char* p)
{
	return (p == NULL || *p == '\0') ? NULL : ((*p == ',') ? p : iuString_FindComma(++p));
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsStringEqual(const char* str1, const char* str2)
{
	return str1 == NULL ? (str2 == NULL ? TRUE : FALSE) : (str2 == NULL ? FALSE : (iu_strcmp(str1, str2) == 0));
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsStringCaseEqual(const char* str1, const char* str2)
{
	return str1 == NULL ? (str2 == NULL ? TRUE : FALSE) : (str2 == NULL ? FALSE : (iu_stricmp(str1, str2) == 0));
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsDisabledTestName(const char* name)
{
	return name == NULL ? FALSE : (iu_strstr(name, "DISABLED_") == name ? TRUE : FALSE);
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsNullOrEmpty(const char* str)
{
	return str == NULL || *str == '\0' ? TRUE : FALSE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsWhitespace(char c)
{
	return (c == 0x9 || c == 0xA || c == 0xD) ? TRUE: FALSE;
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuString_IsValidXmlCharacter(char c)
{
	return (iuString_IsWhitespace(c) || c >= 0x20) ? TRUE: FALSE;
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char iuString_ToHex(int half_byte)
{
	if( half_byte & ~0xF ) return '?';
	return (char)(half_byte > 9 ? 'A' + (half_byte-10) : '0' + half_byte);
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_itoa_(int value, char* dst, int radix)
{
	if( value != 0 )
	{
		const int d = value%radix;
		dst = iu_itoa_(value/radix, dst, radix);
		*dst = iuString_ToHex(d);
		return dst + 1;
	}
	return dst;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char * iu_itoa(int value, char* dst, int radix)
{
	if( value == 0 )
	{
		*dst = '0';
		*(dst+1) = '\0';
	}
	else
	{
		char* d = iu_itoa_(value, dst, radix);
		*d = '\0';
	}
	return dst;
}

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()

#endif
