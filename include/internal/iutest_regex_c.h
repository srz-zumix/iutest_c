/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_regex_c.h
 * @brief		iris unit test 用 regex ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_regex_C_H_1575CB44_189A_4248_B305_DB4882E3BFC2_
#define INCG_IRIS_iutest_regex_C_H_1575CB44_189A_4248_B305_DB4882E3BFC2_

IUTEST_EXTERN_C_BEGIN()

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestRegex_Match(const char* regex, const char* src);

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_regex_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
