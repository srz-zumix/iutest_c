/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_internal_c.h
 * @brief		iris unit test info
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_INTERNAL_C_H_A3DF31D4_5FC6_4C62_BCF6_EF835E47B10A_
#define INCG_IRIS_IUTEST_INTERNAL_C_H_A3DF31D4_5FC6_4C62_BCF6_EF835E47B10A_

/* include ===========================================================*/
#include "../iutest_pred_c.h"

/* define ============================================================*/
/**
 * @private
 * @{
*/
#define IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_)	iutest_c_test_body_##testcase_##_##testname_##_
#define IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_)	s_iutest_c_test_info_##testcase_##_##testname_##_
#define IIUT_C_TEST_INITIALIZATION_SECTION_NAME(testcase_, testname_)	iutest_c_test_register_dummy_##testcase_##_##testname_

/* テストの定義 */
#define IIUT_C_TEST_(testcase_, testname_)							\
	IIUT_C_TEST_ADD_(testcase_, testname_, NULL, NULL, NULL, NULL, NULL)

/* テストフィクスチャの定義 */
#define IIUT_C_TEST_F_(testfix_, testname_)							\
	IIUT_C_TEST_ADD_(testfix_, testname_, testfix_.setup_testcase	\
	, testfix_.teardown_testcase, testfix_.setup, testfix_.teardown, testfix_.user)

#if IUTEST_C_HAS_MALLOC

#define IIUT_C_TEST_ADD_(testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_)	\
	IIUT_C_TEST_ADD_I_(testcase_, testname_, setup_testcase_, teardown_testcase_		\
	, setup_, teardown_, user_, iuUnitTest_AllocTestCase)

#else

#define IIUT_C_TEST_ADD_(testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_)		\
	IUTEST_TEST_SECTION_ static iuTestCase * IUTEST_PP_CAT(iutest_c_alloc_##testcase_##_dummy_, __LINE__)(void) {	\
	static iuTestCase instance; return &instance; }												\
	IIUT_C_TEST_ADD_I_(testcase_, testname_, setup_testcase_, teardown_testcase_				\
	, setup_, teardown_, user_, IUTEST_PP_CAT(iutest_c_alloc_##testcase_##_dummy_, __LINE__))

#endif

#define IIUT_C_TEST_ADD_I_(testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_, allocator_)	\
	void IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_)(void);														\
	IUTEST_DATA_SECTION_ static iuTestInfo IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_) = 							\
	iuTestInfo_ctor(#testname_, IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_) );										\
	IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN( IIUT_C_TEST_INITIALIZATION_SECTION_NAME(testcase_, testname_) )			\
	iuTestCase_AddTestInfo(iuUnitTest_AddTestCase(#testcase_, setup_testcase_, teardown_testcase_, allocator_),			\
	& IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_) );																\
	iuTest_Init( &IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_).test, setup_, teardown_, user_);						\
	IUTEST_C_DECL_INITIALIZATION_SECTION_END()																			\
	IUTEST_TEST_SECTION_ void IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_)(void)

#if IUTEST_C_HAS_PARAM_METHOD_TEST

/* パラメタライズテストの定義 */
#define IIUT_C_TEST_PMZ_(testcase_, testname_, method_, ...)		\
	IIUT_C_TEST_PMZ_ADD_(testcase_, testname_, NULL, NULL, NULL, NULL, NULL, method_, __VA_ARGS__)

/* パラメタライズテスト テストフィクスチャの定義 */
#define IIUT_C_TEST_PMZ_F_(testfix_, testname_, method_, ...)			\
	IIUT_C_TEST_PMZ_ADD_(testfix_, testname_, testfix_.setup_testcase	\
	, testfix_.teardown_testcase, testfix_.setup, testfix_.teardown, testfix_.user, method_, __VA_ARGS__)

#if IUTEST_C_HAS_MALLOC

#define IIUT_C_TEST_PMZ_ADD_(testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_, method_, ...)	\
	IIUT_C_TEST_PMZ_ADD_I_(testcase_, testname_, setup_testcase_, teardown_testcase_		\
	, setup_, teardown_, user_, iuUnitTest_AllocTestCase, method_, __VA_ARGS__)

#else

#define IIUT_C_TEST_PMZ_ADD_(testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_, method_, ...)	\
	IUTEST_TEST_SECTION_ static iuTestCase * IUTEST_PP_CAT(iutest_c_alloc_testcase_dummy_, __LINE__)(void) {	\
	static iuTestCase instance; return &instance; }																\
	IIUT_C_TEST_PMZ_ADD_I_(testcase_, testname_, setup_testcase_, teardown_testcase_							\
	, setup_, teardown_, user_, IUTEST_PP_CAT(iutest_c_alloc_testcase_dummy_, __LINE__), method_, __VA_ARGS__)

#endif

#define IIUTE_C_TEST_PMZ_BODY_DECL_NAME(testcase_, testname_)	IUTEST_PP_CAT(iutest_c_test_body_##testcase_##_##testname_##_, __LINE__)
#define IIUTE_C_TEST_PMZ_INFO_DECL_NAME(testcase_, testname_)	IUTEST_PP_CAT(s_iutest_c_test_info_##testcase_##_##testname_##_, __LINE__)

#define IIUT_C_TEST_PMZ_ADD_I_(testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_, allocator_, method_, ...)	\
	IUTEST_TEST_SECTION_ void IIUTE_C_TEST_PMZ_BODY_DECL_NAME(testcase_, testname_)(void) { method_(__VA_ARGS__); }						\
	IUTEST_DATA_SECTION_ static iuTestInfo IIUTE_C_TEST_PMZ_INFO_DECL_NAME(testcase_, testname_) = 															\
	iuTestInfo_ctor(#testname_, IIUTE_C_TEST_PMZ_BODY_DECL_NAME(testcase_, testname_) );												\
	IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN( IUTEST_PP_CAT(iutest_c_test_register_dummy_##testcase_##_##testname_, __LINE__) )		\
	iuTestCase_AddTestInfo(iuUnitTest_AddTestCase(#testcase_, setup_testcase_, teardown_testcase_, allocator_),							\
	& IIUTE_C_TEST_PMZ_INFO_DECL_NAME(testcase_, testname_) );																			\
	iuTest_Init(&IIUTE_C_TEST_PMZ_INFO_DECL_NAME(testcase_, testname_).test, setup_, teardown_, user_);									\
	IUTEST_C_DECL_INITIALIZATION_SECTION_END()																							\

#endif

/**
 * @}
*/

/**
 * @brief	ASSERT
*/
#define IUTEST_ASSERT(cond)	do {	\
	if( !(cond) ) {					\
		IUTEST_MESSAGE(#cond, kTestResultFatalFailure);	\
		iuExit(1);					\
	} } while(iuAlwaysZero())

/**
 * @internal
 * @brief	ASSERTION メッセージ処理
*/
#define IUTEST_MESSAGE_AT(file_, line_, msg_, result_type_)	iuAssertionHelper_Report(file_, line_, msg_, result_type_)
#define IUTEST_MESSAGE(msg_, result_type_)					IUTEST_MESSAGE_AT(__FILE__, __LINE__, msg_, result_type_)

/**
 * @internal
 * @brief	ASSERT メッセージ処理
*/
#define IUTEST_ASSERT_FAILURE(msg)					IUTEST_ASSERT_FAILURE_AT(msg, __FILE__, __LINE__)

#define IUTEST_ASSERT_FAILURE_AT(msg, file, line)	if( !IUTEST_MESSAGE_AT(file, line, msg, kTestResultFatalFailure) ) return

/**
 * @internal
 * @brief	EXPECT メッセージ処理
*/
#define IUTEST_EXPECT_FAILURE(msg)					IUTEST_EXPECT_FAILURE_AT(msg, __FILE__, __LINE__)

#define IUTEST_EXPECT_FAILURE_AT(msg, file, line)	IUTEST_MESSAGE_AT(file, line, msg, kTestResultNonFatalFailure)

/**
 * @internal
 * @brief	INFORM メッセージ処理
*/
#define IUTEST_INFORM_FAILURE(msg)					IUTEST_INFORM_FAILURE_AT(msg, __FILE__, __LINE__)

#define IUTEST_INFORM_FAILURE_AT(msg, file, line)	IUTEST_MESSAGE_AT(file, line, msg, kTestResultWarning)

/**
 * @internal
 * @brief	ASSUME メッセージ処理
*/
#define IUTEST_ASSUME_FAILURE(msg)					IUTEST_ASSUME_FAILURE_AT(msg, __FILE__, __LINE__)

#define IUTEST_ASSUME_FAILURE_AT(msg, file, line)	if( !IUTEST_MESSAGE_AT(file, line, msg, kTestResultAssume) ) return

/**
* @internal
* @brief	SKIP メッセージ処理
*/
#define IUTEST_SKIP_MESSAGE(msg)					IUTEST_SKIP_MESSAGE_AT(msg, __FILE__, __LINE__)

#define IUTEST_SKIP_MESSAGE_AT(msg, file, line)		if( !IUTEST_MESSAGE_AT(file, line, msg, kTestResultSkip) ) return


/**
 * @internal
 * @biref	比較検証マクロ
*/
#define IUTEST_TEST_ASSERT_(expression, on_failure)	do {	\
	iuAssertionResult temp_ar_; temp_ar_ = (expression);	\
	if( !temp_ar_.result )									\
		on_failure(temp_ar_.message);						\
	} while(iuAlwaysZero())

/**
 * @internal
 * @biref	BOOL 比較検証マクロ
*/
#define IUTEST_TEST_BOOLEAN_(expression, text, actual, expected, on_failure)	\
	IUTEST_AMBIGUOUS_ELSE_BLOCKER_												\
	if( expression )															\
		;																		\
	else																		\
		on_failure(iuTestAssertion_GetBooleanAssertionFailureMessage(			\
			text, #actual, #expected) )


#define IIUT_SUCCEED()						IUTEST_MESSAGE("Succeeded.\n", kTestResultSuccess)
#define IIUT_FAIL()							IUTEST_ASSERT_FAILURE("Failed.\n")
#define IIUT_ADD_FAILURE()					IUTEST_EXPECT_FAILURE("Failed.\n")
#define IIUT_ADD_FAILURE_AT(file_, line_)	IUTEST_EXPECT_FAILURE_AT("Failed.\n", file_, line_)


/**
 * @internal
 * @brief	テストマクロ
 * @{
*/
#define	IUTEST_TEST_EQ(v1, v2, on_failure)				IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperEQ, v1, v2, on_failure )
#define	IUTEST_TEST_LVALUE_EQ(v1, v2, on_failure)		IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperLValueEQ, v1, v2, on_failure )
#define	IUTEST_TEST_RVALUE_EQ(v1, v2, on_failure)		IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperRValueEQ, v1, v2, on_failure )
#define	IUTEST_TEST_NE(v1, v2, on_failure)				IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperNE, v1, v2, on_failure )
#define	IUTEST_TEST_LE(v1, v2, on_failure)				IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperLE, v1, v2, on_failure )
#define	IUTEST_TEST_LT(v1, v2, on_failure)				IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperLT, v1, v2, on_failure )
#define	IUTEST_TEST_GE(v1, v2, on_failure)				IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperGE, v1, v2, on_failure )
#define	IUTEST_TEST_GT(v1, v2, on_failure)				IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperGT, v1, v2, on_failure )

#define IUTEST_TEST_TRUE(v, on_failure)					IUTEST_PRED_FORMAT1_( iuTestAssertion_CompHelperTRUE , v, on_failure)
#define IUTEST_TEST_FALSE(v, on_failure)				IUTEST_PRED_FORMAT1_( iuTestAssertion_CompHelperFALSE, v, on_failure)

#if IUTEST_C_HAS_FLOATINGPOINT

#define IUTEST_TEST_FLOAT_EQ(v1, v2, on_failure)		IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperFloatEQ , v1, v2, on_failure )
#define IUTEST_TEST_DOUBLE_EQ(v1, v2, on_failure)		IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperDoubleEQ, v1, v2, on_failure )

#define IUTEST_TEST_NEAR(v1, v2, abs_v, on_failure)		IUTEST_PRED_FORMAT3_( iuTestAssertion_CompHelperNear, v1, v2, abs_v, on_failure )

#endif

#define	IUTEST_TEST_STREQ(v1, v2, on_failure)			IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperSTREQ, v1, v2, on_failure )
#define	IUTEST_TEST_STRNE(v1, v2, on_failure)			IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperSTRNE, v1, v2, on_failure )
#define	IUTEST_TEST_STRCASEEQ(v1, v2, on_failure)		IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperSTRCASEEQ, v1, v2, on_failure )
#define	IUTEST_TEST_STRCASENE(v1, v2, on_failure)		IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperSTRCASENE, v1, v2, on_failure )

#if defined(IUTEST_OS_WINDOWS)

#define IUTEST_TEST_HRESULT_SUCCEEDED(hr, on_failure)	IUTEST_PRED_FORMAT1_( iuTestAssertion_IsHRESULTSuccess, hr, on_failure )
#define IUTEST_TEST_HRESULT_FAILED(hr, on_failure)		IUTEST_PRED_FORMAT1_( iuTestAssertion_IsHRESULTFailure, hr, on_failure )

#endif

#define IUTEST_TEST_NULL(v, on_failure)					IUTEST_PRED_FORMAT1_( iuTestAssertion_CompHelperNull, v, on_failure )
#define IUTEST_TEST_NOTNULL(v, on_failure)				IUTEST_PRED_FORMAT1_( iuTestAssertion_CompHelperNotNull, v, on_failure )

#define IUTEST_TEST_SAME(v1, v2, on_failure)			IUTEST_PRED_FORMAT2_( iuTestAssertion_CompHelperSame, v1, v2, on_failure )

#define IUTEST_TEST_NO_FATAL_FAILURE_(statement, on_failure)					\
	if( iuAlwaysTrue() ) {														\
		iuTestResult temp_result;												\
		iuTestEnv* env = iuTestEnv_GetInstance();								\
		iuTestCommitTestPartResult pfnPrev = env->commit_result.func;			\
		env->commit_result.func = iuTest_DummyCommitResult;						\
		iuTestResult_Clear(&temp_result);										\
		iuUnitTest_GetInstance()->temp_result = &temp_result;					\
		IUTEST_SUPPRESS_UNREACHABLE_CODE_WARNING( { (void)0; statement; } );	\
		env->commit_result.func = pfnPrev;										\
		iuUnitTest_GetInstance()->temp_result = NULL;							\
		if( pfnPrev == NULL ) iuTest_CommitResults(&temp_result);				\
		if( 0 < iuTestResult_GetPartCount(&temp_result, kTestResultFatalFailure) ) {	\
			goto IUTEST_PP_CAT(iutest_label_test_no_fatalfailure_, __LINE__);	\
		}																		\
	} else																		\
		IUTEST_PP_CAT(iutest_label_test_no_fatalfailure_, __LINE__):			\
		on_failure("\nExpected: " #statement " doesn't generate new fatal failure.\n  Actual: it does.")

#define IUTEST_TEST_NO_FAILURE_(statement, on_failure)							\
	if( iuAlwaysTrue() ) {														\
		iuTestResult temp_result;												\
		iuTestEnv* env = iuTestEnv_GetInstance();								\
		iuTestCommitTestPartResult pfnPrev = env->commit_result.func;			\
		env->commit_result.func = iuTest_DummyCommitResult;						\
		iuTestResult_Clear(&temp_result);										\
		iuUnitTest_GetInstance()->temp_result = &temp_result;					\
		IUTEST_SUPPRESS_UNREACHABLE_CODE_WARNING( { (void)0; statement; } );	\
		env->commit_result.func = pfnPrev;										\
		iuUnitTest_GetInstance()->temp_result = NULL;							\
		if( pfnPrev == NULL ) iuTest_CommitResults(&temp_result);				\
		if( 0 < iuTestResult_FailurePartCount(&temp_result) ) {					\
			goto IUTEST_PP_CAT(iutest_label_test_no_failure_, __LINE__);		\
		}																		\
	} else																		\
		IUTEST_PP_CAT(iutest_label_test_no_failure_, __LINE__):					\
		on_failure("\nExpected: " #statement " doesn't generate new fatal failure.\n  Actual: it does.")


#define IUTEST_TEST_SKIP()				\
	IUTEST_SKIP_MESSAGE(iuTestResult_IsFailed(iuUnitTest_GetCurrentTestResult()) ? "Skipped. but already failed. " : "Skipped. ")

/**
 * @}
*/

#endif
