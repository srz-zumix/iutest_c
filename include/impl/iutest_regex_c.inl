/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_regex_c.inl
 * @brief		iris unit test 用 regex
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_REGEX_C_INL_1575CB44_189A_4248_B305_DB4882E3BFC2_
#define INCG_IRIS_IUTEST_REGEX_C_INL_1575CB44_189A_4248_B305_DB4882E3BFC2_

/* include ===========================================================*/
#include "../internal/iutest_regex_c.h"

/* function ==========================================================*/
#if defined(_MSC_VER) && defined(__STDC_WANT_SECURE_LIB__) && __STDC_WANT_SECURE_LIB__
#  pragma warning (push)
#  pragma warning (disable:4996)
#endif

IUTEST_C_INL_INLINE iuBOOL	iuTestRegex_MatchImpl(const char* begin, const char* end, const char* src)
{
	const char* tp = begin;
	if( *tp == '\0' ) return FALSE;
	while( tp != end )
	{
		if( *tp == '*' )	/* 任意の文字列にマッチ */
		{
			++tp;
			while( *tp == '*' ) ++tp;
			if( tp == end ) return TRUE;

			{
				const char nc = *tp;
				if( nc == '\0' ) return TRUE;

				for( ; ; )
				{
					while( *src != nc )
					{
						++src;
						if( *src == '\0' ) return FALSE;
					}
					/* つづきを検査 */
					if( iuTestRegex_MatchImpl(tp+1, end, ++src) ) return TRUE;
				}
			}
		}
		else if( *tp == '?' )	/* 任意の一文字にマッチ */
		{
			if( *src == '\0' ) return FALSE;
		}
		else	/* 指定文字にマッチ */
		{
			if( *tp != *src ) return FALSE;
		}
		++tp;
		++src;
	}
	if( *src != '\0' ) return FALSE;
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestRegex_Match(const char* regex, const char* src)
{
	const char* tp = regex;

	while( *tp != '\0' )
	{
		const char* end = tp;
		while( *end != '\0' && *end != ':' ) ++end;

		{
			iuBOOL match = TRUE;
			const char* end2 = tp;
			while( end2 != end )
			{
				++end2;
				while( *end2 != '-' && end2 != end ) ++end2;
				if( *tp == '-' )
				{
					if( iuTestRegex_MatchImpl(tp+1, end2, src) ) match = FALSE;
				}
				else
				{
					if( !iuTestRegex_MatchImpl(tp, end2, src) ) match = FALSE;
				}
				tp = end2;
			}
			if( match ) return TRUE;
		}
		tp = end;
	}
	return FALSE;
}

#if defined(_MSC_VER) && defined(__STDC_WANT_SECURE_LIB__) && __STDC_WANT_SECURE_LIB__
#  pragma warning (pop)
#endif

#endif
