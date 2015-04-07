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

IUTEST(VersionTest, Check)
{
	unsigned long v = (IUTEST_C_MAJORVER << 24) | (IUTEST_C_MINORVER << 16) | (IUTEST_C_BUILD << 8) | IUTEST_C_REVISION;
	IUTEST_ASSERT_EQ( IUTEST_C_VER, v );
}

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

IUTEST(GenericUnit, FormatMessage)
{
	{
		signed short x=1;
		if( x )
		{
			const char* p = IUTEST_PRINTF_FORMAT_MSG("x=", x, ".");
			IUTEST_ASSERT_STREQ("x=%hd.", p);
		}
	}
}

IUTEST(GenericUnit, FormatMessage2)
{
	{
		char x=1;
		int y=1;
		if( x && y )
		{
			const char* p = IUTEST_PRINTF_FORMAT_MSG2("x=", x, ", y=", y, ".");
			IUTEST_ASSERT_STREQ("x=%c, y=%d.", p);
		}
	}
}

typedef char GenericUnitTestType;
IUTEST(GenericUnit, IsTypeName)
{
	IUTEST_ASSERT_TRUE ( IUTEST_C_IS_TYPENAME(int) );
	IUTEST_ASSERT_TRUE ( IUTEST_C_IS_TYPENAME(GenericUnitTestType) );
	IUTEST_ASSERT_FALSE( IUTEST_C_IS_TYPENAME(test) );
}

#endif

IUTEST(FormatUnit, FormatDecimalNumber)
{
	char s[2];
	const char* p = iuTest_FormatDecimalNumber(s, 0);
	IUTEST_ASSERT_STREQ("0", p);
}

IUTEST(FormatUnit, PrintTo)
{
	char s[64];
	{
		char c=42;
		const char* p = iuTest_PrintTo(s, &c, sizeof(c));
		IUTEST_ASSERT_STREQ("0x2A", p);
	}
	{
		short c=42;
		const char* p = iuTest_PrintTo(s, &c, sizeof(c));
		IUTEST_ASSERT_STREQ("0x002A", p);
	}
	{
		int c=42;
		const char* p = iuTest_PrintTo(s, &c, sizeof(c));
		IUTEST_ASSERT_STREQ("0x0000002A", p);
	}
#if IUTEST_C_HAS_LONGLONG
	{
		long long c=42;
		const char* p = iuTest_PrintTo(s, &c, sizeof(c));
		IUTEST_ASSERT_STREQ("0x000000000000002A", p);
	}
	{
		int c[2]={42, 43};
		const char* p = iuTest_PrintTo(s, c, sizeof(c));
		IUTEST_ASSERT_STREQ("0x0000002B0000002A", p);
	}
#endif
	{
		char c[9]={42, 43, 44, 45, 46, 47, 48, 49, 50};
		const char* p = iuTest_PrintTo(s, c, sizeof(c));
		IUTEST_ASSERT_STREQ("{ 2A, 2B, 2C, 2D, 2E, 2F, 30, 31, 32 }", p);
	}
	{
		int c[4]={42, 43, 44, 45};
		const char* p = iuTest_PrintTo(s, c, sizeof(c));
		IUTEST_ASSERT_STREQ("{ 2A, 00, 00, 00, 2B, ... , 00, 2D, 00, 00, 00 }", p);
	}
}

IUTEST(XmlUnit, Escape)
{
	char str[64];
	iuXmlFile_EscapeXmlAttribute(str, "a<>	b& \'\"c\r\n");
	IUTEST_ASSERT_STREQ("a&lt;&gt;&#x09;b&amp; &apos;&quot;c&#x0D;&#x0A;", str);
}

