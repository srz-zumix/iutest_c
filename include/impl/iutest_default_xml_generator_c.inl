/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_default_xml_generator_c.inl
 * @brief		iris unit test xml 出力イベントリスナー ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_default_xml_generator_c_INL_791DCB98_05CC_49ba_8518_0EC9CA2B5450_
#define INCG_IRIS_iutest_default_xml_generator_c_INL_791DCB98_05CC_49ba_8518_0EC9CA2B5450_

/* include ===========================================================*/
#include "../listener/iutest_default_xml_generator_c.h"

#if IUTEST_C_HAS_DEFAULT_XML_GENERATOR

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestProgramStart(struct iuUnitTest_t *unit_test)
{
	IUTEST_UNUSED_VAR(unit_test);
}

/**
 * @brief	OnTestIterationStart
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestIterationStart(struct iuUnitTest_t *unit_test, int iteration)
{
	IUTEST_UNUSED_VAR(unit_test);
	IUTEST_UNUSED_VAR(iteration);
}

/**
 * @brief	OnTestCaseStart
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestCaseStart(struct iuTestCase_t *test_case)
{
	IUTEST_UNUSED_VAR(test_case);
}

/**
 * @brief	OnTestStart
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestStart(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info)
{
	IUTEST_UNUSED_VAR(test_case);
	IUTEST_UNUSED_VAR(test_info);
}

/**
 * @brief	OnTestPartResult
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestPartResult(struct iuTestPartResult_t *test_part_result)
{
	IUTEST_UNUSED_VAR(test_part_result);
}

/**
 * @brief	OnTestRecordProperty
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestRecordProperty(struct iuTestProperty_t *test_property)
{
	IUTEST_UNUSED_VAR(test_property);
}

/**
 * @brief	OnTestEnd
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestEnd(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info)
{
	IUTEST_UNUSED_VAR(test_case);
	IUTEST_UNUSED_VAR(test_info);
}

/**
 * @brief	OnTestCaseEnd
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestCaseEnd(struct iuTestCase_t *test_case)
{
	IUTEST_UNUSED_VAR(test_case);
}

/**
 * @brief	OnTestIterationEnd
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestIterationEnd(struct iuUnitTest_t *unit_test, int iteration)
{
	IUTEST_UNUSED_VAR(unit_test);
	IUTEST_UNUSED_VAR(iteration);
}

#if IUTEST_C_HAS_FILEAPI

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnReportTestInfo(FILE* fp, struct iuTestInfo_t *test_info)
{
	if( fp == NULL ) return;

	{
		char buf[1024];
		iuXmlFile_EscapeXmlAttribute(buf, test_info->name);
		fprintf(fp, "    <testcase name=\"%s\" ", buf );

		if( iuTestInfo_IsRanTest(test_info) )
			fprintf(fp, "status=\"run\" ");
		else
			fprintf(fp, "status=\"notrun\" ");

		iuTest_FormatTimeInMillisecAsSecond(buf, test_info->result.elapsedmsec);
		fprintf(fp, "time=\"%s\" ", buf);

		iuXmlFile_EscapeXmlAttribute(buf, test_info->testcase_name);
		fprintf(fp, "classname=\"%s\"", buf);

		/* propertys */
		{
			iuTestProperty* curr = test_info->result.properties;
			while(curr != NULL)
			{
				iuXmlFile_EscapeXmlAttribute(buf, curr->key);
				fprintf(fp, " %s=", buf);
				iuXmlFile_EscapeXmlAttribute(buf, curr->value);
				fprintf(fp, "\"%s\"", buf);
				curr = curr->next;
			}
		}

		if( iuTestInfo_HasFailure(test_info) )
		{
			iuTestPartResult* curr = test_info->result.list;
			fprintf(fp, ">\n");
			while(curr != NULL)
			{
				if( iuTestPartResult_IsFailed(curr) )
				{
					char failure_buf[2048];
					iuXmlFile_EscapeXmlAttribute(failure_buf, curr->message);
					fprintf(fp, "      <failure message=\"");
					fprintf(fp, "%s", failure_buf);
					fprintf(fp, "\" type=\"\">");
					{
						char cddata[4096]={0};
						iuTest_FormatCompilerIndependentFileLocation(cddata, curr->file, curr->line);
						iu_strcat(cddata, "\n");
						iu_strcat(cddata, curr->message);
						iuXmlFile_OutputCDataSection(fp, cddata);
					}
					fprintf(fp, "\n      </failure>\n");
				}
				curr = curr->next;
			}
			fprintf(fp, "    </testcase>\n");
		}
		else
		{
#if IUTEST_C_REPORT_SKIPPED
			iuBOOL should_run = iuTestInfo_IsShouldRunTest(test_info);
			if( !should_run )
			{
				fprintf(fp, ">\n");
				fprintf(fp, "      <skipped />\n");
				fprintf(fp, "    </testcase>\n");
			}
			else
#endif
			{
				fprintf(fp, " />\n");
			}
		}
	}
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnReportTestCase(FILE* fp, struct iuTestCase_t *test_case)
{
	if( fp == NULL ) return;

	{
		char buf[1024];
		iuXmlFile_EscapeXmlAttribute(buf, test_case->name);
		fprintf(fp, "  <testsuite name=\"%s\" tests=\"%d\" failures=\"%d\" disabled=\"%d\" "
			, buf
			, iuTestCase_GetTotalTestCount(test_case)
			, iuTestCase_GetFailureTestCount(test_case)
			, iuTestCase_GetDisableTestCount(test_case)
			);
	}
#if IUTEST_C_REPORT_SKIPPED
	fprintf(fp, "skip=\"%d\" ", iuTestCase_GetSkipTestCount(test_case) );
#endif
	{
		char time_buf[32];
		iuTest_FormatTimeInMillisecAsSecond(time_buf, test_case->elapsedmsec);
		fprintf(fp, "errors=\"0\" time=\"%s\">\n", time_buf);
	}
	{
		iuTestInfo* curr = test_case->list;
		while( curr != NULL )
		{
			iuTestDefaultXMLGenerator_OnReportTestInfo(fp, curr);
			curr = curr->next;
		}
	}
	fprintf(fp, "  </testsuite>\n");
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnReportTests(FILE* fp, struct iuUnitTest_t *unit_test)
{
	if( fp == NULL ) return;

	fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(fp, "<testsuites tests=\"%d\" failures=\"%d\" disabled=\"%d\" "
		, iuUnitTest_GetTotalTestCount(unit_test)
		, iuUnitTest_GetFailureTestCount(unit_test)
		, iuUnitTest_GetDisableTestCount(unit_test)
		);
#if IUTEST_C_REPORT_SKIPPED
	fprintf(fp, "skip=\"%d\" ", iuUnitTest_GetSkipTestCount(unit_test) );
#endif
	{
		char time_buf[32];
		iuTest_FormatTimeInMillisecAsSecond(time_buf, unit_test->elapsedmsec);
		fprintf(fp, "errors=\"0\" time=\"%s\" ", time_buf);
	}
	if( iuTestEnv_IsEnableShuffleTests() )
	{
		fprintf(fp, "random_seed=\"%u\" ", iuUnitTest_GetCurrentRandomSeed());
	}
	fprintf(fp, "name=\"AllTests\">\n");

	{
		iuTestCase* curr = unit_test->list;
		while( curr != NULL )
		{
			iuTestDefaultXMLGenerator_OnReportTestCase(fp, curr);
			curr = curr->next;
		}

	}
	fprintf(fp, "</testsuites>\n");
}
#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnOutputReport(struct iuUnitTest_t *unit_test)
{
#if IUTEST_C_HAS_FILEAPI

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()
	FILE* fp = NULL;
	const char* filepath = NULL;
	const char* output = IIUT_C_TESTENV().option.output;
	if(output == NULL) return;

	{
		const char* file = iu_strchr(output + 3, ':');
		if( file != NULL )
		{
			filepath = file + 1;
		}
		else
		{
			filepath = "test_detail.xml";
		}
	}
	fp = fopen(filepath, "wb");
	iuTestDefaultXMLGenerator_OnReportTests(fp, unit_test);
	fclose(fp);
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()

#else
	IUTEST_UNUSED_VAR(unit_test);
#endif
}

/**
 * @brief	OnTestProgramEnd
*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestProgramEnd(struct iuUnitTest_t *unit_test)
{
	iuTestDefaultXMLGenerator_OnOutputReport(unit_test);
}

#endif

#endif
