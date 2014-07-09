/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		main.c
 * @brief		sample code
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/*
 * include testing framework
*/
#include "../include/iutest_c.h"

#if !IUTEST_C_HAS_LIB
IUTEST_C_WORKSPACE();
#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_REGISTER_TEST(AssertionTest, Simple);
#if IUTEST_C_HAS_PARAM_TEST
	IUTEST_REGISTER_TEST(TestCombine, Test);
	IUTEST_REGISTER_TEST_P(A, TestCombine);
	IUTEST_REGISTER_TEST_P(B, TestCombine);
#endif
/*
	iuUnitTest_SetVPrintfFunction(vprintf);
*/

	IUTEST_INIT(&argc, argv);
	return IUTEST_RUN_ALL_TESTS();
}
