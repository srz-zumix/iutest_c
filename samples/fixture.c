/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		fixture.c
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

static int s_count = 1;
static void TestF_SetUp(void)
{
	s_count = 0;
}
static const iuTestFixture TestF = { NULL, NULL, TestF_SetUp, NULL, NULL };
IUTEST_F(TestF, First)
{
	IUTEST_EXPECT_EQ(0, s_count);
}

