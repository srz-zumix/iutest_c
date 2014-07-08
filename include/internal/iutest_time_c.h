/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_time_c.h
 * @brief		iris unit test time utility
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_TIME_C_H_C6B9E65B_4059_4175_A6DB_397DBF338AA8_
#define INCG_IRIS_IUTEST_TIME_C_H_C6B9E65B_4059_4175_A6DB_397DBF338AA8_

/* include ===========================================================*/
#include "../iutest_defs_c.h"

#if		IUTEST_C_HAS_HDR_TIME
#  include <time.h>
#endif

#if		IUTEST_C_HAS_HDR_SYSTIME
#  include <sys/time.h>
#elif	defined(IUTEST_OS_WINDOWS) && !defined(IUTEST_OS_WINDOWS_MOBILE)
#  include <sys/timeb.h>
#endif

/* function ==========================================================*/

/**
 * @brief	ミリ秒から秒単位の文字列を生成
*/
static IUTEST_ATTRIBUTE_UNUSED_ void	iuTest_FormatTimeInMillisecAsSecond(char* dst, iuTimeInMillisec mmsec)
{
#if IUTEST_C_HAS_LIBC && IUTEST_C_HAS_FLOATINGPOINT
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()
	sprintf(dst, "%f", mmsec/1000.0f);
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()
#else
	char* p = dst;
	{
		iuTimeInMillisec sec = mmsec/1000;
		if( sec > 0 )
		{
			for( ; sec > 0; sec/=10, ++p ) *p = (char)('0' + sec % 10);
			iu_strrev_self(dst);
		}
		else
		{
			*p = '0';
			++p;
		}
	}
	{
		iuTimeInMillisec dec = mmsec%1000;
		if( dec > 0 )
		{
			int i = 0;
			*p++ = '.';
			for( i=0; i < 3; ++i, ++p )
			{
				int digit = 10*(2-i);
				if( digit )
				{
					*p = (char)('0' + (dec/digit)%10);
					if( dec % digit == 0 ) break;
				}
				else
				{
					*p = (char)('0' + (dec%10));
				}
			}
		}
	}
	*p = '\0';
#endif
}

/**
 * @brief	現在時刻の取得
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTimeInMillisec	iuTest_GetTime(void)
{
#if IUTEST_C_HAS_CTIME
	return (iuTimeInMillisec)time(NULL);
#else
	return 0;
#endif
}

/**
 * @brief	現在時刻のミリ秒取得
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTimeInMillisec	iuTest_GetTimeInMillis(void)
{
#if		defined(IUTEST_GetMillisec)
	return IUTEST_GetMillisec();

#elif	IUTEST_C_HAS_GETTIMEOFDAY
	timeval tv;
	gettimeofday(&tv, NULL);
	return (iuTimeInMillisec)(tv.tv_sec) * 1000 + (iuTimeInMillisec)(tv.tv_usec) / 1000;

#elif	IUTEST_C_HAS_CLOCK
	return clock() * 1000 / CLOCKS_PER_SEC;

#elif	defined(IUTEST_OS_WINDOWS)

#if		defined(IUTEST_OS_WINDOWS_MOBILE)
	return (iuTimeInMillisec)(GetTickCount());
#else

	struct __timeb64 tb;

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()
	_ftime64(&tb);
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()

	return (iuTimeInMillisec)(tb.time * 1000 + tb.millitm);

#endif

#else

#define IUTEST_C_NO_GETTIMEINMILLIS
	return iuTest_GetTime()*1000;
#endif
}

/**
 * @brief	不定な値の取得
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuTest_GetIndefiniteValue(void)
{
#if !defined(IUTEST_C_NO_GETTIMEINMILLIS)
	return (iuUInt32)(iuTest_GetTimeInMillis());
#else
	/* なるべく同じにならないようにする */
	static iuUInt32 s = 20120206u;
	s = s*1664525u + 1013904223u;
	return s;
#endif
}

/**
 * @brief	ストップウォッチ用構造体
*/
typedef struct iuTestStopWatch_t
{
	iuTimeInMillisec	begin;
} iuTestStopWatch;

/**
 * @brief	ストップウォッチのスタート
*/
static IUTEST_ATTRIBUTE_UNUSED_ void iuTest_StopWatchStart(iuTestStopWatch* watch)
{
	watch->begin = iuTest_GetTimeInMillis();
}

/**
 * @brief	ストップウォッチの停止
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTimeInMillisec iuTest_StopWatchStop(iuTestStopWatch* watch)
{
	return iuTest_GetTimeInMillis() - watch->begin;
}


#endif
