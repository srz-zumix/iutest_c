/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_disabled_tests.c
 * @brief		also_run_disabled_tests 対応テスト
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

IUTEST(DISABLED_Foo, Bar)
{
	IUTEST_ASSERT_RVALUE_EQ(2, 3);
}

IUTEST(Foo, DISABLED_Bar)
{
	IUTEST_ASSERT_RVALUE_EQ(2, 3);
}

IUTEST(Foo, Bar)
{
	IUTEST_ASSERT_RVALUE_EQ(3, 3);
}

IUTEST(Foo, Bar_DISABLED_)
{
	IUTEST_ASSERT_RVALUE_EQ(3, 3);
}

#if IUTEST_C_HAS_PARAM_TEST

IUTEST_INSTANTIATE_TEST_CASE_P(int, A, TestP, iuValues, 0, 1, 2, 3 );
IUTEST_INSTANTIATE_TEST_CASE_P(int, A, DISABLED_TestP, iuValues, 0, 1, 2, 3 );

IUTEST_P(int, TestP, DISABLED_Test)
{
	const int x = param;
	IUTEST_ASSERT_RVALUE_EQ(10, x);
}

IUTEST_P(int, DISABLED_TestP, Test)
{
	const int x = param;
	IUTEST_ASSERT_RVALUE_EQ(10, x);
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
#if defined(OUTPUTXML)
	// 失敗テストを含むので xml 出力しない
	IUTEST_FLAG(output) = NULL;
#endif
	{
		const int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
#if IUTEST_C_HAS_PARAM_TEST
		IUTEST_ASSERT( iuUnitTest_GetDisableTestCount(iuUnitTest_GetInstance()) == 10 );
#else
		IUTEST_ASSERT( iuUnitTest_GetDisableTestCount(iuUnitTest_GetInstance()) == 2 );
#endif
	}
	
	{
		int ret = 0;
		IUTEST_FLAG(also_run_disabled_tests) = TRUE;
		ret = IUTEST_RUN_ALL_TESTS();
#if IUTEST_C_HAS_PARAM_TEST
		IUTEST_ASSERT( iuUnitTest_GetDisableTestCount(iuUnitTest_GetInstance()) == 10 );
		IUTEST_ASSERT( iuUnitTest_GetTestToRunCount(iuUnitTest_GetInstance()) == 12 );
		IUTEST_ASSERT( iuUnitTest_GetFailureTestCount(iuUnitTest_GetInstance()) == 10 );
		IUTEST_ASSERT( iuUnitTest_GetTotalTestCount(iuUnitTest_GetInstance()) == 12 );
#else
		IUTEST_ASSERT( iuUnitTest_GetDisableTestCount(iuUnitTest_GetInstance()) == 2 );
		IUTEST_ASSERT( iuUnitTest_GetTestToRunCount(iuUnitTest_GetInstance()) == 4 );
		IUTEST_ASSERT( iuUnitTest_GetFailureTestCount(iuUnitTest_GetInstance()) == 2 );
		IUTEST_ASSERT( iuUnitTest_GetTotalTestCount(iuUnitTest_GetInstance()) == 4 );
#endif
		if( ret == 0 ) return 1;
	}

	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}
