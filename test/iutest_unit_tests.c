/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_unit_tests.c
 * @brief		iutest unit test
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

IUTEST(Unit, ItoA)
{
	char buf[32];
	IUTEST_ASSERT_STREQ("0"  , iu_itoa(  0, buf, 10));
	IUTEST_ASSERT_STREQ("1"  , iu_itoa(  1, buf, 10));
	IUTEST_ASSERT_STREQ("128", iu_itoa(128, buf, 10));
	IUTEST_ASSERT_STREQ("FF" , iu_itoa(255, buf, 16));
}

#if IUTEST_C_HAS_GENERIC
IUTEST(GenericUnit, Format)
{
	{
		char x=1;
		if( x )
		{
			const char* p = IUTEST_PRINTF_FORMAT(x);
			IUTEST_ASSERT_STREQ("%c", p);
		}
	}
	{
		unsigned int x=1;
		if( x )
		{
			const char* p = IUTEST_PRINTF_FORMAT(x);
			IUTEST_ASSERT_STREQ("%u", p);
		}
	}
	{
		const char* p = IUTEST_PRINTF_FORMAT(0);
		IUTEST_ASSERT_STREQ("%d", p);
	}
}

#endif
