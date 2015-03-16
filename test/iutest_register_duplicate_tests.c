/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_register_duplicate_tests.c
 * @brief		IUTEST_REGISTER_TEST ƒeƒXƒg
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2013-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

IUTEST(Foo, Bar)
{
}

void TestFixed_SetUp(iuTestInfo* test_info)
{
	IUTEST_UNUSED_VAR(test_info);
}

void TestFixed_SetUpTestCase(void)
{
}

iuTestFixture TestFixed = {
	TestFixed_SetUpTestCase
	, NULL
	, TestFixed_SetUp
	, NULL
	, NULL
};

IUTEST_F(TestFixed, Test)
{
}

#if IUTEST_C_HAS_PARAM_TEST

IUTEST_INSTANTIATE_TEST_CASE_P(int, A, TestP, iuValues, 0, 1, 2, 3 );

IUTEST_P(int, TestP, Test)
{
	IUTEST_UNUSED_VAR(param);
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_REGISTER_TEST(Foo, Bar);
	IUTEST_REGISTER_TEST(TestFixed, Test);
#if IUTEST_C_HAS_PARAM_TEST
	IUTEST_REGISTER_TEST(TestP, Test);
	IUTEST_REGISTER_TEST_P(A, TestP);
#endif
	
	IUTEST_INIT(&argc, argv);
	
	{
		int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
	}

	{
		int nTestCaseCount = 2;
		int nTestCount = 2;
#if IUTEST_C_HAS_PARAM_TEST
		nTestCaseCount += 4;
		nTestCount += 4;
#endif
		IUTEST_PRINTF("%d %d\r\n", iuUnitTest_GetTotalTestCaseCount(iuUnitTest_GetInstance()), iuUnitTest_GetTotalTestCount(iuUnitTest_GetInstance()));
		IUTEST_ASSERT(iuUnitTest_GetTotalTestCaseCount(iuUnitTest_GetInstance()) == nTestCaseCount);
		IUTEST_ASSERT(iuUnitTest_GetTotalTestCount(iuUnitTest_GetInstance()) == nTestCount);
	}

	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}

