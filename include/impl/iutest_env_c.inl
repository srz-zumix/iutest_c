/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_env_c.inl
 * @brief		iris unit test environment
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_ENV_C_INL_DC5C5193_7081_4FEF_B668_283CAEFA1F77_
#define INCG_IRIS_IUTEST_ENV_C_INL_DC5C5193_7081_4FEF_B668_283CAEFA1F77_

/* include ===========================================================*/
#include "../iutest_env_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestEnv* iuTestEnv_GetInstance(void)
{
	return &IIUT_C_TESTENV();
}

IUTEST_C_INL_INLINE iuTestGlobalEnvSetUp*	iuTestEnv_AllocGlobalEnvSetUp(void)
{
#if IUTEST_C_HAS_MALLOC
	return (iuTestGlobalEnvSetUp*)iu_malloc(sizeof(iuTestGlobalEnvSetUp));
#else
	iuTestGlobalEnvSetUp* ptr = NULL;
	IUTEST_C_AllocByPool(ptr, iuTestGlobalEnvSetUp, IUTEST_C_GLOBALENVSETUP_POOL_COUNT);
	return ptr;
#endif
}

IUTEST_C_INL_INLINE iuTestGlobalEnvTearDown*	iuTestEnv_AllocGlobalEnvTearDown(void)
{
#if IUTEST_C_HAS_MALLOC
	return (iuTestGlobalEnvTearDown*)iu_malloc(sizeof(iuTestGlobalEnvTearDown));
#else
	iuTestGlobalEnvTearDown* ptr = NULL;
	IUTEST_C_AllocByPool(ptr, iuTestGlobalEnvTearDown, IUTEST_C_GLOBALENVTEARDOWN_POOL_COUNT);
	return ptr;
#endif
}

#if IUTEST_C_HAS_STDARG
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_SetVPrintfFunction(iuTestEnv* test_env, iuVPrintf proc)
{
	test_env->pfnvprintf = proc;
}
#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestEnv_AddTestListener(iuTestEnv* test_env, iuTestListener* test_listener)
{
	if( test_env == NULL ) return FALSE;
	iuTestHelper_AddList(iuTestListener, test_env->listeners, test_listener);
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuTestListener* iuTestEnv_SubTestListener(iuTestEnv* test_env, iuTestListener* test_listener)
{
	if( test_env == NULL ) return NULL;
	if( test_listener == NULL ) return NULL;
	{
		iuTestListener *top = test_env->listeners;
		if( top == NULL ) return NULL;
		if( top == test_listener )
		{
			test_env->listeners = test_listener->next;
			test_listener->next = NULL;
			return test_listener;
		}
		{
			iuTestListener *prev = top;
			iuTestListener *curr = top->next;
			while( curr != NULL )
			{
				if( curr == test_listener )
				{
					prev->next = test_listener->next;
					test_listener->next = NULL;
					return test_listener;
				}
				prev = curr;
				curr = curr->next;
			}
		}
	}
	return NULL;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_AddGlobalEnvironmentSetUp(iuTestEnv* test_env, iuGlobalEnvironmentSetUp func)
{
	if( test_env == NULL ) return FALSE;
	{
		iuTestGlobalEnvSetUp* elem = iuTestEnv_AllocGlobalEnvSetUp();
		if( elem == NULL ) return FALSE;
		elem->func = func;
		elem->next = NULL;
		iuTestHelper_AddList(iuTestGlobalEnvSetUp, test_env->env_setup, elem);
	}
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_AddGlobalEnvironmentTearDown(iuTestEnv* test_env, iuGlobalEnvironmentTearDown func)
{
	if( test_env == NULL ) return FALSE;
	{
		iuTestGlobalEnvTearDown* elem = iuTestEnv_AllocGlobalEnvTearDown();
		if( elem == NULL ) return FALSE;
		elem->func = func;
		elem->next = NULL;
		iuTestHelper_AddList(iuTestGlobalEnvTearDown, test_env->env_teardown, elem);
	}
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_GlobalEnvironmentSetUp(void)
{
	iuTestGlobalEnvSetUp* curr = IIUT_C_TESTENV().env_setup;
	while( curr != NULL )
	{
		if( curr->func != NULL )
		{
			(*curr->func)();
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_GlobalEnvironmentTearDown(void)
{
	iuTestGlobalEnvTearDown* curr = IIUT_C_TESTENV().env_teardown;
	while( curr != NULL )
	{
		if( curr->func != NULL )
		{
			(*curr->func)();
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestProgramStart(struct iuUnitTest_t* unit_test)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestProgramStart != NULL )
		{
			(*curr->OnTestProgramStart)(unit_test);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestIterationStart(struct iuUnitTest_t* unit_test, int iteration)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestIterationStart != NULL )
		{
			(*curr->OnTestIterationStart)(unit_test, iteration);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsSetUpStart(struct iuUnitTest_t* unit_test)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnEnvironmentsSetUpStart != NULL )
		{
			(*curr->OnEnvironmentsSetUpStart)(unit_test);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsSetUpEnd(struct iuUnitTest_t* unit_test)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnEnvironmentsSetUpEnd != NULL )
		{
			(*curr->OnEnvironmentsSetUpEnd)(unit_test);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestCaseStart(struct iuTestCase_t* test_case)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestCaseStart != NULL )
		{
			(*curr->OnTestCaseStart)(test_case);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestStart(struct iuTestCase_t* test_case, struct iuTestInfo_t* test_info)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestStart != NULL )
		{
			(*curr->OnTestStart)(test_case, test_info);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestPartResult(struct iuTestPartResult_t* test_part_result)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestPartResult != NULL )
		{
			(*curr->OnTestPartResult)(test_part_result);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestRecordProperty(struct iuTestProperty_t* test_property)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestRecordProperty != NULL )
		{
			(*curr->OnTestRecordProperty)(test_property);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestEnd(struct iuTestCase_t* test_case, struct iuTestInfo_t* test_info)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestEnd != NULL )
		{
			(*curr->OnTestEnd)(test_case, test_info);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void IUTEST_ATTRIBUTE_UNUSED_ iuTestEnv_ListenerEvent_OnTestCaseEnd(struct iuTestCase_t* test_case)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestCaseEnd != NULL )
		{
			(*curr->OnTestCaseEnd)(test_case);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsTearDownStart(struct iuUnitTest_t* unit_test)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnEnvironmentsTearDownStart != NULL )
		{
			(*curr->OnEnvironmentsTearDownStart)(unit_test);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsTearDownEnd(struct iuUnitTest_t* unit_test)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnEnvironmentsTearDownEnd != NULL )
		{
			(*curr->OnEnvironmentsTearDownEnd)(unit_test);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestIterationEnd(struct iuUnitTest_t* unit_test, int iteration)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestIterationEnd != NULL )
		{
			(*curr->OnTestIterationEnd)(unit_test, iteration);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestProgramEnd(struct iuUnitTest_t* unit_test)
{
	iuTestListener* curr = IIUT_C_TESTENV().listeners;
	while( curr != NULL )
	{
		if( curr->OnTestProgramEnd != NULL )
		{
			(*curr->OnTestProgramEnd)(unit_test);
		}
		curr = curr->next;
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_SetUp(iuTestEnv* test_env)
{
	iuUInt32 seed = test_env->option.random_seed;
	if( seed == 0 )
	{
		seed = iuTest_GetIndefiniteValue();
	}
	iuTestRandom_SetSeed(&test_env->random_context, seed);
	test_env->current_seed = seed;
}

IUTEST_C_INL_INLINE const char* iuTestEnv_ParseOptionSettingStr(const char* opt)
{
	const char* eq = iu_strchr(opt, '=');
	if( eq == NULL ) return NULL;
	return eq+1;
}

IUTEST_C_INL_INLINE void iuTestEnv_SetFlag(int enable, int mask)
{
	IIUT_C_TESTENV().flag |= enable;
	IIUT_C_TESTENV().flag &= mask;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableRunDisabledTests(void)
{
	return IIUT_C_TESTENV().option.also_run_disabled_tests;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableShuffleTests(void)
{
	return IIUT_C_TESTENV().option.shuffle;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableBreakOnFailure(void)
{
	return IIUT_C_TESTENV().option.break_on_failure;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnablePrintTime(void)
{
	return IIUT_C_TESTENV().option.print_time;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableOutputXml(void)
{
	const char* output = IIUT_C_TESTENV().option.output;
	if(output == NULL) return FALSE;
	if(iu_strstr(output, "xml") != output) return FALSE;
	return TRUE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestEnv_IsEnableFlag(int mask)
{
	return IIUT_C_TESTENV().flag & mask ? TRUE : FALSE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuTestEnve_GetCurrentRandomSeed(void)
{
	return IIUT_C_TESTENV().current_seed;
}

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION || IUTEST_C_HAS_COMMANDLINE_OPTION

IUTEST_C_INL_INLINE iuBOOL iuTestEnv_IsYesOption(const char* option)
{
	if( iuString_IsStringCaseEqual(option, "yes")
		|| iuString_IsStringCaseEqual(option, "y")
		|| iuString_IsStringCaseEqual(option, "on")
		|| iuString_IsStringCaseEqual(option, "true")
		|| iuString_IsStringCaseEqual(option, "t")
		|| iuString_IsStringEqual(option, "1") )
	{
		return TRUE;
	}
	return FALSE;
}

IUTEST_C_INL_INLINE iuBOOL iuTestEnv_IsNoOption(const char* option)
{
	if( iuString_IsStringCaseEqual(option, "no")
		|| iuString_IsStringCaseEqual(option, "n")
		|| iuString_IsStringCaseEqual(option, "off")
		|| iuString_IsStringCaseEqual(option, "false")
		|| iuString_IsStringCaseEqual(option, "f")
		|| iuString_IsStringEqual(option, "0") )
	{
		return TRUE;
	}
	return FALSE;
}

IUTEST_C_INL_INLINE int iuTestEnv_ParseYesNoOption(const char* option)
{
	if( option == NULL ) return -1;
	if( iuTestEnv_IsYesOption(option) ) return 1;
	if( iuTestEnv_IsNoOption(option) ) return 0;
	return -1;
}

IUTEST_C_INL_INLINE iuBOOL	iuTestEnv_ParseColorOption(const char* option)
{
	if( option == NULL ) return FALSE;

	if( iuTestEnv_IsYesOption(option) )
	{
		iuTestEnv_SetFlag(IUTESTENV_CONSOLECOLOR_ON, ~IUTESTENV_CONSOLECOLOR_OFF);
	}
	else if( iuTestEnv_IsNoOption(option) )
	{
		iuTestEnv_SetFlag(IUTESTENV_CONSOLECOLOR_OFF, ~IUTESTENV_CONSOLECOLOR_ON);
	}
	else if( iuString_IsStringCaseEqual(option, "auto") )
	{
		iuTestEnv_SetFlag(0, ~(IUTESTENV_CONSOLECOLOR_ON|IUTESTENV_CONSOLECOLOR_OFF));
	}
	else if( iuString_IsStringCaseEqual(option, "ansi") )
	{
		iuTestEnv_SetFlag(IUTESTENV_CONSOLECOLOR_ON|IUTESTENV_CONSOLECOLOR_ANSI, ~IUTESTENV_CONSOLECOLOR_OFF);
	}
	else
	{
		return FALSE;
	}
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestEnv_ParseYesNoFlagOption(const char* option, iuBOOL* flag, int def)
{
	const char* str = iuTestEnv_ParseOptionSettingStr(option);
	int yesno = str != NULL ? iuTestEnv_ParseYesNoOption(str) : def;
	if( yesno < 0 )
	{
		return FALSE;
	}
	*flag = yesno;
	return TRUE;
}

IUTEST_C_INL_INLINE iuBOOL	iuTestEnv_ParseOutputOption(const char* option)
{
	IIUT_C_TESTENV().option.output = option;
	if( option == NULL )
	{
		return FALSE;
	}
	return TRUE;
}

#endif

#if IUTEST_C_HAS_COMMANDLINE_OPTION

IUTEST_C_INL_INLINE iuBOOL	iuTestEnv_ParseCommandLineElemA(const char* arg)
{
	iuBOOL find = FALSE;
	if( arg == NULL ) return FALSE;
	if( *arg == '-' )
	{
		find = TRUE;
		++arg;
		if( *arg == '-' )
		{
			iuBOOL iuopt = TRUE;
			++arg;
			{
				const char* base = arg;
				const char* prefix = "iutest_";
				size_t i=0, n=iu_strlen(prefix);
				for( i=0; i < n; ++i, ++arg )
				{
					if( *arg != prefix[i] )
					{
						iuopt = FALSE;
						arg = base;
						break;
					}
				}
			}
			if( iuopt )
			{
				if( iu_strstr(arg, "filter") == arg )
				{
					const char* opt = iuTestEnv_ParseOptionSettingStr(arg);
					if( opt != NULL )
					{
						IUTEST_FLAG(filter) = opt;
					}
				}
				else if( iu_strstr(arg, "output") == arg )
				{
					find = iuTestEnv_ParseOutputOption(iuTestEnv_ParseOptionSettingStr(arg));
				}
				else if( iu_strstr(arg, "color") == arg )
				{
					find = iuTestEnv_ParseColorOption(iuTestEnv_ParseOptionSettingStr(arg));
				}
				else if( iuString_IsStringEqual(arg, "list_tests") )
				{
					iuTestEnv_SetFlag(IUTESTENV_SHOWTESTSLIST, -1);
				}
				else if( iuString_IsStringEqual(arg, "also_run_disabled_tests") )
				{
					IUTEST_FLAG(also_run_disabled_tests) = TRUE;
				}
				else if( iu_strstr(arg, "break_on_failure") == arg )
				{
					find = iuTestEnv_ParseYesNoFlagOption(arg, &IIUT_C_TESTENV().option.break_on_failure, 1);
				}
				else if( iuString_IsStringEqual(arg, "shuffle") )
				{
					IUTEST_FLAG(shuffle) = TRUE;
				}
				else if( iu_strstr(arg, "random_seed") == arg )
				{
					const char* opt = iuTestEnv_ParseOptionSettingStr(arg);
					if( opt != NULL )
					{
						IUTEST_FLAG(random_seed) = (unsigned int)iuString_ToInt(opt);
					}
					else
					{
						find = FALSE;
					}
				}
				else if( iu_strstr(arg, "print_time") == arg )
				{
					find = iuTestEnv_ParseYesNoFlagOption(arg, &IIUT_C_TESTENV().option.print_time, -1);
				}
				else if( iu_strstr(arg, "repeat") == arg )
				{
					const char* opt = iuTestEnv_ParseOptionSettingStr(arg);
					if( opt != NULL )
					{
						IUTEST_FLAG(repeat) = (int)iuString_ToInt(opt);
					}
					else
					{
						find = FALSE;
					}
				}
 				else
				{
					find = FALSE;
					iuTestEnv_SetFlag(IUTESTENV_SHOWHELP, -1);
				}
			}
			else
			{
				if( iuString_IsStringEqual(arg, "version") )
				{
					iuTestEnv_SetFlag(IUTESTENV_SHOWVERSION, -1);
				}
				else if( iuString_IsStringEqual(arg, "help") )
				{
					iuTestEnv_SetFlag(IUTESTENV_SHOWHELP, -1);
				}
				else if( iuString_IsStringEqual(arg, "feature") )
				{
					iuTestEnv_SetFlag(IUTESTENV_SHOWFEATURE, -1);
				}
 				else
				{
					find = FALSE;
				}
			}
		}
		else
		{
			if( iuString_IsStringEqual(arg, "v") )
			{
				iuTestEnv_SetFlag(IUTESTENV_SHOWVERSION, -1);
			}
			else if( iuString_IsStringEqual(arg, "h")
				|| iuString_IsStringEqual(arg, "?") )
			{
				iuTestEnv_SetFlag(IUTESTENV_SHOWHELP, -1);
			}
 			else
			{
				find = FALSE;
			}
		}
	}
	return find;
}

IUTEST_C_INL_INLINE void	iuTestEnv_ParseCommandLineA(int* pargc, char** argv)
{
	if( pargc == NULL ) return;
	if( argv == NULL ) return;

	{
		int i=0;
		int argc = *pargc;
		for( i=0; i < argc; )
		{
			if( iuTestEnv_ParseCommandLineElemA(argv[i]) )
			{
				int k=0;
				--argc;
				/* 見つかった場合、オプションを末尾に移動 */
				for( k=i; k < argc; ++k )
				{
					char* tmp = argv[k];
					argv[k] = argv[k+1];
					argv[k+1] = tmp;
				}
			}
			else
			{
				++i;
			}
		}
		*pargc = argc;
	}
}

#if IUTEST_C_HAS_WCHAR_T
IUTEST_C_INL_INLINE iuBOOL	iuTestEnv_ParseCommandLineElemW(const wchar_t* arg)
{
	iuBOOL find = FALSE;
	if( arg == NULL ) return FALSE;
	if( *arg == L'-' )
	{
		find = TRUE;
		++arg;
		if( *arg == L'-' )
		{
			iuBOOL iuopt = TRUE;
			++arg;
			{
				const wchar_t* base = arg;
				const wchar_t* prefix = L"iutest_";
				size_t i=0, n=iu_wcslen(prefix);
				for( i=0; i < n; ++i, ++arg )
				{
					if( *arg != prefix[i] )
					{
						iuopt = FALSE;
						arg = base;
						break;
					}
				}
			}
			if( iuopt )
			{
				/* not supproted */
				iuTestEnv_SetFlag(IUTESTENV_SHOWHELP_AND_SORRY, -1);
			}
		}
	}
	return find;
}

IUTEST_C_INL_INLINE void	iuTestEnv_ParseCommandLineW(int* pargc, wchar_t** argv)
{
	if( pargc == NULL ) return;
	if( argv == NULL ) return;

	{
		int i=0;
		int argc = *pargc;
		for( i=0; i < argc; )
		{
			if( iuTestEnv_ParseCommandLineElemW(argv[i]) )
			{
				int k=0;
				--argc;
				/* 見つかった場合、オプションを末尾に移動 */
				for( k=i; k < argc; ++k )
				{
					wchar_t* tmp = argv[k];
					argv[k] = argv[k+1];
					argv[k+1] = tmp;
				}
			}
			else
			{
				++i;
			}
		}
		*pargc = argc;
	}
}
#endif

#endif

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION

IUTEST_C_INL_INLINE void iuTestEnv_LoadEnviromentVariable(void)
{
#if !defined(IUTEST_C_NO_GETENV)
	{
		int var = 0;
		if( iuTestOS_GetEnvironmentInt("IUTEST_C_ALSO_RUN_DISABLED_TESTS", &var) )
		{
			IUTEST_FLAG(also_run_disabled_tests) = var ? TRUE : FALSE;
		}
		if( iuTestOS_GetEnvironmentInt("IUTEST_C_SHUFFLE", &var) )
		{
			IUTEST_FLAG(shuffle) = var ? TRUE : FALSE;
		}
		if( iuTestOS_GetEnvironmentInt("IUTEST_C_BREAK_ON_FAILURE", &var) )
		{
			IUTEST_FLAG(break_on_failure) = var ? TRUE : FALSE;
		}
		if( iuTestOS_GetEnvironmentInt("IUTEST_C_RANDOM_SEED", &var) )
		{
			IUTEST_FLAG(random_seed) = (unsigned int)var;
		}
		if( iuTestOS_GetEnvironmentInt("IUTEST_C_PRINT_TIME", &var) )
		{
			IUTEST_FLAG(print_time) = var ? TRUE : FALSE;
		}
		if( iuTestOS_GetEnvironmentInt("IUTEST_C_REPEAT", &var) )
		{
			IUTEST_FLAG(repeat) = var;
		}
	}
	{
		char var[128];
		if( iuTestOS_GetEnvironmentVariable("IUTEST_C_COLOR", var, 128) )
		{
			iuTestEnv_ParseColorOption(var);
		}
	}
	{
		char path[260+32];
		if( iuTestOS_GetEnvironmentVariable("IUTEST_C_OUTPUT", path, sizeof(path)) )
		{
			iuTestEnv_ParseOutputOption(path);
		}
		if( iuTestOS_GetEnvironmentVariable("IUTEST_C_FILTER", path, sizeof(path)) )
		{
			static char f[260+32];
			iu_strcpy(f, path);
			IUTEST_FLAG(filter) = f;
		}
	}
#endif
}

#endif

#endif
