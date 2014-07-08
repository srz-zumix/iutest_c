/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_console_c.h
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
#ifndef INCG_IRIS_IUTEST_CONSOLE_C_H_5D02AA77_5C25_4919_BDEC_CD32EB5774C8_
#define INCG_IRIS_IUTEST_CONSOLE_C_H_5D02AA77_5C25_4919_BDEC_CD32EB5774C8_

/* include ===========================================================*/
#include "iutest_port_c.h"
#include "../iutest_env_c.h"

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
#if !defined(IUTEST_HAS_COLORCONSOLE)
#  if defined(IUTEST_OS_WINDOWS_MOBILE) || defined(IUTEST_OS_NACL)
#    define IUTEST_HAS_COLORCONSOLE	0	/*!< 色つきターミナルが使用可能かどうか */
#  else
#    define IUTEST_HAS_COLORCONSOLE	1	/*!< 色つきターミナルが使用可能かどうか */
#  endif
#endif

/* enum ==============================================================*/
/**
 * @internal
 * @brief	文字色
*/
typedef enum iuConsoleColor
{
	PRINT_BLACK,
	PRINT_RED,
	PRINT_GREEN,
	PRINT_YELLOW,
	PRINT_BLUE,
	PRINT_MAGENTA,
	PRINT_CYAN,
	PRINT_WHITE
} iuConsoleColor;

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB && IUTEST_C_HAS_CONSOLEOUT

/**
 * @brief	標準出力
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_VPrint(const char *fmt, va_list va);

/**
 * @brief	標準出力
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_Output(const char *fmt, ...);

/**
 * @brief	標準出力
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_Print(const char *buf);

/**
 * @brief	色指定で標準出力
 * @param [in]	color	= 文字色
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_ColorOutputV(int color, const char *fmt, va_list va);
/**
 * @brief	色指定で標準出力
 * @param [in]	color	= 文字色
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuConsole_ColorOutput(int color, const char *fmt, ...);

#endif

#if !IUTEST_C_HAS_CONSOLEOUT
#  define iuConsole_Print(buf)	(void)0
#  if IUTEST_C_HAS_VARIADIC_MACROS
#    define iuConsole_Output(fmt, ...)				(void)0
#    define iuConsole_ColorOutput(color, fmt, ...)	(void)0
#  endif
#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_console_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
