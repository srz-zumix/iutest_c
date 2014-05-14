/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_all.c
 * @brief		iris unit test ŽÀ‘• ƒtƒ@ƒCƒ‹
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/

/* include ===========================================================*/
#define IUTEST_C_USE_LIB
#include "../include/iutest_c.h"

IIUT_C_WORKSPACE_();

/* inl */
#include "../include/impl/iutest_defs_c.inl"
#include "../include/impl/iutest_port_c.inl"
#include "../include/impl/iutest_body_c.inl"
#include "../include/impl/iutest_assertion_c.inl"
#include "../include/impl/iutest_env_c.inl"
#include "../include/impl/iutest_info_c.inl"
#include "../include/impl/iutest_case_c.inl"
#include "../include/impl/iutest_core_c.inl"
#include "../include/impl/iutest_listener_c.inl"
#include "../include/impl/iutest_printer_c.inl"

#include "../include/impl/iutest_string_c.inl"
#include "../include/impl/iutest_console_c.inl"
#include "../include/impl/iutest_xml_file_c.inl"
#include "../include/impl/iutest_message_c.inl"
#include "../include/impl/iutest_regex_c.inl"
#include "../include/impl/iutest_option_message_c.inl"

#include "../include/impl/iutest_default_printer_c.inl"
#include "../include/impl/iutest_default_xml_generator_c.inl"
