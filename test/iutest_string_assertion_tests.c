/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_string_assertion_tests.c
 * @brief		iutest 文字列比較 アサーション test
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

IUTEST(StringAssertTest, STREQ)
{
	const char* text = "text";
	IUTEST_ASSERT_STREQ("text", text);
	IUTEST_EXPECT_STREQ("text", text);
	IUTEST_INFORM_STREQ("text", text);
	IUTEST_EXPECT_STREQ(text, "text");
	IUTEST_EXPECT_STREQ(text, text);
}

IUTEST(StringAssertTest, STRNE)
{
	const char* text = "text";
	const char* test = "teXt";
	IUTEST_ASSERT_STRNE("text", test);
	IUTEST_EXPECT_STRNE("text", test);
	IUTEST_INFORM_STRNE("text", test);
	IUTEST_EXPECT_STRNE(test, "text");
	IUTEST_EXPECT_STRNE(text, test);
}

IUTEST(StringAssertTest, STRCASEEQ)
{
	const char* text = "text";
	const char* Text = "text";
	IUTEST_ASSERT_STREQ("text", Text);
	IUTEST_EXPECT_STREQ("text", Text);
	IUTEST_INFORM_STREQ("text", Text);
	IUTEST_EXPECT_STREQ(Text, "text");
	IUTEST_EXPECT_STREQ(text, Text);
}

IUTEST(StringAssertTest, STRCASENE)
{
	const char* text = "text";
	const char* test = "Test";
	IUTEST_ASSERT_STRCASENE("text", test);
	IUTEST_EXPECT_STRCASENE("text", test);
	IUTEST_INFORM_STRCASENE("text", test);
	IUTEST_EXPECT_STRCASENE(test, "text");
	IUTEST_EXPECT_STRCASENE(text, test);
}

