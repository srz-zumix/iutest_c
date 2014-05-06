/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_environment_tests.c
 * @brief		Environment ‘Î‰žƒeƒXƒg
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

static int call_setup = 0;
static int call_teardown = 0;

void GlobalSetUp(void)
{
	++call_setup;
}
	
void GlobalSetUp2(void)
{
	++call_setup;
}

void GlobalTearDown(void)
{
	++call_teardown;
}

void GlobalTearDown2(void)
{
	++call_teardown;
}

IUTEST(Foo, Bar)
{
	IUTEST_EXPECT_EQ(2, call_setup);
	IUTEST_EXPECT_EQ(0, call_teardown);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	int ret = 0;
	
	iuUnitTest_AddGlobalEnvironmentSetUp(GlobalSetUp);
	iuUnitTest_AddGlobalEnvironmentSetUp(GlobalSetUp2);
	iuUnitTest_AddGlobalEnvironmentTearDown(GlobalTearDown);
	iuUnitTest_AddGlobalEnvironmentTearDown(GlobalTearDown2);
	
	IUTEST_INIT(&argc, argv);
	IUTEST_ASSERT( call_setup == 0 );
	IUTEST_ASSERT( call_teardown == 0 );
	
	ret = IUTEST_RUN_ALL_TESTS();

	IUTEST_ASSERT( call_teardown == 2 );

	if( ret == 0 )
	{
		IUTEST_PRINTF("*** Successful ***\n");
	}
	return ret;
}
