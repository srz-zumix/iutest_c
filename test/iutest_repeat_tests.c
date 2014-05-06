/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_repeat_tests.c
 * @brief		ŒJ‚è•Ô‚µ‘Î‰žƒeƒXƒg
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

int g_foo_bar = 0;
int g_hoge_fuga = 0;

IUTEST(Foo, Bar)
{
	++g_foo_bar;
}

IUTEST(Hoge, Fuga)
{
	++g_hoge_fuga;
}

void ClearCounter(void)
{
	g_foo_bar = 0;
	g_hoge_fuga = 0;
}

void CheckCount(int expected)
{
	IUTEST_EXPECT_EQ(expected, g_foo_bar);
	IUTEST_EXPECT_EQ(expected, g_hoge_fuga);
}

iuBOOL RunTest(void)
{
	ClearCounter();
	IUTEST_RUN_ALL_TESTS();
	return iuUnitTest_Passed(iuUnitTest_GetInstance());
}

iuBOOL RepeatTest(int repeat)
{
	IUTEST_FLAG(repeat) = repeat;
	return RunTest();
}

iuBOOL RepeatTestUnspecified(void)
{
	RunTest();
	CheckCount(1);
	return iuUnitTest_Passed(iuUnitTest_GetInstance());
}

iuBOOL RepeatTestNonFilter(int repeat)
{
	if( !RepeatTest(repeat) ) return FALSE;
	CheckCount(repeat);
	return iuUnitTest_Passed(iuUnitTest_GetInstance());
}

iuBOOL RepeatTestWithEmpyFilter(int repeat)
{
	IUTEST_FLAG(filter) = "None";
	if( !RepeatTest(repeat) ) return FALSE;
	CheckCount(0);
	return iuUnitTest_Passed(iuUnitTest_GetInstance());
}

iuBOOL RepeatTestWithFilter(int repeat)
{
	IUTEST_FLAG(filter) = "*Bar*";
	if( !RepeatTest(repeat) ) return FALSE;
	IUTEST_EXPECT_EQ(repeat, g_foo_bar);
	IUTEST_EXPECT_EQ(0, g_hoge_fuga);
	return iuUnitTest_Passed(iuUnitTest_GetInstance());
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	
	IUTEST_ASSERT( RepeatTestUnspecified() );
	IUTEST_ASSERT( RepeatTestNonFilter(0) );
	IUTEST_ASSERT( RepeatTestNonFilter(2) );
	IUTEST_ASSERT( RepeatTestNonFilter(10) );

	IUTEST_ASSERT( RepeatTestWithEmpyFilter(2) );
	IUTEST_ASSERT( RepeatTestWithEmpyFilter(3) );
	
	IUTEST_ASSERT( RepeatTestWithFilter(3) );

	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}

