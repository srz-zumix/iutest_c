/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_assertion_c.h
 * @brief		iris unit test assertion 定義
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_ASSERTION_C_H_E6AF3476_DA81_46F7_A961_ACCEF7363932_
#define INCG_IRIS_IUTEST_ASSERTION_C_H_E6AF3476_DA81_46F7_A961_ACCEF7363932_

/* include ===========================================================*/
#include "iutest_info_c.h"
#include "iutest_printer_c.h"

IUTEST_EXTERN_C_BEGIN()

/* struct ============================================================*/
/**
 * @brief	テストの結果
*/
typedef struct iuAssertionResult_t
{
	iuBOOL		result;		/*!< 成否 */
	const char*	message;	/*!< メッセージ */
	char*		buf;		/*!< バッファ */
} iuAssertionResult;

/* define ============================================================*/
/** @private */
#define iuAssertionResult_ctor(b)	{ b, NULL, NULL }

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	成功を示す AssertionResult の取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionSuccess(void);
/**
 * @brief	失敗を示す AssertionResult の取得
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailure(void);

/**
 * @brief	メッセージ報告関数
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuAssertionHelper_Report(const char* file, int line, const char* message, eTestResultType type);

/**
 * @brief	メッセージの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessage(const char* message);

/**
* @brief	メッセージの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessage2(const char* message, const char* append);

/**
 * @brief	メッセージの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessageComp(const char* message
													, const void* val1, size_t size1, const char* msg1
													, const void* val2, size_t size2, const char* msg2);

/**
 * @brief	メッセージの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionStringFailureMessage(const char* message, const char* val1, const char* msg1
																				  , const char* val2, const char* msg2);

#if IUTEST_C_HAS_LIBC && IUTEST_C_HAS_STDARG && !defined(__STRICT_ANSI__)

/**
 * @brief	メッセージの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureFormatMessageV(const char* fmt, va_list va);

/**
 * @brief	メッセージの作成
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureFormatMessage(const char* fmt, ...);

#endif

#endif

/**
 * @brief	BOOL 比較テストの失敗メッセージの作成
*/
#define iuTestAssertion_GetBooleanAssertionFailureMessage(expression, actual, expected)	\
	"error: Value of: " expression "\n   Actual: " #actual "\n Expected: " #expected

/**
 * @biref	比較テスト
 * @{
*/

/**
 * @private
 * @{
*/
/* actual に rvalue を使用できなくなる */
#define iuTestAssertion_EqFailureMessageShowActual(expected_str, actual_str, expected, actual)	\
	iuAssertionFailureMessageComp("error: Value of : " actual_str "\n  Actual: "				\
	, &actual, sizeof(actual), "\nExpected: " expected_str , NULL, 0u, NULL)

/* どちらも rvalue を使用できなくなる */
#define iuTestAssertion_EqFailureMessageShowWhichIs(expected_str, actual_str, expected, actual)	\
	iuAssertionFailureMessageComp("error: Value of : " actual_str "\n  Actual: "				\
	, &actual, sizeof(actual), "\nExpected: " expected_str "\nWhich is: ", &expected, sizeof(expected), NULL)

/* どちらも rvalue を使用できるが、式しか表示されない */
#define iuTestAssertion_EqFailureMessageShowOnlyExpr(expected_str, actual_str, expected, actual)	\
	iuAssertionFailureMessage("error: Expected: " expected_str " == " actual_str)

#if IUTEST_C_HAS_GENERIC_ASSERTION
#define iuTestAssertion_EqFailureMessageGeneric(expected_str, actual_str, expected, actual)	\
	iuAssertionFailureFormatMessage(IUTEST_PRINTF_FORMAT_MSG2(								\
	  "error: Value of : " actual_str "\n  Actual: ", actual								\
	, "\nExpected: " expected_str "\nWhich is: ", expected, "" ), actual, expected)

#endif


#if !defined(iuTestAssertion_EqFailureMessage)
#if IUTEST_C_HAS_GENERIC_ASSERTION
#    define iuTestAssertion_EqFailureMessage		iuTestAssertion_EqFailureMessageGeneric
#  else
#    define iuTestAssertion_EqFailureMessage		iuTestAssertion_EqFailureMessageShowActual
#  endif
#endif

#define iuTestAssertion_StrEqFailureMessage(expected_str, actual_str, expected, actual)		\
	iuAssertionStringFailureMessage("error: Value of : " actual_str "\n  Actual: \""		\
	, actual, "\"\nExpected: " expected_str "\nWhich is: \"", expected, "\"")

#define iuTestAssertion_StrCaseEqFailureMessage(expected_str, actual_str, expected, actual)	\
	iuAssertionStringFailureMessage("error: Value of : " actual_str "\n  Actual: \""		\
	, actual, "\"\nExpected: " expected_str "\nWhich is: \"", expected, "\" (ignoring case)")

#define iuTestAssertion_StrNeFailureMessage(val1_str, val2_str, val1, val2)							\
	iuAssertionStringFailureMessage("error: Expected : " val1_str " != " val2_str "\n  Actual: \""	\
	, val1, "\" vs \"" , val2, "\"")

#define iuTestAssertion_StrCaseNeFailureMessage(val1_str, val2_str, val1, val2)			\
	iuAssertionStringFailureMessage("error: Expected : " val1_str " != " val2_str " (ignoring case)\n  Actual: \""	\
	, val1, "\" vs \"" , val2, "\"")


/* val1 は lvalue only*/
#define iuTestAssertion_VsFailureMessageShowActual1(expression_str, val1, val2)			\
	iuAssertionFailureMessageComp("error: Expected of : " expression_str "\n  Actual: "	\
	, &val1, sizeof(val1), " vs ", #val2, 0, NULL)

/* val2 は lvalue only*/
#define iuTestAssertion_VsFailureMessageShowActual2(expression_str, val1, val2)			\
	iuAssertionFailureMessageComp("error: Expected of : " expression_str "\n  Actual: "	\
	, NULL, 0, #val1 " vs ", &val2, sizeof(val2), NULL)

/* どちらも rvalue を使用できなくなる */
#define iuTestAssertion_VsFailureMessageShowActual12(expression_str, val1, val2)		\
	iuAssertionFailureMessageComp("error: Expected of : " expression_str "\n  Actual: "	\
	, &val1, sizeof(val1), " vs ", &val2, sizeof(val2), NULL)

/* どちらも rvalue を使用できるが、式しか表示されない */
#define iuTestAssertion_VsFailureMessageShowOnlyExpr(expression_str, val1, val2)		\
	iuAssertionFailureMessage("error: Expected: " expression_str ) )

#if IUTEST_C_HAS_GENERIC_ASSERTION
#define iuTestAssertion_VsFailureMessageGeneric(expression_str, val1, val2)		\
	iuAssertionFailureFormatMessage(IUTEST_PRINTF_FORMAT_MSG2(					\
	  "error: Expected of : " expression_str "\n  Actual: ",	val1			\
	, " vs ", val2, "" ), val1, val2)

#endif

#if !defined(iuTestAssertion_VsFailureMessage)
#if IUTEST_C_HAS_GENERIC_ASSERTION
#    define iuTestAssertion_VsFailureMessage		iuTestAssertion_VsFailureMessageGeneric
#  else
#    define iuTestAssertion_VsFailureMessage		iuTestAssertion_VsFailureMessageShowActual12
#  endif
#endif

/**
 * @}
*/

/** NULL 比較テスト */
#define iuTestAssertion_CompHelperNull(expression, actual)	\
	(((actual) == NULL) ? iuAssertionSuccess() :			\
	iuAssertionFailureMessage("error: Expected: NULL == " expression) )

/** NOT NULL テスト */
#define iuTestAssertion_CompHelperNotNull(expression, actual)	\
	(((actual) != NULL) ? iuAssertionSuccess() :				\
	iuAssertionFailureMessage("error: Expected: NULL != " expression) )

/** == テスト */
#define iuTestAssertion_CompHelperEQ(expected_str, actual_str, expected, actual)	\
	((expected == actual) ? iuAssertionSuccess() :									\
	 iuTestAssertion_EqFailureMessage(expected_str, actual_str, expected, actual))

/** == テスト */
#define iuTestAssertion_CompHelperLValueEQ(expected_str, actual_str, expected, actual)	\
	((expected == actual) ? iuAssertionSuccess() :										\
	iuTestAssertion_EqFailureMessageShowWhichIs(expected_str, actual_str, expected, actual))

/** == テスト */
#define iuTestAssertion_CompHelperRValueEQ(expected_str, actual_str, expected, actual)	\
	((expected == actual) ? iuAssertionSuccess() :										\
	 iuTestAssertion_EqFailureMessageShowOnlyExpr(expected_str, actual_str, expected, actual))

/** アドレス比較テスト */
#define iuTestAssertion_CompHelperSame(expected_str, actual_str, expected, actual)	\
	((&expected == &actual) ? iuAssertionSuccess() :								\
	iuTestAssertion_EqFailureMessage(expected_str, actual_str, expected, actual))

/** != テスト */
#define iuTestAssertion_CompHelperNE(expected_str, actual_str, expected, actual)	\
	((expected != actual) ? iuAssertionSuccess() :									\
	iuTestAssertion_VsFailureMessage(expected_str " != " actual_str, expected, actual) )

/** < テスト */
#define iuTestAssertion_CompHelperLT(expr1, expr2, val1, val2)				\
	((val1 < val2) ? iuAssertionSuccess() :									\
	iuTestAssertion_VsFailureMessage(expr1 " < " expr2, val1, val2) )

/** <= テスト */
#define iuTestAssertion_CompHelperLE(expr1, expr2, val1, val2)				\
	((val1 <= val2) ? iuAssertionSuccess() :								\
	iuTestAssertion_VsFailureMessage(expr1 " <= " expr2, val1, val2) )

/** > テスト */
#define iuTestAssertion_CompHelperGT(expr1, expr2, val1, val2)				\
	((val1 > val2) ? iuAssertionSuccess() :									\
	iuTestAssertion_VsFailureMessage(expr1 " > " expr2, val1, val2) )

/** >= テスト */
#define iuTestAssertion_CompHelperGE(expr1, expr2, val1, val2)				\
	((val1 >= val2) ? iuAssertionSuccess() :								\
	iuTestAssertion_VsFailureMessage(expr1 " >= " expr2, val1, val2) )

#if IUTEST_C_HAS_FLOATINGPOINT
#include <math.h>

/** float 比較テスト */
#define iuTestAssertion_CompHelperFloatEQ(expr1, expr2, val1, val2)			\
	(iuAlmostFloatEquals(val1, val2) ? iuAssertionSuccess() :				\
	iuTestAssertion_EqFailureMessage(expr1, expr2, val1, val2))
/** dobule 比較テスト */
#define iuTestAssertion_CompHelperDoubleEQ(expr1, expr2, val1, val2)		\
	(iuAlmostDoubleEquals(val1, val2) ? iuAssertionSuccess() :				\
	iuTestAssertion_EqFailureMessage(expr1, expr2, val1, val2))

/** 近似値テスト */
#define iuTestAssertion_CompHelperNear(expr1, expr2, abs_str, val1, val2, abs_val)	\
	(fabs(val1 - val2) < abs_val ? iuAssertionSuccess() :							\
	iuAssertionFailureMessageComp("error: Expected of : abs(" expr1 " - " expr2		\
		") < " abs_str "\n  Actual: abs("											\
	, &val1, sizeof(val1), " - ", &val2, sizeof(val2), ")"))

#endif

/** 文字列比較テスト */
#define iuTestAssertion_CompHelperSTREQ(expr1, expr2, val1, val2)			\
	(iuString_IsStringEqual(val1, val2) ? iuAssertionSuccess() :			\
	iuTestAssertion_StrEqFailureMessage(expr1, expr2, val1, val2) )

/** 文字列不一致テスト */
#define iuTestAssertion_CompHelperSTRNE(expr1, expr2, val1, val2)			\
	((!iuString_IsStringEqual(val1, val2)) ? iuAssertionSuccess() :			\
	iuTestAssertion_StrNeFailureMessage(expr1, expr2, val1, val2) )

/** 大小文字を区別しない文字列比較テスト */
#define iuTestAssertion_CompHelperSTRCASEEQ(expr1, expr2, val1, val2)		\
	(iuString_IsStringCaseEqual(val1, val2) ? iuAssertionSuccess() :		\
	iuTestAssertion_StrCaseEqFailureMessage(expr1, expr2, val1, val2) )

/** 大小文字を区別しない文字列不一致テスト */
#define iuTestAssertion_CompHelperSTRCASENE(expr1, expr2, val1, val2)		\
	((!iuString_IsStringCaseEqual(val1, val2)) ? iuAssertionSuccess() :		\
	iuTestAssertion_StrCaseNeFailureMessage(expr1, expr2, val1, val2) )

#if defined(IUTEST_OS_WINDOWS)

#if IUTEST_C_HAS_LIB

IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureHResultMessage(const char* fmt, HRESULT hr);

#endif

/** HRESULT 成功テスト */
#define iuTestAssertion_IsHRESULTSuccess(expr, hr)							\
	( SUCCEEDED(hr) ? iuAssertionSuccess() :								\
	iuAssertionFailureHResultMessage( "error: Expected: SUCCEEDED(" expr	\
		")\n  Actual: "	 #hr ": ", hr ) )

/** HRESULT 失敗テスト */
#define iuTestAssertion_IsHRESULTFailure(expr, hr)							\
	( FAILED(hr) ? iuAssertionSuccess() :									\
	iuAssertionFailureMessage( "error: Expected: FAILED(" expr	\
		")\n  Actual: "	 #hr ) )

/**
 * @}
*/

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_assertion_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
