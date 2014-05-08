/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_body_c.h
 * @brief		iris unit test テスト単体クラス ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_BODY_C_H_3EEA6706_9954_4330_B292_129667FA6B96_
#define INCG_IRIS_IUTEST_BODY_C_H_3EEA6706_9954_4330_B292_129667FA6B96_

/* include ===========================================================*/
#include "iutest_result_c.h"
#include "internal/iutest_core_impl_c.h"

IUTEST_EXTERN_C_BEGIN()

/* typedef ===========================================================*/
/**
 * @brief	テストの関数ポインタ型
*/
typedef void (*iuTestBody)(void);

/**
 * @brief	テストの SetUp 関数ポインタ型
*/
typedef void (*iuTestSetUp)(void);

/**
 * @brief	テストの TearDown 関数ポインタ型
*/
typedef void (*iuTestTearDown)(void);

/* struct ============================================================*/
/**
 * @brief	テスト構造体
*/
typedef struct iuTest_t
{
	iuTestBody		body;		/*!< テスト関数 */
	iuTestSetUp		setup;		/*!< SetUp関数 */
	iuTestTearDown	teardown;	/*!< TearDown関数 */
	void*			user;		/*!< ユーザー定義領域アドレス */
} iuTest;

/* define ============================================================*/
/** @private */
#define iuTest_ctor(body)	{ body, NULL, NULL, NULL }

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
* @brief	iuTest Body の初期化
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTest_Init(iuTest* test_body, iuTestSetUp setup, iuTestTearDown teardown, void* user);

/**
 * @brief	プロパティの記録
 * @param [in]	key		= キー名
 * @param [in]	value	= 値の文字列
 * @return	成否
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTest_RecordProperty(const char *key, const char *value);

/**
 * @brief	テスト結果を報告
*/
void iuTest_CommitResult(iuTestPartResult* part_result);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_body_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
