/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_no_test_tests.c
 * @brief		テストが無いときの結果 対応テスト
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

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	int ret = 0;
	IUTEST_INIT(&argc, argv);

	IUTEST_EXPECT_RVALUE_EQ(0, 1);

	ret = IUTEST_RUN_ALL_TESTS();
	if( ret != 0 ) IUTEST_PRINTF("*** Successful ***\n");
	return ret != 0 ? 0 : 1;
}

