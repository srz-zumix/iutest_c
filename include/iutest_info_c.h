/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_info_c.h
 * @brief		iris unit test info ファイル
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
#ifndef INCG_IRIS_iutest_info_c_H_A3DF31D4_5FC6_4c62_BCF6_EF835E47B10A_
#define INCG_IRIS_iutest_info_c_H_A3DF31D4_5FC6_4c62_BCF6_EF835E47B10A_

/* include ===========================================================*/
#include "iutest_body_c.h"
#include "internal/iutest_regex_c.h"

IUTEST_EXTERN_C_BEGIN()

/* declare ===========================================================*/
struct iuTestCase_t;

/* enum ==============================================================*/
typedef enum IUTESTINFO_FLAG
{
	IUTESTINFO_SHOULD_NOTRUN	= 0x00000001,	/*!< 実行するかどうか */
	IUTESTINFO_DISABLED			= 0x00000002,	/*!< 無効かどうか */
	IUTESTINFO_RAN				= 0x00000010,	/*!< 実行したかどうか */
} IUTESTINFO_FLAG;

/* struct ============================================================*/
/**
 * @brief	TestInfo 構造体
*/
typedef struct iuTestInfo_t
{
	const char*		name;			/*!< テスト名 */
	const char*		testcase_name;	/*!< テストケース名 */
	iuUInt32		flag;			/*!< bit フラグ */
	void*			param;			/*!< パラメータ */
	iuTest			test;			/*!< テスト本体 */
	iuTestResult	result;			/*!< テスト結果 */
	struct iuTestInfo_t	*next;		/*!< 次のノード */
} iuTestInfo;

/* define ============================================================*/
/** @private */
#define iuTestInfo_ctor(name, body)	{ name, NULL, 0, NULL, iuTest_ctor(body), iuTestResult_ctor(), NULL }

/* declare ===========================================================*/
#if !IUTEST_C_HAS_LIB

static iuBOOL iuTestInfo_IsShouldRunTest(const iuTestInfo* test_info);

#endif

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	TestBody の実行
*/
iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Run(struct iuTestCase_t* test_case, iuTestInfo* test_info);

/**
 * @brief	実行かどうか
*/
iuBOOL iuTestInfo_IsShouldRunTest(const iuTestInfo *test_info);

/**
 * @brief	実行したかどうか
*/
iuBOOL iuTestInfo_IsRanTest(const iuTestInfo *test_info);

/**
 * @brief	失敗したかどうか
*/
iuBOOL iuTestInfo_HasFailure(const iuTestInfo *test_info);

/**
 * @brief	無効かどうか
*/
iuBOOL iuTestInfo_IsDisabledTest(const iuTestInfo *test_info);

/**
 * @brief	状態のクリア
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Clear(iuTestInfo* test_info);

/**
 * @brief	テストのフィルタリング
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Filter(iuTestInfo *test_info);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_info_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
