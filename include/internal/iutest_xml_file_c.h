/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_xml_file_c.h
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
#ifndef INCG_IRIS_IUTEST_XML_FILE_C_H_E22B02D7_E9E7_412C_B609_DC3D9C66895D_
#define INCG_IRIS_IUTEST_XML_FILE_C_H_E22B02D7_E9E7_412C_B609_DC3D9C66895D_

/* include ===========================================================*/
#include "iutest_string_c.h"

IUTEST_EXTERN_C_BEGIN()

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
#if IUTEST_C_HAS_FILEAPI

IUTEST_ATTRIBUTE_UNUSED_ void iuXmlFile_OutputCDataSection(FILE* fp, const char* data);

#endif

IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuXmlFile_EscapeXmlAttribute(char* dst, const char* src);
//IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuXmlFile_EscapeXmlText(char* dst, const char* src);

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_xml_file_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
