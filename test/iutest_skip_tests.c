/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_skip_tests.c
 * @brief		IUTEST_SKIP テスト
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

static iuBOOL skip_check = TRUE;

IUTEST(DISABLED_SkipTest, A)
{
}

IUTEST(SkipTest, CanSkip)
{
	IUTEST_SKIP();
	IUTEST_EXPECT_TRUE(FALSE);
}

IUTEST(SkipTest, Failed)
{
	IUTEST_EXPECT_TRUE(FALSE);
	IUTEST_SKIP();
	skip_check = FALSE;
	IUTEST_EXPECT_TRUE(FALSE);
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
		if( ret == 0 ) return 1;
	}
	IUTEST_ASSERT( iuUnitTest_GetTestToRunCount(iuUnitTest_GetInstance()) == 2 );
	IUTEST_ASSERT( iuUnitTest_GetRunSkippedTestCount(iuUnitTest_GetInstance()) == 1 );
	IUTEST_ASSERT( iuUnitTest_GetSkipTestCount(iuUnitTest_GetInstance()) == 2 );
	IUTEST_ASSERT( iuUnitTest_GetSuccessfulTestCount(iuUnitTest_GetInstance()) == 0 );
	IUTEST_ASSERT( iuUnitTest_GetFailureTestCount(iuUnitTest_GetInstance()) == 1 );
	IUTEST_ASSERT( skip_check );
	printf("*** Successful ***\n");
	return 0;
}
