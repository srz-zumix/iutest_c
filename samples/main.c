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
 * is not available vprintf, can be replaced.
*/
/*#define IUTEST_VPRINTF*/

/*
 * include testing framework
*/
#define IUTEST_C_HAS_PARAM_TEST	1
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();


#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_REGISTER_TEST(AssertionTest, Simple);
	IUTEST_REGISTER_TEST(SubTest1, A);
	IUTEST_REGISTER_TEST(TestCombine, Test);
	IUTEST_REGISTER_TEST_P(A, TestCombine);
	IUTEST_REGISTER_TEST_P(B, TestCombine);
/*
	iuUnitTest_SetVPrintfFunction(vprintf);
*/

	IUTEST_INIT(&argc, argv);
	return IUTEST_RUN_ALL_TESTS();
}

/** --------------------------------------------------
 * 簡単なテスト
*//*--------------------------------------------------*/
IUTEST(Test, Version)
{
	unsigned long v = (IUTEST_C_MAJORVER << 24) | (IUTEST_C_MINORVER << 16) | (IUTEST_C_BUILD << 8) | IUTEST_C_REVISION;
	IUTEST_ASSERT_EQ( IUTEST_C_VER, v );

	iuTest_RecordProperty("test", "value");
}

IUTEST(AssertionTest, Simple)
{
	int zero = 0, one = 1;
	int yes=TRUE, no=FALSE;

	IUTEST_EXPECT_TRUE(yes);
	IUTEST_EXPECT_FALSE(no);
	IUTEST_EXPECT_EQ(0, zero);
#if 0
	IUTEST_EXPECT_NE(0, 1);
	IUTEST_EXPECT_LE(1, 1);
	IUTEST_EXPECT_LT(0, 1);
	IUTEST_EXPECT_GE(1, 1);
	IUTEST_EXPECT_GT(1, 0);
#else
	IUTEST_EXPECT_NE(zero, one);
	IUTEST_EXPECT_LE(one , one);
	IUTEST_EXPECT_LT(zero, one);
	IUTEST_EXPECT_GE(one , one);
	IUTEST_EXPECT_GT(one , zero);
#endif
#if IUTEST_C_HAS_FLOATINGPOINT
	{
		float fa = 2.0f/2;
		double da = 2.0/2;
		double db = 1.5;
		IUTEST_EXPECT_FLOAT_EQ(1, fa);
		IUTEST_EXPECT_DOUBLE_EQ(1, da);
		IUTEST_EXPECT_NEAR(da, db, 1.0f);
	}
#endif

	IUTEST_ASSERT_TRUE(yes);
	IUTEST_ASSERT_FALSE(no);
	IUTEST_ASSERT_EQ(0, zero);
#if 0
	IUTEST_ASSERT_NE(0, 1);
	IUTEST_ASSERT_LE(1, 1);
	IUTEST_ASSERT_LT(0, 1);
	IUTEST_ASSERT_GE(1, 1);
	IUTEST_ASSERT_GT(1, 0);
#else
	IUTEST_ASSERT_NE(zero, one);
	IUTEST_ASSERT_LE(one , one);
	IUTEST_ASSERT_LT(zero, one);
	IUTEST_ASSERT_GE(one , one);
	IUTEST_ASSERT_GT(one , zero);
#endif
#if IUTEST_C_HAS_FLOATINGPOINT
	{
		float fa = 2.0f/2;
		double da = 2.0/2;
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

/** --------------------------------------------------
 * パラメタライズ関数コール
*//*--------------------------------------------------*/
#if IUTEST_C_HAS_PARAM_METHOD_TEST

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

#ifdef SHOW_FAILURE

IUTEST(ExpectFailureTest, Simple)
{
	int zero = 0, one = 1;
	int yes=TRUE, no=FALSE;
	IUTEST_EXPECT_TRUE(no);
	IUTEST_EXPECT_FALSE(yes);
	IUTEST_EXPECT_EQ(1, zero);
#if 0
	IUTEST_EXPECT_NE(0, 0);
	IUTEST_EXPECT_LE(1, 0);
	IUTEST_EXPECT_LT(1, 1);
	IUTEST_EXPECT_GE(0, 1);
	IUTEST_EXPECT_GT(1, 1);
#else
	IUTEST_EXPECT_NE(zero, zero);
	IUTEST_EXPECT_LE(one, zero);
	IUTEST_EXPECT_LT(one, one);
	IUTEST_EXPECT_GE(zero, one);
	IUTEST_EXPECT_GT(one, one);
#endif
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
