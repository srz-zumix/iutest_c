/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_core_c.h
 * @brief		iris unit test core ファイル
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
#ifndef INCG_IRIS_iutest_core_c_H_5D8217F4_1A99_4dd8_A103_7DCBCA25ABAE_
#define INCG_IRIS_iutest_core_c_H_5D8217F4_1A99_4dd8_A103_7DCBCA25ABAE_

/* include ===========================================================*/
#include "iutest_case_c.h"
#include "internal/iutest_option_message_c.h"
#include "internal/iutest_internal_c.h"
#include "internal/iutest_params_util_c.h"

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
/**
 * @brief	テストフィクスチャの定義
*/
#define IUTEST_TEST_FIXTURE(name, setup_testcase, teardown_testcase, setup, teardown, user)		\
	static const iuTestFixture name { setup_testcase, teardown_testcase, setup, teardown, user }

/**
 * @private
 * @{
*/
/* コアインスタンス */
#define IIUT_C_UNITTEST_NAME	g_iutest_c_unittest_instance

#if IUTEST_C_HAS_PARAM_TEST
#  define IIUT_C_UNITTEST_DEF_INSTANCE()	\
	iuUnitTest	IIUT_C_UNITTEST_NAME = { NULL, NULL, 0, iuTestResult_ctor(), iuTestListener_ctor(), iuTestListener_ctor(), 0, NULL, NULL }
#else
#  define IIUT_C_UNITTEST_DEF_INSTANCE()	\
	iuUnitTest	IIUT_C_UNITTEST_NAME = { NULL, NULL, 0, iuTestResult_ctor(), iuTestListener_ctor(), iuTestListener_ctor(), 0 }
#endif

#if IUTEST_C_HAS_LIB
#  define IIUT_C_WORKSPACE()
#else
#  define IIUT_C_WORKSPACE()	IIUT_C_WORKSPACE_()
#endif

/* ワークスペースの生成 */
#define IIUT_C_WORKSPACE_()			\
	IIUT_C_UNITTEST_DEF_INSTANCE();	\
	iuTestEnv	IIUT_C_TESTENV_NAME = iuTestEnv_ctor()
/**
 * @}
*/


/* struct ============================================================*/
/**
 * @brief	テストコア構造体
*/
typedef struct iuUnitTest_t
{
	iuTestCase*			list;				/*!< TestCase リスト */
	iuTestInfo*			current_test_info;	/*!< 実行中の TestInfo */
	iuTimeInMillisec	elapsedmsec;		/*!< 実行時間 */
	iuTestResult		adhoc_testresult;	/*!< テスト実行中でないときのテスト結果 */
	iuTestListener		def_printer;		/*!< デフォルトPrinter */
	iuTestListener		def_xml_generator;	/*!< デフォルトXML出力 */
	int					initialized_count;	/*!< 初期化回数 */
#if IUTEST_C_HAS_PARAM_TEST
	iuTestCase*			paramtests;			/*!< Parameter Test 用 TestCase リスト */
	iuTestParamHolder*	param_holder;		/*!< パラメータホルダーリスト */
#endif
} iuUnitTest;

/**
 * @brief	テストフィクスチャ
*/
typedef struct iuTestFixture_t
{
	const iuTestSetUpTestCase		setup_testcase;
	const iuTestTearDownTestCase	teardown_testcase;
	const iuTestSetUp		setup;
	const iuTestTearDown	teardown;
	void*	user;
} iuTestFixture;

/* extern ============================================================*/
extern iuUnitTest	IIUT_C_UNITTEST_NAME;

/* declare ===========================================================*/
#if !IUTEST_C_HAS_LIB

static iuTestCase*	iuUnitTest_AddTestCase(const char* testcase_name
						, iuTestSetUpTestCase setup, iuTestTearDownTestCase teardown, iuTest_AllocTestCase pfnAlloc);
static iuTestCase*	iuUnitTest_FindTestCase(iuTestCase* list, const char* testcase_name);

#if IUTEST_C_HAS_PARAM_TEST
static void iuUnitTest_ParamHolderRegisterTest(void);
#endif

#endif

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	テスト管理インスタンスの取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuUnitTest* iuUnitTest_GetInstance(void);

#if IUTEST_C_HAS_STDARG
/**
 * @brief	vprintf 関数ポインタを設定
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_SetVPrintfFunction(iuVPrintf proc);
#endif

/**
 * @brief	TestListener の追加
*/
iuBOOL	iuUnitTest_AddTestListener(iuTestListener* test_listener);

/**
 * @brief	GlobalEnvironmentSetUp の追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuUnitTest_AddGlobalEnvironmentSetUp(iuGlobalEnvironmentSetUp func);

/**
 * @brief	GlobalEnvironmentTearDown の追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuUnitTest_AddGlobalEnvironmentTearDown(iuGlobalEnvironmentTearDown func);

/**
 * @biref	テストの初期化
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_Init(void);

/**
 * @biref	テストの実行
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_Run(void);

/**
 * @biref	テストケースの検索
*/
iuTestCase* iuUnitTest_FindTestCase(iuTestCase* list, const char* testcase_name);

/**
 * @brief	現在実行中の TestInfo 取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo* iuUnitTest_GetCurrentTestInfo(void);

/**
 * @brief	現在実行中の Test のユーザーデータ取得
*/
IUTEST_ATTRIBUTE_UNUSED_ void* iuUnitTest_GetCurrentUserData(void);

/**
 * @private
 * @brief	現在実行中の TestInfo の設定
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_SetCurrentTestInfo(struct iuTestInfo_t* curr);

/**
 * @brief	現在実行中のテストの TestResult 取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestResult* iuUnitTest_GetCurrentTestResult(void);

/**
 * @brief	乱数シードの取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuUnitTest_GetCurrentRandomSeed(void);

/**
 * @brief	テストケースの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTotalTestCaseCount(const iuUnitTest* unit_test);

/**
 * @brief	実行対象のテストケースの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTestCaseToRunCount(const iuUnitTest* unit_test);

/**
 * @brief	テストの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTotalTestCount(const iuUnitTest* unit_test);

/**
 * @brief	実行対象のテストの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTestToRunCount(const iuUnitTest* unit_test);

/**
 * @brief	成功テストの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetSuccessfulTestCount(const iuUnitTest* unit_test);

/**
 * @brief	失敗テストの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetFailureTestCount(const iuUnitTest* unit_test);

/**
 * @brief	無効テストの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetDisableTestCount(const iuUnitTest* unit_test);

/**
 * @brief	スキップしたテストの総数取得
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetSkippedTestCount(const iuUnitTest* unit_test);

/**
 * @brief	テスト結果の取得
*/
iuBOOL iuUnitTest_IsFaild(const iuUnitTest* unit_test);

/**
 * @brief	テスト結果の取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuUnitTest_Passed(const iuUnitTest* unit_test);

/**
 * @brief	乱数シードの取得
*/
IUTEST_ATTRIBUTE_UNUSED_ unsigned int iuUnitTest_GetRandomSeed(void);

/**
 * @brief	テストのリスト出力
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowTestList(const iuUnitTest* unit_test);

/**
 * @biref	テストケースの追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestCase*	iuUnitTest_AddTestCase(const char* testcase_name
															   , iuTestSetUpTestCase setup
															   , iuTestTearDownTestCase teardown
															   , iuTest_AllocTestCase pfnAlloc);


#if IUTEST_C_HAS_PARAM_TEST

/**
 * @biref	パラメータテスト登録用テストケースの追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestCase*	iuUnitTest_AddParameterizedTestCase(const char* testcase_name
															   , iuTestSetUpTestCase setup
															   , iuTestTearDownTestCase teardown
															   , iuTest_AllocTestCase pfnAlloc);


IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_AddTestParamHolder(iuTestParamHolder* holder);

IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_ParamHolderRegisterTest(void);

#endif

#if IUTEST_C_HAS_MALLOC

IUTEST_ATTRIBUTE_UNUSED_ iuTestCase* iuUnitTest_AllocTestCase(void);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_core_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
