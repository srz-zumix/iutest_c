/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_info_c.h
 * @brief		iris unit test info �t�@�C��
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
#ifndef INCG_IRIS_iutest_info_c_H_A3DF31D4_5FC6_4c62_BCF6_EF835E47B10A_
#define INCG_IRIS_iutest_info_c_H_A3DF31D4_5FC6_4c62_BCF6_EF835E47B10A_

/* include ===========================================================*/
#include "iutest_body_c.h"
#include "internal/iutest_regex_c.h"

IUTEST_EXTERN_C_BEGIN()

/* declare ===========================================================*/
struct iuTestCase_t;

/* enum ==============================================================*/
typedef enum IUTESTINFO_FLAG
{
	IUTESTINFO_SHOULD_NOTRUN	= 0x00000001,	/*!< ���s���邩�ǂ��� */
	IUTESTINFO_DISABLED			= 0x00000002,	/*!< �������ǂ��� */
	IUTESTINFO_RAN				= 0x00000010,	/*!< ���s�������ǂ��� */
} IUTESTINFO_FLAG;

/* struct ============================================================*/
/**
 * @brief	TestInfo �\����
*/
typedef struct iuTestInfo_t
{
	const char*		name;			/*!< �e�X�g�� */
	const char*		testcase_name;	/*!< �e�X�g�P�[�X�� */
	iuUInt32		flag;			/*!< bit �t���O */
	void*			param;			/*!< �p�����[�^ */
	iuTest			test;			/*!< �e�X�g�{�� */
	iuTestResult	result;			/*!< �e�X�g���� */
	struct iuTestInfo_t	*next;		/*!< ���̃m�[�h */
} iuTestInfo;

/* define ============================================================*/
/** @private */
#define iuTestInfo_ctor(name, body)	{ name, NULL, 0, NULL, iuTest_ctor(body), iuTestResult_ctor(), NULL }

/* declare ===========================================================*/
#if !IUTEST_C_HAS_LIB

static iuBOOL iuTestInfo_IsShouldRunTest(const iuTestInfo* test_info);

#endif

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	TestBody �̎��s
*/
iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Run(struct iuTestCase_t* test_case, iuTestInfo* test_info);

/**
 * @brief	���s���ǂ���
*/
iuBOOL iuTestInfo_IsShouldRunTest(const iuTestInfo *test_info);

/**
 * @brief	���s�������ǂ���
*/
iuBOOL iuTestInfo_IsRanTest(const iuTestInfo *test_info);

/**
 * @brief	���s�������ǂ���
*/
iuBOOL iuTestInfo_HasFailure(const iuTestInfo *test_info);

/**
 * @brief	�������ǂ���
*/
iuBOOL iuTestInfo_IsDisabledTest(const iuTestInfo *test_info);

/**
 * @brief	��Ԃ̃N���A
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Clear(iuTestInfo* test_info);

/**
 * @brief	�e�X�g�̃t�B���^�����O
*/
void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Filter(iuTestInfo *test_info);

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_info_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
