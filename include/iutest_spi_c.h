/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_spi_c.h
 * @brief		iris unit test spi ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_spi_C_H_31A295B7_1BFC_429D_84F2_FC76F7FB647F_
#define INCG_IRIS_iutest_spi_C_H_31A295B7_1BFC_429D_84F2_FC76F7FB647F_

/* include ===========================================================*/
#include "iutest_c.h"

/* define ============================================================*/
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	Fatal Failure 発生確認テスト
*/
#define IUTEST_ASSERT_FATAL_FAILURE(statement, substr)		IUTEST_TEST_FATAL_FAILURE_(statement, #statement, substr, IUTEST_ASSERT_FAILURE)

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	Non Fatal Failure 発生確認テスト
*/
#define IUTEST_ASSERT_NONFATAL_FAILURE(statement, substr)	IUTEST_TEST_NONFATAL_FAILURE_(statement, #statement, substr, IUTEST_ASSERT_FAILURE)

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	Fatal Failure 発生確認テスト
*/
#define IUTEST_EXPECT_FATAL_FAILURE(statement, substr)		IUTEST_TEST_FATAL_FAILURE_(statement, #statement, substr, IUTEST_EXPECT_FAILURE)

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	Non Fatal Failure 発生確認テスト
*/
#define IUTEST_EXPECT_NONFATAL_FAILURE(statement, substr)	IUTEST_TEST_NONFATAL_FAILURE_(statement, #statement, substr, IUTEST_EXPECT_FAILURE)


#define IIUT_PUSH_COMMITRESULT_FUNC(env)					\
	iuTestCommitTestPartResult pfnPrev = env->commit_result.func;	\
	void* pUserPrev = env->commit_result.user

#define IIUT_POP_COMMITRESULT_FUNC(env)						\
	env->commit_result.func = pfnPrev;	\
	env->commit_result.user = pUserPrev

#define IUTEST_TEST_FATAL_FAILURE_(statement, text, substr, on_failure)			\
	IIUT_TEST_CHECK_FAILURE_(statement, text, substr, on_failure, kTestResultFatalFailure, "1 fatal failure")

#define IUTEST_TEST_NONFATAL_FAILURE_(statement, text, substr, on_failure)		\
	IIUT_TEST_CHECK_FAILURE_(statement, text, substr, on_failure, kTestResultNonFatalFailure, "1 non-fatal failure")

#define IIUT_TEST_CHECK_FAILURE_(statement, text, substr, on_failure, expected_type, expected_str)	\
	do {																		\
		iuTestEnv* env = iuTestEnv_GetInstance();								\
		static iuTestSpiCheckResult result ={ 0, kTestResultSuccess, NULL };	\
		IIUT_PUSH_COMMITRESULT_FUNC(env);										\
		result.num = 0; result.type = kTestResultSuccess; result.msg = NULL;	\
		env->commit_result.func = iuTestSpiFailureCheck_OnCommitTestPartResult;	\
		env->commit_result.user = (void*)&result;								\
		statement;																\
		IIUT_POP_COMMITRESULT_FUNC(env);										\
		if( result.num != 1 ) {													\
			on_failure(iuTestSpi_CountFailureMessage("error: Expected: "		\
				expected_str "\"\n  Actual: ", result.num, "\n"));				\
		}																		\
		if( result.type != expected_type ) {									\
			on_failure("error: Expected: " expected_str "\n  Actual: different type.\n");	\
		}																		\
		if( iu_strstr(result.msg, substr) == NULL ) {							\
			on_failure(iuTestSpi_SubstrFailureMessage( "error: Expected: "		\
				expected_str " containing \"" substr "\"\n  Actual: ", result.msg, "\n") );	\
		}																		\
	} while(iuAlwaysZero())

/* struct ============================================================*/
typedef struct iuTestSpiCheckResult_t
{
	int num;
	eTestResultType type;
	const char* msg;
} iuTestSpiCheckResult;

/* function ==========================================================*/

/**
 * @brief	失敗の回数チェック
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestSpiFailureCheck_OnCommitTestPartResult(iuTestPartResult* part_result, void* user)
{
	iuTestSpiCheckResult* result = (iuTestSpiCheckResult*)user;
	++result->num;
	result->type = part_result->type;
	result->msg = part_result->message;
	return TRUE;
}

/**
 * @brief	失敗メッセージの作成
*/
static IUTEST_ATTRIBUTE_UNUSED_ const char* iuTestSpi_CountFailureMessage(const char* msg1, int num, const char* msg2)
{
	const size_t length1 = iu_strlen(msg1);
	const size_t length2 = iu_strlen(msg2);
	char* p = iuTest_AllocTestFailureMessageString(length1+length2+32);
	if(p == NULL) return NULL;

	iu_strcpy(p, msg1);
	iu_itoa(num, p+length1, 10);
	iu_strcat(p, msg2);
	return p;
}

/**
 * @brief	失敗メッセージの作成
*/
static IUTEST_ATTRIBUTE_UNUSED_ const char* iuTestSpi_SubstrFailureMessage(const char* msg1, const char* actual, const char* msg2)
{
	const size_t length = iu_strlen(msg1) + iu_strlen(msg2) + iu_strlen(actual) + 4;
	char* p = iuTest_AllocTestFailureMessageString(length);
	if(p == NULL) return NULL;

	iu_strcpy(p, msg1);
	iu_strcat(p, actual);
	iu_strcat(p, msg2);
	return p;
}


#endif
