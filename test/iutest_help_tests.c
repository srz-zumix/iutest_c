/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_help_tests.c
 * @brief		help ‘Î‰žƒeƒXƒg
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

#if IUTEST_C_HAS_COMMANDLINE_OPTION

IUTEST(Foo, NotRun)
{
	IUTEST_ASSERT_RVALUE_EQ(0, 1);
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t** argv)
#else
int main(int argc, char** argv)
#endif
{
	int targc = 2;
	char* cmd = "--help";
	char* targv[] = {
		argv[0]
		, cmd
	};
	(void)argc;
	IUTEST_INIT(&targc, targv);
	return IUTEST_RUN_ALL_TESTS();
}

