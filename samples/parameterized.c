/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		parameterized.c
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

/** --------------------------------------------------
 * パラメタライズ関数コール
*//*--------------------------------------------------*/
#if IUTEST_C_HAS_PARAM_METHOD_TEST

static int s_count = 1;
static void TestF_SetUp(void)
{
	s_count = 0;
}

void TestFunction(int x, int y)
{
	IUTEST_ASSERT_EQ(x, y);
}
IUTEST_PMZ(ParamMethodTest, EQ, TestFunction, 0, 0);
IUTEST_PMZ(ParamMethodTest, EQ, TestFunction, 1, 1);
IUTEST_PMZ(ParamMethodTest, EQ, TestFunction, 2, 2);

static const iuTestFixture ParamMethodTestFixed = { NULL, NULL, TestF_SetUp, NULL, NULL };

IUTEST_PMZ_F(ParamMethodTestFixed, EQ, TestFunction, 0, 0);
IUTEST_PMZ_F(ParamMethodTestFixed, EQ, TestFunction, 1, 1);
IUTEST_PMZ_F(ParamMethodTestFixed, EQ, TestFunction, 2, 2);

#endif

#if IUTEST_C_HAS_PARAM_TEST

IUTEST_INSTANTIATE_TEST_CASE_P(int, A, TestP, iuRange, 0, 2 );

IUTEST_P(int, TestP, Test)
{
	const int x = param;
	const int kMax = 10;
	IUTEST_ASSERT_LT(x, kMax);
	iuConsole_Output("%d\n", x);
}

IUTEST_P(int, TestP, Test2)
{
	const int x = param;
	const int kMax = 10;
	IUTEST_ASSERT_LT(x, kMax);
	iuConsole_Output("%d\n", x);
}

#if IUTEST_C_HAS_COMBINE

typedef IUTEST_P_TYPE((int, char, unsigned int)) TestCombineParamType;
IUTEST_INSTANTIATE_TEST_CASE_P((int, char, unsigned int), A
							   , TestCombine, iuCombine
							   , (iuRange, (-1, 1)), (iuRange, (100, 105)), (iuRange, (0, 2)) );

IUTEST_INSTANTIATE_TEST_CASE_P((int, char, unsigned int), B
							   , TestCombine, iuCombine
							   , (iuRange, (-2, 0)), (iuRange, (200, 205)), (iuRange, (2, 4)) );

IUTEST_P(TestCombineParamType, TestCombine, Test)
{
	const int x0 = param.value0;
	const char x1 = param.value1;
	const unsigned int x2 = param.value2;
	iuConsole_Output("%d %d %d\n", x0, x1, x2);
}

#endif

#endif
