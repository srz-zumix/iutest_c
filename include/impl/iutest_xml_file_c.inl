/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_xml_file_c.inl
 * @brief		iris unit test XML file helper
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_XML_FILE_C_INL_E22B02D7_E9E7_412C_B609_DC3D9C66895D_
#define INCG_IRIS_IUTEST_XML_FILE_C_INL_E22B02D7_E9E7_412C_B609_DC3D9C66895D_

/* include ===========================================================*/
#include "../internal/iutest_xml_file_c.h"

/* function ==========================================================*/
#if IUTEST_C_HAS_FILEAPI

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuXmlFile_OutputCDataSection(FILE* fp, const char* data)
{
	fprintf(fp, "<![CDATA[");
	fprintf(fp, "%s", data);
	fprintf(fp, "]]>");
}

#endif

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuXmlFile_EscapeCharactor(char* dst, const char* src, iuBOOL is_attribute)
{
	if( src == NULL ) return FALSE;
	{
		char* p = dst;
		for( ; *src; ++src )
		{
			switch(*src)
			{
			case '<':
				*p++ = '&';
				*p++ = 'l';
				*p++ = 't';
				*p++ = ';';
				break;
			case '>':
				*p++ = '&';
				*p++ = 'g';
				*p++ = 't';
				*p++ = ';';
				break;
			case '&':
				*p++ = '&';
				*p++ = 'a';
				*p++ = 'm';
				*p++ = 'p';
				*p++ = ';';
				break;
			case '\'':
				if( is_attribute )
				{
					*p++ = '&';
					*p++ = 'a';
					*p++ = 'p';
					*p++ = 'o';
					*p++ = 's';
					*p++ = ';';
				}
				else
				{
					*p++ = *src;
				}
				break;
			case '\"':
				if( is_attribute )
				{
					*p++ = '&';
					*p++ = 'q';
					*p++ = 'u';
					*p++ = 'o';
					*p++ = 't';
					*p++ = ';';
				}
				else
				{
					*p++ = *src;
				}
				break;
			default:
				if( iuString_IsValidXmlCharacter(*src) )
				{
					if( is_attribute
						&& iuString_IsWhitespace(*src) )
					{
						*p++ = '&';
						*p++ = '#';
						*p++ = 'x';
						*p++ = iuString_ToHex((*src>>4)&0xF);
						*p++ = iuString_ToHex((*src   )&0xF);
						*p++ = ';';
					}
					else
					{
						*p++ = *src;
					}
				}
				break;
			}
		}
		*p = '\0';
	}
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuXmlFile_EscapeXmlAttribute(char* dst, const char* src)
{
	return iuXmlFile_EscapeCharactor(dst, src, TRUE);
}
//IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuXmlFile_EscapeXmlText(char* dst, const char* src)
//{
//	return iuXmlFile_EscapeCharactor(dst, src, FALSE);
//}

#endif
