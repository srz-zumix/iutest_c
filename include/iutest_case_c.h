/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_case_c.h
 * @brief		iris unit test case ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_case_c_H_1EFD40F6_D189_467b_93B0_887A64E2B830_
#define INCG_IRIS_iutest_case_c_H_1EFD40F6_D189_467b_93B0_887A64E2B830_

/* include ===========================================================*/
#include "iutest_info_c.h"

IUTEST_EXTERN_C_BEGIN()

/* typedef ===========================================================*/
/**
 * @brief	テストケースの SetUp 関数ポインタ型
*/
typedef void (*iuTestSetUpTestCase)(void);

/**
 * @brief	テストケースの TearDown 関数ポインタ型
*/
typedef void (*iuTestTearDownTestCase)(void);

/* enum ==============================================================*/
typedef enum IUTESTCASE_FLAG
{
	IUTESTCASE_DISABLED			= 0x00000002,	/*!< 無効かどうか */
} IUTESTCASE_FLAG;

/* struct ============================================================*/
/**
 * @brief	TestCase 構造体
*/
typedef struct iuTestCase_t
{
	const char* name;		/*!< テストケース名 */
	iuTestInfo*	list;		/*!< TestInfo リスト */
	iuTestSetUpTestCase		setup;		/*!< SetUp */
	iuTestTearDownTestCase	teardown;	/*!< TearDown */
	iuTimeInMillisec		elapsedmsec;/*!< 実行時間 */
	iuUInt32	flag;		/*!< bit フラグ */
	void*		param;		/*!< パラメータへのポインタ */
	struct iuTestCase_t	*next;		/*!< 次の TestCase のノード */
} iuTestCase;

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	テストの総数取得
*/
int iuTestCase_GetTotalTestCount(const iuTestCase* test_case);

/**
 * @brief	実行対象のテストの総数取得
*/
int iuTestCase_GetTestToRunCount(const iuTestCase* test_case);

/**
 * @brief	成功テストの総数取得
*/
int iuTestCase_GetSuccessfulTestCount(const iuTestCase* test_case);

/**
 * @brief	失敗テストの総数取得
*/
int iuTestCase_GetFailureTestCount(const iuTestCase* test_case);

/**
 * @brief	テスト結果の取得
*/
iuBOOL iuTestCase_IsFaild(const iuTestCase* test_case);

/**
 * @brief	無効かどうか
*/
iuBOOL iuTestCase_IsDisabledTest(const iuTestCase* test_case);

/**
 * @brief	無効テストの総数取得
*/
int iuTestCase_GetDisableTestCount(const iuTestCase* test_case);

/**
 * @brief	スキップしたテストの総数取得
*/
int iuTestCase_GetSkippedTestCount(const iuTestCase* test_case);

/**
 * @brief	実行テストがあるかどうか
*/
iuBOOL iuTestCase_HasShouldRunTest(const iuTestCase* test_case);

/**
 * @brief	状態のクリア
*/
void iuTestCase_Clear(iuTestCase* test_case);

/**
 * @brief	テストのフィルタリング
*/
void iuTestCase_Filter(iuTestCase* test_case);

/**
 * @brief	TestInfo の追加
*/
int IUTEST_ATTRIBUTE_UNUSED_ iuTestCase_AddTestInfo(iuTestCase* test_case, iuTestInfo* test_info);

/**
 * @brief	テストの実行
*/
iuBOOL	iuTestCase_Run(iuTestCase* test_case);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_case_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
