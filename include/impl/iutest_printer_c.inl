/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_printer_c.inl
 * @brief		iris unit test printer ƒtƒ@ƒCƒ‹
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_PRINTER_C_INL_ADF851F3_C89B_4CA4_B9A0_A2B2229945C6_
#define INCG_IRIS_IUTEST_PRINTER_C_INL_ADF851F3_C89B_4CA4_B9A0_A2B2229945C6_

/* include ===========================================================*/
#include "../iutest_printer_c.h"

/* function ==========================================================*/

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU8(char *dst, iuUInt8 data)
{
	dst[0] = '0';
	dst[1] = 'x';
	dst[2] = iuString_ToHex((int)((data>> 4)&0xF));
	dst[3] = iuString_ToHex((int)((data>> 0)&0xF));
	dst[4] = '\0';
	return dst;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU16(char *dst, iuUInt16 data)
{
	dst[0] = '0';
	dst[1] = 'x';
	dst[2] = iuString_ToHex((int)((data>>12)&0xF));
	dst[3] = iuString_ToHex((int)((data>> 8)&0xF));
	dst[4] = iuString_ToHex((int)((data>> 4)&0xF));
	dst[5] = iuString_ToHex((int)((data>> 0)&0xF));
	dst[6] = '\0';
	return dst;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU32(char *dst, iuUInt32 data)
{
	dst[0] = '0';
	dst[1] = 'x';
	dst[2] = iuString_ToHex((int)((data>>28)&0xF));
	dst[3] = iuString_ToHex((int)((data>>24)&0xF));
	dst[4] = iuString_ToHex((int)((data>>20)&0xF));
	dst[5] = iuString_ToHex((int)((data>>16)&0xF));
	dst[6] = iuString_ToHex((int)((data>>12)&0xF));
	dst[7] = iuString_ToHex((int)((data>> 8)&0xF));
	dst[8] = iuString_ToHex((int)((data>> 4)&0xF));
	dst[9] = iuString_ToHex((int)((data>> 0)&0xF));
	dst[10] = '\0';
	return dst;
}

#if IUTEST_C_HAS_LONGLONG

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_	char* iuTest_PrintToU64(char *dst, iuUInt64 data)
{
	dst[ 0] = '0';
	dst[ 1] = 'x';
	dst[ 2] = iuString_ToHex((int)((data>>60)&0xF));
	dst[ 3] = iuString_ToHex((int)((data>>56)&0xF));
	dst[ 4] = iuString_ToHex((int)((data>>52)&0xF));
	dst[ 5] = iuString_ToHex((int)((data>>48)&0xF));
	dst[ 6] = iuString_ToHex((int)((data>>44)&0xF));
	dst[ 7] = iuString_ToHex((int)((data>>40)&0xF));
	dst[ 8] = iuString_ToHex((int)((data>>36)&0xF));
	dst[ 9] = iuString_ToHex((int)((data>>32)&0xF));
	dst[10] = iuString_ToHex((int)((data>>28)&0xF));
	dst[11] = iuString_ToHex((int)((data>>24)&0xF));
	dst[12] = iuString_ToHex((int)((data>>20)&0xF));
	dst[13] = iuString_ToHex((int)((data>>16)&0xF));
	dst[14] = iuString_ToHex((int)((data>>12)&0xF));
	dst[15] = iuString_ToHex((int)((data>> 8)&0xF));
	dst[16] = iuString_ToHex((int)((data>> 4)&0xF));
	dst[17] = iuString_ToHex((int)((data>> 0)&0xF));
	dst[18] = '\0';
	return dst;
}

#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ char* iuTest_PrintTo(char* dst, const void *buf, size_t size)
{
	char* p = dst;
	if( dst != NULL && buf != NULL && size != 0 )
	{
		const size_t MAX=10u;
		if( size == 1 )
		{
			return iuTest_PrintToU8(dst, *(iuUInt8*)buf);
		}
		else if( size == 2 )
		{
			return iuTest_PrintToU16(dst, *(iuUInt16*)buf);
		}
		else if( size == 4 )
		{
			return iuTest_PrintToU32(dst, *(iuUInt32*)buf);
		}
#if IUTEST_C_HAS_LONGLONG
		else if( size == 8 )
		{
			return iuTest_PrintToU64(dst, *(iuUInt64*)buf);
		}
#endif
		else
		{
			unsigned char *src = (unsigned char*)buf;
			size_t i=0;
			*dst++ = '{';
			*dst++ = ' ';
			*dst++ = iuString_ToHex(((*src)>>4)&0xF);
			*dst++ = iuString_ToHex(((*src)>>0)&0xF);
			++src;
			if( size < MAX )
			{
				for( i=1; i < size; ++i, ++p )
				{
					*dst++ = ',';
					*dst++ = ' ';
					*dst++ = iuString_ToHex(((*src)>>4)&0xF);
					*dst++ = iuString_ToHex(((*src)>>0)&0xF);
				}
			}
			else
			{
				for( i=1; i < (MAX+1)/2; ++i, ++p )
				{
					*dst++ = ',';
					*dst++ = ' ';
					*dst++ = iuString_ToHex(((*src)>>4)&0xF);
					*dst++ = iuString_ToHex(((*src)>>0)&0xF);
				}
				*dst++ = '.';
				*dst++ = '.';
				*dst++ = '.';
				*dst++ = ' ';
				p += size - MAX;
				for( i=0; i < MAX/2; ++i, ++p )
				{
					*dst++ = ',';
					*dst++ = ' ';
					*dst++ = iuString_ToHex(((*src)>>4)&0xF);
					*dst++ = iuString_ToHex(((*src)>>0)&0xF);
				}
			}
			*dst++ = ' ';
			*dst++ = '}';
			*dst = '\0';
		}
	}
	return p;
}

#endif
