/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_filter_tests.c
 * @brief		filter ‘Î‰žƒeƒXƒg
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"

IUTEST_C_WORKSPACE();

IUTEST(Test, Fail)
{
	IUTEST_ASSERT_RVALUE_EQ(2, 3);
}

IUTEST(Fail, Test)
{
	IUTEST_ASSERT_RVALUE_EQ(2, 3);
}

IUTEST(Foo, Bar)
{
	IUTEST_ASSERT_RVALUE_EQ(3, 3);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	int ret = 0;
	IUTEST_INIT(&argc, argv);

	{
		IUTEST_FLAG(filter) = "-*Fail*";
		ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
	}
	
	{
		IUTEST_FLAG(filter) = "*Fail*";
		
		ret = IUTEST_RUN_ALL_TESTS();
		if( ret == 0 ) return 1;
	}
	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}
