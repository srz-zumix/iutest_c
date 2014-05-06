/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_default_xml_generator_c.h
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
#ifndef INCG_IRIS_iutest_default_xml_generator_c_H_791DCB98_05CC_49ba_8518_0EC9CA2B5450_
#define INCG_IRIS_iutest_default_xml_generator_c_H_791DCB98_05CC_49ba_8518_0EC9CA2B5450_

/* include ===========================================================*/
#include "../iutest_core_c.h"
#include "../internal/iutest_xml_file_c.h"

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
/**
 * @ingroup	IUTEST_CONFIG
 * @brief	xml 出力に skipped タグを含めるかどうか
*/
#if !defined(IUTEST_C_REPORT_SKIPPED)
#  define IUTEST_C_REPORT_SKIPPED		1
#endif

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB && IUTEST_C_HAS_DEFAULT_XML_GENERATOR

/**
 * @brief	OnTestProgramStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestProgramStart(struct iuUnitTest_t *unit_test);

/**
 * @brief	OnTestIterationStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestIterationStart(struct iuUnitTest_t *unit_test, int iteration);

/**
 * @brief	OnTestCaseStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestCaseStart(struct iuTestCase_t *test_case);

/**
 * @brief	OnTestStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestStart(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info);

/**
 * @brief	OnTestPartResult
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestPartResult(struct iuTestPartResult_t *test_part_result);

/**
 * @brief	OnTestRecordProperty
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestRecordProperty(struct iuTestProperty_t *test_property);

/**
 * @brief	OnTestEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestEnd(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info);

/**
 * @brief	OnTestCaseEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestCaseEnd(struct iuTestCase_t *test_case);

/**
 * @brief	OnTestIterationEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestIterationEnd(struct iuUnitTest_t *unit_test, int iteration);

/**
 * @brief	OnTestProgramEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestDefaultXMLGenerator_OnTestProgramEnd(struct iuUnitTest_t *unit_test);

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_default_xml_generator_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
