/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_case_c.inl
 * @brief		iris unit test case ƒtƒ@ƒCƒ‹
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_CASE_C_INL_1EFD40F6_D189_467B_93B0_887A64E2B830_
#define INCG_IRIS_IUTEST_CASE_C_INL_1EFD40F6_D189_467B_93B0_887A64E2B830_

/* include ===========================================================*/
#include "../iutest_case_c.h"

IUTEST_C_INL_INLINE int iuTestCase_GetTotalTestCount(const iuTestCase* test_case)
{
	int cnt = 0;
	iuTestHelper_CountList(cnt, iuTestInfo, test_case->list);
	return cnt;
}

IUTEST_C_INL_INLINE int iuTestCase_GetTestToRunCount(const iuTestCase* test_case)
{
	int cnt = 0;
	const iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestInfo_IsShouldRunTest(curr) )
		{
			++cnt;
		}
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE int iuTestCase_GetSuccessfulTestCount(const iuTestCase* test_case)
{
	int cnt = 0;
	const iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestInfo_IsShouldRunTest(curr) && iuTestInfo_Passed(curr) )
		{
			++cnt;
		}
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE int iuTestCase_GetFailureTestCount(const iuTestCase* test_case)
{
	int cnt = 0;
	const iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestInfo_IsShouldRunTest(curr) && iuTestInfo_HasFailure(curr) )
		{
			++cnt;
		}
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE iuBOOL iuTestCase_IsFaild(const iuTestCase* test_case)
{
	return iuTestCase_GetFailureTestCount(test_case) != 0 ? TRUE : FALSE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestCase_IsDisabledTest(const iuTestCase* test_case)
{
	return test_case->flag & IUTESTINFO_DISABLED ? TRUE : FALSE;
}

IUTEST_C_INL_INLINE int iuTestCase_GetDisableTestCount(const iuTestCase* test_case)
{
	if( iuTestCase_IsDisabledTest(test_case) )
	{
		return iuTestCase_GetTotalTestCount(test_case);
	}
	else
	{
		int cnt = 0;
		const iuTestInfo* curr = test_case->list;
		while( curr != NULL )
		{
			if( iuTestInfo_IsDisabledTest(curr) )
			{
				++cnt;
			}
			curr = curr->next;
		}
		return cnt;
	}
}

IUTEST_C_INL_INLINE int iuTestCase_GetRunSkippedTestCount(const iuTestCase* test_case)
{
	int cnt = 0;
	const iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestInfo_IsSkippedTest(curr) )
		{
			++cnt;
		}
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE int iuTestCase_GetSkipTestCount(const iuTestCase* test_case)
{
	int cnt = 0;
	const iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestInfo_IsSkippedTest(curr) || !iuTestInfo_IsRanTest(curr) )
		{
			++cnt;
		}
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE iuBOOL iuTestCase_HasShouldRunTest(const iuTestCase* test_case)
{
	const iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestInfo_IsShouldRunTest(curr) )
		{
			return TRUE;
		}
		curr = curr->next;
	}
	return FALSE;
}

IUTEST_C_INL_INLINE void iuTestCase_Clear(iuTestCase* test_case)
{
	iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		iuTestInfo_Clear(curr);
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE void iuTestCase_Filter(iuTestCase* test_case)
{
	iuTestInfo* curr = test_case->list;
	while( curr != NULL )
	{
		if( iuTestCase_IsDisabledTest(test_case) )
		{
			/* DISABLE ‚Ì“`”À */
			curr->flag |= IUTESTINFO_DISABLED;
		}
		iuTestInfo_Filter(curr);
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTestCase_AddTestInfo(iuTestCase* test_case, iuTestInfo* test_info)
{
	if( test_case == NULL ) return FALSE;
	if( test_info == NULL ) return FALSE;

	{
		iuBOOL find = FALSE;
		iuTestHelper_FindList(iuTestInfo, test_case->list, test_info, find);
		/* ‚·‚Å‚É’Ç‰ÁÏ‚Ý */
		if( find ) return TRUE;
	}
	iuTestHelper_AddList(iuTestInfo, test_case->list, test_info);

	if( iuString_IsDisabledTestName(test_info->name) )
	{
		test_info->flag |= IUTESTINFO_DISABLED;
	}
	test_info->testcase_name = test_case->name;
	return TRUE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestCase_Run(iuTestCase* test_case)
{
	iuBOOL ret = TRUE;
	if( test_case == NULL ) return FALSE;
	if( iuTestCase_GetTestToRunCount(test_case) == 0 ) return TRUE;

	iuTestEnv_ListenerEvent_OnTestCaseStart(test_case);

	if( iuTestEnv_IsEnableShuffleTests() )
	{
		iuTestHelper_ShuffleList(iuTestInfo, iuTestRandom_Gen(&IIUT_C_TESTENV().random_context)
			, (unsigned int)iuTestCase_GetTotalTestCount(test_case), test_case->list);
	}

	{
		iuTestStopWatch watch;
		iuTest_StopWatchStart(&watch);

		if( test_case->setup != NULL )
		{
			(*test_case->setup)();
		}
		{
			iuTestInfo* curr = test_case->list;
			while( curr != NULL )
			{
				curr->param = test_case->param;
				if( !iuTestInfo_Run(test_case, curr) ) ret = FALSE;
				curr = curr->next;
			}
		}
		if( test_case->teardown != NULL )
		{
			(*test_case->teardown)();
		}

		test_case->elapsedmsec = iuTest_StopWatchStop(&watch);
	}

	iuTestEnv_ListenerEvent_OnTestCaseEnd(test_case);
	return ret;
}

#endif
