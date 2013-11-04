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

#if IUTEST_C_HAS_CONSOLEOUT

static int call_printf = 0;

int test_vprintf(const char* fmt, va_list va)
{
	IUTEST_UNUSED_VAR(fmt);
	IUTEST_UNUSED_VAR(va);
	call_printf = 1;
	return 0;
}

void Test(void)
{
	IUTEST_ASSERT_RVALUE_EQ(0, 1);
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
#if IUTEST_C_HAS_CONSOLEOUT
	iuUnitTest_SetVPrintfFunction(test_vprintf);
#endif
	
	IUTEST_INIT(&argc, argv);
#if IUTEST_C_HAS_CONSOLEOUT
	Test();
	
	if( call_printf == 0 ) return 1;
#endif
	IUTEST_PRINTF("*** Successful ***\n");
	return 0;
}

