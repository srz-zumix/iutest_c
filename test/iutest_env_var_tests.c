/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_env_var_tests.c
 * @brief		ä¬ã´ïœêîëŒâûÉeÉXÉg
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

#if !defined(IUTEST_C_NO_GETENV) && !defined(IUTEST_C_NO_PUTENV) && IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION
int SetUpEnvironment(void)
{
	iuTestOS_PutEnv("IUTEST_C_SHUFFLE=1");
	iuTestOS_PutEnv("IUTEST_C_RANDOM_SEED=200");
	iuTestOS_PutEnv("IUTEST_C_ALSO_RUN_DISABLED_TESTS=1");
	iuTestOS_PutEnv("IUTEST_C_BREAK_ON_FAILURE=1");
	iuTestOS_PutEnv("IUTEST_C_PRINT_TIME=1");
	iuTestOS_PutEnv("IUTEST_C_REPEAT=2");
	iuTestOS_PutEnv("IUTEST_C_FILTER=Flag*");
	return 0;
}

IUTEST(FlagTest, Check)
{
	IUTEST_EXPECT_TRUE( IUTEST_FLAG(also_run_disabled_tests) );
	IUTEST_EXPECT_TRUE( IUTEST_FLAG(break_on_failure) );
	IUTEST_EXPECT_TRUE( IUTEST_FLAG(print_time) );
	IUTEST_EXPECT_TRUE( IUTEST_FLAG(shuffle) );
	
	IUTEST_EXPECT_EQ( 200, IUTEST_FLAG(random_seed) );
	IUTEST_EXPECT_EQ(   2, IUTEST_FLAG(repeat) );

	IUTEST_EXPECT_STREQ( "Flag*", IUTEST_FLAG(filter) );
}

#else
int SetUpEnvironment(void) { return 0; }
#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	SetUpEnvironment();
	
	IUTEST_INIT(&argc, argv);
	return IUTEST_RUN_ALL_TESTS();
}

