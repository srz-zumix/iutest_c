/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_static_assertion_tests.c
 * @brief		iutest IUTEST_STATIC_ASSERT test
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

IUTEST(StaticAssertEqTest, OK)
{
	IUTEST_STATIC_ASSERT(1 == 1);
}
