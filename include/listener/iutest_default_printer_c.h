/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_default_printer_c.h
 * @brief		iris unit test デフォルト出力 イベントリスナー ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_default_printer_C_H_FA31CAB7_32CB_4764_89FC_6AC5C0D25385_
#define INCG_IRIS_iutest_default_printer_C_H_FA31CAB7_32CB_4764_89FC_6AC5C0D25385_

/* include ===========================================================*/
#include "../iutest_core_c.h"
#include "../internal/iutest_console_c.h"

IUTEST_EXTERN_C_BEGIN()

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	OnTestProgramStart
*/
void iuTestDefaultPrinter_OnTestProgramStart(struct iuUnitTest_t *unit_test);

/**
 * @brief	OnTestIterationStart
*/
void iuTestDefaultPrinter_OnTestIterationStart(struct iuUnitTest_t *unit_test, int iteration);

/**
 * @brief	OnTestCaseStart
*/
void iuTestDefaultPrinter_OnTestCaseStart(struct iuTestCase_t *test_case);

/**
 * @brief	OnTestStart
*/
void iuTestDefaultPrinter_OnTestStart(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info);

/**
 * @brief	OnTestPartResult
*/
void iuTestDefaultPrinter_OnTestPartResult(struct iuTestPartResult_t *test_part_result);

/**
 * @brief	OnTestRecordProperty
*/
void iuTestDefaultPrinter_OnTestRecordProperty(struct iuTestProperty_t *test_property);

/**
 * @brief	OnTestEnd
*/
void iuTestDefaultPrinter_OnTestEnd(struct iuTestCase_t *test_case, struct iuTestInfo_t *test_info);

/**
 * @brief	OnTestCaseEnd
*/
void iuTestDefaultPrinter_OnTestCaseEnd(struct iuTestCase_t *test_case);

/**
 * @brief	OnTestIterationEnd
*/
void iuTestDefaultPrinter_OnTestIterationEnd(struct iuUnitTest_t *unit_test, int iteration);

/**
 * @brief	OnTestProgramEnd
*/
void iuTestDefaultPrinter_OnTestProgramEnd(struct iuUnitTest_t *unit_test);

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_default_printer_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
