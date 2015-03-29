/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_commandline_tests.c
 * @brief		CommandLine test
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2014-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

IUTEST(Foo, NotRun)
{
	int a=1;
	IUTEST_ASSERT_EQ(0, a);
}

#ifdef UNICODE
#  define DECAL_ARGV(cmd) wchar_t* targv[] = { argv[0], L cmd }
#  define DECAL_ARGV_BEGIN() wchar_t* targv[] = { argv[0]
#  define DECAL_ARGV_PARAM(cmd) , L cmd
#else
#  define DECAL_ARGV(cmd) char* targv[] = { argv[0],   cmd }
#  define DECAL_ARGV_BEGIN() char* targv[] = { argv[0]
#  define DECAL_ARGV_PARAM(cmd) , cmd
#endif
#define DECAL_ARGV_END() };


#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	(void)argc;
#if defined(OUTPUTXML)
	// 実行対象テストがないので xml 出力しない
	IUTEST_FLAG(output) = NULL;
#endif

	{
		int targc = 2;
		DECAL_ARGV("--help");
		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}
	{
		int targc = 2;
		DECAL_ARGV("--version");

		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP));

		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}
	{
		int targc = 2;
		DECAL_ARGV("--feature");
		
		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWVERSION));

		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}
	{
		int targc = 4;
		DECAL_ARGV_BEGIN()
		DECAL_ARGV_PARAM("test1")
		DECAL_ARGV_PARAM("-v")
		DECAL_ARGV_PARAM("test2")
		DECAL_ARGV_END()

		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWFEATURE));

		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(3, targc);
		IUTEST_EXPECT_STREQ("test1", targv[1]);
		IUTEST_EXPECT_STREQ("test2", targv[2]);
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}

	{
		int targc = 2;
		DECAL_ARGV("-h");

		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWVERSION));

		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}
	{
		int targc = 2;
		DECAL_ARGV("-?");

		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP));

		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}

	{
		int targc = 2;
		DECAL_ARGV_BEGIN()
		DECAL_ARGV_PARAM("--iutest_color=no")
		DECAL_ARGV_END()
		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		
		IUTEST_EXPECT_TRUE ( iuConsole_IsColorModeOff() );
		
		if( iuUnitTest_IsFaild(iuUnitTest_GetInstance()) ) return 1;
	}

	{
		int targc = 4;
		DECAL_ARGV_BEGIN()
		DECAL_ARGV_PARAM("--iutest_break_on_failure")
		DECAL_ARGV_PARAM("--iutest_filter")
		DECAL_ARGV_PARAM("--iutest_color=1")
		DECAL_ARGV_END()
		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		
		IUTEST_EXPECT_TRUE( IUTEST_FLAG(break_on_failure) );
		IUTEST_EXPECT_EQ(NULL, IUTEST_FLAG(filter));
		IUTEST_EXPECT_TRUE ( iuConsole_IsColorModeOn() );
		
		if( iuUnitTest_IsFaild(iuUnitTest_GetInstance()) ) return 1;
	}
	
	{
		int targc = 10;
		DECAL_ARGV_BEGIN()
		DECAL_ARGV_PARAM("--iutest_break_on_failure=1")
		DECAL_ARGV_PARAM("--iutest_also_run_disabled_tests")
		DECAL_ARGV_PARAM("--iutest_print_time=n")
		DECAL_ARGV_PARAM("--iutest_shuffle")
		DECAL_ARGV_PARAM("--iutest_color=ansi")
		DECAL_ARGV_PARAM("--iutest_random_seed=200")
		DECAL_ARGV_PARAM("--iutest_repeat=2")
		DECAL_ARGV_PARAM("--iutest_color=ansi")
		DECAL_ARGV_PARAM("--iutest_filter=Flag*")
		DECAL_ARGV_END()

		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP));
		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWFEATURE));
		IUTEST_EXPECT_FALSE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWVERSION));

		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(1, targc);
		
		IUTEST_EXPECT_TRUE ( IUTEST_FLAG(also_run_disabled_tests) );
		IUTEST_EXPECT_TRUE ( IUTEST_FLAG(break_on_failure) );
		IUTEST_EXPECT_FALSE( IUTEST_FLAG(print_time) );
		IUTEST_EXPECT_TRUE ( IUTEST_FLAG(shuffle) );
		IUTEST_EXPECT_TRUE ( iuConsole_IsColorModeAnsi() );
		
		IUTEST_EXPECT_EQ( 200u, IUTEST_FLAG(random_seed) );
		IUTEST_EXPECT_EQ(   2 , IUTEST_FLAG(repeat) );
		
		IUTEST_EXPECT_STREQ( "Flag*", IUTEST_FLAG(filter) );
		
		if( iuUnitTest_IsFaild(iuUnitTest_GetInstance()) ) return 1;
	}

	printf("*** Successful ***\n");
	return 0;
}

