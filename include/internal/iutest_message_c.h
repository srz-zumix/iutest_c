/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_message_c.h
 * @brief		iris unit test 用 メッセージ
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_MESSAGE_C_H_B8037C4F_8F86_4C64_B1FB_01F9018076A0_
#define INCG_IRIS_IUTEST_MESSAGE_C_H_B8037C4F_8F86_4C64_B1FB_01F9018076A0_

/* include ===========================================================*/
#include "iutest_string_c.h"

IUTEST_EXTERN_C_BEGIN()

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	10進数文字列を生成
*/
char* iuTest_FormatDecimalNumber(char* dst, int number);

/**
 * @brief	ファイル名と行番号を連結した文字列を生成(コンパイラを考慮する)
*/
IUTEST_ATTRIBUTE_UNUSED_ char* iuTest_FormatCompilerFileLocation(char* dst, const char* file, int line);

/**
 * @brief	ファイル名と行番号を連結した文字列を生成
*/
IUTEST_ATTRIBUTE_UNUSED_ char* iuTest_FormatCompilerIndependentFileLocation(char* dst, const char* file, int line);

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_message_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
