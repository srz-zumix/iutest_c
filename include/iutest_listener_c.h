/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_listener_c.h
 * @brief		iris unit test イベントリスナー 定義 ファイル
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
#ifndef INCG_IRIS_iutest_listener_C_H_B8604F9D_23F4_455e_B7EF_6D5E5D3EF9EC_
#define INCG_IRIS_iutest_listener_C_H_B8604F9D_23F4_455e_B7EF_6D5E5D3EF9EC_

/* include ===========================================================*/
#include "internal/iutest_pool_c.h"

IUTEST_EXTERN_C_BEGIN()

/* declare ===========================================================*/
struct iuUnitTest_t;
struct iuTestInfo_t;
struct iuTestCase_t;
struct iuTestPartResult_t;
struct iuTestProperty_t;

/* typedef ===========================================================*/
typedef void (*iuTestListener_OnTestProgramStart)(struct iuUnitTest_t *unit_test);
typedef void (*iuTestListener_OnTestIterationStart)(struct iuUnitTest_t *unit_test, int iteration);
typedef void (*iuTestListener_OnEnvironmentsSetUpStart)(struct iuUnitTest_t *unit_test);
typedef void (*iuTestListener_OnEnvironmentsSetUpEnd)(struct iuUnitTest_t *unit_test);
typedef void (*iuTestListener_OnTestCaseStart)(struct iuTestCase_t *test_case);
typedef void (*iuTestListener_OnTestStart)(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info);
typedef void (*iuTestListener_OnTestPartResult)(struct iuTestPartResult_t *test_part_result);
typedef void (*iuTestListener_OnTestRecordProperty)(struct iuTestProperty_t *test_property);
typedef void (*iuTestListener_OnTestEnd)(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info);
typedef void (*iuTestListener_OnTestCaseEnd)(struct iuTestCase_t *test_case);
typedef void (*iuTestListener_OnEnvironmentsTearDownStart)(struct iuUnitTest_t *unit_test);
typedef void (*iuTestListener_OnEnvironmentsTearDownEnd)(struct iuUnitTest_t *unit_test);
typedef void (*iuTestListener_OnTestIterationEnd)(struct iuUnitTest_t *unit_test, int iteration);
typedef void (*iuTestListener_OnTestProgramEnd)(struct iuUnitTest_t *unit_test);

/* struct ============================================================*/
/**
 * @brief	テストイベントリスナー構造体
*/
typedef struct iuTestListener_t
{
	iuTestListener_OnTestProgramStart			OnTestProgramStart;			/*!< テストプログラム開始時に呼ばれます */
	iuTestListener_OnTestIterationStart			OnTestIterationStart;		/*!< 単体テスト開始時に毎回呼ばれます */
	iuTestListener_OnEnvironmentsSetUpStart		OnEnvironmentsSetUpStart;	/*!< グローバル環境設定 SetUp 前に呼ばれます */
	iuTestListener_OnEnvironmentsSetUpEnd		OnEnvironmentsSetUpEnd;		/*!< グローバル環境設定 SetUp 後に呼ばれます */
	iuTestListener_OnTestCaseStart				OnTestCaseStart;			/*!< テストケース開始時に呼ばれます */
	iuTestListener_OnTestStart					OnTestStart;				/*!< テスト開始時に呼ばれます */
	iuTestListener_OnTestPartResult				OnTestPartResult;			/*!< テスト失敗時に呼ばれます */
	iuTestListener_OnTestRecordProperty			OnTestRecordProperty;		/*!< RecordProperty 時に呼ばれます */
	iuTestListener_OnTestEnd					OnTestEnd;					/*!< テストケース終了時にに呼ばれます */
	iuTestListener_OnTestCaseEnd				OnTestCaseEnd;				/*!< テスト終了時にに呼ばれます */
	iuTestListener_OnEnvironmentsTearDownStart	OnEnvironmentsTearDownStart;/*!< グローバル環境設定 TearDown 前に呼ばれます */
	iuTestListener_OnEnvironmentsTearDownEnd	OnEnvironmentsTearDownEnd;	/*!< グローバル環境設定 TearDown 後に呼ばれます */
	iuTestListener_OnTestIterationEnd			OnTestIterationEnd;			/*!< 単体テスト終了時に毎回呼ばれます */
	iuTestListener_OnTestProgramEnd				OnTestProgramEnd;			/*!< テストプログラム終了時に呼ばれます */
	struct iuTestListener_t *next;
} iuTestListener;

/* define ============================================================*/
/** @private */
#define iuTestListener_ctor()	{ NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	リスナーの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestListener* iuTestListener_MakeListener(iuTestListener* listener
										, iuTestListener_OnTestProgramStart OnTestProgramStart
										, iuTestListener_OnTestIterationStart OnTestIterationStart
										, iuTestListener_OnEnvironmentsSetUpStart OnEnvironmentsSetUpStart
										, iuTestListener_OnEnvironmentsSetUpEnd OnEnvironmentsSetUpEnd
										, iuTestListener_OnTestCaseStart OnTestCaseStart
										, iuTestListener_OnTestStart OnTestStart
										, iuTestListener_OnTestPartResult OnTestPartResult
										, iuTestListener_OnTestRecordProperty OnTestProperty
										, iuTestListener_OnTestEnd OnTestEnd
										, iuTestListener_OnTestCaseEnd OnTestCaseEnd
										, iuTestListener_OnEnvironmentsTearDownStart OnEnvironmentsTearDownStart
										, iuTestListener_OnEnvironmentsTearDownEnd OnEnvironmentsTearDownEnd
										, iuTestListener_OnTestIterationEnd OnTestIterationEnd
										, iuTestListener_OnTestProgramEnd OnTestProgramEnd
										);

/**
 * @brief	iuTestListener の作成
*/
iuTestListener*	iuTestListener_AllocListener(void);

/**
 * @brief	リスナーの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestListener* iuTestListener_NewListener(
	iuTestListener_OnTestProgramStart OnTestProgramStart
	, iuTestListener_OnTestIterationStart OnTestIterationStart
	, iuTestListener_OnEnvironmentsSetUpStart OnEnvironmentsSetUpStart
	, iuTestListener_OnEnvironmentsSetUpEnd OnEnvironmentsSetUpEnd
	, iuTestListener_OnTestCaseStart OnTestCaseStart
	, iuTestListener_OnTestStart OnTestStart
	, iuTestListener_OnTestPartResult OnTestPartResult
	, iuTestListener_OnTestRecordProperty OnTestProperty
	, iuTestListener_OnTestEnd OnTestEnd
	, iuTestListener_OnTestCaseEnd OnTestCaseEnd
	, iuTestListener_OnEnvironmentsTearDownStart OnEnvironmentsTearDownStart
	, iuTestListener_OnEnvironmentsTearDownEnd OnEnvironmentsTearDownEnd
	, iuTestListener_OnTestIterationEnd OnTestIterationEnd
	, iuTestListener_OnTestProgramEnd OnTestProgramEnd
	);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_listener_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
