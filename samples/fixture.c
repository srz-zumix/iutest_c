/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		fixture.c
 * @brief		sample code
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
/*
 * include testing framework
*/
#include "../include/iutest_c.h"

static int s_count = 1;
static void TestF_SetUp(iuTestInfo* test_info)
{
	IUTEST_UNUSED_VAR(test_info);
	s_count = 0;
}
static const iuTestFixture TestF = { NULL, NULL, TestF_SetUp, NULL, NULL };
IUTEST_F(TestF, First)
{
	IUTEST_EXPECT_EQ(0, s_count);
}

void SkipTestFixed_SetUpTestCase(void)
{
	IUTEST_SKIP();
}

iuTestFixture SkipTestFixed ={
	SkipTestFixed_SetUpTestCase
	, NULL
	, NULL
	, NULL
	, NULL
};

IUTEST_F(SkipTestFixed, Test1)
{
	IUTEST_EXPECT_TRUE(FALSE);
}
