/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_body_c.h
 * @brief		iris unit test �e�X�g�P�̃N���X �t�@�C��
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_BODY_C_H_3EEA6706_9954_4330_B292_129667FA6B96_
#define INCG_IRIS_IUTEST_BODY_C_H_3EEA6706_9954_4330_B292_129667FA6B96_

/* include ===========================================================*/
#include "iutest_result_c.h"
#include "internal/iutest_core_impl_c.h"

IUTEST_EXTERN_C_BEGIN()

/* typedef ===========================================================*/
/**
 * @brief	�e�X�g�̊֐��|�C���^�^
*/
typedef void (*iuTestBody)(void);

/**
 * @brief	�e�X�g�� SetUp �֐��|�C���^�^
*/
typedef void (*iuTestSetUp)(void);

/**
 * @brief	�e�X�g�� TearDown �֐��|�C���^�^
*/
typedef void (*iuTestTearDown)(void);

/* struct ============================================================*/
/**
 * @brief	�e�X�g�\����
*/
typedef struct iuTest_t
{
	iuTestBody		body;		/*!< �e�X�g�֐� */
	iuTestSetUp		setup;		/*!< SetUp�֐� */
	iuTestTearDown	teardown;	/*!< TearDown�֐� */
	void*			user;		/*!< ���[�U�[��`�̈�A�h���X */
} iuTest;

/* define ============================================================*/
/** @private */
#define iuTest_ctor(body)	{ body, NULL, NULL, NULL }

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
* @brief	iuTest Body �̏�����
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTest_Init(iuTest* test_body, iuTestSetUp setup, iuTestTearDown teardown, void* user);

/**
 * @brief	�v���p�e�B�̋L�^
 * @param [in]	key		= �L�[��
 * @param [in]	value	= �l�̕�����
 * @return	����
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTest_RecordProperty(const char *key, const char *value);

/**
 * @brief	�e�X�g���ʂ��
*/
void iuTest_CommitResult(iuTestPartResult* part_result);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_body_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
