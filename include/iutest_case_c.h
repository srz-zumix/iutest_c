/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_case_c.h
 * @brief		iris unit test case �t�@�C��
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
#ifndef INCG_IRIS_iutest_case_c_H_1EFD40F6_D189_467b_93B0_887A64E2B830_
#define INCG_IRIS_iutest_case_c_H_1EFD40F6_D189_467b_93B0_887A64E2B830_

/* include ===========================================================*/
#include "iutest_info_c.h"

IUTEST_EXTERN_C_BEGIN()

/* typedef ===========================================================*/
/**
 * @brief	�e�X�g�P�[�X�� SetUp �֐��|�C���^�^
*/
typedef void (*iuTestSetUpTestCase)(void);

/**
 * @brief	�e�X�g�P�[�X�� TearDown �֐��|�C���^�^
*/
typedef void (*iuTestTearDownTestCase)(void);

/* enum ==============================================================*/
typedef enum IUTESTCASE_FLAG
{
	IUTESTCASE_DISABLED			= 0x00000002,	/*!< �������ǂ��� */
} IUTESTCASE_FLAG;

/* struct ============================================================*/
/**
 * @brief	TestCase �\����
*/
typedef struct iuTestCase_t
{
	const char* name;		/*!< �e�X�g�P�[�X�� */
	iuTestInfo*	list;		/*!< TestInfo ���X�g */
	iuTestSetUpTestCase		setup;		/*!< SetUp */
	iuTestTearDownTestCase	teardown;	/*!< TearDown */
	iuTimeInMillisec		elapsedmsec;/*!< ���s���� */
	iuUInt32	flag;		/*!< bit �t���O */
	void*		param;		/*!< �p�����[�^�ւ̃|�C���^ */
	struct iuTestCase_t	*next;		/*!< ���� TestCase �̃m�[�h */
} iuTestCase;

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	�e�X�g�̑����擾
*/
int iuTestCase_GetTotalTestCount(const iuTestCase* test_case);

/**
 * @brief	���s�Ώۂ̃e�X�g�̑����擾
*/
int iuTestCase_GetTestToRunCount(const iuTestCase* test_case);

/**
 * @brief	�����e�X�g�̑����擾
*/
int iuTestCase_GetSuccessfulTestCount(const iuTestCase* test_case);

/**
 * @brief	���s�e�X�g�̑����擾
*/
int iuTestCase_GetFailureTestCount(const iuTestCase* test_case);

/**
 * @brief	�e�X�g���ʂ̎擾
*/
iuBOOL iuTestCase_IsFaild(const iuTestCase* test_case);

/**
 * @brief	�������ǂ���
*/
iuBOOL iuTestCase_IsDisabledTest(const iuTestCase* test_case);

/**
 * @brief	�����e�X�g�̑����擾
*/
int iuTestCase_GetDisableTestCount(const iuTestCase* test_case);

/**
 * @brief	�X�L�b�v�����e�X�g�̑����擾
*/
int iuTestCase_GetSkippedTestCount(const iuTestCase* test_case);

/**
 * @brief	���s�e�X�g�����邩�ǂ���
*/
iuBOOL iuTestCase_HasShouldRunTest(const iuTestCase* test_case);

/**
 * @brief	��Ԃ̃N���A
*/
void iuTestCase_Clear(iuTestCase* test_case);

/**
 * @brief	�e�X�g�̃t�B���^�����O
*/
void iuTestCase_Filter(iuTestCase* test_case);

/**
 * @brief	TestInfo �̒ǉ�
*/
int IUTEST_ATTRIBUTE_UNUSED_ iuTestCase_AddTestInfo(iuTestCase* test_case, iuTestInfo* test_info);

/**
 * @brief	�e�X�g�̎��s
*/
iuBOOL	iuTestCase_Run(iuTestCase* test_case);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_case_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
