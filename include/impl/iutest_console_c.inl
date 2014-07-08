/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_console_c.inl
 * @brief		iris unit test console
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_CONSOLE_C_INL_5D02AA77_5C25_4919_BDEC_CD32EB5774C8_
#define INCG_IRIS_IUTEST_CONSOLE_C_INL_5D02AA77_5C25_4919_BDEC_CD32EB5774C8_

/* include ===========================================================*/
#include "../internal/iutest_console_c.h"

/* function ==========================================================*/
#if IUTEST_C_HAS_CONSOLEOUT

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_VPrint(const char *fmt, va_list va)
{
	if( iuTestEnv_GetInstance()->pfnvpritf != NULL )
	{
		(void)(iuTestEnv_GetInstance()->pfnvpritf)(fmt, va);
	}
	else
	{
		IUTEST_UNUSED_VAR(fmt);
		IUTEST_UNUSED_VAR(va);
		IUTEST_VPRINTF(fmt, va);
	}
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_Output(const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	iuConsole_VPrint(fmt, va);
	va_end(va);
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_Print(const char *buf)
{
	iuConsole_Output(buf);
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_ColorOutputV(int color, const char *fmt, va_list va)
{
#if defined(IUTEST_OS_WINDOWS) && !defined(IUTEST_OS_WINDOWS_MOBILE)
	const WORD attr[] = {
		0,
		FOREGROUND_RED,
		FOREGROUND_GREEN,
		FOREGROUND_GREEN | FOREGROUND_RED,
		FOREGROUND_BLUE,
		FOREGROUND_RED | FOREGROUND_BLUE,
		FOREGROUND_GREEN | FOREGROUND_BLUE,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
	};
	const HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(stdout_handle, &csbi);
	{
		const WORD wAttributes = csbi.wAttributes;

#if IUTEST_C_HAS_LIBC
		fflush(stdout);
#endif
		SetConsoleTextAttribute(stdout_handle, attr[color] | FOREGROUND_INTENSITY);

		iuConsole_VPrint(fmt, va);

#if IUTEST_C_HAS_LIBC
		fflush(stdout);
#endif
		SetConsoleTextAttribute(stdout_handle, wAttributes);
	}
#else
	const char c = (char)('0' + color);
	IUTEST_UNUSED_VAR(color);
	IUTEST_UNUSED_VAR(fmt);
	IUTEST_UNUSED_VAR(va);

	iuConsole_Output("\033[1;3%cm", c);
	iuConsole_VPrint(fmt, va);
	iuConsole_Output("\033[m");
#endif
}

IUTEST_C_INL_INLINE iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuConsole_IsColorModeOff(void)
{
	return iuTestEnv_IsEnableFlag(IUTESTENV_CONSOLECOLOR_OFF);
}
IUTEST_C_INL_INLINE iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuConsole_IsColorModeOn(void)
{
	return iuTestEnv_IsEnableFlag(IUTESTENV_CONSOLECOLOR_ON);
}
IUTEST_C_INL_INLINE iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuConsole_IsColorModeAnsi(void)
{
	return iuTestEnv_IsEnableFlag(IUTESTENV_CONSOLECOLOR_ANSI);
}

IUTEST_C_INL_INLINE iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuConsole_IsShouldUseColor(iuBOOL use_color)
{
	if( iuConsole_IsColorModeOn() )
	{
		return TRUE;
	}
	else if( iuConsole_IsColorModeOff() )
	{
		return FALSE;
	}

#if defined(IUTEST_OS_WINDOWS) || defined(IUTEST_C_NO_GETENV)
	return use_color;
#else
	{
		const char* env = iuTestOS_GetEnv("TERM");
		iuBOOL term_conf = (env != NULL) && (
			iuString_IsStringEqual(env, "xterm")
			|| iuString_IsStringEqual(env, "xterm-color")
			|| iuString_IsStringEqual(env, "xterm-256color")
			|| iuString_IsStringEqual(env, "screen")
			|| iuString_IsStringEqual(env, "screen-256color")
			|| iuString_IsStringEqual(env, "linux")
			|| iuString_IsStringEqual(env, "cygwin")
			);
		return use_color && term_conf;
	}
#endif
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_ColorOutput(int color, const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	if( iuConsole_IsShouldUseColor(TRUE) )
	{
		iuConsole_ColorOutputV(color, fmt, va);
	}
	else
	{
		iuConsole_VPrint(fmt, va);
	}
	va_end(va);
}

#endif

#endif
