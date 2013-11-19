/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_disabled_tests.c
 * @brief		also_run_disabled_tests 対応テスト
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
		IUTEST_ASSERT( iuUnitTest_GetDisableTestCount(iuUnitTest_GetInstance()) == 2 );
	}
	
	{
		int ret = 0;
		IUTEST_FLAG(also_run_disabled_tests) = TRUE;
		ret = IUTEST_RUN_ALL_TESTS();
		IUTEST_ASSERT( iuUnitTest_GetDisableTestCount(iuUnitTest_GetInstance()) == 2 );
		IUTEST_ASSERT( iuUnitTest_GetTestToRunCount(iuUnitTest_GetInstance()) == 4 );
		IUTEST_ASSERT( iuUnitTest_GetFailureTestCount(iuUnitTest_GetInstance()) == 2 );
		IUTEST_ASSERT( iuUnitTest_GetTotalTestCount(iuUnitTest_GetInstance()) == 4 );
		if( ret == 0 ) return 1;
	}

	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}
