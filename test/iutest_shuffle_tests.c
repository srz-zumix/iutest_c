/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_shuffle_tests.c
 * @brief		shuffle test
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

static unsigned int seed = 0;
static int count = 0;

void GlobalTearDown(void)
{ 
	seed = iuUnitTest_GetRandomSeed();
	++count;
}

IUTEST(Foo, Bar)
{
	unsigned int s = iuUnitTest_GetRandomSeed();
	IUTEST_ASSERT_NE(s, seed);
}


static int order[3][10];
static int pos = 0;

void GlobalSetUp(void)
{
	pos = 0;
}

#define DECL_ORDER_TEST(n) IUTEST(OrderTest, IUTEST_PP_CAT(Bar,n)) { order[count][pos] = (n); ++pos; }

DECL_ORDER_TEST(0)
DECL_ORDER_TEST(1)
DECL_ORDER_TEST(2)
DECL_ORDER_TEST(3)
DECL_ORDER_TEST(4)
DECL_ORDER_TEST(5)
DECL_ORDER_TEST(6)
DECL_ORDER_TEST(7)
DECL_ORDER_TEST(8)
DECL_ORDER_TEST(9)

void OrderCheck(int a, int b)
{
	int i=0;
	for( ; i < 10; ++i )
	{
		if( order[a][i] != order[b][i] ) return;
	}
	IUTEST_FAIL();
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	iuUnitTest_AddGlobalEnvironmentSetUp(GlobalSetUp);
	iuUnitTest_AddGlobalEnvironmentTearDown(GlobalTearDown);
	IUTEST_INIT(&argc, argv);
	
	IUTEST_FLAG(repeat) = 3;
	IUTEST_FLAG(shuffle) = TRUE;

	{
		const int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return ret;
	}
	
	OrderCheck(0, 1);
	OrderCheck(0, 2);
	OrderCheck(1, 2);
	
	return iuUnitTest_Passed(iuUnitTest_GetInstance()) ? 0 : 1;
}

