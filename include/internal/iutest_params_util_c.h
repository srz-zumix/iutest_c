/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_params_util_c.h
 * @brief		iris unit test parameter テスト用 util ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_params_util_C_H_4B4332BA_2300_416B_A1EE_004BC08A627E_
#define INCG_IRIS_iutest_params_util_C_H_4B4332BA_2300_416B_A1EE_004BC08A627E_

/* include ===========================================================*/
#include "../iutest_defs_c.h"

#if IUTEST_C_HAS_PARAM_TEST

/* define ============================================================*/
/** @private */
#define iuTestParamHolder_ctor(testcase_name_, testcases_, params)	{	\
	NULL, IUTEST_PP_TOSTRING(testcase_name_), testcases_, params		\
	, sizeof(params[0]), IUTEST_PP_COUNTOF(params), NULL }

/* struct ============================================================*/
/**
 * @brief	ParameterHolder
*/
typedef struct iuTestParamHolder_t
{
	const char**	testcase_names;		/*!< テストケース名 */
	const char*		testcase_base_name;	/*!< テストケース名 */
	iuTestCase*		testcases;			/*!< 登録用テストケース配列 */
	void*			params;				/*!< パラメータ配列 */
	size_t			align;				/*!< パラメータアラインメント */
	size_t			elem;				/*!< パラメータ総数 */
	struct iuTestParamHolder_t	*next;	/*!< 次の iuTestParamHolder のノード */
} iuTestParamHolder;

#endif	/* IUTEST_C_HAS_PARAM_TEST */

#endif
