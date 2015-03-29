/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_record_property_tests.c
 * @brief		record property test
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#include "../include/iutest_c.h"
#include "../include/iutest_spi_c.h"

IUTEST_C_WORKSPACE();

void CheckProperty_(const iuTestResult* tr, const char* key, const char* value)
{
	int count = iuTestResult_TotalPropertyCount(tr);
	IUTEST_ASSERT_EQ(1, count);
	IUTEST_EXPECT_STREQ(key, iuTestResult_GetProperty(tr, 0)->key);
	IUTEST_EXPECT_STREQ(value, iuTestResult_GetProperty(tr, 0)->value);
}

iuBOOL CheckProperty(const iuTestResult* tr, const char* key, const char* value)
{
	CheckProperty_(tr, key, value);
	return iuUnitTest_Passed(iuUnitTest_GetInstance());
}

void RecordTest_SetUpTestCase(void)
{
	iuTest_RecordProperty("foo", "A");
	
	/* ban list */
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("name"     , "A"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("tests"    , "A"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("failures" , "A"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("disabled" , "A"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("skip"     , "A"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("errors"   , "A"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("time"     , "A"), "Reserved key");

	CheckProperty(iuUnitTest_GetCurrentTestResult(), "foo", "A");
}

iuTestFixture RecordTest = {
	RecordTest_SetUpTestCase
	, NULL
	, NULL
	, NULL
	, NULL
};

IUTEST_F(RecordTest, A)
{
	iuTest_RecordProperty("hoge", "B");
	/* ban list */
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("name"       , "B"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("status"     , "B"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("time"       , "B"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("classname"  , "B"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("type_param" , "B"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("value_param", "B"), "Reserved key");
	CheckProperty(iuUnitTest_GetCurrentTestResult(), "hoge", "B");
	
	/* overwirte */
	/*
	iuTest_RecordProperty("hoge", "b");
	CheckProperty(iuUnitTest_GetCurrentTestResult(), "hoge", "b");
	*/
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	iuTest_RecordProperty("bar", "C");
	/* ban list */
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("name"       , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("tests"      , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("failures"   , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("disabled"   , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("skip"       , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("errors"     , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("time"       , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("timestamp"  , "C"), "Reserved key");
	IUTEST_EXPECT_NONFATAL_FAILURE( iuTest_RecordProperty("random_seed", "C"), "Reserved key");
	
	{
		const int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
		if( !CheckProperty(iuUnitTest_GetCurrentTestResult(), "bar", "C") )
			return 1;
	}
	/*
	{
		const int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
		if( !CheckProperty(iuUnitTest_GetCurrentTestResult(), "bar", "C") )
			return 1;
	}
	*/
	{
		IUTEST_INIT(&argc, argv);
		const int ret = IUTEST_RUN_ALL_TESTS();
		if( ret != 0 ) return 1;
		if( CheckProperty(iuUnitTest_GetCurrentTestResult(), "bar", "C") )
			return 1;
	}

	printf("*** Successful ***\n");
	return 0;
}
