/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_param_test_tests.c
 * @brief		iutest parameter test tests
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

#if IUTEST_C_HAS_PARAM_TEST

IUTEST_INSTANTIATE_TEST_CASE_P(int, A, TestP, iuValues, 0, 1, 2, 3 );
IUTEST_INSTANTIATE_TEST_CASE_P(int, B, TestP, iuRange, 0, 11);
IUTEST_INSTANTIATE_TEST_CASE_P(int, C, TestP, iuStepRange, 0, 11, 2);

#if defined(__GNUC__)
IUTEST_INSTANTIATE_TEST_CASE_P(int, D, TestP, iuRange, 0, 11, 2);
#endif

IUTEST_P(int, TestP, Test)
{
	const int x = param;
	const int kMax = 11;
	IUTEST_ASSERT_LT(x, kMax);
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d\n", x);
#endif
}

IUTEST_P(int, TestP, Test2)
{
	const int x = param;
	const int kMax = 11;
	IUTEST_ASSERT_LT(x, kMax);
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d\n", x);
#endif
}

static int s_test_pf_count = 1;
static void TestPF_SetUp(void)
{
	s_test_pf_count = 0;
}
static void TestPF_TearDown(void)
{
	s_test_pf_count = 1;
}

static const iuTestFixture TestPF ={ NULL, NULL, TestPF_SetUp, TestPF_TearDown, NULL };
IUTEST_INSTANTIATE_TEST_CASE_P(int, A, TestPF, iuRange, 0, 2);

IUTEST_P_F(int, TestPF, Test)
{
	const int x = param;
	const int kMax = 10;
	IUTEST_EXPECT_EQ(0, s_test_pf_count);
	IUTEST_ASSERT_LT(x, kMax);
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d\n", x);
#endif
}

IUTEST_P_F(int, TestPF, Test2)
{
	const int x = param;
	const int kMax = 10;
	IUTEST_EXPECT_EQ(0, s_test_pf_count);
	IUTEST_ASSERT_LT(x, kMax);
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d\n", x);
#endif
}

#if IUTEST_C_HAS_COMBINE

typedef IUTEST_P_TYPE((int, char, unsigned int)) TestCombineParamType;
IUTEST_INSTANTIATE_TEST_CASE_P((int, char, unsigned int), A
							   , TestCombine, iuCombine
							   , (iuRange, ( 0, 2)), (iuStepRange, (100, 110, 2)), (iuValues, (0, 4, 2)) );

IUTEST_INSTANTIATE_TEST_CASE_P((int, char, unsigned int), B
							   , TestCombine, iuCombine
							   , (iuRange, (-2, 0)), (iuStepRange, (200, 210, 2)), (iuValues, (2, 5, 9)) );

IUTEST_P(TestCombineParamType, TestCombine, Test)
{
	const int x0 = param.value0;
	const char x1 = param.value1;
	const unsigned int x2 = param.value2;
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d %d %d\n", x0, x1, x2);
#endif
}

IUTEST_P(TestCombineParamType, TestCombine, Test2)
{
	const int x0 = param.value0;
	const char x1 = param.value1;
	const unsigned int x2 = param.value2;
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("%d %d %d\n", x0, x1, x2);
#endif
}

#endif

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	{
		int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
	}
#if IUTEST_C_HAS_PARAM_TEST
	{
		int nTestCaseCount = (4+11+6+2);
#if IUTEST_C_HAS_COMBINE
		nTestCaseCount += 2*5*3 * 2;
#endif
#if defined(__GNUC__)
		nTestCaseCount += 6;
#endif
		IUTEST_ASSERT( iuUnitTest_GetTotalTestCaseCount(iuUnitTest_GetInstance()) == nTestCaseCount );
		IUTEST_ASSERT( iuUnitTest_GetTotalTestCount(iuUnitTest_GetInstance()) == nTestCaseCount*2 );
	}
#endif
	
	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}
