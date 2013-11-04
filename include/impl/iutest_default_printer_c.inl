/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_default_printer_c.inl
 * @brief		iris unit test デフォルト出力 イベントリスナー ファイル
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
#ifndef INCG_IRIS_iutest_default_printer_C_INL_FA31CAB7_32CB_4764_89FC_6AC5C0D25385_
#define INCG_IRIS_iutest_default_printer_C_INL_FA31CAB7_32CB_4764_89FC_6AC5C0D25385_

/* include ===========================================================*/
#include "../listener/iutest_default_printer_c.h"

#if IUTEST_C_HAS_CONSOLEOUT

/* function ==========================================================*/
IUTEST_C_INL_INLINE void iuTestDefaultPrinter_OnTestProgramStart(struct iuUnitTest_t *unit_test)
{
	IUTEST_UNUSED_VAR(unit_test);
	/* フィルタリング */
	if( iuTestEnv_IsEnableFlag(IUTESTENV_FILTERING_TESTS) )
	{
		iuConsole_ColorOutput(PRINT_YELLOW, "Note: iutest filter = %s\n", IUTEST_FLAG(filter));
	}
}

IUTEST_C_INL_INLINE void iuTestDefaultPrinter_OnTestIterationStart(struct iuUnitTest_t *unit_test, int iteration)
{
	if( IUTEST_FLAG(repeat) > 1 )
	{
		iuConsole_Output("\nRepeating all tests (iteration %d) . . .\n\n", iteration+1);
	}
	iuConsole_ColorOutput(PRINT_GREEN, "[==========] ");
	iuConsole_Output("Running %d tests from %d test cases.\n", iuUnitTest_GetTestToRunCount(unit_test), iuUnitTest_GetTestCaseToRunCount(unit_test) );
}

IUTEST_C_INL_INLINE void	iuTestDefaultPrinter_OnTestCaseStart(struct iuTestCase_t *test_case)
{
	iuConsole_ColorOutput(PRINT_GREEN, "[----------] ");
	iuConsole_Output("%d tests from %s\n", iuTestCase_GetTestToRunCount(test_case), test_case->name );
}

IUTEST_C_INL_INLINE void	iuTestDefaultPrinter_OnTestStart(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info)
{
	iuConsole_ColorOutput(PRINT_GREEN, "[ RUN      ] ");
	iuConsole_Output("%s.%s\n", test_case->name, test_info->name);
}

IUTEST_C_INL_INLINE void	iuTestDefaultPrinter_OnTestPartResult(struct iuTestPartResult_t *test_part_result)
{
	char buf[1024];
	iuTestResult_PartMessage(buf, test_part_result);
	iuConsole_Print(buf);
#if		defined(_MSC_VER) && !defined(IUTEST_OS_WINDOWS_MOBILE)
	OutputDebugStringA(buf);
#endif
}

IUTEST_C_INL_INLINE void	iuTestDefaultPrinter_OnTestRecordProperty(struct iuTestProperty_t *test_property)
{
	IUTEST_UNUSED_VAR(test_property);
}

IUTEST_C_INL_INLINE void	iuTestDefaultPrinter_OnTestEnd(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info)
{
	if( iuTestResult_IsFailed(&test_info->result) )
	{
		iuConsole_ColorOutput(PRINT_RED  , "[  FAILED  ] ");
	}
	else
	{
		iuConsole_ColorOutput(PRINT_GREEN, "[       OK ] ");
	}
	if( iuTestEnv_IsEnablePrintTime() )
	{
		iuConsole_Output("%s.%s (%dms)\n", test_case->name, test_info->name, test_info->result.elapsedmsec);
	}
	else
	{
		iuConsole_Output("%s.%s\n", test_case->name, test_info->name);
	}
}

IUTEST_C_INL_INLINE void	iuTestDefaultPrinter_OnTestCaseEnd(struct iuTestCase_t *test_case)
{
	iuConsole_ColorOutput(PRINT_GREEN, "[----------] ");
	if( iuTestEnv_IsEnablePrintTime() )
	{
		iuConsole_Output("%d tests from %s (%dms total)\n\n", iuTestCase_GetTestToRunCount(test_case), test_case->name, test_case->elapsedmsec );
	}
	else
	{
		iuConsole_Output("%d tests from %s\n\n", iuTestCase_GetTestToRunCount(test_case), test_case->name );
	}
}

IUTEST_C_INL_INLINE void iuTestDefaultPrinter_OnTestIterationEnd(struct iuUnitTest_t *unit_test, int iteration)
{
	IUTEST_UNUSED_VAR(iteration);

	iuConsole_ColorOutput(PRINT_GREEN, "[==========] ");
	if( iuTestEnv_IsEnablePrintTime() )
	{
		iuConsole_Output("%d tests from %d testcase ran. (%dms total)\n"
			, iuUnitTest_GetTestToRunCount(unit_test), iuUnitTest_GetTestCaseToRunCount(unit_test), unit_test->elapsedmsec );
	}
	else
	{
		iuConsole_Output("%d tests from %d testcase ran.\n", iuUnitTest_GetTestToRunCount(unit_test), iuUnitTest_GetTestCaseToRunCount(unit_test) );
	}

	{
		{
			iuConsole_ColorOutput(PRINT_GREEN, "[  PASSED  ] ");
			iuConsole_Output("%d tests.\n", iuUnitTest_GetSuccessfulTestCount(unit_test) );
		}
		{
			int disabled = iuUnitTest_GetDisableTestCount(unit_test);
			if( disabled > 0 )
			{
				iuConsole_ColorOutput(PRINT_YELLOW, "[ DISABLED ] ");
				iuConsole_Output("%d tests.\n", disabled );
			}
		}
		{
			int failed_num = iuUnitTest_GetFailureTestCount(unit_test);
			if( failed_num > 0 )
			{
				iuConsole_ColorOutput(PRINT_RED, "[  FAILED  ] ");
				iuConsole_Output("%d tests.\n", failed_num );

				{
					iuTestCase *test_case = unit_test->list;
					while( test_case != NULL )
					{
						iuTestInfo *test_info = test_case->list;
						while( test_info != NULL )
						{
							if( iuTestInfo_HasFailure(test_info) )
							{
								iuConsole_ColorOutput(PRINT_RED, "[  FAILED  ] ");
								iuConsole_Output("%s.%s\n", test_case->name, test_info->name);
							}
							test_info = test_info->next;
						}
						test_case = test_case->next;
					}
				}
				iuConsole_Output("\n%d FAILED %s.\n", failed_num, failed_num == 1 ? "TEST" : "TESTS" );
			}
		}
	}
}

IUTEST_C_INL_INLINE void iuTestDefaultPrinter_OnTestProgramEnd(struct iuUnitTest_t *unit_test)
{
	IUTEST_UNUSED_VAR(unit_test);
}

#endif

#endif
