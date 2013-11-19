/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_option_message_c.inl
 * @brief		iris unit test 用 オプションメッセージ ファイル
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
#ifndef INCG_IRIS_iutest_option_message_C_INL_B8037C4F_8F86_4c64_B1FB_01F9018076A0_
#define INCG_IRIS_iutest_option_message_C_INL_B8037C4F_8F86_4c64_B1FB_01F9018076A0_

/* include ===========================================================*/
#include "../internal/iutest_option_message_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowNotinitializedWarning(void)
{
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("This test program did NOT call iuInitIrisUnitTest before calling IUTEST_RUN_ALL_TESTS().  Please fix it.\n");
#endif
	return 1;
}

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION || IUTEST_C_HAS_COMMANDLINE_OPTION

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowVersion(void)
{
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_Output("iutest version %x.%x.%x.%x\n"
			, IUTEST_C_MAJORVER, IUTEST_C_MINORVER, IUTEST_C_BUILD, IUTEST_C_REVISION);
#endif
	return 0;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowHelp(void)
{
#if IUTEST_C_HAS_CONSOLEOUT
	const char *name = 
		"--------------------------------------------------\n"
		"Name\n"
		"    iutest_c - iris unit test framework\n"
		;
	const char *option0 = 
		"--------------------------------------------------\n"
		"Command Line Options\n"
		"\n"
		;
	const char *option1 = 
		"    --help, -h                      : generate help message.\n"
		"    --iutest_output=xml[:path]      : path of xml report.\n"
		;
	const char *option2 = 
		"    --iutest_list_tests             : list up tests.\n"
		"    --iutest_color=<yes|no|auto>    : console color enable.\n"
		;
	const char *option3 = 
		"    --iutest_filter=<filter>        : Select the test run.\n"
		"    --iutest_shuffle                : do shuffle test.\n"
		;
	const char *option4 = 
		"    --iutest_random_seed=<seed>     : set random seed.\n"
		"    --iutest_also_run_disabled_tests: run disabled tests.\n"
		;
	const char *option5 = 
		"    --iutest_break_on_failure[=0|1] : When that failed to break.\n"
		"    --iutest_print_time=<0|1>       : Setting the display of elapsed time.\n"
		;
	const char *option6 = 
		"    --iutest_repeat=<count>         : Set the number of repetitions of the test.\n"
		"    --version, -v                   : show iutest version.\n"
		;
	const char *option_end = 
		"\n"
		"--------------------------------------------------\n"
		;
	const char *license = 
		"License\n"
		"\n"
		"    Copyright (c) 2012-2013 Takazumi-Shirayanagi,\n"
		"    All rights reserved.\n"
		"\n"
		"    The new(modified) BSD License is applied to this software, see LICENSE\n"
		"\n"
		;
	const int color = PRINT_CYAN;
	iuConsole_ColorOutput(color, name);
	iuConsole_ColorOutput(color, option0);
	iuConsole_ColorOutput(color, option1);
	iuConsole_ColorOutput(color, option2);
	iuConsole_ColorOutput(color, option3);
	iuConsole_ColorOutput(color, option4);
	iuConsole_ColorOutput(color, option5);
	iuConsole_ColorOutput(color, option6);
	iuConsole_ColorOutput(color, option_end);
	iuConsole_ColorOutput(color, license);
#endif
	return 0;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowHelpAndSorry(void)
{
	iuTest_ShowHelp();
#if IUTEST_C_HAS_CONSOLEOUT
	iuConsole_ColorOutput(PRINT_YELLOW, "sorry. Is not supported in a wide-character string.\n");
#endif
	return 1;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowFeature(void)
{
#if IUTEST_C_HAS_CONSOLEOUT
#  define SHOW_MACRO(macro)		iuConsole_Output("#define %s  %s\n", #macro, IUTEST_PP_TOSTRING(macro))
#  define SHOW_NO_MACRO(macro)	iuConsole_Output("#define %s\n", #macro)
#else
#  define SHOW_MACRO(macro)		(void)0
#  define SHOW_NO_MACRO(macro)	(void)0
#endif

#ifdef IUTEST_C_NO_FLOATINGPOINT
	SHOW_NO_MACRO(IUTEST_C_NO_FLOATINGPOINT);
#endif
#ifdef IUTEST_C_NO_VPRINTF
	SHOW_NO_MACRO(IUTEST_C_NO_VPRINTF);
#endif
#ifdef IUTEST_C_NO_WCHAR_T
	SHOW_NO_MACRO(IUTEST_C_NO_WCHAR_T);
#endif
#ifdef IUTEST_C_NO_STDARG
	SHOW_NO_MACRO(IUTEST_C_NO_STDARG);
#endif
#ifdef IUTEST_C_NO_LIBC
	SHOW_NO_MACRO(IUTEST_C_NO_LIBC);
#endif
#ifdef IUTEST_C_NO_MALLOC
	SHOW_NO_MACRO(IUTEST_C_NO_MALLOC);
#endif
#ifdef IUTEST_C_NO_LONGLONG
	SHOW_NO_MACRO(IUTEST_C_NO_LONGLONG);
#endif
#ifdef IUTEST_C_NO_GETENV
	SHOW_NO_MACRO(IUTEST_C_NO_GETENV);
#endif
#ifdef IUTEST_C_NO_PUTENV
	SHOW_NO_MACRO(IUTEST_C_NO_PUTENV);
#endif

	SHOW_MACRO(IUTEST_C_HAS_CLOCK);
	SHOW_MACRO(IUTEST_C_HAS_COMMANDLINE_OPTION);
	SHOW_MACRO(IUTEST_C_HAS_CTIME);
	SHOW_MACRO(IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION);
	SHOW_MACRO(IUTEST_C_HAS_FILEAPI);
	SHOW_MACRO(IUTEST_C_HAS_FLOATINGPOINT);
	SHOW_MACRO(IUTEST_C_HAS_GETTIMEOFDAY);
	SHOW_MACRO(IUTEST_C_HAS_HDR_STDINT);
	SHOW_MACRO(IUTEST_C_HAS_HDR_SYSTIME);
	SHOW_MACRO(IUTEST_C_HAS_HDR_TIME);
	SHOW_MACRO(IUTEST_C_HAS_LIB);
	SHOW_MACRO(IUTEST_C_HAS_LIBC);
	SHOW_MACRO(IUTEST_C_HAS_LONGLONG);
	SHOW_MACRO(IUTEST_C_HAS_MALLOC);
	SHOW_MACRO(IUTEST_C_HAS_PARAM_METHOD_TEST);
	SHOW_MACRO(IUTEST_C_HAS_PARAM_TEST);
	SHOW_MACRO(IUTEST_C_HAS_STDARG);
	SHOW_MACRO(IUTEST_C_HAS_VARIADIC_MACROS);
	SHOW_MACRO(IUTEST_C_HAS_WCHAR_T);

#if !IUTEST_C_HAS_MALLOC
	SHOW_MACRO(IUTEST_C_GLOBALENVSETUP_POOL_COUNT);
	SHOW_MACRO(IUTEST_C_GLOBALENVTEARDOWN_POOL_COUNT);
	SHOW_MACRO(IUTEST_C_LISTENER_POOL_COUNT);
	SHOW_MACRO(IUTEST_C_TESTMSGBUFFER_POOL_COUNT);
	SHOW_MACRO(IUTEST_C_TESTPARTRESULT_POOL_COUNT);
	SHOW_MACRO(IUTEST_C_TESTPROPERTY_POOL_COUNT);
#endif

	SHOW_MACRO(IUTEST_STDC_VER);
	SHOW_MACRO(IUTEST_PLATFORM);

#undef SHOW_MACRO
	return 0;
}

#endif

#endif
