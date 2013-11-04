/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_unit_tests.c
 * @brief		iutest unit test
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST(Unit, ItoA)
{
	char buf[32];
	IUTEST_ASSERT_STREQ("0"  , iu_itoa(  0, buf, 10));
	IUTEST_ASSERT_STREQ("1"  , iu_itoa(  1, buf, 10));
	IUTEST_ASSERT_STREQ("128", iu_itoa(128, buf, 10));
	IUTEST_ASSERT_STREQ("FF" , iu_itoa(255, buf, 16));
}
