/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_env_c.h
 * @brief		iris unit test 環境 ファイル
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
#ifndef INCG_IRIS_iutest_env_C_H_DC5C5193_7081_4fef_B668_283CAEFA1F77_
#define INCG_IRIS_iutest_env_C_H_DC5C5193_7081_4fef_B668_283CAEFA1F77_

/* include ===========================================================*/
#include "iutest_listener_c.h"
#include "internal/iutest_random_c.h"
#include "internal/iutest_string_c.h"

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
/**
 * @private
 * @{
*/
#define IIUT_C_TESTENV_NAME		g_iutest_c_testenv_instance
#define IIUT_C_TESTENV()		IIUT_C_TESTENV_NAME
/**
 * @}
*/

#define IUTEST_FLAG(name)		IIUT_C_TESTENV().option.name

/* enum ==============================================================*/
typedef enum IUTESTENV_FLAG
{
	IUTESTENV_FILTERING_TESTS		= 0x0004,	/*!< フィルタリング */
	IUTESTENV_CONSOLECOLOR_ON		= 0x0010,	/*!< 色つき出力ON */
	IUTESTENV_CONSOLECOLOR_OFF		= 0x0020,	/*!< 色つき出力OFF */
	IUTESTENV_CONSOLECOLOR_ANSI		= 0x0040,	/*!< エスケープシーケンスで出力 */
	IUTESTENV_OUTPUT_XML_REPORT		= 0x0100,	/*!< xml 出力 */
	IUTESTENV_SHOWHELP_AND_SORRY	= 0x0400,	/*!< ヘルプを出力 */
	IUTESTENV_SHOWHELP				= 0x0800,	/*!< ヘルプを出力 */
	IUTESTENV_SHOWVER				= 0x1000,	/*!< バージョン出力 */
	IUTESTENV_SHOWTESTSLIST			= 0x2000,	/*!< テストリスト出力 */
	IUTESTENV_SHOWFEATURE			= 0x4000,	/*!< 機能情報出力 */

	IUTESTENV_FLAG_DEFAULT			= 0
} IUTESTENV_FLAG;

/* declare ===========================================================*/
struct iuTestPartResult_t;

/* typedef ===========================================================*/
#if IUTEST_C_HAS_STDARG
typedef int (*iuVPrintf)(const char* fmt, va_list va);
#endif
typedef void (*iuGlobalEnvironmentSetUp)(void);
typedef void (*iuGlobalEnvironmentTearDown)(void);
typedef iuBOOL (*iuTestCommitTestPartResult)(struct iuTestPartResult_t* part_result, void* user);

/* struct ============================================================*/
/**
 * @brief	グローバル環境 SetUp 構造体
*/
typedef struct iuTestGlobalEnvSetUp_t
{
	iuGlobalEnvironmentSetUp		func;	/*!< SetUp 関数 */
	struct iuTestGlobalEnvSetUp_t*	next;	/*!< 次の構造体 */
} iuTestGlobalEnvSetUp;

/**
 * @brief	グローバル環境 TearDown 構造体
*/
typedef struct iuTestGlobalEnvTearDown_t
{
	iuGlobalEnvironmentTearDown			func;	/*!< TearDown 関数 */
	struct iuTestGlobalEnvTearDown_t*	next;	/*!< 次の構造体 */
} iuTestGlobalEnvTearDown;

/**
 * @brief	結果の登録コールバック関数情報
*/
typedef struct iuTestCommitPartResultInfo_t
{
	iuTestCommitTestPartResult func;
	void* user;
} iuTestCommitPartResultInfo;

/**
 * @brief	テスト環境構造体
*/
typedef struct iuTestEnv_t
{
	iuTestListener*	listeners;		/*!< リスナーリスト */
	iuTestGlobalEnvSetUp*		env_setup;		/*!< グローバル環境 SetUp リスト */
	iuTestGlobalEnvTearDown*	env_teardown;	/*!< グローバル環境 TearDown リスト */
#if IUTEST_C_HAS_STDARG
	iuVPrintf		pfnvpritf;		/*!< vprintf 関数ポインタ */
#endif
	iuUInt32		flag;			/*!< フラグ */
	iuUInt32		current_seed;	/*!< 乱数シードの現在値 */
	iuRandomContext	random_context;	/*!< 乱数コンテキスト */
	iuTestCommitPartResultInfo	commit_result;	/*!< テスト結果の登録コールバック関数 */

	/* オプション */
	struct {
		const char*		filter;			/*!< テストフィルタリング文字列 */
		const char*		output;			/*!< 出力文字列 */
		int				repeat;			/*!< リピートカウント */
		iuUInt32		random_seed;	/*!< 乱数シードの設定値 */
		iuBOOL			shuffle;		/*!< シャッフルテスト */
		iuBOOL			print_time;		/*!< 経過時間の出力 */
		iuBOOL			break_on_failure;			/*!< テスト失敗時にブレーク */
		iuBOOL			also_run_disabled_tests;	/*!< DISABLED テストも実行 */
	} option;
} iuTestEnv;

/* define ============================================================*/
/**
 * @private
 * @{
*/
#define iuTestEnvOption_ctor()	{ NULL, NULL, 1, 0, FALSE, TRUE, FALSE, FALSE }
#if IUTEST_C_HAS_STDARG
#define iuTestEnv_ctor()	{ NULL, NULL, NULL, NULL, IUTESTENV_FLAG_DEFAULT, 0		\
								, iuRandomContext_ctor(), { NULL, NULL }, iuTestEnvOption_ctor() }
#else
#define iuTestEnv_ctor()	{ NULL, NULL, NULL, IUTESTENV_FLAG_DEFAULT, 0		\
								, iuRandomContext_ctor(), { NULL, NULL }, iuTestEnvOption_ctor() }
#endif
/**
 * @}
*/

/* extern ============================================================*/
extern iuTestEnv	IIUT_C_TESTENV_NAME;

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	テスト環境インスタンスの取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestEnv* iuTestEnv_GetInstance(void);

#if IUTEST_C_HAS_STDARG
/**
 * @brief	vprintf 関数ポインタを設定
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_SetVPrintfFunction(iuTestEnv* test_env, iuVPrintf proc);

#endif

/**
 * @brief	TestListener の追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestEnv_AddTestListener(iuTestEnv* test_env, iuTestListener* test_listener);

/**
 * @brief	TestListener の削除
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestEnv_SubTestListener(iuTestEnv* test_env, iuTestListener* test_listener);

/**
 * @brief	GlobalEnvironmentSetUp の追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_AddGlobalEnvironmentSetUp(iuTestEnv* test_env, iuGlobalEnvironmentSetUp func);

/**
 * @brief	GlobalEnvironmentTearDown の追加
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_AddGlobalEnvironmentTearDown(iuTestEnv* test_env, iuGlobalEnvironmentTearDown func);

/**
 * @brief	GlobalEnvironmentSetUp の実行
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_GlobalEnvironmentSetUp(void);

/**
 * @brief	GlobalEnvironmentTearDown の実行
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_GlobalEnvironmentTearDown(void);

/**
 * @brief	OnTestProgramStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestProgramStart(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnTestIterationStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestIterationStart(struct iuUnitTest_t* unit_test, int iteration);

/**
 * @brief	OnEnvironmentsSetUpStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsSetUpStart(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnEnvironmentsSetUpEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsSetUpEnd(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnTestCaseStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestCaseStart(struct iuTestCase_t* test_case);

/**
 * @brief	OnTestStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestStart(struct iuTestCase_t* test_case, struct iuTestInfo_t* test_info);

/**
 * @brief	OnTestPartResult
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestPartResult(struct iuTestPartResult_t* test_part_result);

/**
 * @brief	OnTestRecordProperty
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestRecordProperty(struct iuTestProperty_t* test_property);

/**
 * @brief	OnTestEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestEnd(struct iuTestCase_t* test_case, struct iuTestInfo_t* test_info);

/**
 * @brief	OnTestCaseEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void IUTEST_ATTRIBUTE_UNUSED_ iuTestEnv_ListenerEvent_OnTestCaseEnd(struct iuTestCase_t* test_case);

/**
 * @brief	OnEnvironmentsTearDownStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsTearDownStart(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnEnvironmentsTearDownEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsTearDownEnd(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnTestIterationEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestIterationEnd(struct iuUnitTest_t* unit_test, int iteration);

/**
 * @brief	OnTestProgramEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestProgramEnd(struct iuUnitTest_t* unit_test);

/**
 * @brief	テスト環境のセットアップ
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_SetUp(iuTestEnv* test_env);

/**
 * @brief	DISABLED テストも実行するかどうか
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableRunDisabledTests(void);

/**
 * @brief	シャッフルテストかどうか
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableShuffleTests(void);

/**
 * @brief	テスト失敗時に BREAK するかどうか
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableBreakOnFailure(void);

/**
 * @brief	時間出力するかどうか
*/
iuBOOL iuTestEnv_IsEnablePrintTime(void);

/**
 * @biref	xml 出力するかどうか
*/
iuBOOL iuTestEnv_IsEnableOutputXml(void);

/**
 * @brief	テストフラグが有効かどうか
*/
iuBOOL iuTestEnv_IsEnableFlag(int mask);

/**
 * @brief	乱数シードの取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuTestEnve_GetCurrentRandomSeed(void);

#if IUTEST_C_HAS_COMMANDLINE_OPTION
/**
 * @brief	コマンドライン引数の解析
*/
IUTEST_C_INL_INLINE void iuTestEnv_ParseCommandLineA(int* pargc, char** argv);

#if IUTEST_C_HAS_WCHAR_T
/**
 * @brief	コマンドライン引数の解析
*/
IUTEST_C_INL_INLINE void iuTestEnv_ParseCommandLineW(int* pargc, wchar_t** argv);
#endif

#endif

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION

/**
 * @brief	環境変数の読み取り
*/
void iuTestEnv_LoadEnviromentVariable(void);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_env_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
