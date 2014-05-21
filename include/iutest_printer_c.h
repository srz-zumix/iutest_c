/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_printer_c.h
 * @brief		iris unit test printer ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_PRINTER_C_H_ADF851F3_C89B_4CA4_B9A0_A2B2229945C6_
#define INCG_IRIS_IUTEST_PRINTER_C_H_ADF851F3_C89B_4CA4_B9A0_A2B2229945C6_

/* include ===========================================================*/
#include "iutest_defs_c.h"
#include "internal/iutest_string_c.h"

IUTEST_EXTERN_C_BEGIN()

/* function ===========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	バッファの出力
*/
IUTEST_ATTRIBUTE_UNUSED_ char* iuTest_PrintTo(char* dst, const void *buf, size_t size);

/**
 * @brief	1Byte 変数の出力
*/
IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU8(char *dst, iuUInt8 data);

/**
 * @brief	2Byte 変数の出力
*/
IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU16(char *dst, iuUInt16 data);

/**
 * @brief	4Byte 変数の出力
*/
IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU32(char *dst, iuUInt32 data);

#if IUTEST_C_HAS_LONGLONG

/**
 * @brief	8Byte 変数の出力
*/
IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU64(char *dst, iuUInt64 data);

#endif

#endif

#if IUTEST_C_HAS_GENERIC

#if IUTEST_C_HAS_FLOATINGPOINT

#define IUTEST_PRINTF_FORMAT_PARAM(x, m, p) _Generic((x)	\
	, char : m(p, "%c")				\
	, signed char: m(p, "%hhd")		\
	, unsigned char: m(p, "%hhu")	\
	, signed short: m(p, "%hd")		\
	, unsigned short: m(p, "%hu")	\
	, signed int: m(p, "%d")		\
	, unsigned int: m(p, "%u")		\
	, signed long: m(p, "%ld")		\
	, unsigned long: m(p, "%lu")	\
	, char* : m(p, "%s")			\
	, void* : m(p, "%p")			\
	, float: m(p, "%f")				\
	, double: m(p, "%lf")			\
	, default: m(p, "%p")			\
	)

#else

#define IUTEST_PRINTF_FORMAT_PARAM(x, m, p) _Generic((x)	\
	, char : m(p, "%c")				\
	, signed char: m(p, "%hhd")		\
	, unsigned char: m(p, "%hhu")	\
	, signed short: m(p, "%hd")		\
	, unsigned short: m(p, "%hu")	\
	, signed int: m(p, "%d")		\
	, unsigned int: m(p, "%u")		\
	, signed long: m(p, "%ld")		\
	, unsigned long: m(p, "%lu")	\
	, char* : m(p, "%s")			\
	, void* : m(p, "%p")			\
	, default: m(p, "%p")			\
	)

#endif

/**
 * @private
* @{
*/
#define IIUT_PRINTF_FORMAT_M(p, c) c
/**
 * @}
*/

#define IUTEST_PRINTF_FORMAT(x) IUTEST_PRINTF_FORMAT_PARAM(x, IIUT_PRINTF_FORMAT_M, IUTEST_PP_EMPTY())

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_printer_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
