/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_pool_c.h
 * @brief		iris unit test memory pool ファイル
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
#ifndef INCG_IRIS_iutest_pool_c_H_C6B9E65B_4059_4175_A6DB_397DBF338AA8_
#define INCG_IRIS_iutest_pool_c_H_C6B9E65B_4059_4175_A6DB_397DBF338AA8_

/* include ===========================================================*/
#include "../iutest_defs_c.h"

/* declare ===========================================================*/
static IUTEST_ATTRIBUTE_UNUSED_ char * iuTest_AllocTestFailureMessageString(size_t length);

/* define ============================================================*/
#define IUTEST_C_AllocByPool(Result, Type, Count)	do {	\
	static iuUInt32 flags[(Count+31)/32] = {0};		\
	static Type results[Count];						\
	int i=0;										\
	for( i=0; i<Count; ++i ) {						\
		if( (flags[i/32] & (1<<(i&0x1F))) == 0 ) {	\
			flags[i/32] |= (1<<(i&0x1F));			\
			Result = results + i;					\
			break;									\
		}											\
	}												\
} while (iuAlwaysZero())


/**
 * @brief	メッセージ文字列用プール
*/
static IUTEST_ATTRIBUTE_UNUSED_	char * iuTest_AllocTestFailureMessageString(size_t length)
{
#if IUTEST_C_HAS_MALLOC
	return (char*)iu_malloc(length);
#else
	static char buffer[IUTEST_C_TESTMSGBUFFER_POOL_COUNT];
	static int alloc_index = 0;
	if( alloc_index + length <= IUTEST_C_TESTMSGBUFFER_POOL_COUNT )
	{
		char *ptr = buffer + alloc_index;
		alloc_index += length;
		return ptr;
	}
	return NULL;
#endif
}

#endif
