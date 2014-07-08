/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_port_c.h
 * @brief		iris unit portable
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_PORT_C_H_6D5DBD9D_C830_4415_957D_D38D69AEE35B_
#define INCG_IRIS_IUTEST_PORT_C_H_6D5DBD9D_C830_4415_957D_D38D69AEE35B_

/* include ===========================================================*/
#include "iutest_compiler_c.h"
#include "iutest_pp_c.h"

#if defined(IUTEST_OS_LINUX)
#  include <unistd.h>
#endif

IUTEST_EXTERN_C_BEGIN()

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

IUTEST_ATTRIBUTE_UNUSED_ const char * iuTestOS_GetEnv(const char* name);

IUTEST_ATTRIBUTE_UNUSED_ int iuTestOS_PutEnv(const char* expr);

IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestOS_GetEnvironmentVariable(const char* name, char* value, size_t size);

IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestOS_GetEnvironmentInt(const char* name, int* value);

IUTEST_ATTRIBUTE_UNUSED_ void iuAbort(void);

IUTEST_ATTRIBUTE_UNUSED_ void iuExit(int exit_code);

#if defined(IUTEST_OS_WINDOWS)

/**
 * @brief	HRESULT のエラー文字列を取得
 * @param [in]	hr	= エラー値
 * @return	文字列
*/
IUTEST_ATTRIBUTE_UNUSED_ char* iuTestOS_AllocHResultString(HRESULT hr);

IUTEST_ATTRIBUTE_UNUSED_ void iuTestOS_FreeHResultString(char* ptr);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_port_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
