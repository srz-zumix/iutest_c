/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_random_c.h
 * @brief		iris unit test 乱数生成器 定義 ファイル
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
#ifndef INCG_IRIS_iutest_random_c_H_89F260D7_9145_4b50_A8F0_B7A2696121B6_
#define INCG_IRIS_iutest_random_c_H_89F260D7_9145_4b50_A8F0_B7A2696121B6_

/* include ===========================================================*/
#include "iutest_time_c.h"

/* struct ============================================================*/
typedef struct iuRandomContext_t
{
	iuUInt32 v1, v2, v3, v4;
} iuRandomContext;

/* define ============================================================*/
/** @private */
#define iuRandomContext_ctor()	{ 0, 0, 0, 0 }

/* function ==========================================================*/

/**
 * @brief	乱数シードの設定
*/
static IUTEST_ATTRIBUTE_UNUSED_ void iuTestRandom_SetSeed(iuRandomContext* context, iuUInt32 seed)
{
	context->v4 = seed;
	context->v3 = (iuUInt32)(1812433253u * ((context->v4 ^ (context->v4>>30)) + 1u));
	context->v2 = (iuUInt32)(1812433253u * ((context->v3 ^ (context->v3>>30)) + 2u));
	context->v1 = (iuUInt32)(1812433253u * ((context->v2 ^ (context->v2>>30)) + 3u));
}

/**
 * @brief	乱数の取得
*/
static IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuTestRandom_Gen(iuRandomContext* context)
{
	const iuUInt32 t = (context->v1 ^ (context->v1<<11));
	context->v1 = context->v2;
	context->v2 = context->v3;
	context->v3 = context->v4;
	context->v4 = (context->v4 ^ (context->v4>>19)) ^ (t ^ (t>>8));
	return context->v4;
}

#endif
