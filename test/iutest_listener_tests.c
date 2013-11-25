/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_listener_tests.c
 * @brief		リスナー 対応テスト
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

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

struct MyTestEventListenerInfo
{
	iuBOOL called_OnTestProgramStart;
	iuBOOL called_OnTestIterationStart;
	iuBOOL called_OnEnvironmentsSetUpStart;
	iuBOOL called_OnEnvironmentsSetUpEnd;
	iuBOOL called_OnTestCaseStart;
	iuBOOL called_OnTestStart;
	iuBOOL called_OnTestPartResult;
	iuBOOL called_OnTestRecordProperty;
	iuBOOL called_OnTestEnd;
	iuBOOL called_OnTestCaseEnd;
	iuBOOL called_OnEnvironmentsTearDownStart;
	iuBOOL called_OnEnvironmentsTearDownEnd;
	iuBOOL called_OnTestIterationEnd;
	iuBOOL called_OnTestProgramEnd;
} g_TestEventListenerInfo = { FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE };

void MyTestEvenet_OnTestProgramStart(iuUnitTest* test)
{
	IUTEST_UNUSED_VAR(test);
	g_TestEventListenerInfo.called_OnTestProgramStart = TRUE;
}
void MyTestEvenet_OnTestIterationStart(iuUnitTest* test
								, int iteration)
{
	IUTEST_UNUSED_VAR(test);
	IUTEST_UNUSED_VAR(iteration);
	g_TestEventListenerInfo.called_OnTestIterationStart = TRUE;
}
void MyTestEvenet_OnEnvironmentsSetUpStart(iuUnitTest* test)
{
	IUTEST_UNUSED_VAR(test);
	g_TestEventListenerInfo.called_OnEnvironmentsSetUpStart = TRUE;
}
void MyTestEvenet_OnEnvironmentsSetUpEnd(iuUnitTest* test)
{
	IUTEST_UNUSED_VAR(test);
	g_TestEventListenerInfo.called_OnEnvironmentsSetUpEnd = TRUE;
}
void MyTestEvenet_OnTestCaseStart(iuTestCase* test_case)
{
	IUTEST_UNUSED_VAR(test_case);
	g_TestEventListenerInfo.called_OnTestCaseStart = TRUE;
}
void MyTestEvenet_OnTestStart(iuTestCase* test_case, iuTestInfo* test_info)
{
	IUTEST_UNUSED_VAR(test_case);
	IUTEST_UNUSED_VAR(test_info);
	g_TestEventListenerInfo.called_OnTestStart = TRUE;
}
void MyTestEvenet_OnTestPartResult(iuTestPartResult* test_part_result)
{
	IUTEST_UNUSED_VAR(test_part_result);
	g_TestEventListenerInfo.called_OnTestPartResult = TRUE;
}
void MyTestEvenet_OnTestRecordProperty(iuTestProperty* test_propterty)
{
	IUTEST_UNUSED_VAR(test_propterty);
	g_TestEventListenerInfo.called_OnTestRecordProperty = TRUE;
}
void MyTestEvenet_OnTestEnd(iuTestCase* test_case, iuTestInfo* test_info)
{
	IUTEST_UNUSED_VAR(test_case);
	IUTEST_UNUSED_VAR(test_info);
	g_TestEventListenerInfo.called_OnTestEnd = TRUE;
}
void MyTestEvenet_OnTestCaseEnd(iuTestCase* test_case)
{
	IUTEST_UNUSED_VAR(test_case);
	g_TestEventListenerInfo.called_OnTestCaseEnd = TRUE;
}
void MyTestEvenet_OnEnvironmentsTearDownStart(iuUnitTest* test)
{
	IUTEST_UNUSED_VAR(test);
	g_TestEventListenerInfo.called_OnEnvironmentsTearDownStart = TRUE;
}
void MyTestEvenet_OnEnvironmentsTearDownEnd(iuUnitTest* test)
{
	IUTEST_UNUSED_VAR(test);
	g_TestEventListenerInfo.called_OnEnvironmentsTearDownEnd = TRUE;
}
void MyTestEvenet_OnTestIterationEnd(iuUnitTest* test
								, int iteration)
{
	IUTEST_UNUSED_VAR(test);
	IUTEST_UNUSED_VAR(iteration);
	g_TestEventListenerInfo.called_OnTestIterationEnd = TRUE;
}
void MyTestEvenet_OnTestProgramEnd(iuUnitTest* test)
{
	IUTEST_UNUSED_VAR(test);
	g_TestEventListenerInfo.called_OnTestProgramEnd = TRUE;
}

IUTEST(ListenerTest, Check)
{
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnTestProgramStart );
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnTestIterationStart );
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnEnvironmentsSetUpStart );
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnEnvironmentsSetUpEnd );
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnTestCaseStart );
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnTestStart );
	
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnTestEnd );
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnTestCaseEnd );
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnEnvironmentsTearDownStart );
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnEnvironmentsTearDownEnd );
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnTestIterationEnd );
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnTestProgramEnd );

	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnTestPartResult );
	IUTEST_EXPECT_RVALUE_EQ(1, 2);
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnTestPartResult );
	
	IUTEST_ASSERT_FALSE( g_TestEventListenerInfo.called_OnTestRecordProperty );
	iuTest_RecordProperty("dummy", 0);
	IUTEST_ASSERT_TRUE( g_TestEventListenerInfo.called_OnTestRecordProperty );
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	int ret = 0;
	IUTEST_INIT(&argc, argv);

#if defined(OUTPUTXML)
	// 失敗テストを含むので xml 出力しない
	IUTEST_FLAG(output) = NULL;
#endif
	{
		iuTestListener* listener = iuTestListener_NewListener(
			  MyTestEvenet_OnTestProgramStart
			, MyTestEvenet_OnTestIterationStart
			, MyTestEvenet_OnEnvironmentsSetUpStart
			, MyTestEvenet_OnEnvironmentsSetUpEnd
			, MyTestEvenet_OnTestCaseStart
			, MyTestEvenet_OnTestStart
			, MyTestEvenet_OnTestPartResult
			, MyTestEvenet_OnTestRecordProperty
			, MyTestEvenet_OnTestEnd
			, MyTestEvenet_OnTestCaseEnd
			, MyTestEvenet_OnEnvironmentsTearDownStart
			, MyTestEvenet_OnEnvironmentsTearDownEnd
			, MyTestEvenet_OnTestIterationEnd
			, MyTestEvenet_OnTestProgramEnd
			);
		if( listener != NULL )
		{
			iuUnitTest_AppendTestListener(listener);
		}
	}
	ret = IUTEST_RUN_ALL_TESTS();
	
	IUTEST_ASSERT( g_TestEventListenerInfo.called_OnTestEnd );
	IUTEST_ASSERT( g_TestEventListenerInfo.called_OnTestCaseEnd );
	IUTEST_ASSERT( g_TestEventListenerInfo.called_OnEnvironmentsTearDownStart );
	IUTEST_ASSERT( g_TestEventListenerInfo.called_OnEnvironmentsTearDownEnd );
	IUTEST_ASSERT( g_TestEventListenerInfo.called_OnTestIterationEnd );
	IUTEST_ASSERT( g_TestEventListenerInfo.called_OnTestProgramEnd );

	if( ret == 1 ) IUTEST_PRINTF("*** Successful ***\n");
	return ret != 0 ? 0 : 1;
}
