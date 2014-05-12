/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_message_c.inl
 * @brief		iris unit test 用 メッセージ ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_message_C_INL_B8037C4F_8F86_4c64_B1FB_01F9018076A0_
#define INCG_IRIS_iutest_message_C_INL_B8037C4F_8F86_4c64_B1FB_01F9018076A0_

/* include ===========================================================*/
#include "../internal/iutest_message_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE char* iuTest_FormatDecimalNumber(char* dst, int number)
{
	if( dst != NULL )
	{
		char* p = dst;
		if( number >= 0 )
		{
			if( number == 0 )
			{
				*p++ = '0';
				*p = '\0';
			}
			else
			{
				while(number)
				{
					*p++ = (char)('0' + number%10);
					number /= 10;
				}
				*p = '\0';
				iu_strrev_self(dst);
			}
		}
	}
	return dst;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char* iuTest_FormatCompilerFileLocation(char* dst, const char* file, int line)
{
	if( dst != NULL )
	{
		const char* const file_name = file == NULL ? "Unkown file" : file;
		iu_strcpy(dst, file_name);
		if( line >= 0 )
		{
			size_t len = iu_strlen(dst);
			char* p = dst + len;
#ifdef _MSC_VER
			*p++ = '(';
#else
			*p++ = ':';
#endif
			iuTest_FormatDecimalNumber(p, line);
#ifdef _MSC_VER
			iu_strcat(p, ")");
#endif
		}
	}
	return dst;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char* iuTest_FormatCompilerIndependentFileLocation(char* dst, const char* file, int line)
{
	if( dst != NULL )
	{
		const char* const file_name = file == NULL ? "Unkown file" : file;
		iu_strcpy(dst, file_name);
		if( line >= 0 )
		{
			size_t len = iu_strlen(dst);
			char* p = dst + len;
			*p++ = ':';
			iuTest_FormatDecimalNumber(p, line);
		}
	}
	return dst;
}

#endif
