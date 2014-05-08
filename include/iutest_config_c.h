/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_config_c.h
 * @brief		iris unit test config �t�@�C��
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_CONFIG_C_H_A0485AB5_8AD8_4AA1_ACD1_A8D0F897E5A4_
#define INCG_IRIS_IUTEST_CONFIG_C_H_A0485AB5_8AD8_4AA1_ACD1_A8D0F897E5A4_

/* define ============================================================*/

/**
 * @defgroup	IUTEST_CONFIG	IUTEST_CONFIG
 * @brief		�ݒ�}�N��
 * @note		���[�U�[�����O��`���邱�ƂŕύX�\
 * @{
*/

/*! Library ���g�����ǂ��� */
#if !defined(IUTEST_C_HAS_LIB)
#  if	defined(IUTEST_C_NO_LIB)
#    define IUTEST_C_HAS_LIB		0
#  elif	defined(IUTEST_C_USE_LIB) || defined(IUTEST_C_AUTO_LINK)
#    define IUTEST_C_HAS_LIB		1
#  endif
#endif

#if !defined(IUTEST_C_HAS_LIB)
#  define IUTEST_C_HAS_LIB			0
#endif

/**
 * @defgroup	IUTEST_CONFIG_C_LANG	C_LANG
 * @brief		����@�\ CONFIG
 * @{
*/

/*! ���������_�����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_FLOATINGPOINT)
#  if !defined(IUTEST_C_NO_FLOATINGPOINT)
#    define IUTEST_C_HAS_FLOATINGPOINT	1
#  else
#    define IUTEST_C_HAS_FLOATINGPOINT	0
#  endif
#endif

/*! wchar_t ���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_WCHAR_T)
#  if !defined(IUTEST_C_NO_WCHAR_T)
#    define IUTEST_C_HAS_WCHAR_T	1
#  else
#    define IUTEST_C_HAS_WCHAR_T	0
#  endif
#endif

/*! stdarg.h ���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_STDARG)
#  if !defined(IUTEST_C_NO_STDARG)
#    define IUTEST_C_HAS_STDARG		1
#  else
#    define IUTEST_C_HAS_STDARG		0
#  endif
#endif

/*! �W�����C�u�������g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_LIBC)
#  if !defined(IUTEST_C_NO_LIBC)
#    define IUTEST_C_HAS_LIBC		1
#  else
#    define IUTEST_C_HAS_LIBC		0
#  endif
#endif

/*! stdint.h �����邩�ǂ��� */
#if !defined(IUTEST_C_HAS_HDR_STDINT)
#  if defined(_MSC_VER) && _MSC_VER < 1600
#    define IUTEST_C_HAS_HDR_STDINT	0
#  else
#    define IUTEST_C_HAS_HDR_STDINT	1
#  endif
#endif

/*! malloc �֐����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_MALLOC)
#  if !defined(IUTEST_C_NO_MALLOC) && IUTEST_C_HAS_LIBC
#    define IUTEST_C_HAS_MALLOC		1
#  else
#    define IUTEST_C_HAS_MALLOC		0
#  endif
#endif

/*! long long ���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_LONGLONG)
#  if !defined(IUTEST_C_NO_LONGLONG)
#    define IUTEST_C_HAS_LONGLONG	1
#  else
#    define IUTEST_C_HAS_LONGLONG	0
#  endif
#endif

/*! �ϒ��}�N�����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_VARIADIC_MACROS)
#  ifdef IUTEST_C_NO_VARIADIC_MACROS
#    define IUTEST_C_HAS_VARIADIC_MACROS	0
#  else
#    define IUTEST_C_HAS_VARIADIC_MACROS	1
#  endif
#endif

/*! getenv �����邩�ǂ��� */
#if !defined(IUTEST_C_NO_GETENV)
#  if !IUTEST_C_HAS_LIBC
#    define IUTEST_C_NO_GETENV
#  endif
#endif

/*! putenv �����邩�ǂ��� */
#if !defined(IUTEST_C_NO_PUTENV)
#  if !IUTEST_C_HAS_LIBC
#    define IUTEST_C_NO_PUTENV
#  endif
#endif

/*! memcpy & memset �����邩�ǂ��� */
#if !defined(IUTEST_C_HAS_MEMCPY_AND_MEMSET)
#  if IUTEST_C_HAS_LIBC || defined(_MSC_VER)
#    define IUTEST_C_HAS_MEMCPY_AND_MEMSET	1
#  else
#    define IUTEST_C_HAS_MEMCPY_AND_MEMSET	0
#  endif
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_OUTPUT	OUTPUT
 * @brief		�o�͊֌W CONFIG
 * @{
*/

/*! vprintf �����邩�ǂ��� */
#if !defined(IUTEST_C_HAS_VPRINTF)
#  if IUTEST_C_HAS_LIBC && !defined(IUTEST_C_NO_VPRINTF)
#    define IUTEST_C_HAS_VPRINTF	1
#  else
#    define IUTEST_C_HAS_VPRINTF	0
#  endif
#endif

/*! printf �����邩�ǂ��� */
#if !defined(IUTEST_C_HAS_PRINTF)
#  if IUTEST_C_HAS_LIBC && !defined(IUTEST_C_NO_PRINTF)
#    define IUTEST_C_HAS_PRINTF		1
#  else
#    define IUTEST_C_HAS_PRINTF		0
#  endif
#endif

/*! vprintf �Ăяo���}�N�� */
#if !defined(IUTEST_VPRINTF)
#  if IUTEST_C_HAS_VPRINTF
#    define IUTEST_VPRINTF(f, a)	vprintf(f, a)
#  else
#    define IUTEST_VPRINTF(f, a)	(void)0
#  endif
#endif

/*! printf �Ăяo���}�N�� */
#if !defined(IUTEST_PRINTF)
#  if IUTEST_C_HAS_PRINTF
#    if IUTEST_C_HAS_VARIADIC_MACROS
#      if defined(__GNUC__)
#        define IUTEST_PRINTF(msg, ...)	printf(msg, ##__VA_ARGS__)
#      else
#        define IUTEST_PRINTF(...)		printf(__VA_ARGS__)
#      endif
#    else
#      define IUTEST_PRINTF				printf
#    endif
#  else
#    if IUTEST_C_HAS_VARIADIC_MACROS
#      define IUTEST_PRINTF(...)		(void)0
#    else
#      define IUTEST_PRINTF				(void)
#    endif
#  endif
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_TEST	TEST
 * @brief		�e�X�g�֌W CONFIG
 * @{
*/

/*! �p�����^���C�Y�֐��R�[���e�X�g���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_PARAM_METHOD_TEST)
#  if IUTEST_C_HAS_VARIADIC_MACROS
#    define IUTEST_C_HAS_PARAM_METHOD_TEST	1
#  else
#    define IUTEST_C_HAS_PARAM_METHOD_TEST	0
#  endif
#endif

/*! �l�̃p�����[�^���e�X�g���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_PARAM_TEST)
#  if IUTEST_C_HAS_VARIADIC_MACROS
#    define IUTEST_C_HAS_PARAM_TEST		1
#  else
#    define IUTEST_C_HAS_PARAM_TEST		0
#  endif
#endif

/*! Combine ���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_COMBINE)
#  if IUTEST_C_HAS_VARIADIC_MACROS && IUTEST_C_HAS_PARAM_TEST
#    define IUTEST_C_HAS_COMBINE		1
#  else
#    define IUTEST_C_HAS_COMBINE		0
#  endif
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_LISTNER LISTENER
 * @brief		���X�i�[�֌W CONFIG
 * @{
*/

/*! �f�t�H���g XML �W�F�l���[�^�[���g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_DEFAULT_XML_GENERATOR)
#  define IUTEST_C_HAS_DEFAULT_XML_GENERATOR	1
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_FILE	FILE
 * @brief		�t�@�C���֌W CONFIG
 * @{
*/

/*! FILE IO �֌W�̊֐����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_FILEAPI)
#  if	!defined(IUTEST_C_NO_FILEAPI) && IUTEST_C_HAS_LIBC
#    define IUTEST_C_HAS_FILEAPI	1
#  else
#    define IUTEST_C_HAS_FILEAPI	0
#  endif
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_TIME	TIME
 * @brief		TIME�֌W CONFIG
 * @{
*/

/*! time.h �����邩�ǂ��� */
#if !defined(IUTEST_C_HAS_HDR_TIME)
#  if IUTEST_C_HAS_LIBC
#    define IUTEST_C_HAS_HDR_TIME	1
#  else
#    define IUTEST_C_HAS_HDR_TIME	0
#  endif
#endif

/*! time �֐����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_CTIME)
#  if IUTEST_C_HAS_HDR_TIME
#    define IUTEST_C_HAS_CTIME		1
#  else
#    define IUTEST_C_HAS_CTIME		0
#  endif
#endif

/*! gettimeofday �֐����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_GETTIMEOFDAY)
#  if IUTEST_C_HAS_HDR_SYSTIME
#    define IUTEST_C_HAS_GETTIMEOFDAY	1
#  else
#    define IUTEST_C_HAS_GETTIMEOFDAY	0
#  endif
#endif

/*! clock �֐����g�p�\���ǂ��� */
#if !defined(IUTEST_C_HAS_CLOCK)
#  ifdef CLOCKS_PER_SEC
#    define IUTEST_C_HAS_CLOCK		1
#  else
#    define IUTEST_C_HAS_CLOCK		0
#  endif
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_OTHER	OTHER
 * @brief		���̑��� CONFIG
 * @{
*/

/*! IUTEST ����������e�X�g�֐��̃Z�N�V������ */
#if !defined(IUTEST_TEST_SECTION_NAME)
#  define IUTEST_TEST_SECTION_NAME
#endif

/*! printf �o�͂��\���ǂ��� */
#if !defined(IUTEST_C_HAS_CONSOLEOUT)
#  if IUTEST_C_HAS_STDARG && IUTEST_C_HAS_VPRINTF
#    define IUTEST_C_HAS_CONSOLEOUT		1
#  else
#    define IUTEST_C_HAS_CONSOLEOUT		0
#  endif
#endif

/*! �R�}���h���C���I�v�V������͂��g�p���邩�ǂ��� */
#if !defined(IUTEST_C_HAS_COMMANDLINE_OPTION)
#  define IUTEST_C_HAS_COMMANDLINE_OPTION	1
#endif

/*! ���ϐ��I�v�V������͂��g�p���邩�ǂ��� */
#if !defined(IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION)
#  if defined(IUTEST_C_NO_GETENV)
#    define IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION	0
#  else
#    define IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION	1
#  endif
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_POOL	MEMORY_POOL
 * @brief		�������v�[�� CONFIG
 * @{
*/

#if !IUTEST_C_HAS_MALLOC || defined(IUTEST_BUILD_DOXYGEN)

/*! malloc ���g���Ȃ��ꍇ�� TestResult �� Pool ���� */
#if !defined(IUTEST_C_TESTPARTRESULT_POOL_COUNT)
#  define IUTEST_C_TESTPARTRESULT_POOL_COUNT	512
#endif

/*! malloc ���g���Ȃ��ꍇ�� TestProerty �� Pool ���� */
#if !defined(IUTEST_C_TESTPROPERTY_POOL_COUNT)
#  define IUTEST_C_TESTPROPERTY_POOL_COUNT		128
#endif

/*! malloc ���g���Ȃ��ꍇ�� TestListner �� Pool ���� */
#if !defined(IUTEST_C_LISTENER_POOL_COUNT)
#  define IUTEST_C_LISTENER_POOL_COUNT			8
#endif

/*! malloc ���g���Ȃ��ꍇ�� iuTestGlobalEnvSetUp �� Pool ���� */
#if !defined(IUTEST_C_GLOBALENVSETUP_POOL_COUNT)
#  define IUTEST_C_GLOBALENVSETUP_POOL_COUNT	8
#endif

/*! malloc ���g���Ȃ��ꍇ�� iuTestGlobalEnvTearDown �� Pool ���� */
#if !defined(IUTEST_C_GLOBALENVTEARDOWN_POOL_COUNT)
#  define IUTEST_C_GLOBALENVTEARDOWN_POOL_COUNT	8
#endif

/*! malloc ���g���Ȃ��ꍇ�� �e�X�g���b�Z�[�W�o�b�t�@ �� Pool ���� */
#if !defined(IUTEST_C_TESTMSGBUFFER_POOL_COUNT)
#  define IUTEST_C_TESTMSGBUFFER_POOL_COUNT		16*1024
#endif

#endif

/**
 * @}
*/


/* Doxygen �p */
#ifdef IUTEST_BUILD_DOXYGEN

#define IUTEST_C_NO_FLOATINGPOINT	/*!< ���������_�����g���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_VPRINTF			/*!< vprintf �֐����g���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_PRINTF			/*!< printf �֐����g���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_WCHAR_T			/*!< wchar_t ���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_STDARG			/*!< stdarg.h ���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_LIBC			/*!< libc ���g���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_MALLOC			/*!< malloc ���Ȃ��ꍇ�͒�` */
#define IUTEST_C_NO_LONGLONG		/*!< long long ���g���Ȃ��ꍇ */

#endif

/**
 * @}
*/

/**
 * @private
 * @{
*/

/* include only */
#if !defined(IUTEST_C_INL_INLINE)
#  if IUTEST_C_HAS_LIB
#    define IUTEST_C_INL_INLINE
#  else
#    define IUTEST_C_INL_INLINE		static
#  endif
#endif

/* auto link */
#if IUTEST_C_HAS_LIB && defined(IUTEST_C_AUTO_LINK)

#if defined(_MSC_VER)

#if defined(_MT) || defined(__MT__)
#  if	defined(_DLL)
#    define IUTEST_LIB_THREAD_OPT	"md"
#  else
#    define IUTEST_LIB_THREAD_OPT	"mt"
#  endif
#else
#  define IUTEST_LIB_THREAD_OPT	""
#endif

#if		_MSC_VER == 1400
#  define IUTEST_LIB_TOOLSET	"vc80"
#elif	_MSC_VER == 1500
#  define IUTEST_LIB_TOOLSET	"vc90"
#elif	_MSC_VER == 1600
#  define IUTEST_LIB_TOOLSET	"vc100"
#elif	_MSC_VER == 1700
#  define IUTEST_LIB_TOOLSET	"vc110"
#else
#  error unkown _MSC_VER.
#endif

#if		defined(_DEBUG)
#  define IUTEST_LIB_RT_OPT		"d"
#else
#  define IUTEST_LIB_RT_OPT		""
#endif

#define IUTEST_LIB_NAME(name)	#name "-" IUTEST_LIB_TOOLSET "-" IUTEST_LIB_THREAD_OPT IUTEST_LIB_RT_OPT ".lib"

#pragma comment(lib, IUTEST_LIB_NAME(libiutest_c) )

#endif

#endif

/**
 * @}
*/

#endif
