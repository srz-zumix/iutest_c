/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_env_c.h
 * @brief		iris unit test �� �t�@�C��
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
#ifndef INCG_IRIS_iutest_env_C_H_DC5C5193_7081_4fef_B668_283CAEFA1F77_
#define INCG_IRIS_iutest_env_C_H_DC5C5193_7081_4fef_B668_283CAEFA1F77_

/* include ===========================================================*/
#include "iutest_listener_c.h"
#include "internal/iutest_random_c.h"
#include "internal/iutest_string_c.h"

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
/**
 * @private
 * @{
*/
#define IIUT_C_TESTENV_NAME		g_iutest_c_testenv_instance
#define IIUT_C_TESTENV()		IIUT_C_TESTENV_NAME
/**
 * @}
*/

#define IUTEST_FLAG(name)		IIUT_C_TESTENV().option.name

/* enum ==============================================================*/
typedef enum IUTESTENV_FLAG
{
	IUTESTENV_FILTERING_TESTS		= 0x0004,	/*!< �t�B���^�����O */
	IUTESTENV_CONSOLECOLOR_ON		= 0x0010,	/*!< �F���o��ON */
	IUTESTENV_CONSOLECOLOR_OFF		= 0x0020,	/*!< �F���o��OFF */
	IUTESTENV_CONSOLECOLOR_ANSI		= 0x0040,	/*!< �G�X�P�[�v�V�[�P���X�ŏo�� */
	IUTESTENV_OUTPUT_XML_REPORT		= 0x0100,	/*!< xml �o�� */
	IUTESTENV_SHOWHELP_AND_SORRY	= 0x0400,	/*!< �w���v���o�� */
	IUTESTENV_SHOWHELP				= 0x0800,	/*!< �w���v���o�� */
	IUTESTENV_SHOWVER				= 0x1000,	/*!< �o�[�W�����o�� */
	IUTESTENV_SHOWTESTSLIST			= 0x2000,	/*!< �e�X�g���X�g�o�� */
	IUTESTENV_SHOWFEATURE			= 0x4000,	/*!< �@�\���o�� */

	IUTESTENV_FLAG_DEFAULT			= 0
} IUTESTENV_FLAG;

/* declare ===========================================================*/
struct iuTestPartResult_t;

/* typedef ===========================================================*/
#if IUTEST_C_HAS_STDARG
typedef int (*iuVPrintf)(const char* fmt, va_list va);
#endif
typedef void (*iuGlobalEnvironmentSetUp)(void);
typedef void (*iuGlobalEnvironmentTearDown)(void);
typedef iuBOOL (*iuTestCommitTestPartResult)(struct iuTestPartResult_t* part_result, void* user);

/* struct ============================================================*/
/**
 * @brief	�O���[�o���� SetUp �\����
*/
typedef struct iuTestGlobalEnvSetUp_t
{
	iuGlobalEnvironmentSetUp		func;	/*!< SetUp �֐� */
	struct iuTestGlobalEnvSetUp_t*	next;	/*!< ���̍\���� */
} iuTestGlobalEnvSetUp;

/**
 * @brief	�O���[�o���� TearDown �\����
*/
typedef struct iuTestGlobalEnvTearDown_t
{
	iuGlobalEnvironmentTearDown			func;	/*!< TearDown �֐� */
	struct iuTestGlobalEnvTearDown_t*	next;	/*!< ���̍\���� */
} iuTestGlobalEnvTearDown;

/**
 * @brief	���ʂ̓o�^�R�[���o�b�N�֐����
*/
typedef struct iuTestCommitPartResultInfo_t
{
	iuTestCommitTestPartResult func;
	void* user;
} iuTestCommitPartResultInfo;

/**
 * @brief	�e�X�g���\����
*/
typedef struct iuTestEnv_t
{
	iuTestListener*	listeners;		/*!< ���X�i�[���X�g */
	iuTestGlobalEnvSetUp*		env_setup;		/*!< �O���[�o���� SetUp ���X�g */
	iuTestGlobalEnvTearDown*	env_teardown;	/*!< �O���[�o���� TearDown ���X�g */
#if IUTEST_C_HAS_STDARG
	iuVPrintf		pfnvpritf;		/*!< vprintf �֐��|�C���^ */
#endif
	iuUInt32		flag;			/*!< �t���O */
	iuUInt32		current_seed;	/*!< �����V�[�h�̌��ݒl */
	iuRandomContext	random_context;	/*!< �����R���e�L�X�g */
	iuTestCommitPartResultInfo	commit_result;	/*!< �e�X�g���ʂ̓o�^�R�[���o�b�N�֐� */

	/* �I�v�V���� */
	struct {
		const char*		filter;			/*!< �e�X�g�t�B���^�����O������ */
		const char*		output;			/*!< �o�͕����� */
		int				repeat;			/*!< ���s�[�g�J�E���g */
		iuUInt32		random_seed;	/*!< �����V�[�h�̐ݒ�l */
		iuBOOL			shuffle;		/*!< �V���b�t���e�X�g */
		iuBOOL			print_time;		/*!< �o�ߎ��Ԃ̏o�� */
		iuBOOL			break_on_failure;			/*!< �e�X�g���s���Ƀu���[�N */
		iuBOOL			also_run_disabled_tests;	/*!< DISABLED �e�X�g�����s */
	} option;
} iuTestEnv;

/* define ============================================================*/
/**
 * @private
 * @{
*/
#define iuTestEnvOption_ctor()	{ NULL, NULL, 1, 0, FALSE, TRUE, FALSE, FALSE }
#if IUTEST_C_HAS_STDARG
#define iuTestEnv_ctor()	{ NULL, NULL, NULL, NULL, IUTESTENV_FLAG_DEFAULT, 0		\
								, iuRandomContext_ctor(), { NULL, NULL }, iuTestEnvOption_ctor() }
#else
#define iuTestEnv_ctor()	{ NULL, NULL, NULL, IUTESTENV_FLAG_DEFAULT, 0		\
								, iuRandomContext_ctor(), { NULL, NULL }, iuTestEnvOption_ctor() }
#endif
/**
 * @}
*/

/* extern ============================================================*/
extern iuTestEnv	IIUT_C_TESTENV_NAME;

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB
/**
 * @brief	�e�X�g���C���X�^���X�̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestEnv* iuTestEnv_GetInstance(void);

#if IUTEST_C_HAS_STDARG
/**
 * @brief	vprintf �֐��|�C���^��ݒ�
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_SetVPrintfFunction(iuTestEnv* test_env, iuVPrintf proc);

#endif

/**
 * @brief	TestListener �̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestEnv_AddTestListener(iuTestEnv* test_env, iuTestListener* test_listener);

/**
 * @brief	TestListener �̍폜
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuTestEnv_SubTestListener(iuTestEnv* test_env, iuTestListener* test_listener);

/**
 * @brief	GlobalEnvironmentSetUp �̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_AddGlobalEnvironmentSetUp(iuTestEnv* test_env, iuGlobalEnvironmentSetUp func);

/**
 * @brief	GlobalEnvironmentTearDown �̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_AddGlobalEnvironmentTearDown(iuTestEnv* test_env, iuGlobalEnvironmentTearDown func);

/**
 * @brief	GlobalEnvironmentSetUp �̎��s
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_GlobalEnvironmentSetUp(void);

/**
 * @brief	GlobalEnvironmentTearDown �̎��s
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_GlobalEnvironmentTearDown(void);

/**
 * @brief	OnTestProgramStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestProgramStart(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnTestIterationStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestIterationStart(struct iuUnitTest_t* unit_test, int iteration);

/**
 * @brief	OnEnvironmentsSetUpStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsSetUpStart(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnEnvironmentsSetUpEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsSetUpEnd(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnTestCaseStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestCaseStart(struct iuTestCase_t* test_case);

/**
 * @brief	OnTestStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestStart(struct iuTestCase_t* test_case, struct iuTestInfo_t* test_info);

/**
 * @brief	OnTestPartResult
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestPartResult(struct iuTestPartResult_t* test_part_result);

/**
 * @brief	OnTestRecordProperty
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestRecordProperty(struct iuTestProperty_t* test_property);

/**
 * @brief	OnTestEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestEnd(struct iuTestCase_t* test_case, struct iuTestInfo_t* test_info);

/**
 * @brief	OnTestCaseEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void IUTEST_ATTRIBUTE_UNUSED_ iuTestEnv_ListenerEvent_OnTestCaseEnd(struct iuTestCase_t* test_case);

/**
 * @brief	OnEnvironmentsTearDownStart
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsTearDownStart(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnEnvironmentsTearDownEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnEnvironmentsTearDownEnd(struct iuUnitTest_t* unit_test);

/**
 * @brief	OnTestIterationEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestIterationEnd(struct iuUnitTest_t* unit_test, int iteration);

/**
 * @brief	OnTestProgramEnd
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_ListenerEvent_OnTestProgramEnd(struct iuUnitTest_t* unit_test);

/**
 * @brief	�e�X�g���̃Z�b�g�A�b�v
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuTestEnv_SetUp(iuTestEnv* test_env);

/**
 * @brief	DISABLED �e�X�g�����s���邩�ǂ���
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableRunDisabledTests(void);

/**
 * @brief	�V���b�t���e�X�g���ǂ���
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableShuffleTests(void);

/**
 * @brief	�e�X�g���s���� BREAK ���邩�ǂ���
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTestEnv_IsEnableBreakOnFailure(void);

/**
 * @brief	���ԏo�͂��邩�ǂ���
*/
iuBOOL iuTestEnv_IsEnablePrintTime(void);

/**
 * @biref	xml �o�͂��邩�ǂ���
*/
iuBOOL iuTestEnv_IsEnableOutputXml(void);

/**
 * @brief	�e�X�g�t���O���L�����ǂ���
*/
iuBOOL iuTestEnv_IsEnableFlag(int mask);

/**
 * @brief	�����V�[�h�̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuTestEnve_GetCurrentRandomSeed(void);

#if IUTEST_C_HAS_COMMANDLINE_OPTION
/**
 * @brief	�R�}���h���C�������̉��
*/
IUTEST_C_INL_INLINE void iuTestEnv_ParseCommandLineA(int* pargc, char** argv);

#if IUTEST_C_HAS_WCHAR_T
/**
 * @brief	�R�}���h���C�������̉��
*/
IUTEST_C_INL_INLINE void iuTestEnv_ParseCommandLineW(int* pargc, wchar_t** argv);
#endif

#endif

#if IUTEST_C_HAS_ENVIRONMENTSVAR_OPTION

/**
 * @brief	���ϐ��̓ǂݎ��
*/
void iuTestEnv_LoadEnviromentVariable(void);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_env_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
