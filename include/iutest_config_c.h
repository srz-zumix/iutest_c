/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_config_c.h
 * @brief		iris unit test config ファイル
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
 * @brief		設定マクロ
 * @note		ユーザーが事前定義することで変更可能
 * @{
*/

/*! Library を使うかどうか */
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
 * @brief		言語機能 CONFIG
 * @{
*/

/*! 浮動小数点数が使用可能かどうか */
#if !defined(IUTEST_C_HAS_FLOATINGPOINT)
#  if !defined(IUTEST_C_NO_FLOATINGPOINT)
#    define IUTEST_C_HAS_FLOATINGPOINT	1
#  else
#    define IUTEST_C_HAS_FLOATINGPOINT	0
#  endif
#endif

/*! wchar_t が使用可能かどうか */
#if !defined(IUTEST_C_HAS_WCHAR_T)
#  if !defined(IUTEST_C_NO_WCHAR_T)
#    define IUTEST_C_HAS_WCHAR_T	1
#  else
#    define IUTEST_C_HAS_WCHAR_T	0
#  endif
#endif

/*! stdarg.h が使用可能かどうか */
#if !defined(IUTEST_C_HAS_STDARG)
#  if !defined(IUTEST_C_NO_STDARG)
#    define IUTEST_C_HAS_STDARG		1
#  else
#    define IUTEST_C_HAS_STDARG		0
#  endif
#endif

/*! 標準ライブラリが使用可能かどうか */
#if !defined(IUTEST_C_HAS_LIBC)
#  if !defined(IUTEST_C_NO_LIBC)
#    define IUTEST_C_HAS_LIBC		1
#  else
#    define IUTEST_C_HAS_LIBC		0
#  endif
#endif

/*! stdint.h があるかどうか */
#if !defined(IUTEST_C_HAS_HDR_STDINT)
#  if defined(_MSC_VER) && _MSC_VER < 1600
#    define IUTEST_C_HAS_HDR_STDINT	0
#  else
#    define IUTEST_C_HAS_HDR_STDINT	1
#  endif
#endif

/*! malloc 関数が使用可能かどうか */
#if !defined(IUTEST_C_HAS_MALLOC)
#  if !defined(IUTEST_C_NO_MALLOC) && IUTEST_C_HAS_LIBC
#    define IUTEST_C_HAS_MALLOC		1
#  else
#    define IUTEST_C_HAS_MALLOC		0
#  endif
#endif

/*! long long が使用可能かどうか */
#if !defined(IUTEST_C_HAS_LONGLONG)
#  if !defined(IUTEST_C_NO_LONGLONG)
#    define IUTEST_C_HAS_LONGLONG	1
#  else
#    define IUTEST_C_HAS_LONGLONG	0
#  endif
#endif

/*! 可変長マクロが使用可能かどうか */
#if !defined(IUTEST_C_HAS_VARIADIC_MACROS)
#  ifdef IUTEST_C_NO_VARIADIC_MACROS
#    define IUTEST_C_HAS_VARIADIC_MACROS	0
#  else
#    define IUTEST_C_HAS_VARIADIC_MACROS	1
#  endif
#endif

/*! getenv があるかどうか */
#if !defined(IUTEST_C_NO_GETENV)
#  if !IUTEST_C_HAS_LIBC
#    define IUTEST_C_NO_GETENV
#  endif
#endif

/*! putenv があるかどうか */
#if !defined(IUTEST_C_NO_PUTENV)
#  if !IUTEST_C_HAS_LIBC
#    define IUTEST_C_NO_PUTENV
#  endif
#endif

/*! memcpy & memset があるかどうか */
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
 * @brief		出力関係 CONFIG
 * @{
*/

/*! vprintf があるかどうか */
#if !defined(IUTEST_C_HAS_VPRINTF)
#  if IUTEST_C_HAS_LIBC && !defined(IUTEST_C_NO_VPRINTF)
#    define IUTEST_C_HAS_VPRINTF	1
#  else
#    define IUTEST_C_HAS_VPRINTF	0
#  endif
#endif

/*! printf があるかどうか */
#if !defined(IUTEST_C_HAS_PRINTF)
#  if IUTEST_C_HAS_LIBC && !defined(IUTEST_C_NO_PRINTF)
#    define IUTEST_C_HAS_PRINTF		1
#  else
#    define IUTEST_C_HAS_PRINTF		0
#  endif
#endif

/*! vprintf 呼び出しマクロ */
#if !defined(IUTEST_VPRINTF)
#  if IUTEST_C_HAS_VPRINTF
#    define IUTEST_VPRINTF(f, a)	vprintf(f, a)
#  else
#    define IUTEST_VPRINTF(f, a)	(void)0
#  endif
#endif

/*! printf 呼び出しマクロ */
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
 * @brief		テスト関係 CONFIG
 * @{
*/

/*! パラメタライズ関数コールテストが使用可能かどうか */
#if !defined(IUTEST_C_HAS_PARAM_METHOD_TEST)
#  if IUTEST_C_HAS_VARIADIC_MACROS
#    define IUTEST_C_HAS_PARAM_METHOD_TEST	1
#  else
#    define IUTEST_C_HAS_PARAM_METHOD_TEST	0
#  endif
#endif

/*! 値のパラメータ化テストが使用可能かどうか */
#if !defined(IUTEST_C_HAS_PARAM_TEST)
#  if IUTEST_C_HAS_VARIADIC_MACROS
#    define IUTEST_C_HAS_PARAM_TEST		1
#  else
#    define IUTEST_C_HAS_PARAM_TEST		0
#  endif
#endif

/*! Combine が使用可能かどうか */
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
 * @brief		リスナー関係 CONFIG
 * @{
*/

/*! デフォルト XML ジェネレーターが使用可能かどうか */
#if !defined(IUTEST_C_HAS_DEFAULT_XML_GENERATOR)
#  define IUTEST_C_HAS_DEFAULT_XML_GENERATOR	1
#endif

/**
 * @}
*/

/**
 * @defgroup	IUTEST_CONFIG_FILE	FILE
 * @brief		ファイル関係 CONFIG
 * @{
*/

/*! FILE IO 関係の関数が使用可能かどうか */
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
 * @brief		TIME関係 CONFIG
 * @{
*/

/*! time.h があるかどうか */
#if !defined(IUTEST_C_HAS_HDR_TIME)
#  if IUTEST_C_HAS_LIBC
#    define IUTEST_C_HAS_HDR_TIME	1
#  else
#    define IUTEST_C_HAS_HDR_TIME	0
#  endif
#endif

/*! time 関数が使用可能かどうか */
#if !defined(IUTEST_C_HAS_CTIME)
#  if IUTEST_C_HAS_HDR_TIME
#    define IUTEST_C_HAS_CTIME		1
#  else
#    define IUTEST_C_HAS_CTIME		0
#  endif
#endif

/*! gettimeofday 関数が使用可能かどうか */
#if !defined(IUTEST_C_HAS_GETTIMEOFDAY)
#  if IUTEST_C_HAS_HDR_SYSTIME
#    define IUTEST_C_HAS_GETTIMEOFDAY	1
#  else
#    define IUTEST_C_HAS_GETTIMEOFDAY	0
#  endif
#endif

/*! clock 関数が使用可能かどうか */
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
 * @brief		その他の CONFIG
 * @{
*/

/*! IUTEST が生成するテスト関数のセクション名 */
#if !defined(IUTEST_TEST_SECTION_NAME)
#  define IUTEST_TEST_SECTION_NAME
#endif

/*! printf 出力が可能かどうか */
#if !defined(IUTEST_C_HAS_CONSOLEOUT)
#  if IUTEST_C_HAS_STDARG && IUTEST_C_HAS_VPRINTF
#    define IUTEST_C_HAS_CONSOLEOUT		1
#  else
#    define IUTEST_C_HAS_CONSOLEOUT		0
#  endif
#endif

/*! コマンドラインオプション解析を使用するかどうか */
#if !defined(IUTEST_C_HAS_COMMANDLINE_OPTION)
#  define IUTEST_C_HAS_COMMANDLINE_OPTION	1
#endif

/*! 環境変数オプション解析を使用するかどうか */
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
 * @brief		メモリプール CONFIG
 * @{
*/

#if !IUTEST_C_HAS_MALLOC || defined(IUTEST_BUILD_DOXYGEN)

/*! malloc が使えない場合の TestResult の Pool 総数 */
#if !defined(IUTEST_C_TESTPARTRESULT_POOL_COUNT)
#  define IUTEST_C_TESTPARTRESULT_POOL_COUNT	512
#endif

/*! malloc が使えない場合の TestProerty の Pool 総数 */
#if !defined(IUTEST_C_TESTPROPERTY_POOL_COUNT)
#  define IUTEST_C_TESTPROPERTY_POOL_COUNT		128
#endif

/*! malloc が使えない場合の TestListner の Pool 総数 */
#if !defined(IUTEST_C_LISTENER_POOL_COUNT)
#  define IUTEST_C_LISTENER_POOL_COUNT			8
#endif

/*! malloc が使えない場合の iuTestGlobalEnvSetUp の Pool 総数 */
#if !defined(IUTEST_C_GLOBALENVSETUP_POOL_COUNT)
#  define IUTEST_C_GLOBALENVSETUP_POOL_COUNT	8
#endif

/*! malloc が使えない場合の iuTestGlobalEnvTearDown の Pool 総数 */
#if !defined(IUTEST_C_GLOBALENVTEARDOWN_POOL_COUNT)
#  define IUTEST_C_GLOBALENVTEARDOWN_POOL_COUNT	8
#endif

/*! malloc が使えない場合の テストメッセージバッファ の Pool 総数 */
#if !defined(IUTEST_C_TESTMSGBUFFER_POOL_COUNT)
#  define IUTEST_C_TESTMSGBUFFER_POOL_COUNT		16*1024
#endif

#endif

/**
 * @}
*/


/* Doxygen 用 */
#ifdef IUTEST_BUILD_DOXYGEN

#define IUTEST_C_NO_FLOATINGPOINT	/*!< 浮動小数点数が使えない場合は定義 */
#define IUTEST_C_NO_VPRINTF			/*!< vprintf 関数が使えない場合は定義 */
#define IUTEST_C_NO_PRINTF			/*!< printf 関数が使えない場合は定義 */
#define IUTEST_C_NO_WCHAR_T			/*!< wchar_t がない場合は定義 */
#define IUTEST_C_NO_STDARG			/*!< stdarg.h がない場合は定義 */
#define IUTEST_C_NO_LIBC			/*!< libc が使えない場合は定義 */
#define IUTEST_C_NO_MALLOC			/*!< malloc がない場合は定義 */
#define IUTEST_C_NO_LONGLONG		/*!< long long が使えない場合 */

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
