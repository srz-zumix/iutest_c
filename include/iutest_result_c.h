/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_result_c.h
 * @brief		iris unit test result ファイル
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
 * @brief	結果のタイプ
*/
typedef enum eTestResultType
{
	kTestResultAssume  = -3,	/*!< 前提条件 */
	kTestResultSkip    = -2,	/*!< スキップ */
	kTestResultWarning = -1,	/*!< 警告 */
	kTestResultSuccess,			/*!< 成功 */
	kTestResultNonFatalFailure,	/*!< 致命的ではない失敗 */
	kTestResultFatalFailure		/*!< 致命的な失敗 */
} eTestResultType;

/* struct ============================================================*/
/**
 * @brief	テストの部分結果
*/
typedef struct iuTestPartResult_t
{
	eTestResultType		type;			/*!< 結果 */
	const char*			message;		/*!< メッセージ */
	const char*			file;			/*!< ファイル名 */
	int					line;			/*!< ファイルライン */
	struct iuTestPartResult_t	*next;	/*!< 次 */
} iuTestPartResult;

/**
 * @brief	プロパティ
*/
typedef struct iuTestProperty_t
{
	const char*	key;				/*!< 名前 */
	const char*	value;				/*!< 値 */
	struct iuTestProperty_t *next;	/*!< 次 */
} iuTestProperty;

/**
 * @brief	テスト結果
*/
typedef struct iuTestResult_t
{
	iuBOOL				result;			/*!< 成否 */
	iuTestPartResult	*list;			/*!< 結果リスト */
	iuTestProperty		*properties;	/*!< プロパティリスト */
	iuTimeInMillisec	elapsedmsec;	/*!< 実行時間 */
} iuTestResult;

/* define ============================================================*/
/** @private */
#define iuTestResult_ctor()	{ TRUE, NULL, NULL, 0 }

/* declare ===========================================================*/
static iuTestPartResult*	iuTestResult_AllocTestPartResult(void);

/* function ==========================================================*/

/**
 * @brief	TestPartResult の作成
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuTestPartResult* iuTestResult_CreatePartResult(const char* file, int line, const char* message, eTestResultType type)
{
	iuTestPartResult* part = iuTestResult_AllocTestPartResult();
	if( part == NULL ) return NULL;
	iu_memset(part, 0, sizeof(iuTestPartResult));
	part->file = file;
	part->line = line;
	part->message = message;	/* メモリ確保されたものとする */
	part->type = type;
	return part;
}

/**
 * @brief	テスト結果の追加
*/
static IUTEST_ATTRIBUTE_UNUSED_ void iuTestResult_AddPartResult(iuTestResult *result, iuTestPartResult *part)
{
	if( result == NULL ) return;
	if( part == NULL ) return;
	iuTestHelper_AddList(iuTestPartResult, result->list, part);
}

/**
 * @brief	テスト結果の取得
*/
static iuBOOL iuTestPartResult_IsFailed(const iuTestPartResult *result)
{
	if( result == NULL ) return FALSE;
	if( result->type > kTestResultSuccess ) return TRUE;
	return FALSE;
}

/**
* @brief	スキップしたかどうか
*/
static iuBOOL iuTestPartResult_IsSkipped(const iuTestPartResult *result)
{
	if( result == NULL ) return FALSE;
	if( result->type == kTestResultSkip || result->type == kTestResultAssume ) return TRUE;
	return FALSE;
}

/**
 * @brief	テスト結果の取得
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
* @brief	スキップしたかどうか
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
 * @brief	テスト結果の総数取得
*/
static IUTEST_ATTRIBUTE_UNUSED_ int iuTestResult_TotalPartCount(const iuTestResult* result)
{
	int count=0;
	iuTestHelper_CountList(count, iuTestPartResult, result->list);
	return count;
}

/**
 * @brief	テスト結果の総数取得
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
 * @brief	テスト結果の総数取得
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
 * @brief	テスト結果メッセージの作成
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
 * @brief	TestPartResult の作成
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
 * @brief	TestProperty の作成
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
