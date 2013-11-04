/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_defs_c.h
 * @brief		iris unit test def ÉtÉ@ÉCÉã
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
#ifndef INCG_IRIS_iutest_defs_c_H_C65D73ED_BE82_4b01_8B5D_756A3C887B9A_
#define INCG_IRIS_iutest_defs_c_H_C65D73ED_BE82_4b01_8B5D_756A3C887B9A_

/* include ===========================================================*/
#include "internal/iutest_internal_defs_c.h"
#if IUTEST_C_HAS_HDR_STDINT
#include <stdint.h>
#endif

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/

/**
 * @private
 * @{
*/
#define IUTEST_SUPPRESS_UNREACHABLE_CODE_WARNING(statement)	if( iuAlwaysTrue() ) statement

/**
 * @}
*/

/* typedef ===========================================================*/
#if IUTEST_C_HAS_HDR_STDINT

typedef int8_t		iuInt8;
typedef uint8_t		iuUInt8;
typedef int16_t		iuInt16;
typedef uint16_t	iuUInt16;
typedef int32_t		iuInt32;
typedef uint32_t	iuUInt32;

#if IUTEST_C_HAS_LONGLONG
typedef int64_t		iuInt64;
typedef uint64_t	iuUInt64;
#endif

#else
typedef signed char		iuInt8;
typedef unsigned char	iuUInt8;
typedef signed short	iuInt16;
typedef unsigned short	iuUInt16;
typedef int				iuInt32;
typedef unsigned int	iuUInt32;

#if IUTEST_C_HAS_LONGLONG

#if defined(_MSC_VER)
typedef __int64				iuInt64;
typedef unsigned __int64	iuUInt64;
#else
typedef long long			iuInt64;
typedef unsigned long long	iuUInt64;
#endif

#endif

#endif

#if IUTEST_C_HAS_LONGLONG

typedef iuUInt64	iuTimeInMillisec;

#else

typedef iuUInt32	iuTimeInMillisec;

typedef struct iuUInt64
{
	iuUInt32	lo;
	iuUInt32	hi;
} iuUInt64, iuInt64;

#endif


/* struct ============================================================*/

#if IUTEST_C_HAS_FLOATINGPOINT

typedef union iuF32Int
{
	float fv;
	iuInt32 iv;
	iuUInt32 uv;
} iuF32Int;

typedef union iuF64Int
{
	double fv;
	iuInt64 iv;
	iuUInt64 uv;
} iuF64Int;

#endif


/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

#if IUTEST_C_HAS_FLOATINGPOINT
/**
 * @brief	float ÇÃÇ†Ç¢Ç‹Ç¢î‰är
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuAlmostFloatEquals(float val1, float val2);

/**
 * @brief	double ÇÃÇ†Ç¢Ç‹Ç¢î‰är
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuAlmostDoubleEquals(double val1, double val2);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_defs_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
