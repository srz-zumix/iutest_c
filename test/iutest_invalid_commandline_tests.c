/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_invalid_commandline_tests.c
 * @brief		不正なコマンドライン引数対応テスト
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
		DECAL_ARGV("--iutest_foo");
		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(2, targc);
		IUTEST_EXPECT_TRUE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP));
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}
	{
		int targc = 13;
		int i;
		DECAL_ARGV_BEGIN()
		DECAL_ARGV_PARAM("--iutest_random_seed")
		DECAL_ARGV_PARAM("--iutest_repeat")
		DECAL_ARGV_PARAM("--iutest_print_time")
		DECAL_ARGV_PARAM("--iutest_print_time=")
		DECAL_ARGV_PARAM("--iutest_color")
		DECAL_ARGV_PARAM("--iutest_color=hoge")
		DECAL_ARGV_PARAM("--iutest_shuffle=1")
		DECAL_ARGV_PARAM("--iutest_output")
		DECAL_ARGV_PARAM("--iutest_also_run_disabled_tests=1")
		DECAL_ARGV_PARAM("--iutest_list_tests=1")
		DECAL_ARGV_PARAM("--x")
		DECAL_ARGV_PARAM("-x")
		DECAL_ARGV_END()
		IUTEST_INIT(&targc, targv);
		IUTEST_EXPECT_EQ(13, targc);
		IUTEST_EXPECT_TRUE(iuTestEnv_IsEnableFlag(IUTESTENV_SHOWHELP));
		if( IUTEST_RUN_ALL_TESTS() != 0 ) return 1;
	}
	printf("*** Successful ***\n");
	return 0;
}

