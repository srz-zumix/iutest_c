/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		simple.c
 * @brief		sample code
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/*
 * include testing framework
*/
#include "../include/iutest_c.h"

/** --------------------------------------------------
 * 簡単なテスト
*//*--------------------------------------------------*/
IUTEST(Test, Version)
{
	unsigned long v = (IUTEST_C_MAJORVER << 24) | (IUTEST_C_MINORVER << 16) | (IUTEST_C_BUILD << 8) | IUTEST_C_REVISION;
	IUTEST_ASSERT_EQ( IUTEST_C_VER, v );

	iuTest_RecordProperty("test", "value");
}

