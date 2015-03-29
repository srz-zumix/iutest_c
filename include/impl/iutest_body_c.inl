/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_body_c.inl
 * @brief		iris unit test テスト単体クラス
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_BODY_C_INL_3EEA6706_9954_4330_B292_129667FA6B96_
#define INCG_IRIS_IUTEST_BODY_C_INL_3EEA6706_9954_4330_B292_129667FA6B96_

/* include ===========================================================*/
#include "../iutest_body_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTest_Init(iuTest* test_body, iuTestSetUp setup, iuTestTearDown teardown, void* user)
{
	test_body->setup = setup;
	test_body->teardown = teardown;
	test_body->user = user;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTest_CommitResult(iuTestPartResult* part_result)
{
	iuBOOL bContinue = FALSE;
	iuTestResult* test_result = iuUnitTest_GetCurrentTestResult();
	if(test_result == NULL) return FALSE;

	{
		iuTestEnv* env = iuTestEnv_GetInstance();
		if( env->commit_result.func != NULL )
		{
			bContinue = env->commit_result.can_continue;
			if( (*env->commit_result.func)(part_result
				, env->commit_result.user) )
			{
				return bContinue;
			}
		}
	}
	if( part_result == NULL || part_result->type > kTestResultSuccess )
	{
		test_result->result = FALSE;
		if( iuTestEnv_IsEnableBreakOnFailure() )
		{
			IUTEST_C_BREAK();
		}
	}
	iuTestResult_AddPartResult(test_result, part_result);
	iuTestEnv_ListenerEvent_OnTestPartResult(part_result);
	return bContinue;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTest_CommitResults(iuTestResult* result)
{
	iuTestPartResult* curr = result->list;
	while( curr != NULL )
	{
		iuTest_CommitResult(curr);
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTest_DummyCommitResult(iuTestPartResult* part_result, void* user)
{
	IUTEST_UNUSED_VAR(part_result);
	IUTEST_UNUSED_VAR(user);
	return FALSE;
}

#endif
