/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_internal_defs_c.h
 * @brief		iris unit test def ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_DEFS_C_H_2EF67DBB_93CC_4C5A_BCB6_556CD9265270_
#define INCG_IRIS_IUTEST_DEFS_C_H_2EF67DBB_93CC_4C5A_BCB6_556CD9265270_

/* include ===========================================================*/
#include "iutest_compiler_c.h"
#include "iutest_pp_c.h"
#include "iutest_libc_c.h"

/* define ============================================================*/

/**
 * @brief	曖昧な else 文の警告抑制
*/
#ifdef __INTEL_COMPILER
#  define IUTEST_AMBIGUOUS_ELSE_BLOCKER_
#else
#  define IUTEST_AMBIGUOUS_ELSE_BLOCKER_	switch(iuAlwaysZero()) case 0: default:
#endif

/* SECTION */
#if IUTEST_PP_IS_EMPTY(IUTEST_TEST_SECTION_NAME)
#  define IUTEST_TEST_SECTION_
#  define IUTEST_INIT_SECTION_
#  define IUTEST_DATA_SECTION_
#else
#  define IUTEST_TEST_SECTION_	IUTEST_SECTION_(IUTEST_TEST_SECTION_NAME)
#  define IUTEST_INIT_SECTION_	IUTEST_SECTION2_(IUTEST_TEST_SECTION_NAME, init)
#  define IUTEST_DATA_SECTION_	IUTEST_SECTION2_(data, IUTEST_TEST_SECTION_NAME)
#endif


/* for C */
#if !defined(IUTEST_C_NO_AUTOREGISTER_TEST)

#if defined(_MSC_VER)
#  pragma section(".CRT$XCU", read)
#  define IUTEST_C_DECL_INITIALIZATION_SECTION(name)	\
	void	__cdecl name(void);							\
	static __declspec(allocate(".CRT$XCU")) void (__cdecl * IUTEST_PP_CAT(pfn,name))(void) = name;	\
	void	__cdecl name(void)

/* /OPT:REF で削除されないための対策 */
#  define IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN(name)	\
	IUTEST_C_DECL_INITIALIZATION_SECTION(name) {			\
		(void)IUTEST_PP_CAT(pfn,name);

#  define IUTEST_C_DECL_INITIALIZATION_SECTION_END()		\
	}

#elif	defined(__GNUC__)
#  define IUTEST_C_DECL_INITIALIZATION_SECTION(name)		\
	void	name(void) __attribute__((constructor));		\
	IUTEST_INIT_SECTION_ void name(void)

#  define IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN(name)	\
	IUTEST_C_DECL_INITIALIZATION_SECTION(name) {			\

#  define IUTEST_C_DECL_INITIALIZATION_SECTION_END()		\
	}

#else
#  define IUTEST_C_NO_AUTOREGISTER_TEST
#endif

#endif

#if defined(IUTEST_C_NO_AUTOREGISTER_TEST)
#  define IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN(name)	\
	IUTEST_INIT_SECTION_ void name(void) {

#  define IUTEST_C_DECL_INITIALIZATION_SECTION_END()		\
	}
#endif

/* 初期化関数の明示的呼び出し */
#  define IUTEST_C_CALL_INITIALIZATION_SECTION(name) do {	\
		IUTEST_PRAGMA_MSC_WARN_PUSH()						\
		IUTEST_PRAGMA_MSC_WARN_DISABLE(4210)				\
		extern void name(void);								\
		name();												\
		IUTEST_PRAGMA_MSC_WARN_POP()						\
	} while(iuAlwaysZero())



#ifndef IUTEST_C_BREAK
#  if   defined(_MSC_VER)
#    define IUTEST_C_BREAK()	__debugbreak()
#  elif defined(__MINGW32__)
#    define IUTEST_C_BREAK()	DebugBreak()
#  elif defined(IUTEST_OS_MAC)
/* http://www.cocoawithlove.com/2008/03/break-into-debugger.html */
#    if defined(__ppc64__) || defined(__ppc__)
#    define IUTEST_C_BREAK()	__asm__("li r0, 20\nsc\nnop\nli r0, 37\nli r4, 2\nsc\nnop\n" : : : "memory","r0","r3","r4" )
#    else
#    define IUTEST_C_BREAK()	__asm__("int $3\n" : : )
#    endif
#  elif defined(__GUNC__) && (defined (__i386__) || defined (__x86_64__))
#    define IUTEST_C_BREAK()	do { __asm{ int 3 } } while(::iutest::detail::AlwaysFalse())
#  elif defined(__clang__) || defined(__GNUC__)
#    define IUTEST_C_BREAK()	__builtin_trap()
#  elif defined(__ARMCC_VERSION)
#    define IUTEST_C_BREAK()	do { __breakpoint(0xF02C); } while(::iutest::detail::AlwaysFalse())
#  else
#    define IUTEST_C_BREAK()	*static_cast<volatile int*>(NULL) = 1;
#  endif
#endif

/**
 * @brief	リスト構造体ヘルパ
 * @{
*/

#define iuTestHelper_AddList(list_type, top, elem) do {		\
		if( (top) == NULL ) { (top) = (elem); }				\
		else {												\
			list_type *prev = (top);						\
			list_type *curr = (top)->next;					\
			while( curr != NULL ) {							\
				prev = curr; curr = curr->next;				\
			}												\
			prev->next = (elem);							\
		}													\
	} while(iuAlwaysZero())

#define iuTestHelper_FindList(list_type, top, elem, ret) do {	\
		list_type *curr = (top);							\
		(ret) = FALSE;										\
		while( curr != NULL ) {								\
			if( curr == elem ) { (ret) = TRUE;	break; }	\
			curr = curr->next;								\
		}													\
	} while(iuAlwaysZero())

#define iuTestHelper_CountList(counter, list_type, top)	do {	\
		list_type *curr = (top);								\
		(counter) = 0;											\
		while(curr != NULL) {									\
			++(counter);										\
			curr = curr->next;									\
		}														\
	} while(iuAlwaysZero())

#define iuTestHelper_ListGetAt(list_type, top, at, ret)	do {	\
		list_type *curr = (top);								\
		unsigned int i=0;										\
		for(i=0; i < (at); ++i ) {								\
			curr = curr->next;									\
		}														\
		(ret) = curr;											\
	} while(iuAlwaysZero())

#define iuTestHelper_ShuffleList(list_type, gen, count, top)	do {	\
		list_type *curr = top;											\
		list_type *pre = NULL;											\
		unsigned int i=2, n=count;										\
		for( i=2; i<n; ++i ) {											\
			list_type *rhs_pre=NULL, *rhs=NULL;							\
			unsigned int pos = (unsigned int)(gen % i);					\
			iuTestHelper_ListGetAt(list_type, top, pos, rhs);			\
			if( pos != 0 ) iuTestHelper_ListGetAt(list_type, top, pos-1u, rhs_pre);	\
			if( curr != rhs ) {											\
				if( pre == NULL ) {										\
					list_type *tmp = rhs->next;							\
					rhs->next = curr->next; curr->next = tmp;			\
					if( rhs_pre == curr ) rhs->next = curr;				\
					else rhs_pre->next = curr;							\
					top = rhs;											\
				} else if( rhs_pre == NULL ) {							\
					list_type *tmp = rhs->next;							\
					rhs->next = curr->next; curr->next = tmp;			\
					if( pre == rhs ) curr->next = rhs;					\
					else pre->next = rhs;								\
					top = curr;											\
				} else {												\
					list_type *tmp = rhs->next;							\
					rhs->next = curr->next; curr->next = tmp;			\
					if( pre == rhs ) curr->next = rhs;					\
					else pre->next = rhs;								\
					if( rhs_pre == curr ) rhs->next = curr;				\
					else rhs_pre->next = curr;							\
				}														\
				curr = rhs;												\
			}															\
			pre = curr;													\
			curr = curr->next;											\
		}																\
	} while(iuAlwaysZero())

/**
 * @}
*/

/* function ==========================================================*/
static IUTEST_ATTRIBUTE_UNUSED_ int iuAlwaysZero(void) { return 0; }
static IUTEST_ATTRIBUTE_UNUSED_ int iuAlwaysTrue(void) { return 1; }

#endif
