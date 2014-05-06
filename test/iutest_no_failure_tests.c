/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_no_failure_tests.c
 * @brief		iutest no failure test
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

void NoFailureTest_Subroutine(void)
{
	IUTEST_EXPECT_TRUE(TRUE);
}

IUTEST_PRAGMA_GCC_WARN_PUSH()
IUTEST_PRAGMA_WARN_DISABLE_EMPTY_BODY()

IUTEST(NoFatalFailureTest, Assert)
{
	IUTEST_ASSERT_NO_FATAL_FAILURE(;);
	IUTEST_ASSERT_NO_FATAL_FAILURE(IUTEST_SUCCEED());
	IUTEST_ASSERT_NO_FATAL_FAILURE(NoFailureTest_Subroutine());
	IUTEST_ASSERT_NO_FATAL_FAILURE({ IUTEST_SUCCEED(); });
}

IUTEST(NoFatalFailureTest, Expect)
{
	IUTEST_EXPECT_NO_FATAL_FAILURE(;);
	IUTEST_EXPECT_NO_FATAL_FAILURE(IUTEST_SUCCEED());
	IUTEST_EXPECT_NO_FATAL_FAILURE(NoFailureTest_Subroutine());
	IUTEST_EXPECT_NO_FATAL_FAILURE({ IUTEST_SUCCEED(); });
}

IUTEST(NoFatalFailureTest, Inform)
{
	IUTEST_INFORM_NO_FATAL_FAILURE(;);
	IUTEST_INFORM_NO_FATAL_FAILURE(IUTEST_SUCCEED());
	IUTEST_INFORM_NO_FATAL_FAILURE(NoFailureTest_Subroutine());
	IUTEST_INFORM_NO_FATAL_FAILURE({ IUTEST_SUCCEED(); });
}

IUTEST(NoFailureTest, Assert)
{
	IUTEST_ASSERT_NO_FAILURE(;);
	IUTEST_ASSERT_NO_FAILURE(IUTEST_SUCCEED());
	IUTEST_ASSERT_NO_FAILURE(NoFailureTest_Subroutine());
	IUTEST_ASSERT_NO_FAILURE({ IUTEST_SUCCEED(); });
}

IUTEST(NoFailureTest, Expect)
{
	IUTEST_EXPECT_NO_FAILURE(;);
	IUTEST_EXPECT_NO_FAILURE(IUTEST_SUCCEED());
	IUTEST_EXPECT_NO_FAILURE(NoFailureTest_Subroutine());
	IUTEST_EXPECT_NO_FAILURE({ IUTEST_SUCCEED(); });
}

IUTEST(NoFailureTest, Inform)
{
	IUTEST_INFORM_NO_FAILURE(;);
	IUTEST_INFORM_NO_FAILURE(IUTEST_SUCCEED());
	IUTEST_INFORM_NO_FAILURE(NoFailureTest_Subroutine());
	IUTEST_INFORM_NO_FAILURE({ IUTEST_SUCCEED(); });
}

IUTEST_PRAGMA_GCC_WARN_POP()
