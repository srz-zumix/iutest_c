/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_assertion_only_tests.c
 * @brief		iutest assertion only test
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

IUTEST(Test, Dummy)
{
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	(void)argc;
	(void)argv;
	if( IUTEST_RUN_ALL_TESTS() == 0 ) return 1;
	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}
