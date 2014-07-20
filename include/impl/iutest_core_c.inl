/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_core_c.inl
 * @brief		iris unit test core
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_CORE_C_INL_5D8217F4_1A99_4DD8_A103_7DCBCA25ABAE_
#define INCG_IRIS_IUTEST_CORE_C_INL_5D8217F4_1A99_4DD8_A103_7DCBCA25ABAE_

/* include ===========================================================*/
#include "../iutest_core_c.h"

#define IIUT_C_UNITTEST()		IIUT_C_UNITTEST_NAME

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuUnitTest* iuUnitTest_GetInstance(void)
{
	return &IIUT_C_UNITTEST();
}

#if IUTEST_C_HAS_STDARG
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_SetVPrintfFunction(iuVPrintf proc)
{
	iuTestEnv_SetVPrintfFunction(iuTestEnv_GetInstance(), proc);
}
#endif

IUTEST_C_INL_INLINE iuBOOL	iuUnitTest_AppendTestListener(iuTestListener* test_listener)
{
	return iuTestEnv_AddTestListener(iuTestEnv_GetInstance(), test_listener);
}

IUTEST_C_INL_INLINE iuTestListener*	iuUnitTest_ReleaseTestListener(iuTestListener* test_listener)
{
	return iuTestEnv_SubTestListener(iuTestEnv_GetInstance(), test_listener);
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuUnitTest_AddGlobalEnvironmentSetUp(iuGlobalEnvironmentSetUp func)
{
	return iuTestEnv_AddGlobalEnvironmentSetUp(iuTestEnv_GetInstance(), func);
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuUnitTest_AddGlobalEnvironmentTearDown(iuGlobalEnvironmentTearDown func)
{
	return iuTestEnv_AddGlobalEnvironmentTearDown(iuTestEnv_GetInstance(), func);
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_Init(void)
{
	if( IIUT_C_UNITTEST().initialized_count == 0 )
	{
#if IUTEST_C_HAS_PARAM_TEST
		iuUnitTest_ParamHolderRegisterTest();
#endif
	}
	++IIUT_C_UNITTEST().initialized_count;
}

IUTEST_C_INL_INLINE iuTestCase* iuUnitTest_FindTestCase(iuTestCase* list, const char* testcase_name)
{
	iuTestCase* curr = list;
	while( curr != NULL )
	{
		if( iuString_IsStringEqual(testcase_name, curr->name) ) return curr;
		curr = curr->next;
	}
	return NULL;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo* iuUnitTest_GetCurrentTestInfo(void)
{
	return IIUT_C_UNITTEST().current_test_info;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void* iuUnitTest_GetCurrentUserData(void)
{
	if( iuUnitTest_GetCurrentTestInfo() == NULL ) return NULL;
	return iuUnitTest_GetCurrentTestInfo()->test.user;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_SetCurrentTestInfo(struct iuTestInfo_t* curr)
{
	IIUT_C_UNITTEST().current_test_info = curr;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestResult* iuUnitTest_GetCurrentTestResult(void)
{
	return iuUnitTest_GetCurrentTestInfo() == NULL ? &iuUnitTest_GetInstance()->adhoc_testresult : &iuUnitTest_GetCurrentTestInfo()->result;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuUnitTest_GetCurrentRandomSeed(void)
{
	return iuTestEnve_GetCurrentRandomSeed();
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTotalTestCaseCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	iuTestHelper_CountList(cnt, iuTestCase, unit_test->list);
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTestCaseToRunCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		if( iuTestCase_HasShouldRunTest(curr) ) ++cnt;
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTotalTestCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetTotalTestCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTestToRunCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetTestToRunCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetSuccessfulTestCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetSuccessfulTestCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetFailureTestCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetFailureTestCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetDisableTestCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetDisableTestCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetRunSkippedTestCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetRunSkippedTestCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetSkipTestCount(const iuUnitTest* unit_test)
{
	int cnt = 0;
	const iuTestCase* curr = unit_test->list;
	while( curr != NULL )
	{
		cnt += iuTestCase_GetSkipTestCount(curr);
		curr = curr->next;
	}
	return cnt;
}

IUTEST_C_INL_INLINE iuBOOL iuUnitTest_IsFaild(const iuUnitTest* unit_test)
{
	if( !unit_test->adhoc_testresult.result ) return TRUE;

	{
		const iuTestCase* curr = unit_test->list;
		while( curr != NULL )
		{
			if( iuTestCase_IsFaild(curr) ) return TRUE;
			curr = curr->next;
		}
	}
	return FALSE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuUnitTest_Passed(const iuUnitTest* unit_test)
{
	return !iuUnitTest_IsFaild(unit_test);
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ unsigned int iuUnitTest_GetRandomSeed(void)
{
	return iuTestEnv_GetInstance()->current_seed;
}

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION || IUTEST_C_HAS_COMMANDLINE_OPTION

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowTestList(const iuUnitTest* unit_test)
{
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d tests from %d testcase\n"
		, iuUnitTest_GetTotalTestCount(unit_test), iuUnitTest_GetTotalTestCaseCount(unit_test) );

	{
		iuTestCase* test_case = unit_test->list;
		while( test_case != NULL )
		{
			iuTestInfo* test_info = test_case->list;
			iuConsole_Output(test_case->name);
			iuConsole_Output("\n");
			while( test_info != NULL )
			{
				iuConsole_Output("  ");
				iuConsole_Output(test_info->name);
				iuConsole_Output("\n");
				test_info = test_info->next;
			}
			test_case = test_case->next;
		}
	}
#else
	IUTEST_UNUSED_VAR(unit_test);
#endif
	return 0;
}
#endif

IUTEST_C_INL_INLINE void iuTestRun_EnvironmentSetUp(iuUnitTest *unit_test)
{
	iuTestEnv_ListenerEvent_OnEnvironmentsSetUpStart(unit_test);
	iuTestEnv_GlobalEnvironmentSetUp();
	iuTestEnv_ListenerEvent_OnEnvironmentsSetUpEnd(unit_test);
}

IUTEST_C_INL_INLINE void iuTestRun_EnvironmentTearDown(iuUnitTest *unit_test)
{
	iuTestEnv_ListenerEvent_OnEnvironmentsTearDownStart(unit_test);
	iuTestEnv_GlobalEnvironmentTearDown();
	iuTestEnv_ListenerEvent_OnEnvironmentsTearDownEnd(unit_test);
}

IUTEST_C_INL_INLINE iuBOOL iuTestRun_RunOnce(iuUnitTest *unit_test)
{
	iuBOOL ret = TRUE;

	if( iuTestEnv_IsEnableShuffleTests() )
	{
		iuTestHelper_ShuffleList(iuTestCase, iuTestRandom_Gen(&iuTestEnv_GetInstance()->random_context)
			, iuUnitTest_GetTotalTestCaseCount(unit_test), unit_test->list);
	}

	iuTestRun_EnvironmentSetUp(unit_test);

	{
		iuTestCase* curr = unit_test->list;

		iuTestStopWatch watch;
		iuTest_StopWatchStart(&watch);

		while( curr != NULL )
		{
			if( !iuTestCase_Run(curr) ) ret = FALSE;
			curr = curr->next;
		}

		unit_test->elapsedmsec = iuTest_StopWatchStop(&watch);
	}

	iuTestRun_EnvironmentTearDown(unit_test);
	return ret;
}

IUTEST_C_INL_INLINE iuBOOL iuTestRun_Iteration(iuUnitTest *unit_test, int iteration)
{
	if( iuUnitTest_GetTestToRunCount(unit_test) != 0 )
	{
		iuBOOL ret = TRUE;
		iuTestEnv_SetUp(iuTestEnv_GetInstance());
		iuTestEnv_ListenerEvent_OnTestIterationStart(unit_test, iteration);

		if( !iuTestRun_RunOnce(unit_test) )
		{
			ret = FALSE;
		}
		iuTestEnv_ListenerEvent_OnTestIterationEnd(unit_test, iteration);
		return ret;
	}
	return iuUnitTest_Passed(unit_test);
}

IUTEST_C_INL_INLINE void iuTestRun_TestProgramStart(iuUnitTest *unit_test)
{
	iuTestEnv_ListenerEvent_OnTestProgramStart(unit_test);

	{
		/* フィルタリング */
		iuTestCase* curr = unit_test->list;
		while( curr != NULL )
		{
			iuTestCase_Clear(curr);
			iuTestCase_Filter(curr);
			curr = curr->next;
		}
	}
}

IUTEST_C_INL_INLINE void iuTestRun_TestProgramEnd(iuUnitTest *unit_test)
{
	iuTestEnv_ListenerEvent_OnTestProgramEnd(unit_test);

	/* 後片付け */
	/*
	iuTestEnv_SubTestListener(iuTestEnv_GetInstance(), &unit_test->def_printer);
	*/
}

IUTEST_C_INL_INLINE int iuTestRun_Run(iuUnitTest *unit_test)
{
	int repeat = IUTEST_FLAG(repeat);
	if( repeat == 0 ) return 0;
	iuTestRun_TestProgramStart(unit_test);

	{
		int iteration = 0;
		while( repeat != 0 )
		{
			if( !iuTestRun_Iteration(unit_test, iteration) )
			{
			}
			++iteration;
			if( repeat > 0 ) --repeat;
		}
	}

	iuTestRun_TestProgramEnd(unit_test);
	return iuUnitTest_Passed(unit_test) ? 0 : 1;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_Run(void)
{
	int ret=0;
	iuUnitTest *unit_test = iuUnitTest_GetInstance();
	if( unit_test->initialized_count == 0 )
	{
		ret = iuTest_ShowNotinitializedWarning();
	}
#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION || IUTEST_C_HAS_COMMANDLINE_OPTION
	else if( iuTestEnv_IsEnableFlag(IUTESTENV_SHOWVERSION) )
	{
		ret = iuTest_ShowVersion();
	}
	else if( iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP) )
	{
		ret = iuTest_ShowHelp();
	}
	else if( iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP_AND_SORRY) )
	{
		ret = iuTest_ShowHelpAndSorry();
	}
	else if( iuTestEnv_IsEnableFlag(IUTESTENV_SHOWFEATURE) )
	{
		ret = iuTest_ShowFeature();
	}
	else if( iuTestEnv_IsEnableFlag(IUTESTENV_SHOWTESTSLIST) )
	{
		ret = iuTest_ShowTestList(unit_test);
	}
#endif
	else
	{
		return iuTestRun_Run(unit_test);
	}
	iuTestEnv_SetFlag(0, ~IUTESTENV_SHOWMASK);
	if( ret == 0 )
	{
		return iuUnitTest_Passed(unit_test) ? 0 : 1;
	}
	return ret;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestCase* iuUnitTest_AddTestCase(const char* testcase_name
									, iuTestSetUpTestCase setup, iuTestTearDownTestCase teardown, iuTest_AllocTestCase pfnAlloc)
{
	iuTestCase* test_case = iuUnitTest_FindTestCase(IIUT_C_UNITTEST().list, testcase_name);
	if( test_case == NULL )
	{
		test_case = (*pfnAlloc)();
		iu_memset(test_case, 0, sizeof(iuTestCase));
		test_case->name = testcase_name;
		test_case->setup = setup;
		test_case->teardown = teardown;
		test_case->flag = 0;
		if( iuString_IsDisabledTestName(testcase_name) )
		{
			test_case->flag |= IUTESTCASE_DISABLED;
		}
		iuTestHelper_AddList(iuTestCase, IIUT_C_UNITTEST().list, test_case);
	}
	return test_case;
}

#if IUTEST_C_HAS_PARAM_TEST

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestCase* iuUnitTest_AddParameterizedTestCase(const char* testcase_name
									, iuTestSetUpTestCase setup, iuTestTearDownTestCase teardown, iuTest_AllocTestCase pfnAlloc)
{
	iuTestCase* test_case = iuUnitTest_FindTestCase(IIUT_C_UNITTEST().paramtests, testcase_name);
	if( test_case == NULL )
	{
		test_case = (*pfnAlloc)();
		iu_memset(test_case, 0, sizeof(iuTestCase));
		test_case->name = testcase_name;
		test_case->setup = setup;
		test_case->teardown = teardown;
		test_case->flag = 0;
		test_case->param = NULL;
		iuTestHelper_AddList(iuTestCase, IIUT_C_UNITTEST().paramtests, test_case);
	}
	return test_case;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_AddTestParamHolder(iuTestParamHolder* holder)
{
	if( holder == NULL ) return FALSE;

	{
		iuBOOL find = FALSE;
		iuTestHelper_FindList(iuTestParamHolder, IIUT_C_UNITTEST().param_holder, holder, find);
		/* すでに追加済み */
		if( find ) return TRUE;
	}
	iuTestHelper_AddList(iuTestParamHolder, IIUT_C_UNITTEST().param_holder, holder);
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_ParamHolderRegisterTest(void)
{
	iuTestCase* test_cases = IIUT_C_UNITTEST().paramtests;
	iuTestParamHolder* curr = IIUT_C_UNITTEST().param_holder;
	while( curr != NULL )
	{
		const char** testcase_names = curr->testcase_names;
		iuTestCase* p = iuUnitTest_FindTestCase(test_cases, curr->testcase_base_name);
		if( p != NULL )
		{
			size_t i=0;
			for( ; i < curr->elem; ++i )
			{
				iuTestCase* test_case = curr->testcases+i;
				iu_memset(test_case, 0, sizeof(iuTestCase));
				test_case->name = testcase_names[i];
				test_case->setup = p->setup;
				test_case->teardown = p->teardown;
				test_case->flag = 0;
				test_case->param = ((char*)curr->params + curr->align*i);
				if( iuString_IsDisabledTestName(test_case->name) )
				{
					test_case->flag |= IUTESTCASE_DISABLED;
				}
				iuTestHelper_AddList(iuTestCase, IIUT_C_UNITTEST().list, test_case);

				/* 新しい TestCase から参照 */
				test_case->list = p->list;
			}
		}
		curr = curr->next;
	}
}

#endif

#if IUTEST_C_HAS_MALLOC

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestCase* iuUnitTest_AllocTestCase(void)
{
	return (iuTestCase*)iu_malloc(sizeof(iuTestCase));
}

#endif

#undef IIUT_C_UNITTEST

#endif
