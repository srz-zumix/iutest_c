/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_filter_tests.c
 * @brief		filter 対応テスト
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

#define NOT_RAN 0
#define RAN 1

static int state[6];

void SetUp(void)
{
	iuUInt32 i=0;
	for( ; i < IUTEST_PP_COUNTOF(state); ++i )
	{
		state[i] = NOT_RAN;
	}
}

IUTEST(Test, Hoge)
{
	state[0] = RAN;
}

IUTEST(Hoge, Test)
{
	state[1] = RAN;
}

IUTEST(Foo, Bar)
{
	state[2] = RAN;
}

IUTEST(Foo, Baz)
{
	state[3] = RAN;
}

IUTEST(Foo, BarTest)
{
	state[4] = RAN;
}

IUTEST(Foo, Qux)
{
	state[5] = RAN;
}

iuBOOL FilterTest(const char* filter
	, int ranTestHoge
	, int ranHogeTest
	, int ranFooBar
	, int ranFooBaz
	, int ranFooBarTest
	, int ranFooQux)
{
	IUTEST_FLAG(filter) = filter;
	const int ret = IUTEST_RUN_ALL_TESTS();
	
	if( ret != 0 ) return FALSE;

	IUTEST_EXPECT_LVALUE_EQ( ranTestHoge  , state[0] );
	IUTEST_EXPECT_LVALUE_EQ( ranHogeTest  , state[1] );
	IUTEST_EXPECT_LVALUE_EQ( ranFooBar    , state[2] );
	IUTEST_EXPECT_LVALUE_EQ( ranFooBaz    , state[3] );
	IUTEST_EXPECT_LVALUE_EQ( ranFooBarTest, state[4] );
	IUTEST_EXPECT_LVALUE_EQ( ranFooQux    , state[5] );
	
	if( iuUnitTest_IsFaild(iuUnitTest_GetInstance()) ) return FALSE;
	return TRUE;
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
	iuUnitTest_AddGlobalEnvironmentSetUp(SetUp);

	if( !FilterTest("-*Test*"
		, NOT_RAN
		, NOT_RAN
		, RAN
		, RAN
		, NOT_RAN
		, RAN
	) ) {
		return 1;
	}
	
	if( !FilterTest("Foo.Bar"
		, NOT_RAN
		, NOT_RAN
		, RAN
		, NOT_RAN
		, NOT_RAN
		, NOT_RAN
	) ) {
		return 1;
	}

	if( !FilterTest("***.Bar"
		, NOT_RAN
		, NOT_RAN
		, RAN
		, NOT_RAN
		, NOT_RAN
		, NOT_RAN
	) ) {
		return 1;
	}

	if( !FilterTest("???.Ba?"
		, NOT_RAN
		, NOT_RAN
		, RAN
		, RAN
		, NOT_RAN
		, NOT_RAN
	) ) {
		return 1;
	}

	if( !FilterTest("???.Ba?"
		, NOT_RAN
		, NOT_RAN
		, RAN
		, RAN
		, NOT_RAN
		, NOT_RAN
	) ) {
		return 1;
	}

	if( !FilterTest("Foo.Ba*-*Test*"
		, NOT_RAN
		, NOT_RAN
		, RAN
		, RAN
		, NOT_RAN
		, NOT_RAN
	) ) {
		return 1;
	}

	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}
