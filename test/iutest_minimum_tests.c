/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_minimum_tests.c
 * @brief		ç≈è¨ÉeÉXÉg
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

int f(int n) { return n < 0 ? -n : n; }

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	return IUTEST_RUN_ALL_TESTS();
}

IUTEST(Foo, Bar)
{
	IUTEST_ASSERT_RVALUE_EQ(1, f(-1));
}
