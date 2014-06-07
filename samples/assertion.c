/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		assertion.c
 * @brief		sample code
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/*
 * include testing framework
*/
#include "../include/iutest_c.h"

IUTEST(AssertionTest, Simple)
{
	int zero = 0, one = 1;
	int yes=TRUE, no=FALSE;

	IUTEST_EXPECT_TRUE(yes);
	IUTEST_EXPECT_FALSE(no);
	IUTEST_EXPECT_EQ(0, zero);
#if IUTEST_C_HAS_GENERIC_ASSERTION
	IUTEST_EXPECT_NE(0, 1);
	IUTEST_EXPECT_LE(1, 1);
	IUTEST_EXPECT_LT(0, 1);
	IUTEST_EXPECT_GE(1, 1);
	IUTEST_EXPECT_GT(1, 0);
#endif
	IUTEST_EXPECT_NE(zero, one);
	IUTEST_EXPECT_LE(one, one);
	IUTEST_EXPECT_LT(zero, one);
	IUTEST_EXPECT_GE(one, one);
	IUTEST_EXPECT_GT(one, zero);

#if IUTEST_C_HAS_FLOATINGPOINT
	{
		float fa = 2.0f / 2;
		double da = 2.0 / 2;
		double db = 1.5;
		IUTEST_EXPECT_FLOAT_EQ(1, fa);
		IUTEST_EXPECT_DOUBLE_EQ(1, da);
		IUTEST_EXPECT_NEAR(da, db, 1.0f);
	}
#endif

	IUTEST_ASSERT_TRUE(yes);
	IUTEST_ASSERT_FALSE(no);
	IUTEST_ASSERT_EQ(0, zero);
#if IUTEST_C_HAS_GENERIC_ASSERTION
	IUTEST_ASSERT_NE(0, 1);
	IUTEST_ASSERT_LE(1, 1);
	IUTEST_ASSERT_LT(0, 1);
	IUTEST_ASSERT_GE(1, 1);
	IUTEST_ASSERT_GT(1, 0);
#endif
	IUTEST_ASSERT_NE(zero, one);
	IUTEST_ASSERT_LE(one, one);
	IUTEST_ASSERT_LT(zero, one);
	IUTEST_ASSERT_GE(one, one);
	IUTEST_ASSERT_GT(one, zero);

#if IUTEST_C_HAS_FLOATINGPOINT
	{
		float fa = 2.0f / 2;
		double da = 2.0 / 2;
		double db = 1.5;
		IUTEST_ASSERT_FLOAT_EQ(1, fa);
		IUTEST_ASSERT_DOUBLE_EQ(1, da);
		IUTEST_ASSERT_NEAR(da, db, 1.0f);
	}
#endif
}

#if defined(IUTEST_OS_WINDOWS)

IUTEST(AssertionTest, Windows)
{
	IUTEST_EXPECT_HRESULT_SUCCEEDED(0);
	IUTEST_EXPECT_HRESULT_FAILED(-1);

	IUTEST_ASSERT_HRESULT_SUCCEEDED(0);
	IUTEST_ASSERT_HRESULT_FAILED(-1);
}

#endif

IUTEST(AssertionTest, String)
{
	IUTEST_EXPECT_STREQ("test", "test");
	IUTEST_EXPECT_STREQ(NULL, NULL);

	IUTEST_EXPECT_STRNE("test", NULL);
	IUTEST_EXPECT_STRNE(NULL, "test");
	IUTEST_EXPECT_STRNE("test", "host");

	IUTEST_EXPECT_STRCASEEQ("test", "test");
	IUTEST_EXPECT_STRCASEEQ("test", "TeSt");
	IUTEST_EXPECT_STRCASEEQ(NULL, NULL);

	IUTEST_EXPECT_STRCASENE("test", NULL);
	IUTEST_EXPECT_STRCASENE(NULL, "test");
	IUTEST_EXPECT_STRCASENE("test", "host");

	IUTEST_ASSERT_STREQ("test", "test");
	IUTEST_ASSERT_STREQ(NULL, NULL);

	IUTEST_ASSERT_STRNE("test", NULL);
	IUTEST_ASSERT_STRNE(NULL, "test");
	IUTEST_ASSERT_STRNE("test", "host");

	IUTEST_ASSERT_STRCASEEQ("test", "test");
	IUTEST_ASSERT_STRCASEEQ("test", "TeSt");
	IUTEST_ASSERT_STRCASEEQ(NULL, NULL);

	IUTEST_ASSERT_STRCASENE("test", NULL);
	IUTEST_ASSERT_STRCASENE(NULL, "test");
	IUTEST_ASSERT_STRCASENE("test", "host");
}

#ifdef SHOW_FAILURE

IUTEST(ExpectFailureTest, Simple)
{
	int zero = 0, one = 1;
	int yes=TRUE, no=FALSE;
	IUTEST_EXPECT_TRUE(no);
	IUTEST_EXPECT_FALSE(yes);
	IUTEST_EXPECT_EQ(1, zero);
#if IUTEST_C_HAS_GENERIC_ASSERTION
	IUTEST_EXPECT_NE(0, 0);
	IUTEST_EXPECT_LE(1, 0);
	IUTEST_EXPECT_LT(1, 1);
	IUTEST_EXPECT_GE(0, 1);
	IUTEST_EXPECT_GT(1, 1);
#endif
	IUTEST_EXPECT_NE(zero, zero);
	IUTEST_EXPECT_LE(one, zero);
	IUTEST_EXPECT_LT(one, one);
	IUTEST_EXPECT_GE(zero, one);
	IUTEST_EXPECT_GT(one, one);
	{
		float fa = 2.0f/2;
		double da = 2.0/2;
		double db = 1.5;
		IUTEST_EXPECT_FLOAT_EQ(1.1f, fa);
		IUTEST_EXPECT_DOUBLE_EQ(1.1, da);
		IUTEST_EXPECT_NEAR(da, db, 0.1f);
	}
}

#if defined(IUTEST_OS_WINDOWS)
IUTEST(ExpectFailureTest, Windows)
{
	IUTEST_EXPECT_HRESULT_SUCCEEDED(-1);
	IUTEST_EXPECT_HRESULT_FAILED(0);
}
#endif

IUTEST(ExpectFailureTest, String)
{
	IUTEST_EXPECT_STREQ("test", "teSt");
	IUTEST_EXPECT_STREQ("test", NULL);
	IUTEST_EXPECT_STREQ(NULL, "test");

	IUTEST_EXPECT_STRNE(NULL, NULL);
	IUTEST_EXPECT_STRNE("test", "test");

	IUTEST_EXPECT_STRCASEEQ("test", "host");
	IUTEST_EXPECT_STRCASEEQ("test", NULL);
	IUTEST_EXPECT_STRCASEEQ(NULL, "test");

	IUTEST_EXPECT_STRCASENE(NULL, NULL);
	IUTEST_EXPECT_STRCASENE("test", "test");
}

#endif
