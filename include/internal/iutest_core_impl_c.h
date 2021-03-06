/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_core_impl_c.h
 * @brief		iris unit test UnitTest implement
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_CORE_IMPL_C_H_D5ABC7DE_C751_4AC0_922F_547880163891_
#define INCG_IRIS_IUTEST_CORE_IMPL_C_H_D5ABC7DE_C751_4AC0_922F_547880163891_

IUTEST_EXTERN_C_BEGIN()

/* declare ===========================================================*/
struct iuTestResult_t;
struct iuTestInfo_t;
struct iuTestCase_t;

IUTEST_C_INL_INLINE struct iuTestInfo_t*		iuUnitTest_GetCurrentTestInfo(void);
IUTEST_C_INL_INLINE void						iuUnitTest_SetCurrentTestInfo(struct iuTestInfo_t* curr);

IUTEST_C_INL_INLINE struct iuTestResult_t*	iuUnitTest_GetCurrentTestResult(void);

/* typedef ===========================================================*/
typedef struct iuTestCase_t* (*iuTest_AllocTestCase)(void);

IUTEST_EXTERN_C_END()

#endif
