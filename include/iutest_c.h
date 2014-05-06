/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_c.h
 * @brief		iris unit test �t�@�C��
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
 * 
 * @see			iutest_ver_c.h
 * @example		main.c
 * @example		sub.c
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_c_H_
#define INCG_IRIS_iutest_c_H_

/* include ===========================================================*/
#include "iutest_ver_c.h"
#include "iutest_core_c.h"
#include "iutest_param_tests_c.h"
#include "iutest_static_assertion_c.h"
#include "listener/iutest_default_printer_c.h"
#include "listener/iutest_default_xml_generator_c.h"

/* define ============================================================*/
/**
 * @defgroup	TESTDEF		�e�X�g��`
 * @brief		�e�X�g��`�}�N��
*/

/**
 * @ingroup	TESTDEF
 * @brief	���[�N�X�y�[�X�̍\�z
 * @note	�ǂ����P�� c �t�@�C���ŌĂяo���Ă�������
*/
#define IUTEST_C_WORKSPACE()						IIUT_C_WORKSPACE()

/**
 * @ingroup	TESTDEF
 * @def		IUTEST(testcase_, testname_)
 * @brief	�e�X�g�֐���`�}�N��
*/
#define IUTEST(testcase_, testname_)				IIUT_C_TEST_(testcase_, testname_)

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_F(testcase_, testname_)
 * @brief	�e�X�g�֐���`�}�N��
*/
#define IUTEST_F(testcase_, testname_)				IIUT_C_TEST_F_(testcase_, testname_)

#if IUTEST_C_HAS_PARAM_METHOD_TEST

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_PMZ(testcase_, testname_)
 * @brief	�p�����^���C�Y�e�X�g�֐���`�}�N��
*/
#define IUTEST_PMZ(testcase_, testname_, method_, ...)	IIUT_C_TEST_PMZ_(testcase_, testname_, method_, __VA_ARGS__)

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_PMZ_F(testcase_, testname_)
 * @brief	�p�����^���C�Y�e�X�g�֐���`�}�N��
*/
#define IUTEST_PMZ_F(testcase_, testname_, method_, ...)	IIUT_C_TEST_PMZ_F_(testcase_, testname_, method_, __VA_ARGS__)

#endif

/**
 * @ingroup	TESTDEF
 * @brief	iutest �̏���������
*/
#define IUTEST_INIT(argc_, argv_)					iuInitIrisUnitTest(argc_, argv_)

/**
 * @ingroup	TESTDEF
 * @brief	���ׂẴe�X�g�����s����
*/
#define IUTEST_RUN_ALL_TESTS()						iuTestRun()

/**
 * @ingroup TESTDEF
 * @brief	�e�X�g�𖾎��I�ɓo�^
*/
#define IUTEST_REGISTER_TEST(testcase_, testname_)	IUTEST_C_CALL_INITIALIZATION_SECTION(IIUT_C_TEST_INITIALIZATION_SECTION_NAME(testcase_, testname_))

/**
 * @defgroup	IUTEST_UTIL		�e�X�g�L�q�⏕
 * @brief		�e�X�g�L�q�⏕�}�N��
*/

/**
 * @ingroup		IUTEST_UTIL
 * @brief		�����I�Ȑ���
*/
#ifndef IUTEST_SUCCEED
#  define IUTEST_SUCCEED()							IIUT_SUCCEED()
#endif

/**
 * @ingroup		IUTEST_UTIL
 * @brief		�����I�Ȏ��s
*/
#ifndef IUTEST_FAIL
#  define IUTEST_FAIL()								IIUT_FAIL()
#endif

/**
 * @ingroup		IUTEST_UTIL
 * @brief		�����I�Ȏ��s
*/
#ifndef IUTEST_ADD_FAILURE
#  define IUTEST_ADD_FAILURE()						IIUT_ADD_FAILURE()
#endif

/**
 * @ingroup		IUTEST_UTIL
 * @brief		�����I�Ȏ��s
 * @param		file	= �t�@�C���p�X
 * @param		line	= �s�ԍ�
*/
#ifndef IUTEST_ADD_FAILURE_AT
#  define IUTEST_ADD_FAILURE_AT(file, line)			IIUT_ADD_FAILURE_AT(file, line)
#endif

/**
 * @ingroup		IUTEST_UTIL
 * @brief		�e�X�g�̖����I�ȃX�L�b�v
 * @details		�����I�ɃX�L�b�v��񍐂��܂�
*/
#ifndef IUTEST_SKIP
#  define IUTEST_SKIP()								IUTEST_TEST_SKIP()
#endif

/**
 * @defgroup	IUTEST_ASSERT_	�A�T�[�V����(ASSERT)
 * @brief		�e�X�g�L�q�}�N��
 * @details		���s�����ꍇ�A���̎��_�Ńe�X�g���甲���܂��B
*/

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_ASSERT_EQ
#  define	IUTEST_ASSERT_EQ(v1, v2)				IUTEST_TEST_EQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_ASSERT_LVALUE_EQ
#  define	IUTEST_ASSERT_LVALUE_EQ(v1, v2)			IUTEST_TEST_LVALUE_EQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_ASSERT_RVALUE_EQ
#  define	IUTEST_ASSERT_RVALUE_EQ(v1, v2)			IUTEST_TEST_RVALUE_EQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_ASSERT_NE
#  define	IUTEST_ASSERT_NE(v1, v2)				IUTEST_TEST_NE(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	<= �e�X�g
*/
#ifndef IUTEST_ASSERT_LE
#  define	IUTEST_ASSERT_LE(v1, v2)				IUTEST_TEST_LE(v1, v2, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	< �e�X�g
*/
#ifndef IUTEST_ASSERT_LT
#  define	IUTEST_ASSERT_LT(v1, v2)				IUTEST_TEST_LT(v1, v2, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	>= �e�X�g
*/
#ifndef IUTEST_ASSERT_GE
#  define	IUTEST_ASSERT_GE(v1, v2)				IUTEST_TEST_GE(v1, v2, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	> �e�X�g
*/
#ifndef IUTEST_ASSERT_GT
#  define	IUTEST_ASSERT_GT(v1, v2)				IUTEST_TEST_GT(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	TRUE �e�X�g
*/
#ifndef IUTEST_ASSERT_TRUE
#  define	IUTEST_ASSERT_TRUE(v)					IUTEST_TEST_BOOLEAN_(v, #v, FALSE, TRUE, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	FALSE �e�X�g
*/
#ifndef IUTEST_ASSERT_FALSE
#  define	IUTEST_ASSERT_FALSE(v)					IUTEST_TEST_BOOLEAN_(!(v), #v, TRUE, FALSE, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	NULL �e�X�g
*/
#ifndef IUTEST_ASSERT_NULL
#  define	IUTEST_ASSERT_NULL(v)					IUTEST_TEST_NULL(v, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	NOT NULL �e�X�g
*/
#ifndef IUTEST_ASSERT_NOTNULL
#  define	IUTEST_ASSERT_NOTNULL(v)				IUTEST_TEST_NOTNULL(v, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	�A�h���X��v �e�X�g
*/
#ifndef IUTEST_ASSERT_SAME
#  define	IUTEST_ASSERT_SAME(v1, v2)				IUTEST_TEST_SAME(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

#if IUTEST_C_HAS_FLOATINGPOINT

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	float �̔�r �e�X�g
*/
#ifndef IUTEST_ASSERT_FLOAT_EQ
#  define	IUTEST_ASSERT_FLOAT_EQ(v1, v2)			IUTEST_TEST_FLOAT_EQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	double �̔�r �e�X�g
*/
#ifndef IUTEST_ASSERT_DOUBLE_EQ
#  define	IUTEST_ASSERT_DOUBLE_EQ(v1, v2)			IUTEST_TEST_DOUBLE_EQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	�Q�l�̍��͈̔� �e�X�g
*/
#ifndef IUTEST_ASSERT_NEAR
#  define	IUTEST_ASSERT_NEAR(v1, v2, abs_v)		IUTEST_TEST_NEAR(v1, v2, abs_v, IUTEST_ASSERT_FAILURE)
#endif

#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	������̈�v �e�X�g
*/
#ifndef IUTEST_ASSERT_STREQ
#  define	IUTEST_ASSERT_STREQ(v1, v2)				IUTEST_TEST_STREQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	������̕s��v �e�X�g
*/
#ifndef IUTEST_ASSERT_STRNE
#  define	IUTEST_ASSERT_STRNE(v1, v2)				IUTEST_TEST_STRNE(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	������̈�v�i�啶����������ʂȂ��j �e�X�g
*/
#ifndef IUTEST_ASSERT_STRCASEEQ
#  define	IUTEST_ASSERT_STRCASEEQ(v1, v2)			IUTEST_TEST_STRCASEEQ(v1, v2, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	������̕s��v�i�啶����������ʂȂ��j �e�X�g
*/
#ifndef IUTEST_ASSERT_STRCASENE
#  define	IUTEST_ASSERT_STRCASENE(v1, v2)			IUTEST_TEST_STRCASENE(v1, v2, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	HRESULT �̐��� �e�X�g
*/
#ifndef IUTEST_ASSERT_HRESULT_SUCCEEDED
#  define IUTEST_ASSERT_HRESULT_SUCCEEDED(hr)		IUTEST_TEST_HRESULT_SUCCEEDED(hr, IUTEST_ASSERT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	HRESULT �̎��s �e�X�g
*/
#ifndef IUTEST_ASSERT_HRESULT_FAILED
#  define IUTEST_ASSERT_HRESULT_FAILED(hr)			IUTEST_TEST_HRESULT_FAILED(hr, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	no new fatal failure �e�X�g
*/
#ifndef IUTEST_ASSERT_NO_FATAL_FAILURE
#  define IUTEST_ASSERT_NO_FATAL_FAILURE(statement)	IUTEST_TEST_NO_FATAL_FAILURE_(statement, IUTEST_ASSERT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	no new failure �e�X�g
*/
#ifndef IUTEST_ASSERT_NO_FAILURE
#  define IUTEST_ASSERT_NO_FAILURE(statement)		IUTEST_TEST_NO_FAILURE_(statement, IUTEST_ASSERT_FAILURE)
#endif


/**
 * @defgroup	IUTEST_EXPECT_		�A�T�[�V����(EXPECT)
 * @brief		�e�X�g�L�q�}�N��
 * @details		���s�����ꍇ�ł��A�e�X�g�𑱍s���܂��B
*/

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_EXPECT_EQ
#  define	IUTEST_EXPECT_EQ(v1, v2)				IUTEST_TEST_EQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_EXPECT_LVALUE_EQ
#  define	IUTEST_EXPECT_LVALUE_EQ(v1, v2)			IUTEST_TEST_LVALUE_EQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_EXPECT_RVALUE_EQ
#  define	IUTEST_EXPECT_RVALUE_EQ(v1, v2)			IUTEST_TEST_RVALUE_EQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_EXPECT_NE
#  define	IUTEST_EXPECT_NE(v1, v2)				IUTEST_TEST_NE(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	<= �e�X�g
*/
#ifndef IUTEST_EXPECT_LE
#  define	IUTEST_EXPECT_LE(v1, v2)				IUTEST_TEST_LE(v1, v2, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	< �e�X�g
*/
#ifndef IUTEST_EXPECT_LT
#  define	IUTEST_EXPECT_LT(v1, v2)				IUTEST_TEST_LT(v1, v2, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	>= �e�X�g
*/
#ifndef IUTEST_EXPECT_GE
#  define	IUTEST_EXPECT_GE(v1, v2)				IUTEST_TEST_GE(v1, v2, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	> �e�X�g
*/
#ifndef IUTEST_EXPECT_GT
#  define	IUTEST_EXPECT_GT(v1, v2)				IUTEST_TEST_GT(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	TRUE �e�X�g
*/
#ifndef IUTEST_EXPECT_TRUE
#  define	IUTEST_EXPECT_TRUE(v)					IUTEST_TEST_BOOLEAN_(v, #v, FALSE, TRUE, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	FALSE �e�X�g
*/
#ifndef IUTEST_EXPECT_FALSE
#  define	IUTEST_EXPECT_FALSE(v)					IUTEST_TEST_BOOLEAN_(!(v), #v, TRUE, FALSE, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	NULL �e�X�g
*/
#ifndef IUTEST_EXPECT_NULL
#  define	IUTEST_EXPECT_NULL(v)					IUTEST_TEST_NULL(v, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	NOT NULL �e�X�g
*/
#ifndef IUTEST_EXPECT_NOTNULL
#  define	IUTEST_EXPECT_NOTNULL(v)				IUTEST_TEST_NOTNULL(v, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	�A�h���X��v �e�X�g
*/
#ifndef IUTEST_EXPECT_SAME
#  define	IUTEST_EXPECT_SAME(v1, v2)				IUTEST_TEST_SAME(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

#if IUTEST_C_HAS_FLOATINGPOINT

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	float �̔�r �e�X�g
*/
#ifndef IUTEST_EXPECT_FLOAT_EQ
#  define	IUTEST_EXPECT_FLOAT_EQ(v1, v2)			IUTEST_TEST_FLOAT_EQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	double �̔�r �e�X�g
*/
#ifndef IUTEST_EXPECT_DOUBLE_EQ
#  define	IUTEST_EXPECT_DOUBLE_EQ(v1, v2)			IUTEST_TEST_DOUBLE_EQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	�Q�l�̍��͈̔� �e�X�g
*/
#ifndef IUTEST_EXPECT_NEAR
#  define	IUTEST_EXPECT_NEAR(v1, v2, abs_v)		IUTEST_TEST_NEAR(v1, v2, abs_v, IUTEST_EXPECT_FAILURE)
#endif

#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	������̈�v �e�X�g
*/
#ifndef IUTEST_EXPECT_STREQ
#  define	IUTEST_EXPECT_STREQ(v1, v2)				IUTEST_TEST_STREQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	������̕s��v �e�X�g
*/
#ifndef IUTEST_EXPECT_STRNE
#  define	IUTEST_EXPECT_STRNE(v1, v2)				IUTEST_TEST_STRNE(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	������̈�v�i�啶����������ʂȂ��j �e�X�g
*/
#ifndef IUTEST_EXPECT_STRCASEEQ
#  define	IUTEST_EXPECT_STRCASEEQ(v1, v2)			IUTEST_TEST_STRCASEEQ(v1, v2, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	������̕s��v�i�啶����������ʂȂ��j �e�X�g
*/
#ifndef IUTEST_EXPECT_STRCASENE
#  define	IUTEST_EXPECT_STRCASENE(v1, v2)			IUTEST_TEST_STRCASENE(v1, v2, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	HRESULT �̐��� �e�X�g
*/
#ifndef IUTEST_EXPECT_HRESULT_SUCCEEDED
#  define IUTEST_EXPECT_HRESULT_SUCCEEDED(hr)		IUTEST_TEST_HRESULT_SUCCEEDED(hr, IUTEST_EXPECT_FAILURE)
#endif
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	HRESULT �̎��s �e�X�g
*/
#ifndef IUTEST_EXPECT_HRESULT_FAILED
#  define IUTEST_EXPECT_HRESULT_FAILED(hr)			IUTEST_TEST_HRESULT_FAILED(hr, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	no new fatal failure �e�X�g
*/
#ifndef IUTEST_EXPECT_NO_FATAL_FAILURE
#  define IUTEST_EXPECT_NO_FATAL_FAILURE(statement)	IUTEST_TEST_NO_FATAL_FAILURE_(statement, IUTEST_EXPECT_FAILURE)
#endif

/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	no new failure �e�X�g
*/
#ifndef IUTEST_EXPECT_NO_FAILURE
#  define IUTEST_EXPECT_NO_FAILURE(statement)		IUTEST_TEST_NO_FAILURE_(statement, IUTEST_EXPECT_FAILURE)
#endif


/**
 * @defgroup	IUTEST_INFORM_		�A�T�[�V����(INFORM)
 * @brief		�e�X�g�L�q�}�N��
 * @details		���s�����ꍇ�ł��A�e�X�g���s�Ƃ��ċL�^���܂���B�܂��A�e�X�g�͑��s���܂��B
*/

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_INFORM_EQ
#  define	IUTEST_INFORM_EQ(expected, actual)		IUTEST_TEST_EQ(expected, actual, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_INFORM_LVALUE_EQ
#  define	IUTEST_INFORM_LVALUE_EQ(v1, v2)			IUTEST_TEST_LVALUE_EQ(v1, v2, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	== �e�X�g
*/
#ifndef IUTEST_INFORM_RVALUE_EQ
#  define	IUTEST_INFORM_RVALUE_EQ(v1, v2)			IUTEST_TEST_RVALUE_EQ(v1, v2, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	!= �e�X�g
*/
#ifndef IUTEST_INFORM_NE
#  define	IUTEST_INFORM_NE(v1, v2)				IUTEST_TEST_NE(v1, v2, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	<= �e�X�g
*/
#ifndef IUTEST_INFORM_LE
#  define	IUTEST_INFORM_LE(v1, v2)				IUTEST_TEST_LE(v1, v2, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	< �e�X�g
*/
#ifndef IUTEST_INFORM_LT
#  define	IUTEST_INFORM_LT(v1, v2)				IUTEST_TEST_LT(v1, v2, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	>= �e�X�g
*/
#ifndef IUTEST_INFORM_GE
#  define	IUTEST_INFORM_GE(v1, v2)				IUTEST_TEST_GE(v1, v2, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	> �e�X�g
*/
#ifndef IUTEST_INFORM_GT
#  define	IUTEST_INFORM_GT(v1, v2)				IUTEST_TEST_GT(v1, v2, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	TRUE �e�X�g
*/
#ifndef IUTEST_INFORM_TRUE
#  define	IUTEST_INFORM_TRUE(v)					IUTEST_TEST_BOOLEAN_(v, #v, FALSE, TRUE, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	FALSE �e�X�g
*/
#ifndef IUTEST_INFORM_FALSE
#  define	IUTEST_INFORM_FALSE(v)					IUTEST_TEST_BOOLEAN_(!(v), #v, TRUE, FALSE, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	NULL �e�X�g
*/
#ifndef IUTEST_INFORM_NULL
#  define	IUTEST_INFORM_NULL(v)					IUTEST_TEST_NULL(v, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	NOT NULL �e�X�g
*/
#ifndef IUTEST_INFORM_NOTNULL
#  define	IUTEST_INFORM_NOTNULL(v)				IUTEST_TEST_NOTNULL(v, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	�A�h���X��v �e�X�g
*/
#ifndef IUTEST_INFORM_SAME
#  define	IUTEST_INFORM_SAME(v1, v2)				IUTEST_TEST_SAME(v1, v2, IUTEST_INFORM_FAILURE)
#endif

#if IUTEST_C_HAS_FLOATINGPOINT

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	float �̔�r �e�X�g
*/
#ifndef IUTEST_INFORM_FLOAT_EQ
#  define	IUTEST_INFORM_FLOAT_EQ(expected, actual)	IUTEST_TEST_FLOAT_EQ(expected, actual, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	double �̔�r �e�X�g
*/
#ifndef IUTEST_INFORM_DOUBLE_EQ
#  define	IUTEST_INFORM_DOUBLE_EQ(expected, actual)	IUTEST_TEST_DOUBLE_EQ(expected, actual, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	�Q�l�̍��͈̔� �e�X�g
*/
#ifndef IUTEST_INFORM_NEAR
#  define	IUTEST_INFORM_NEAR(v1, v2, abs_v)		IUTEST_TEST_NEAR(v1, v2, abs_v, IUTEST_INFORM_FAILURE)
#endif

#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	������̈�v �e�X�g
*/
#ifndef IUTEST_INFORM_STREQ
#  define	IUTEST_INFORM_STREQ(expected_str, actual_str)	IUTEST_TEST_STREQ(expected_str, actual_str, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	������̕s��v �e�X�g
*/
#ifndef IUTEST_INFORM_STRNE
#  define	IUTEST_INFORM_STRNE(v1, v2)				IUTEST_TEST_STRNE(v1, v2, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	������̈�v�i�啶����������ʂȂ��j �e�X�g
*/
#ifndef IUTEST_INFORM_STRCASEEQ
#  define	IUTEST_INFORM_STRCASEEQ(expected_str, actual_str)	IUTEST_TEST_STRCASEEQ(expected_str, actual_str, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	������̕s��v�i�啶����������ʂȂ��j �e�X�g
*/
#ifndef IUTEST_INFORM_STRCASENE
#  define	IUTEST_INFORM_STRCASENE(v1, v2)			IUTEST_TEST_STRCASENE(v1, v2, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	HRESULT �̐��� �e�X�g
*/
#ifndef IUTEST_INFORM_HRESULT_SUCCEEDED
#  define IUTEST_INFORM_HRESULT_SUCCEEDED(hr)		IUTEST_TEST_HRESULT_SUCCEEDED(hr, IUTEST_INFORM_FAILURE)
#endif
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	HRESULT �̎��s �e�X�g
*/
#ifndef IUTEST_INFORM_HRESULT_FAILED
#  define IUTEST_INFORM_HRESULT_FAILED(hr)			IUTEST_TEST_HRESULT_FAILED(hr, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	no new fatal failure �e�X�g
*/
#ifndef IUTEST_INFORM_NO_FAILURE
#  define IUTEST_INFORM_NO_FAILURE(statement)		IUTEST_TEST_NO_FAILURE_(statement, IUTEST_INFORM_FAILURE)
#endif

/**
 * @ingroup	IUTEST_INFORM_
 * @brief	no new failure �e�X�g
*/
#ifndef IUTEST_INFORM_NO_FATAL_FAILURE
#  define IUTEST_INFORM_NO_FATAL_FAILURE(statement)	IUTEST_TEST_NO_FATAL_FAILURE_(statement, IUTEST_INFORM_FAILURE)
#endif


/* declare ===========================================================*/
static void iuTestInitialize(void);

/* function ==========================================================*/
/**
 * @brief	�e�X�g�̏�����
*/
static IUTEST_ATTRIBUTE_UNUSED_ void	iuInitIrisUnitTestA(int* argc, char** argv)
{
#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION
	iuTestEnv_LoadEnviromentVariable();
#endif
#if IUTEST_C_HAS_COMMANDLINE_OPTION
	iuTestEnv_ParseCommandLineA(argc, argv);
#else
	IUTEST_UNUSED_VAR(argc);
	IUTEST_UNUSED_VAR(argv);
#endif
	iuTestInitialize();
}
#if IUTEST_C_HAS_WCHAR_T
/**
 * @brief	�e�X�g�̏�����
*/
static IUTEST_ATTRIBUTE_UNUSED_ void iuInitIrisUnitTestW(int* argc, wchar_t** argv)
{
#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION
	iuTestEnv_LoadEnviromentVariable();
#endif
#if IUTEST_C_HAS_COMMANDLINE_OPTION
	iuTestEnv_ParseCommandLineW(argc, argv);
#else
	IUTEST_UNUSED_VAR(argc);
	IUTEST_UNUSED_VAR(argv);
#endif
	iuTestInitialize();
}
#endif

/** �e�X�g�̏����� */
#ifdef UNICODE
#  define iuInitIrisUnitTest	iuInitIrisUnitTestW
#else
#  define iuInitIrisUnitTest	iuInitIrisUnitTestA
#endif

/**
 * @biref	�e�X�g�̏������i���ʍ��j
*/
static IUTEST_ATTRIBUTE_UNUSED_ void iuTestInitialize(void)
{
#if IUTEST_C_HAS_CONSOLEOUT
	{
		iuTestListener* listener = iuTestListener_MakeListener(&iuUnitTest_GetInstance()->def_printer
		, iuTestDefaultPrinter_OnTestProgramStart
		, iuTestDefaultPrinter_OnTestIterationStart
		, NULL
		, NULL
		, iuTestDefaultPrinter_OnTestCaseStart
		, iuTestDefaultPrinter_OnTestStart
		, iuTestDefaultPrinter_OnTestPartResult
		, iuTestDefaultPrinter_OnTestRecordProperty
		, iuTestDefaultPrinter_OnTestEnd
		, iuTestDefaultPrinter_OnTestCaseEnd
		, NULL
		, NULL
		, iuTestDefaultPrinter_OnTestIterationEnd
		, iuTestDefaultPrinter_OnTestProgramEnd
		);
		if(listener != NULL)
		{
			iuUnitTest_AppendTestListener(listener);
		}
	}
#endif
	iuUnitTest_Init();
}

/**
 * @brief	�e�X�g�̎��s
*/
static IUTEST_ATTRIBUTE_UNUSED_ int iuTestRun(void)
{
#if IUTEST_C_HAS_DEFAULT_XML_GENERATOR
	if(iuTestEnv_IsEnableOutputXml())
	{
		iuUnitTest_ReleaseTestListener(&iuUnitTest_GetInstance()->def_xml_generator);
		{
			iuTestListener* listener = iuTestListener_MakeListener(&iuUnitTest_GetInstance()->def_xml_generator
			, iuTestDefaultXMLGenerator_OnTestProgramStart
			, iuTestDefaultXMLGenerator_OnTestIterationStart
			, NULL
			, NULL
			, iuTestDefaultXMLGenerator_OnTestCaseStart
			, iuTestDefaultXMLGenerator_OnTestStart
			, iuTestDefaultXMLGenerator_OnTestPartResult
			, iuTestDefaultXMLGenerator_OnTestRecordProperty
			, iuTestDefaultXMLGenerator_OnTestEnd
			, iuTestDefaultXMLGenerator_OnTestCaseEnd
			, NULL
			, NULL
			, iuTestDefaultXMLGenerator_OnTestIterationEnd
			, iuTestDefaultXMLGenerator_OnTestProgramEnd
			);
			if(listener != NULL)
			{
				iuUnitTest_AppendTestListener(listener);
			}
		}
	}
#endif
	return iuUnitTest_Run();
}

#endif
