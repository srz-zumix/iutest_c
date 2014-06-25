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

#define IUTEST_PRINTF_FORMAT_PARAM(x, prefix, postfix) _Generic((x)	\
	, char : prefix "%c" postfix				\
	, signed char: prefix "%hhd" postfix		\
	, unsigned char: prefix "%hhu" postfix		\
	, signed short: prefix "%hd" postfix		\
	, unsigned short: prefix "%hu" postfix		\
	, signed int: prefix "%d" postfix			\
	, unsigned int: prefix "%u" postfix			\
	, signed long: prefix "%ld" postfix			\
	, unsigned long: prefix "%lu" postfix		\
	, char* : prefix "%s" postfix				\
	, void* : prefix "%p" postfix				\
	, float: prefix "%f" postfix				\
	, double: prefix "%lf" postfix				\
	, default: prefix "%p" postfix				\
	 )

#define IUTEST_PRINTF_FORMAT_PARAM2(x, y, str0, str1, str2) _Generic((x)	\
	, char : IUTEST_PRINTF_FORMAT_PARAM(y, str0 "%c" str1, str2)			\
	, signed char: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hhd" str1, str2)	\
	, unsigned char: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hhu" str1, str2)	\
	, signed short: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hd" str1, str2)	\
	, unsigned short: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hu" str1, str2)	\
	, signed int: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%d" str1, str2)		\
	, unsigned int: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%u" str1, str2)	\
	, signed long: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%ld" str1, str2)	\
	, unsigned long: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%lu" str1, str2)	\
	, char* : IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%s" str1, str2)			\
	, void* : IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%p" str1, str2)			\
	, float: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%f" str1, str2)			\
	, double: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%lf" str1, str2)			\
	, default: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%p" str1, str2)			\
	)

#else

#define IUTEST_PRINTF_FORMAT_PARAM(x, prefix, postfix) _Generic((x)	\
	, char : prefix "%c" postfix				\
	, signed char: prefix "%hhd" postfix		\
	, unsigned char: prefix "%hhu" postfix		\
	, signed short: prefix "%hd" postfix		\
	, unsigned short: prefix "%hu" postfix		\
	, signed int: prefix "%d" postfix			\
	, unsigned int: prefix "%u" postfix			\
	, signed long: prefix "%ld" postfix			\
	, unsigned long: prefix "%lu" postfix		\
	, char* : prefix "%s" postfix				\
	, void* : prefix "%p" postfix				\
	, default: prefix "%p" postfix				\
	)

#define IUTEST_PRINTF_FORMAT_PARAM2(x, y, str0, str1, str2) _Generic((x)	\
	, char : IUTEST_PRINTF_FORMAT_PARAM(y, str0 "%c" str1, str2)			\
	, signed char: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hhd" str1, str2)	\
	, unsigned char: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hhu" str1, str2)	\
	, signed short: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hd" str1, str2)	\
	, unsigned short: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%hu" str1, str2)	\
	, signed int: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%d" str1, str2)		\
	, unsigned int: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%u" str1, str2)	\
	, signed long: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%ld" str1, str2)	\
	, unsigned long: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%lu" str1, str2)	\
	, char* : IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%s" str1, str2)			\
	, void* : IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%p" str1, str2)			\
	, default: IUTEST_PRINTF_FORMAT_PARAM(y, str0  "%p" str1, str2)			\
	)

#endif

#define IUTEST_PRINTF_FORMAT(x) IUTEST_PRINTF_FORMAT_PARAM(x, IUTEST_PP_EMPTY(), IUTEST_PP_EMPTY())
#define IUTEST_PRINTF_FORMAT_MSG(prefix, x, postfix) IUTEST_PRINTF_FORMAT_PARAM(x, prefix, postfix)
#define IUTEST_PRINTF_FORMAT_MSG2(str0, x, str1, y, str2) IUTEST_PRINTF_FORMAT_PARAM2(x, y, str0, str1, str2)

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_printer_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
