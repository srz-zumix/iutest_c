/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_assertion_c.inl
 * @brief		iris unit test assertion 定義 ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_ASSERTION_C_INL_E6AF3476_DA81_46F7_A961_ACCEF7363932_
#define INCG_IRIS_IUTEST_ASSERTION_C_INL_E6AF3476_DA81_46F7_A961_ACCEF7363932_

/* include ===========================================================*/
#include "../iutest_assertion_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionSuccess(void)	{ iuAssertionResult res = { TRUE, NULL, NULL }; return res; }
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailure(void)	{ iuAssertionResult res = { FALSE, NULL, NULL }; return res; }

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuAssertionHelper_Report(const char* file, int line, const char* message, eTestResultType type)
{
	iuTest_CommitResult(iuTestResult_CreatePartResult(file, line, message, type));
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessage(const char* message)
{
	iuAssertionResult res = iuAssertionResult_ctor(); res.message = message;
	return res;
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessage2(const char* message, const char* append)
{
	iuAssertionResult res = iuAssertionResult_ctor();
	const size_t length = iu_strlen(message) + iu_strlen(append) + 1;
	res.buf = iuTest_AllocTestFailureMessageString(length);
	if(res.buf == NULL)
	{
		res.message = message;
	}
	else
	{
		iu_strcpy(res.buf, message);
		iu_strcat(res.buf, append);
		res.message = res.buf;
	}
	return res;
}
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessageComp(const char* message
													, const void* val1, size_t size1, const char* msg1
													, const void* val2, size_t size2, const char* msg2)
{
	iuAssertionResult res = iuAssertionResult_ctor();
	size_t length = iu_strlen(message) + iu_strlen(msg1) + iu_strlen(msg2);
	length += size1 * 4 + 16;
	length += size2 * 4 + 16;

	res.buf = iuTest_AllocTestFailureMessageString(length);
	if( res.buf == NULL )
	{
		res.message = message;
	}
	else
	{
		iu_strcpy(res.buf, message);
		length = iu_strlen(res.buf);
		iuTest_PrintTo(res.buf+length, val1, size1);
		iu_strcat(res.buf, msg1);
		if( val2 != NULL )
		{
			length = iu_strlen(res.buf);
			iuTest_PrintTo(res.buf+length, val2, size2);
		}
		iu_strcat(res.buf, msg2);
		res.message = res.buf;
	}
	return res;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionStringFailureMessage(const char* message, const char* val1, const char* msg1
																				  , const char* val2, const char* msg2)
{
	iuAssertionResult res = iuAssertionResult_ctor();
	const size_t length = iu_strlen(message) + iu_strlen(msg1) + iu_strlen(msg2)
		+ (val1 == NULL ? 6 : iu_strlen(val1)) + (val2 == NULL ? 6 : iu_strlen(val2)) + 1;

	res.buf = iuTest_AllocTestFailureMessageString(length);
	if( res.buf == NULL )
	{
		res.message = message;
	}
	else
	{
		iu_strcpy(res.buf, message);
		iu_strcat(res.buf, val1 == NULL ? "(null)" : val1);
		iu_strcat(res.buf, msg1);
		iu_strcat(res.buf, val2 == NULL ? "(null)" : val2);
		iu_strcat(res.buf, msg2);
		res.message = res.buf;
	}
	return res;
}

#if IUTEST_C_HAS_LIBC && IUTEST_C_HAS_STDARG

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureFormatMessageV(const char* fmt, va_list va)
{
	iuAssertionResult res = iuAssertionResult_ctor();
	res.buf = iuTest_AllocTestFailureMessageString(256);
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()
	vsnprintf(res.buf, 256, fmt, va);
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()
	res.message = res.buf;
	return res;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureFormatMessage(const char* fmt, ...)
{
	iuAssertionResult res;
	va_list va;
	va_start(va, fmt);
	res = iuAssertionFailureFormatMessageV(fmt, va);
	va_end(va);
	return res;
}
#endif

#if defined(IUTEST_OS_WINDOWS)

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureHResultMessage(const char* fmt, HRESULT hr)
{
	char* str = iuTestOS_AllocHResultString(hr);
	iuAssertionResult res = iuAssertionFailureMessage2(fmt, str);
	iuTestOS_FreeHResultString(str);
	return res;
}

#endif

#endif
