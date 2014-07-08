/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_static_assertion_c.h
 * @brief		iris unit test static assertion
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_STATIC_ASSERTION_C_H_53842FD6_9E5D_40A6_905D_EC6DEBE5ED6A_
#define INCG_IRIS_IUTEST_STATIC_ASSERTION_C_H_53842FD6_9E5D_40A6_905D_EC6DEBE5ED6A_

/* define ============================================================*/
/**
 * @brief	static_assert
*/
#define IUTEST_STATIC_ASSERT_MSG(B, Msg)	\
	typedef char IUTEST_PP_CAT(IUTEST_PP_CAT(static_assert_typedef_, __LINE__),IUTEST_PP_COUNTER)[(iuBOOL)( B ) ? 1 : -1]

/**
 * @brief	static_assert
*/
#ifdef IUTEST_NO_VARIADIC_MACROS
#  define IUTEST_STATIC_ASSERT(B)		IUTEST_STATIC_ASSERT_MSG(B, "")
#else
#  define IUTEST_STATIC_ASSERT(...)		IUTEST_STATIC_ASSERT_MSG((__VA_ARGS__), "")
#endif

#ifdef IUTEST_HAS_COUNTER_MACRO
#ifdef IUTEST_NO_VARIADIC_MACROS
#  define IUTEST_PP_STATIC_ASSERT(B)	IUTEST_STATIC_ASSERT_MSG(B, "")
#else
#  define IUTEST_PP_STATIC_ASSERT(...)	IUTEST_STATIC_ASSERT_MSG((__VA_ARGS__), "")
#endif
#else
#ifdef IUTEST_NO_VARIADIC_MACROS
#  define IUTEST_PP_STATIC_ASSERT(B)	
#else
#  define IUTEST_PP_STATIC_ASSERT(...)	
#endif
#endif

#endif
