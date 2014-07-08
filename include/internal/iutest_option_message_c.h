/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_option_message_c.h
 * @brief		iris unit test �p �I�v�V�������b�Z�[�W
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_OPTION_MESSAGE_C_H_B8037C4F_8F86_4C64_B1FB_01F9018076A0_
#define INCG_IRIS_IUTEST_OPTION_MESSAGE_C_H_B8037C4F_8F86_4C64_B1FB_01F9018076A0_

/* include ===========================================================*/
#include "iutest_console_c.h"

IUTEST_EXTERN_C_BEGIN()

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	���������G���[�̏o��
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowNotinitializedWarning(void);

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION || IUTEST_C_HAS_COMMANDLINE_OPTION

/**
 * @brief	�o�[�W�����̏o��
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowVersion(void);

/**
 * @brief	�w���v�̏o��
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowHelp(void);

/**
 * @brief	�w���v�̏o��
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowHelpAndSorry(void);

/**
 * @brief	�@�\���̏o��
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowFeature(void);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "../impl/iutest_option_message_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
