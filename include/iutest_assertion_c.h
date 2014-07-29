/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_assertion_c.h
 * @brief		iris unit test assertion ��`
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
 * @brief	�e�X�g�̌���
*/
typedef struct iuAssertionResult_t
{
	iuBOOL		result;		/*!< ���� */
	const char*	message;	/*!< ���b�Z�[�W */
	char*		buf;		/*!< �o�b�t�@ */
} iuAssertionResult;

/* define ============================================================*/
/** @private */
#define iuAssertionResult_ctor(b)	{ b, NULL, NULL }

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	���������� AssertionResult �̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionSuccess(void);
/**
 * @brief	���s������ AssertionResult �̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailure(void);

/**
 * @brief	���b�Z�[�W�񍐊֐�
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuAssertionHelper_Report(const char* file, int line, const char* message, eTestResultType type);

/**
 * @brief	���b�Z�[�W�̍쐬
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessage(const char* message);

/**
* @brief	���b�Z�[�W�̍쐬
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessage2(const char* message, const char* append);

/**
 * @brief	���b�Z�[�W�̍쐬
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureMessageComp(const char* message
													, const void* val1, size_t size1, const char* msg1
													, const void* val2, size_t size2, const char* msg2);

/**
 * @brief	���b�Z�[�W�̍쐬
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionStringFailureMessage(const char* message, const char* val1, const char* msg1
																				  , const char* val2, const char* msg2);

#if IUTEST_C_HAS_LIBC && IUTEST_C_HAS_STDARG && !defined(__STRICT_ANSI__)

/**
 * @brief	���b�Z�[�W�̍쐬
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureFormatMessageV(const char* fmt, va_list va);

/**
 * @brief	���b�Z�[�W�̍쐬
*/
IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureFormatMessage(const char* fmt, ...);

#endif

#endif

/**
 * @brief	BOOL ��r�e�X�g�̎��s���b�Z�[�W�̍쐬
*/
#define iuTestAssertion_GetBooleanAssertionFailureMessage(expression, actual, expected)	\
	"error: Value of: " expression "\n   Actual: " #actual "\n Expected: " #expected

/**
 * @biref	��r�e�X�g
 * @{
*/

/**
 * @private
 * @{
*/
/* actual �� rvalue ���g�p�ł��Ȃ��Ȃ� */
#define iuTestAssertion_EqFailureMessageShowActual(expected_str, actual_str, expected, actual)	\
	iuAssertionFailureMessageComp("error: Value of : " actual_str "\n  Actual: "				\
	, &actual, sizeof(actual), "\nExpected: " expected_str , NULL, 0u, NULL)

/* �ǂ���� rvalue ���g�p�ł��Ȃ��Ȃ� */
#define iuTestAssertion_EqFailureMessageShowWhichIs(expected_str, actual_str, expected, actual)	\
	iuAssertionFailureMessageComp("error: Value of : " actual_str "\n  Actual: "				\
	, &actual, sizeof(actual), "\nExpected: " expected_str "\nWhich is: ", &expected, sizeof(expected), NULL)

/* �ǂ���� rvalue ���g�p�ł��邪�A�������\������Ȃ� */
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


/* val1 �� lvalue only*/
#define iuTestAssertion_VsFailureMessageShowActual1(expression_str, val1, val2)			\
	iuAssertionFailureMessageComp("error: Expected of : " expression_str "\n  Actual: "	\
	, &val1, sizeof(val1), " vs ", #val2, 0, NULL)

/* val2 �� lvalue only*/
#define iuTestAssertion_VsFailureMessageShowActual2(expression_str, val1, val2)			\
	iuAssertionFailureMessageComp("error: Expected of : " expression_str "\n  Actual: "	\
	, NULL, 0, #val1 " vs ", &val2, sizeof(val2), NULL)

/* �ǂ���� rvalue ���g�p�ł��Ȃ��Ȃ� */
#define iuTestAssertion_VsFailureMessageShowActual12(expression_str, val1, val2)		\
	iuAssertionFailureMessageComp("error: Expected of : " expression_str "\n  Actual: "	\
	, &val1, sizeof(val1), " vs ", &val2, sizeof(val2), NULL)

/* �ǂ���� rvalue ���g�p�ł��邪�A�������\������Ȃ� */
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

/** NULL ��r�e�X�g */
#define iuTestAssertion_CompHelperNull(expression, actual)	\
	(((actual) == NULL) ? iuAssertionSuccess() :			\
	iuAssertionFailureMessage("error: Expected: NULL == " expression) )

/** NOT NULL �e�X�g */
#define iuTestAssertion_CompHelperNotNull(expression, actual)	\
	(((actual) != NULL) ? iuAssertionSuccess() :				\
	iuAssertionFailureMessage("error: Expected: NULL != " expression) )

/** == �e�X�g */
#define iuTestAssertion_CompHelperEQ(expected_str, actual_str, expected, actual)	\
	((expected == actual) ? iuAssertionSuccess() :									\
	 iuTestAssertion_EqFailureMessage(expected_str, actual_str, expected, actual))

/** == �e�X�g */
#define iuTestAssertion_CompHelperLValueEQ(expected_str, actual_str, expected, actual)	\
	((expected == actual) ? iuAssertionSuccess() :										\
	iuTestAssertion_EqFailureMessageShowWhichIs(expected_str, actual_str, expected, actual))

/** == �e�X�g */
#define iuTestAssertion_CompHelperRValueEQ(expected_str, actual_str, expected, actual)	\
	((expected == actual) ? iuAssertionSuccess() :										\
	 iuTestAssertion_EqFailureMessageShowOnlyExpr(expected_str, actual_str, expected, actual))

/** �A�h���X��r�e�X�g */
#define iuTestAssertion_CompHelperSame(expected_str, actual_str, expected, actual)	\
	((&expected == &actual) ? iuAssertionSuccess() :								\
	iuTestAssertion_EqFailureMessage(expected_str, actual_str, expected, actual))

/** != �e�X�g */
#define iuTestAssertion_CompHelperNE(expected_str, actual_str, expected, actual)	\
	((expected != actual) ? iuAssertionSuccess() :									\
	iuTestAssertion_VsFailureMessage(expected_str " != " actual_str, expected, actual) )

/** < �e�X�g */
#define iuTestAssertion_CompHelperLT(expr1, expr2, val1, val2)				\
	((val1 < val2) ? iuAssertionSuccess() :									\
	iuTestAssertion_VsFailureMessage(expr1 " < " expr2, val1, val2) )

/** <= �e�X�g */
#define iuTestAssertion_CompHelperLE(expr1, expr2, val1, val2)				\
	((val1 <= val2) ? iuAssertionSuccess() :								\
	iuTestAssertion_VsFailureMessage(expr1 " <= " expr2, val1, val2) )

/** > �e�X�g */
#define iuTestAssertion_CompHelperGT(expr1, expr2, val1, val2)				\
	((val1 > val2) ? iuAssertionSuccess() :									\
	iuTestAssertion_VsFailureMessage(expr1 " > " expr2, val1, val2) )

/** >= �e�X�g */
#define iuTestAssertion_CompHelperGE(expr1, expr2, val1, val2)				\
	((val1 >= val2) ? iuAssertionSuccess() :								\
	iuTestAssertion_VsFailureMessage(expr1 " >= " expr2, val1, val2) )

#if IUTEST_C_HAS_FLOATINGPOINT
#include <math.h>

/** float ��r�e�X�g */
#define iuTestAssertion_CompHelperFloatEQ(expr1, expr2, val1, val2)			\
	(iuAlmostFloatEquals(val1, val2) ? iuAssertionSuccess() :				\
	iuTestAssertion_EqFailureMessage(expr1, expr2, val1, val2))
/** dobule ��r�e�X�g */
#define iuTestAssertion_CompHelperDoubleEQ(expr1, expr2, val1, val2)		\
	(iuAlmostDoubleEquals(val1, val2) ? iuAssertionSuccess() :				\
	iuTestAssertion_EqFailureMessage(expr1, expr2, val1, val2))

/** �ߎ��l�e�X�g */
#define iuTestAssertion_CompHelperNear(expr1, expr2, abs_str, val1, val2, abs_val)	\
	(fabs(val1 - val2) < abs_val ? iuAssertionSuccess() :							\
	iuAssertionFailureMessageComp("error: Expected of : abs(" expr1 " - " expr2		\
		") < " abs_str "\n  Actual: abs("											\
	, &val1, sizeof(val1), " - ", &val2, sizeof(val2), ")"))

#endif

/** �������r�e�X�g */
#define iuTestAssertion_CompHelperSTREQ(expr1, expr2, val1, val2)			\
	(iuString_IsStringEqual(val1, val2) ? iuAssertionSuccess() :			\
	iuTestAssertion_StrEqFailureMessage(expr1, expr2, val1, val2) )

/** ������s��v�e�X�g */
#define iuTestAssertion_CompHelperSTRNE(expr1, expr2, val1, val2)			\
	((!iuString_IsStringEqual(val1, val2)) ? iuAssertionSuccess() :			\
	iuTestAssertion_StrNeFailureMessage(expr1, expr2, val1, val2) )

/** �召��������ʂ��Ȃ��������r�e�X�g */
#define iuTestAssertion_CompHelperSTRCASEEQ(expr1, expr2, val1, val2)		\
	(iuString_IsStringCaseEqual(val1, val2) ? iuAssertionSuccess() :		\
	iuTestAssertion_StrCaseEqFailureMessage(expr1, expr2, val1, val2) )

/** �召��������ʂ��Ȃ�������s��v�e�X�g */
#define iuTestAssertion_CompHelperSTRCASENE(expr1, expr2, val1, val2)		\
	((!iuString_IsStringCaseEqual(val1, val2)) ? iuAssertionSuccess() :		\
	iuTestAssertion_StrCaseNeFailureMessage(expr1, expr2, val1, val2) )

#if defined(IUTEST_OS_WINDOWS)

#if IUTEST_C_HAS_LIB

IUTEST_ATTRIBUTE_UNUSED_ iuAssertionResult iuAssertionFailureHResultMessage(const char* fmt, HRESULT hr);

#endif

/** HRESULT �����e�X�g */
#define iuTestAssertion_IsHRESULTSuccess(expr, hr)							\
	( SUCCEEDED(hr) ? iuAssertionSuccess() :								\
	iuAssertionFailureHResultMessage( "error: Expected: SUCCEEDED(" expr	\
		")\n  Actual: "	 #hr ": ", hr ) )

/** HRESULT ���s�e�X�g */
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
