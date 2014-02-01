/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_result_c.h
 * @brief		iris unit test result �t�@�C��
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_result_C_H_D27B1599_F42F_4e2d_B3EB_FACE24C2B921_
#define INCG_IRIS_iutest_result_C_H_D27B1599_F42F_4e2d_B3EB_FACE24C2B921_

/* include ===========================================================*/
#include "internal/iutest_message_c.h"
#include "internal/iutest_console_c.h"

/* declare ===========================================================*/
struct iuTestPartResult_t;
struct iuTestResult_t;
struct iuTestProperty_t;

/* enum ==============================================================*/
/**
 * @brief	���ʂ̃^�C�v
*/
typedef enum eTestResultType
{
	kTestResultAssume  = -3,	/*!< �O����� */
	kTestResultSkip    = -2,	/*!< �X�L�b�v */
	kTestResultWarning = -1,	/*!< �x�� */
	kTestResultSuccess,			/*!< ���� */
	kTestResultNonFatalFailure,	/*!< �v���I�ł͂Ȃ����s */
	kTestResultFatalFailure		/*!< �v���I�Ȏ��s */
} eTestResultType;

/* struct ============================================================*/
/**
 * @brief	�e�X�g�̕�������
*/
typedef struct iuTestPartResult_t
{
	eTestResultType		type;			/*!< ���� */
	const char*			message;		/*!< ���b�Z�[�W */
	const char*			file;			/*!< �t�@�C���� */
	int					line;			/*!< �t�@�C�����C�� */
	struct iuTestPartResult_t	*next;	/*!< �� */
} iuTestPartResult;

/**
 * @brief	�v���p�e�B
*/
typedef struct iuTestProperty_t
{
	const char*	key;				/*!< ���O */
	const char*	value;				/*!< �l */
	struct iuTestProperty_t *next;	/*!< �� */
} iuTestProperty;

/**
 * @brief	�e�X�g����
*/
typedef struct iuTestResult_t
{
	iuBOOL				result;			/*!< ���� */
	iuTestPartResult	*list;			/*!< ���ʃ��X�g */
	iuTestProperty		*properties;	/*!< �v���p�e�B���X�g */
	iuTimeInMillisec	elapsedmsec;	/*!< ���s���� */
} iuTestResult;

/* define ============================================================*/
/** @private */
#define iuTestResult_ctor()	{ TRUE, NULL, NULL, 0 }

/* declare ===========================================================*/
static iuTestPartResult*	iuTestResult_AllocTestPartResult(void);

/* function ==========================================================*/

/**
 * @brief	TestPartResult �̍쐬
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTestPartResult* iuTestResult_CreatePartResult(const char* file, int line, const char* message, eTestResultType type)
{
	iuTestPartResult* part = iuTestResult_AllocTestPartResult();
	if( part == NULL ) return NULL;
	iu_memset(part, 0, sizeof(iuTestPartResult));
	part->file = file;
	part->line = line;
	part->message = message;	/* �������m�ۂ��ꂽ���̂Ƃ��� */
	part->type = type;
	return part;
}

/**
 * @brief	�e�X�g���ʂ̒ǉ�
*/
static IUTEST_ATTRIBUTE_UNUSED_ void iuTestResult_AddPartResult(iuTestResult *result, iuTestPartResult *part)
{
	if( result == NULL ) return;
	if( part == NULL ) return;
	iuTestHelper_AddList(iuTestPartResult, result->list, part);
}

/**
 * @brief	�e�X�g���ʂ̎擾
*/
static iuBOOL iuTestPartResult_IsFailed(const iuTestPartResult *result)
{
	if( result == NULL ) return FALSE;
	if( result->type > kTestResultSuccess ) return TRUE;
	return FALSE;
}

/**
* @brief	�X�L�b�v�������ǂ���
*/
static iuBOOL iuTestPartResult_IsSkipped(const iuTestPartResult *result)
{
	if( result == NULL ) return FALSE;
	if( result->type == kTestResultSkip || result->type == kTestResultAssume ) return TRUE;
	return FALSE;
}

/**
 * @brief	�e�X�g���ʂ̎擾
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestResult_IsFailed(const iuTestResult *result)
{
	if( result == NULL ) return FALSE;

	{
		const iuTestPartResult *curr = result->list;
		while( curr != NULL )
		{
			if( iuTestPartResult_IsFailed(curr) ) return TRUE;
			curr = curr->next;
		}
	}
	return FALSE;
}

/**
* @brief	�X�L�b�v�������ǂ���
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestResult_IsSkipped(const iuTestResult *result)
{
	if( result == NULL ) return FALSE;

	{
		const iuTestPartResult *curr = result->list;
		while( curr != NULL )
		{
			if( iuTestPartResult_IsSkipped(curr) ) return !iuTestResult_IsFailed(result);
			curr = curr->next;
		}
	}
	return FALSE;
}

/**
 * @brief	�e�X�g���ʂ̑����擾
*/
static IUTEST_ATTRIBUTE_UNUSED_ int iuTestResult_TotalPartCount(const iuTestResult* result)
{
	int count=0;
	iuTestHelper_CountList(count, iuTestPartResult, result->list);
	return count;
}

/**
 * @brief	�e�X�g���ʂ̑����擾
*/
static IUTEST_ATTRIBUTE_UNUSED_ int iuTestResult_FailurePartCount(const iuTestResult* result)
{
	int count=0;
	iuTestPartResult* curr = result->list;
	while( curr != NULL )
	{
		if( iuTestPartResult_IsFailed(curr) )
		{
			++count;
		}
		curr = curr->next;
	}
	return count;
}

/**
 * @brief	�e�X�g���ʂ̑����擾
*/
static IUTEST_ATTRIBUTE_UNUSED_ int iuTestResult_GetPartCount(const iuTestResult* result, eTestResultType type)
{
	int count=0;
	iuTestPartResult* curr = result->list;
	while( curr != NULL )
	{
		if( curr->type == type )
		{
			++count;
		}
		curr = curr->next;
	}
	return count;
}

/**
 * @private
 * @brief	�e�X�g���ʃ��b�Z�[�W�̍쐬
*/
static IUTEST_ATTRIBUTE_UNUSED_ const char* iuTestResult_PartMessage(char* buf, const iuTestPartResult *test_part_result)
{
	if( buf != NULL )
	{
		if( test_part_result == NULL )
		{
			buf[0] = 0;
		}
		else
		{
			iuTest_FormatCompilerFileLocation(buf, test_part_result->file, test_part_result->line);
			iu_strcat(buf, ":");
			iu_strcat(buf, test_part_result->message);
			iu_strcat(buf, "\n");
		}
	}
	return buf;
}

/**
 * @private
 * @brief	TestPartResult �̍쐬
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTestPartResult * iuTestResult_AllocTestPartResult(void)
{
#if IUTEST_C_HAS_MALLOC
	return (iuTestPartResult *)iu_malloc(sizeof(iuTestPartResult));
#else
	iuTestPartResult *ptr = NULL;
	IUTEST_C_AllocByPool(ptr, iuTestPartResult, IUTEST_C_TESTPARTRESULT_POOL_COUNT);
	return ptr;
#endif
}

/**
 * @private
 * @brief	TestProperty �̍쐬
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTestProperty *	iuTestResult_AllocTestProperty(void)
{
#if IUTEST_C_HAS_MALLOC
	return (iuTestProperty *)iu_malloc(sizeof(iuTestProperty));
#else
	iuTestProperty *ptr = NULL;
	IUTEST_C_AllocByPool(ptr, iuTestProperty, IUTEST_C_TESTPROPERTY_POOL_COUNT);
	return ptr;
#endif
}

#endif
