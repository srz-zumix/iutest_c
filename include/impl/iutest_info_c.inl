/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_info_c.inl
 * @brief		iris unit test info
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_INFO_C_INL_A3DF31D4_5FC6_4C62_BCF6_EF835E47B10A_
#define INCG_IRIS_IUTEST_INFO_C_INL_A3DF31D4_5FC6_4C62_BCF6_EF835E47B10A_

/* include ===========================================================*/
#include "../iutest_info_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE iuBOOL IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Run(struct iuTestCase_t* test_case, iuTestInfo* test_info)
{
	if( test_info == NULL ) return FALSE;
	if( !iuTestInfo_IsShouldRunTest(test_info) ) return TRUE;

	test_info->flag |= IUTESTINFO_RAN;

	iuUnitTest_SetCurrentTestInfo(test_info);
	iuTestEnv_ListenerEvent_OnTestStart(test_case, test_info);

	{
		iuTestStopWatch watch;
		iuTest_StopWatchStart(&watch);

		if( test_info->test.setup != NULL )
		{
			(*test_info->test.setup)();
		}
		if( test_info->test.body != NULL )
		{
			(*test_info->test.body)();
		}
		if( test_info->test.teardown != NULL )
		{
			(*test_info->test.teardown)();
		}

		test_info->result.elapsedmsec = iuTest_StopWatchStop(&watch);
	}
	iuTestEnv_ListenerEvent_OnTestEnd(test_case, test_info);

	return test_info->result.result;
}

IUTEST_C_INL_INLINE iuBOOL iuTestInfo_IsShouldRunTest(const iuTestInfo *test_info)
{
	return test_info->flag & IUTESTINFO_SHOULD_NOTRUN ? FALSE : TRUE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestInfo_IsRanTest(const iuTestInfo *test_info)
{
	return test_info->flag & IUTESTINFO_RAN ? TRUE : FALSE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestInfo_HasFailure(const iuTestInfo *test_info)
{
	/*
	if( !iuTestInfo_IsRanTest(test_info) ) return FALSE;
	*/
	if( test_info == NULL ) return FALSE;
	return iuTestResult_IsFailed(&test_info->result);
}

IUTEST_C_INL_INLINE iuBOOL iuTestInfo_Passed(const iuTestInfo *test_info)
{
	if( test_info == NULL ) return FALSE;
	if( iuTestInfo_IsSkippedTest(test_info) ) return FALSE;
	return !iuTestResult_IsFailed(&test_info->result);
}

IUTEST_C_INL_INLINE iuBOOL iuTestInfo_IsDisabledTest(const iuTestInfo *test_info)
{
	return test_info->flag & IUTESTINFO_DISABLED ? TRUE : FALSE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestInfo_IsSkippedTest(const iuTestInfo *test_info)
{
	if( test_info->flag & IUTESTINFO_SKIPPED ) return TRUE;
	return iuTestResult_IsSkipped(&test_info->result);
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Skip(iuTestInfo* test_info)
{
	test_info->flag |= IUTESTINFO_SKIPPED;
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Clear(iuTestInfo* test_info)
{
	test_info->flag &= ~IUTESTINFO_RAN;
}

IUTEST_C_INL_INLINE void IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo_Filter(iuTestInfo *test_info)
{
	if( test_info != NULL )
	{
		iuBOOL bRun = TRUE;
		if( !iuTestEnv_IsEnableRunDisabledTests()
			&& iuTestInfo_IsDisabledTest(test_info) )
		{
			bRun = FALSE;
		}
		if( IUTEST_FLAG(filter) != NULL )
		{
			char fullname[256];
			iu_strcpy(fullname, test_info->testcase_name);
			iu_strcat(fullname, ".");
			iu_strcat(fullname, test_info->name);
			if( !iuTestRegex_Match(IUTEST_FLAG(filter), fullname) )
			{
				bRun = FALSE;
			}
		}
		if( bRun )
		{
			test_info->flag &= ~IUTESTINFO_SHOULD_NOTRUN;
		}
		else
		{
			test_info->flag |= IUTESTINFO_SHOULD_NOTRUN;
		}
	}
}

#endif
