/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_list_test_tests.c
 * @brief		list up commandline option test
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

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


IUTEST_C_WORKSPACE();

IUTEST(Test, A)
{
}

#if IUTEST_C_HAS_PARAM_TEST

IUTEST_INSTANTIATE_TEST_CASE_P(int, A, TestP, iuValues, 0, 1, 2 );

IUTEST_P(int, TestP, A)
{
	IUTEST_UNUSED_VAR(param);
}

IUTEST_P(int, TestP, B)
{
	IUTEST_UNUSED_VAR(param);
}

#endif


#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	int targc = 2;
	DECAL_ARGV("--iutest_list_tests");
	IUTEST_UNUSED_VAR(argc);
	IUTEST_UNUSED_VAR(argv);

#if defined(OUTPUTXML)
	// 失敗テストを含むので xml 出力しない
	IUTEST_FLAG(output) = NULL;
#endif

	IUTEST_INIT(&targc, targv);
	IUTEST_EXPECT_EQ(1, targc);
	return IUTEST_RUN_ALL_TESTS();
}
