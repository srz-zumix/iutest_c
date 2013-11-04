/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_compiler_c.h
 * @brief		iris unit test compiler 依存の吸収 ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_iutest_compiler_C_H_6DDB27E8_E2FF_4754_80B0_F500025820C4_
#define INCG_IRIS_iutest_compiler_C_H_6DDB27E8_E2FF_4754_80B0_F500025820C4_

/* typedef ===========================================================*/
typedef int iuBOOL;

/* define　===========================================================*/
/* os */
#if		defined(__CYGWIN__)
#  define IUTEST_OS_CYGWIN				1
#  define IUTEST_PLATFORM				"CYGWIN"
#elif	defined(_WIN32) || defined(WIN32) || defined(__WIN32__)
#  define IUTEST_OS_WINDOWS				1
#  define IUTEST_PLATFORM				"Windows"
#  include <windows.h>
#  if	defined(_WIN32_WCE)
#    define IUTEST_OS_WINDOWS_MOBILE	1
#  elif	defined(__MINGW__) || defined(__MINGW32__)
#    define IUTEST_OS_WINDOWS_MINGW		1
#  elif	defined(__CUDACC__)
#    define IUTEST_OS_WINDOWS_CUDA		1
#  else
#    define IUTEST_OS_WINDOWS_DESKTOP	1
#  endif
#elif	defined(__APPLE__)
#  include "TargetConditionals.h"
#  ifdef TARGET_OS_IPHONE
#    define IUTEST_OS_IOS				1
#    ifdef TARGET_IPHONE_SIMULATOR
#      define IUTEST_OS_IOS_SIMULATOR	1
#      define IUTEST_PLATFORM			"iOS Simulator"
#    else
#      define IUTEST_PLATFORM			"iOS"
#    endif
#  else
#    define IUTEST_OS_MAC				1
#    define IUTEST_PLATFORM				"Mac OS"
#  endif
#elif	defined(sun) || defined(__sun)
#  define IUTEST_OS_SOLARIS				1
#  define IUTEST_PLATFORM				"Solaris"
#elif	defined(__linux__)
#  define IUTEST_OS_LINUX				1
#  define IUTEST_PLATFORM				"LINUX"
#  ifdef ANDROID
#    define IUTEST_OS_LINUX_ANDROID		1
#  endif
#elif	defined(__native_client__)
#  define IUTEST_OS_NACL				1
#  define IUTEST_PLATFORM				"Google Native Client"
#endif

#if defined(IUTEST_OS_LINUX_ANDROID)
#  include <android/api-level.h>
#endif

/* stdc version */
#if !defined(IUTEST_STDC_VER)
#  if defined(__STRICT_ANSI__) && defined(__STDC__) && (__STDC__ == 1)
#    if defined(__STDC_VERSION__)
#      define IUTEST_STDC_VER	__STDC_VERSION__
#    else
#      define IUTEST_STDC_VER	199000L
#    endif
#  else
#    define IUTEST_STDC_VER		0
#  endif
#endif

#define IUTEST_HAS_C90		(IUTEST_STDC_VER == 199000L)
#define IUTEST_HAS_AMD1		(IUTEST_STDC_VER == 199409L)
#define IUTEST_HAS_C99		(IUTEST_STDC_VER == 199901L)
#define IUTEST_HAS_C11		(IUTEST_STDC_VER == 201112L)

/* attribute */
#ifndef IUTEST_ATTRIBUTE_UNUSED_
#  if defined(__GNUC__) && !defined(COMPILER_ICC)
#    define IUTEST_ATTRIBUTE_UNUSED_	__attribute__ ((unused))
#  else
#    define IUTEST_ATTRIBUTE_UNUSED_
#  endif
#endif

#ifndef IUTEST_SECTION_
#  if defined(__GNUC__) && !defined(COMPILER_ICC)
#    define IUTEST_SECTION_(name)	IUTEST_SECTION_I_(name)
#    define IUTEST_SECTION_I_(name)	IUTEST_SECTION_D_("." #name)
#    define IUTEST_SECTION2_(name1, name2)		IUTEST_SECTION2_I_(name1,name2)
#    define IUTEST_SECTION2_I_(name1, name2)	IUTEST_SECTION_D_("." #name1 "." #name2)
#    define IUTEST_SECTION_D_(name)	__attribute__ ((section(name)))
#  else
#    define IUTEST_SECTION_(name)
#    define IUTEST_SECTION2_(name1, name2)
#  endif
#endif

/* 可変長引数マクロ */
#ifndef IUTEST_C_NO_VARIADIC_MACROS
#  if	defined(_MSC_VER) && (_MSC_VER < 1500)
#    define IUTEST_C_NO_VARIADIC_MACROS
#  elif	!defined(__GNUC__) && IUTEST_HAS_C90
#    define IUTEST_C_NO_VARIADIC_MACROS
#  endif
#endif

/* __COUNTER__ マクロ */
#ifndef IUTEST_C_HAS_COUNTER_MACRO
#  if	defined(_MSC_VER) && (_MSC_VER >= 1300)
#    define IUTEST_C_HAS_COUNTER_MACRO		1
#  elif defined(__clang__)
#    define IUTEST_C_HAS_COUNTER_MACRO		1
#  elif	defined(__GNUC__)
#    if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
#      define IUTEST_HAS_COUNTER_MACRO		1
#    endif
#  endif
#endif

#ifndef IUTEST_C_HAS_COUNTER_MACRO
#  define IUTEST_C_HAS_COUNTER_MACRO		0
#endif

#if defined(__cplusplus)
#  define IUTEST_EXTERN_C_BEGIN()	extern "C" {
#  define IUTEST_EXTERN_C_END()		}
#else
#  define IUTEST_EXTERN_C_BEGIN()	
#  define IUTEST_EXTERN_C_END()		
#endif

#ifndef NULL
#  if defined(__cplusplus)
#    define NULL	0
#  else
#    define NULL	(void*)0
#  endif
#endif

#ifndef TRUE
#  define TRUE	1
#endif

#ifndef FALSE
#  define FALSE	0
#endif

/* include ==========================================================*/
#include "iutest_pragma_c.h"

#endif
