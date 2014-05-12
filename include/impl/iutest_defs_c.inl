/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_defs_c.inl
 * @brief		iris unit test def ƒtƒ@ƒCƒ‹
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_DEFS_C_INL_C65D73ED_BE82_4B01_8B5D_756A3C887B9A_
#define INCG_IRIS_IUTEST_DEFS_C_INL_C65D73ED_BE82_4B01_8B5D_756A3C887B9A_

/* include ===========================================================*/
#include "../iutest_defs_c.h"

/* function ==========================================================*/

#if IUTEST_C_HAS_FLOATINGPOINT

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuAlmostFloatEquals(float val1, float val2)
{
	iuF32Int fi1, fi2;
	fi1.fv = val1;
	fi2.fv = val2;
	{
		const iuInt32 kMaxUlps = 4;
		const iuInt32 v1 = fi1.iv < 0 ? ~fi1.iv + 1 : fi1.iv;
		const iuInt32 v2 = fi2.iv < 0 ? ~fi2.iv + 1 : fi2.iv;
		const iuInt32 diff = (v1 > v2) ? v1 - v2 : v2 - v1;
		if( diff <= kMaxUlps ) return TRUE;
	}
	return FALSE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuAlmostDoubleEquals(double val1, double val2)
{
	iuF64Int fi1, fi2;
	fi1.fv = val1;
	fi2.fv = val2;
	{
#if IUTEST_C_HAS_LONGLONG
		const iuInt64 kMaxUlps = 4;
		const iuInt64 v1 = fi1.iv < 0 ? ~fi1.iv + 1 : fi1.iv;
		const iuInt64 v2 = fi2.iv < 0 ? ~fi2.iv + 1 : fi2.iv;
		const iuInt64 diff = (v1 > v2) ? v1 - v2 : v2 - v1;
		if( diff <= kMaxUlps ) return TRUE;
#else
		const iuInt32 kMaxUlps = 4;
		if( fi1.iv.hi == fi2.iv.hi )
		{
			const iuInt32 v1 = fi1.iv.lo < 0 ? ~fi1.iv.lo + 1 : fi1.iv.lo;
			const iuInt32 v2 = fi2.iv.lo < 0 ? ~fi2.iv.lo + 1 : fi2.iv.lo;
			const iuInt32 diff = (v1 > v2) ? v1 - v2 : v2 - v1;
			if( diff <= kMaxUlps ) return TRUE;
		}
#endif
	}
	return FALSE;
}

#endif

#endif
