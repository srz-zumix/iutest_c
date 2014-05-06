/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_pred_tests.c
 * @brief		iutest assertion pred test
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

static iuBOOL IsOdd(int val)
{
	return (val & 1) != 0;
}
static iuBOOL	IsGreater(int a, int b)
{
	return a > b;
}
static iuBOOL	PredTest3(int a, int b, int c)
{
	IUTEST_UNUSED_VAR(a);
	IUTEST_UNUSED_VAR(b);
	IUTEST_UNUSED_VAR(c);
	return TRUE;
}
static iuBOOL	PredTest4(int a, int b, int c, int d)
{
	IUTEST_UNUSED_VAR(a);
	IUTEST_UNUSED_VAR(b);
	IUTEST_UNUSED_VAR(c);
	IUTEST_UNUSED_VAR(d);
	return TRUE;
}
static iuBOOL	PredTest5(int a, int b, int c, int d, int e)
{
	IUTEST_UNUSED_VAR(a);
	IUTEST_UNUSED_VAR(b);
	IUTEST_UNUSED_VAR(c);
	IUTEST_UNUSED_VAR(d);
	IUTEST_UNUSED_VAR(e);
	return TRUE;
}

IUTEST(AssertionTest, Pred)
{
	IUTEST_ASSERT_PRED1(IsOdd, 3);
	IUTEST_EXPECT_PRED1(IsOdd, 3);
	IUTEST_INFORM_PRED1(IsOdd, 3);
	IUTEST_ASSERT_PRED2(IsGreater, 3, 1);
	IUTEST_EXPECT_PRED2(IsGreater, 3, 1);
	IUTEST_INFORM_PRED2(IsGreater, 3, 1);
	IUTEST_ASSERT_PRED3(PredTest3, 0, 1, 2);
	IUTEST_EXPECT_PRED3(PredTest3, 0, 1, 2);
	IUTEST_INFORM_PRED3(PredTest3, 0, 1, 2);
	IUTEST_ASSERT_PRED4(PredTest4, 0, 1, 2, 3);
	IUTEST_EXPECT_PRED4(PredTest4, 0, 1, 2, 3);
	IUTEST_INFORM_PRED4(PredTest4, 0, 1, 2, 3);
	IUTEST_ASSERT_PRED5(PredTest5, 0, 1, 2, 3, 4);
	IUTEST_EXPECT_PRED5(PredTest5, 0, 1, 2, 3, 4);
	IUTEST_INFORM_PRED5(PredTest5, 0, 1, 2, 3, 4);
}

