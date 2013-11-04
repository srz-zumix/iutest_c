/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_listener_c.inl
 * @brief		iris unit test イベントリスナー 定義 ファイル
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
#ifndef INCG_IRIS_iutest_listener_C_INL_B8604F9D_23F4_455e_B7EF_6D5E5D3EF9EC_
#define INCG_IRIS_iutest_listener_C_INL_B8604F9D_23F4_455e_B7EF_6D5E5D3EF9EC_

/* include ===========================================================*/
#include "../iutest_listener_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestListener* iuTestListener_MakeListener(iuTestListener* listener
													, iuTestListener_OnTestProgramStart OnTestProgramStart
													, iuTestListener_OnTestIterationStart OnTestIterationStart
													, iuTestListener_OnEnvironmentsSetUpStart OnEnvironmentsSetUpStart
													, iuTestListener_OnEnvironmentsSetUpEnd OnEnvironmentsSetUpEnd
													, iuTestListener_OnTestCaseStart OnTestCaseStart
													, iuTestListener_OnTestStart OnTestStart
													, iuTestListener_OnTestPartResult OnTestPartResult
													, iuTestListener_OnTestRecordProperty OnTestProperty
													, iuTestListener_OnTestEnd OnTestEnd
													, iuTestListener_OnTestCaseEnd OnTestCaseEnd
													, iuTestListener_OnEnvironmentsTearDownStart OnEnvironmentsTearDownStart
													, iuTestListener_OnEnvironmentsTearDownEnd OnEnvironmentsTearDownEnd
													, iuTestListener_OnTestIterationEnd OnTestIterationEnd
													, iuTestListener_OnTestProgramEnd OnTestProgramEnd
													)
{
	if( listener == NULL ) return NULL;
	listener->next = NULL;
	listener->OnTestProgramStart		= OnTestProgramStart;
	listener->OnTestIterationStart		= OnTestIterationStart;
	listener->OnEnvironmentsSetUpStart	= OnEnvironmentsSetUpStart;
	listener->OnEnvironmentsSetUpEnd	= OnEnvironmentsSetUpEnd;
	listener->OnTestCaseStart			= OnTestCaseStart;
	listener->OnTestStart				= OnTestStart;
	listener->OnTestPartResult			= OnTestPartResult;
	listener->OnTestRecordProperty		= OnTestProperty;
	listener->OnTestEnd					= OnTestEnd;
	listener->OnTestCaseEnd				= OnTestCaseEnd;
	listener->OnTestIterationEnd		= OnTestIterationEnd;
	listener->OnEnvironmentsTearDownStart	= OnEnvironmentsTearDownStart;
	listener->OnEnvironmentsTearDownEnd	= OnEnvironmentsTearDownEnd;
	listener->OnTestProgramEnd			= OnTestProgramEnd;
	return listener;
}


IUTEST_C_INL_INLINE iuTestListener*	iuTestListener_AllocListener(void)
{
#if IUTEST_C_HAS_MALLOC
	return (iuTestListener*)iu_malloc(sizeof(iuTestListener));
#else
	iuTestListener* ptr = NULL;
	IUTEST_C_AllocByPool(ptr, iuTestListener, IUTEST_C_LISTENER_POOL_COUNT);
	return ptr;
#endif
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestListener* iuTestListener_NewListener(
	iuTestListener_OnTestProgramStart OnTestProgramStart
	, iuTestListener_OnTestIterationStart OnTestIterationStart
	, iuTestListener_OnEnvironmentsSetUpStart OnEnvironmentsSetUpStart
	, iuTestListener_OnEnvironmentsSetUpEnd OnEnvironmentsSetUpEnd
	, iuTestListener_OnTestCaseStart OnTestCaseStart
	, iuTestListener_OnTestStart OnTestStart
	, iuTestListener_OnTestPartResult OnTestPartResult
	, iuTestListener_OnTestRecordProperty OnTestProperty
	, iuTestListener_OnTestEnd OnTestEnd
	, iuTestListener_OnTestCaseEnd OnTestCaseEnd
	, iuTestListener_OnEnvironmentsTearDownStart OnEnvironmentsTearDownStart
	, iuTestListener_OnEnvironmentsTearDownEnd OnEnvironmentsTearDownEnd
	, iuTestListener_OnTestIterationEnd OnTestIterationEnd
	, iuTestListener_OnTestProgramEnd OnTestProgramEnd
	)
{
	iuTestListener* listener = iuTestListener_AllocListener();
	return iuTestListener_MakeListener(listener
		, OnTestProgramStart
		, OnTestIterationStart
		, OnEnvironmentsSetUpStart
		, OnEnvironmentsSetUpEnd
		, OnTestCaseStart
		, OnTestStart
		, OnTestPartResult
		, OnTestProperty
		, OnTestEnd
		, OnTestCaseEnd
		, OnEnvironmentsTearDownStart
		, OnEnvironmentsTearDownEnd
		, OnTestIterationEnd
		, OnTestProgramEnd
		);
}

#endif
