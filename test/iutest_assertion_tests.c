/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_assertion_tests.c
 * @brief		iutest assertion test
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

iuAssertionResult IsEven(int n)
{
	if( n%2 == 0 ) return iuAssertionSuccess();
	return iuAssertionFailureMessage(" is odd");
}

IUTEST(AssertionTest, True)
{
	IUTEST_ASSERT_TRUE(TRUE);
	IUTEST_EXPECT_TRUE(TRUE);
	IUTEST_INFORM_TRUE(TRUE);
	IUTEST_EXPECT_TRUE(1);
	IUTEST_EXPECT_TRUE(100==100);
	/*
	IUTEST_EXPECT_TRUE(IsEven(2));
	*/
}

IUTEST(AssertionTest, False)
{
	IUTEST_ASSERT_FALSE(FALSE);
	IUTEST_EXPECT_FALSE(FALSE);
	IUTEST_INFORM_FALSE(FALSE);
	IUTEST_EXPECT_FALSE(0);
	IUTEST_EXPECT_FALSE(100!=100);
}

IUTEST(AssertionTest, EQ)
{
	{
		int x0=0, y0=0;
		IUTEST_ASSERT_EQ(x0, y0);
		IUTEST_EXPECT_EQ(x0, y0);
		IUTEST_INFORM_EQ(x0, y0);
	}
	{
		int* zero=NULL;
		IUTEST_ASSERT_EQ(NULL, zero);
	}
}

IUTEST(AssertionTest, NE)
{
	{
		int x0=0, x1=1;
		IUTEST_ASSERT_NE(x0, x1);
		IUTEST_EXPECT_NE(x0, x1);
		IUTEST_INFORM_NE(x0, x1);
	}
	{
		int* null=NULL;
		int* one=(int*)1;
		IUTEST_ASSERT_NE(null, one);
	}
}

IUTEST(AssertionTest, LT)
{
	int x0=0, x1=1;
	float f0=0.0f, f1=1.0f;
	double d0=0.0, d1=1.0;
	IUTEST_ASSERT_LT(x0, x1);
	IUTEST_EXPECT_LT(d0, d1);
#if 0
	IUTEST_INFORM_LT(0.0, 0x1);
#else
	IUTEST_INFORM_LT(d0, x1);
#endif
	IUTEST_ASSERT_LT(f0, f1);
}

IUTEST(AssertionTest, LE)
{
	int x0=0, x1=1, y0=0;
	float f0=0.0f, f1=1.0f;
	double d0=0.0, d1=1.0;
	IUTEST_ASSERT_LE(x0, y0);
	IUTEST_EXPECT_LE(f0, f1);
#if 0
	IUTEST_INFORM_LE(0.0, 0x1);
#else
	IUTEST_INFORM_LE(d0, x1);
#endif
	IUTEST_EXPECT_LE(d0, d1);
}

IUTEST(AssertionTest, GT)
{
	int x0=0, x1=1;
	float f0=0.0f, f1=1.0f;
	double d0=0.0, d1=1.0;
	IUTEST_EXPECT_GT(f1, f0);
	IUTEST_ASSERT_GT(x1, x0);
	IUTEST_EXPECT_GT(d1, d0);
#if 0
	IUTEST_INFORM_GT(0x1, 0.0f);
#else
	IUTEST_INFORM_GT(x1, f0);
#endif
}

IUTEST(AssertionTest, GE)
{
	int x0=0, x1=1, y0=0;
	float f0=0.0f, f1=1.0f;
	double d0=0.0, d1=1.0;
	IUTEST_ASSERT_GE(x0, y0);
	IUTEST_EXPECT_GE(f1, f0);
#if 0
	IUTEST_INFORM_GE(0x1, 0.0f);
#else
	IUTEST_INFORM_GE(x1, f0);
#endif
	IUTEST_INFORM_GE(d1, d0);
}

#if IUTEST_C_HAS_FLOATINGPOINT

IUTEST(AssertionTest, Float)
{
	float f0=0.0f, f1=1.0f, fa=-2.0f/2.0f;
	IUTEST_ASSERT_FLOAT_EQ(1.0f, f1);
	IUTEST_EXPECT_FLOAT_EQ(0.0f, f0);
	IUTEST_INFORM_FLOAT_EQ(-1.0f, fa);
}

IUTEST(AssertionTest, Double)
{
	double d0=0.0, d1=1.0, da=-2.0/2.0;
	IUTEST_ASSERT_DOUBLE_EQ(1.0, d1);
	IUTEST_EXPECT_DOUBLE_EQ(0.0, d0);
	IUTEST_INFORM_DOUBLE_EQ(-1.0, da);
}

IUTEST(AssertionTest, Near)
{
	int x0=0, x1=1;
	float fa = 1.0f, fb=4.0f;
	double da = 2.0, db=1.0;
	IUTEST_ASSERT_NEAR(x0, x1, 2);
	IUTEST_EXPECT_NEAR(fa, fb, 4);
	IUTEST_INFORM_NEAR(da, db, 2);
}

#endif

IUTEST(AssertionTest, Null)
{
	int* p1 = NULL;
	IUTEST_ASSERT_NULL(p1);
	IUTEST_EXPECT_NULL(p1);
	IUTEST_INFORM_NULL(p1);
	
	{
		void* p2 = &p1;
		IUTEST_ASSERT_NOTNULL(p2);
		IUTEST_EXPECT_NOTNULL(p2);
		IUTEST_INFORM_NOTNULL(p2);
	}
}

IUTEST(AssertionTest, Same)
{
	int v = 0;
	int* p1 = &v;
	IUTEST_ASSERT_SAME(v, *p1);
	IUTEST_EXPECT_SAME(v, *p1);
	IUTEST_INFORM_SAME(v, *p1);
}

#if defined(IUTEST_OS_WINDOWS)

IUTEST(AssertionTest, HResult)
{
	IUTEST_ASSERT_HRESULT_SUCCEEDED(0);
	IUTEST_EXPECT_HRESULT_SUCCEEDED(0);
	IUTEST_INFORM_HRESULT_SUCCEEDED(0);
	IUTEST_ASSERT_HRESULT_FAILED(-1);
	IUTEST_EXPECT_HRESULT_FAILED(-1);
	IUTEST_INFORM_HRESULT_FAILED(-1);
}

#endif

