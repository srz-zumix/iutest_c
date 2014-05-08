/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_libc_c.h
 * @brief		iris unit test libc ‘Î‰ž ƒtƒ@ƒCƒ‹
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_LIBC_C_H_193F89F4_8C8B_405E_A7CC_A0338271D103_
#define INCG_IRIS_IUTEST_LIBC_C_H_193F89F4_8C8B_405E_A7CC_A0338271D103_

/* include ===========================================================*/
#include "../iutest_config_c.h"
#include <stddef.h>
#include <limits.h>

#if IUTEST_C_HAS_STDARG
#  include <stdarg.h>
#endif

#if IUTEST_C_HAS_LIBC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define iu_memset	memset
#define iu_memcpy	memcpy

#else

static IUTEST_ATTRIBUTE_UNUSED_ void * iu_memcpy(void *buf1, const void *buf2, size_t n);
static IUTEST_ATTRIBUTE_UNUSED_ void * iu_memset(void *buf, int ch, size_t n);

#if !IUTEST_C_HAS_MEMCPY_AND_MEMSET

static void * memcpy(void *buf1, const void *buf2, size_t n)
{
	char *dst = (char *)buf1;
	char *src = (char *)buf2;
	size_t i =0;
	for( i=0; i < n; ++i, ++dst, ++src )
	{
		*dst = *src;
	}
	return buf1;
}

static void * memset(void *buf, int ch, size_t n)
{
	char *p = (char *)buf;
	size_t i =0;
	for( i=0; i < n; ++i, ++p )
	{
		*p = (char)ch;
	}
	return buf;
}

#endif

static IUTEST_ATTRIBUTE_UNUSED_ void * iu_memcpy(void *buf1, const void *buf2, size_t n)
{
	return memcpy(buf1, buf2, n);
}
static IUTEST_ATTRIBUTE_UNUSED_ void * iu_memset(void *buf, int ch, size_t n)
{
	return memset(buf, ch, n);
}

#endif

#if IUTEST_C_HAS_MALLOC

#define iu_malloc	malloc

#else

static IUTEST_ATTRIBUTE_UNUSED_ void * iu_malloc(size_t n) { (void)n; return NULL; }

#endif

/* sys/time.h */
#if !defined(IUTEST_C_HAS_HDR_SYSTIME)
#  if defined(IUTEST_OS_WINDOWS) && !defined(IUTEST_OS_WINDOWS_MINGW)
#    define IUTEST_C_HAS_HDR_SYSTIME	0
#  endif
#endif

#if !defined(IUTEST_C_HAS_HDR_SYSTIME)
#  define IUTEST_C_HAS_HDR_SYSTIME		1
#endif


#endif
