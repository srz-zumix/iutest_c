/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_param_method_tests.c
 * @brief		iutest parameter method test
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

#if IUTEST_C_HAS_PARAM_METHOD_TEST

static int s_parammethod_test_called = 0;
static void ParamMethodTestFixed_SetUp(iuTestInfo* test_info)
{
	IUTEST_UNUSED_VAR(test_info);
	s_parammethod_test_called = 1;
}

void TestFunction(int x, int y)
{
	IUTEST_ASSERT_EQ(x, y);
}
void TestFunctionF(int x, int y)
{
	IUTEST_ASSERT_EQ(1, s_parammethod_test_called);
	TestFunction(x, y);
}
IUTEST_PMZ(ParamMethodTest, EQ, TestFunction, 0, 0);
IUTEST_PMZ(ParamMethodTest, EQ, TestFunction, 1, 1);
IUTEST_PMZ(ParamMethodTest, EQ, TestFunction, 2, 2);

static const iuTestFixture ParamMethodTestFixed = { NULL, NULL, ParamMethodTestFixed_SetUp, NULL, NULL };

IUTEST_PMZ_F(ParamMethodTestFixed, EQ, TestFunction, 0, 0);
IUTEST_PMZ_F(ParamMethodTestFixed, EQ, TestFunction, 1, 1);
IUTEST_PMZ_F(ParamMethodTestFixed, EQ, TestFunction, 2, 2);

#endif

