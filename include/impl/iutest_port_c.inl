/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_port_c.inl
 * @brief		iris unit portable ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_port_c_INL_6D5DBD9D_C830_4415_957D_D38D69AEE35B_
#define INCG_IRIS_iutest_port_c_INL_6D5DBD9D_C830_4415_957D_D38D69AEE35B_

/* include ===========================================================*/
#include "../internal/iutest_port_c.h"

/* function ==========================================================*/

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ const char * iuTestOS_GetEnv(const char* name)
{
#if defined(IUTEST_OS_WINDOWS_MOBILE) || defined(IUTEST_C_NO_GETENV)
	IUTEST_UNUSED_VAR(name);
	return NULL;
#elif defined(__BORLANDC__) || defined(__SunOS_5_8) || defined(__SunOS_5_9)
	const char* env = getenv(name);
	return (env != NULL && env[0] != '\0') ? env : NULL;
#else
	return getenv(name);
#endif
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTestOS_PutEnv(const char* expr)
{
#if defined(IUTEST_OS_WINDOWS_MOBILE) || defined(IUTEST_C_NO_PUTENV)
	IUTEST_UNUSED_VAR(expr);
	return -1;
#else
	return putenv((char*)expr);
#endif
}


IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestOS_GetEnvironmentVariable(const char* name, char* value, size_t size)
{
#if defined(IUTEST_OS_WINDOWS) && !defined(IUTEST_OS_WINDOWS_MOBILE)
	if( !GetEnvironmentVariableA(name, value, size) ) return FALSE;
	return TRUE;
#else
	IUTEST_UNUSED_VAR(size);
	const char* env = iuTestOS_GetEnv(name);
	if( env == NULL ) return FALSE;
	iu_strcpy(value, env);
	return TRUE;
#endif
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestOS_GetEnvironmentInt(const char* name, int* value)
{
	char buf[128];
	iu_memset(buf, 0, sizeof(buf));
	if( value == NULL ) return FALSE;
	if( iuTestOS_GetEnvironmentVariable(name, buf, sizeof(buf)) ) 
	{
		*value = iuString_ToInt(buf);
		return TRUE;
	}
	return FALSE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuAbort(void)
{
#if defined(IUTEST_OS_WINDOWS_MOBILE)
	DebugBreak();
	TerminateProcess(GetCurrentProcess(), 1);
#elif IUTEST_C_HAS_LIBC
	abort();
#else
	int* p = NULL;
	*p = 0;
#endif
}


IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuExit(int exit_code)
{
#if IUTEST_C_HAS_LIBC
	exit(exit_code);
#else
	IUTEST_UNUSED_VAR(exit_code);
	int* p = NULL;
	*p = 0;
#endif
}

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()

#if defined(IUTEST_OS_WINDOWS)

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char* iuTestOS_AllocHResultString(HRESULT hr)
{
#if defined(IUTEST_OS_WINDOWS_MOBILE)
	return NULL;
#else
	LPSTR buf = NULL;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), /* デフォルト ユーザー言語 */
		(LPSTR)&buf,
		0,
		NULL );
	return buf;
#endif
}

static IUTEST_ATTRIBUTE_UNUSED_ void iuTestOS_FreeHResultString(char* ptr)
{
	LocalFree(ptr);
}

#endif

#endif
