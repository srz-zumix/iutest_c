/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_fixture_tests.c
 * @brief		iutest fixture test
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

int TestFixed_x = 0;
int TestFixed_y = 0;

void TestFixed_SetUp(void)
{
	++TestFixed_x;
}

void TestFixed_SetUpTestCase(void)
{
	TestFixed_x = 0;
	TestFixed_y = 0;
}

iuTestFixture TestFixed = {
	TestFixed_SetUpTestCase
	, NULL
	, TestFixed_SetUp
	, NULL
	, NULL
};

IUTEST_F(TestFixed, Test1)
{
	++TestFixed_y;
	IUTEST_EXPECT_EQ(TestFixed_y, TestFixed_x);
	IUTEST_EXPECT_NULL(iuUnitTest_GetCurrentUserData());
}

IUTEST_F(TestFixed, Test2)
{
	++TestFixed_y;
	IUTEST_EXPECT_EQ(TestFixed_y, TestFixed_x);
	IUTEST_EXPECT_NULL(iuUnitTest_GetCurrentUserData());
}

