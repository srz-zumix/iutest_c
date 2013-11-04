/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_core_c.h
 * @brief		iris unit test core �t�@�C��
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
#ifndef INCG_IRIS_iutest_core_c_H_5D8217F4_1A99_4dd8_A103_7DCBCA25ABAE_
#define INCG_IRIS_iutest_core_c_H_5D8217F4_1A99_4dd8_A103_7DCBCA25ABAE_

/* include ===========================================================*/
#include "iutest_case_c.h"
#include "internal/iutest_option_message_c.h"
#include "internal/iutest_internal_c.h"
#include "internal/iutest_params_util_c.h"

IUTEST_EXTERN_C_BEGIN()

/* define ============================================================*/
/**
 * @brief	�e�X�g�t�B�N�X�`���̒�`
*/
#define IUTEST_TEST_FIXTURE(name, setup_testcase, teardown_testcase, setup, teardown, user)		\
	static const iuTestFixture name { setup_testcase, teardown_testcase, setup, teardown, user }

/**
 * @private
 * @{
*/
/* �R�A�C���X�^���X */
#define IIUT_C_UNITTEST_NAME	g_iutest_c_unittest_instance

#if IUTEST_C_HAS_PARAM_TEST
#  define IIUT_C_UNITTEST_DEF_INSTANCE()	\
	iuUnitTest	IIUT_C_UNITTEST_NAME = { NULL, NULL, 0, iuTestResult_ctor(), iuTestListener_ctor(), iuTestListener_ctor(), 0, NULL, NULL }
#else
#  define IIUT_C_UNITTEST_DEF_INSTANCE()	\
	iuUnitTest	IIUT_C_UNITTEST_NAME = { NULL, NULL, 0, iuTestResult_ctor(), iuTestListener_ctor(), iuTestListener_ctor(), 0 }
#endif

#if IUTEST_C_HAS_LIB
#  define IIUT_C_WORKSPACE()
#else
#  define IIUT_C_WORKSPACE()	IIUT_C_WORKSPACE_()
#endif

/* ���[�N�X�y�[�X�̐��� */
#define IIUT_C_WORKSPACE_()			\
	IIUT_C_UNITTEST_DEF_INSTANCE();	\
	iuTestEnv	IIUT_C_TESTENV_NAME = iuTestEnv_ctor()
/**
 * @}
*/


/* struct ============================================================*/
/**
 * @brief	�e�X�g�R�A�\����
*/
typedef struct iuUnitTest_t
{
	iuTestCase*			list;				/*!< TestCase ���X�g */
	iuTestInfo*			current_test_info;	/*!< ���s���� TestInfo */
	iuTimeInMillisec	elapsedmsec;		/*!< ���s���� */
	iuTestResult		adhoc_testresult;	/*!< �e�X�g���s���łȂ��Ƃ��̃e�X�g���� */
	iuTestListener		def_printer;		/*!< �f�t�H���gPrinter */
	iuTestListener		def_xml_generator;	/*!< �f�t�H���gXML�o�� */
	int					initialized_count;	/*!< �������� */
#if IUTEST_C_HAS_PARAM_TEST
	iuTestCase*			paramtests;			/*!< Parameter Test �p TestCase ���X�g */
	iuTestParamHolder*	param_holder;		/*!< �p�����[�^�z���_�[���X�g */
#endif
} iuUnitTest;

/**
 * @brief	�e�X�g�t�B�N�X�`��
*/
typedef struct iuTestFixture_t
{
	const iuTestSetUpTestCase		setup_testcase;
	const iuTestTearDownTestCase	teardown_testcase;
	const iuTestSetUp		setup;
	const iuTestTearDown	teardown;
	void*	user;
} iuTestFixture;

/* extern ============================================================*/
extern iuUnitTest	IIUT_C_UNITTEST_NAME;

/* declare ===========================================================*/
#if !IUTEST_C_HAS_LIB

static iuTestCase*	iuUnitTest_AddTestCase(const char* testcase_name
						, iuTestSetUpTestCase setup, iuTestTearDownTestCase teardown, iuTest_AllocTestCase pfnAlloc);
static iuTestCase*	iuUnitTest_FindTestCase(iuTestCase* list, const char* testcase_name);

#if IUTEST_C_HAS_PARAM_TEST
static void iuUnitTest_ParamHolderRegisterTest(void);
#endif

#endif

/* function ==========================================================*/
#if IUTEST_C_HAS_LIB

/**
 * @brief	�e�X�g�Ǘ��C���X�^���X�̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuUnitTest* iuUnitTest_GetInstance(void);

#if IUTEST_C_HAS_STDARG
/**
 * @brief	vprintf �֐��|�C���^��ݒ�
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_SetVPrintfFunction(iuVPrintf proc);
#endif

/**
 * @brief	TestListener �̒ǉ�
*/
iuBOOL	iuUnitTest_AddTestListener(iuTestListener* test_listener);

/**
 * @brief	GlobalEnvironmentSetUp �̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuUnitTest_AddGlobalEnvironmentSetUp(iuGlobalEnvironmentSetUp func);

/**
 * @brief	GlobalEnvironmentTearDown �̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL	iuUnitTest_AddGlobalEnvironmentTearDown(iuGlobalEnvironmentTearDown func);

/**
 * @biref	�e�X�g�̏�����
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_Init(void);

/**
 * @biref	�e�X�g�̎��s
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_Run(void);

/**
 * @biref	�e�X�g�P�[�X�̌���
*/
iuTestCase* iuUnitTest_FindTestCase(iuTestCase* list, const char* testcase_name);

/**
 * @brief	���ݎ��s���� TestInfo �擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestInfo* iuUnitTest_GetCurrentTestInfo(void);

/**
 * @brief	���ݎ��s���� Test �̃��[�U�[�f�[�^�擾
*/
IUTEST_ATTRIBUTE_UNUSED_ void* iuUnitTest_GetCurrentUserData(void);

/**
 * @private
 * @brief	���ݎ��s���� TestInfo �̐ݒ�
*/
IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_SetCurrentTestInfo(struct iuTestInfo_t* curr);

/**
 * @brief	���ݎ��s���̃e�X�g�� TestResult �擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestResult* iuUnitTest_GetCurrentTestResult(void);

/**
 * @brief	�����V�[�h�̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuUInt32 iuUnitTest_GetCurrentRandomSeed(void);

/**
 * @brief	�e�X�g�P�[�X�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTotalTestCaseCount(const iuUnitTest* unit_test);

/**
 * @brief	���s�Ώۂ̃e�X�g�P�[�X�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTestCaseToRunCount(const iuUnitTest* unit_test);

/**
 * @brief	�e�X�g�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTotalTestCount(const iuUnitTest* unit_test);

/**
 * @brief	���s�Ώۂ̃e�X�g�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetTestToRunCount(const iuUnitTest* unit_test);

/**
 * @brief	�����e�X�g�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetSuccessfulTestCount(const iuUnitTest* unit_test);

/**
 * @brief	���s�e�X�g�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetFailureTestCount(const iuUnitTest* unit_test);

/**
 * @brief	�����e�X�g�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetDisableTestCount(const iuUnitTest* unit_test);

/**
 * @brief	�X�L�b�v�����e�X�g�̑����擾
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_GetSkippedTestCount(const iuUnitTest* unit_test);

/**
 * @brief	�e�X�g���ʂ̎擾
*/
iuBOOL iuUnitTest_IsFaild(const iuUnitTest* unit_test);

/**
 * @brief	�e�X�g���ʂ̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuUnitTest_Passed(const iuUnitTest* unit_test);

/**
 * @brief	�����V�[�h�̎擾
*/
IUTEST_ATTRIBUTE_UNUSED_ unsigned int iuUnitTest_GetRandomSeed(void);

/**
 * @brief	�e�X�g�̃��X�g�o��
*/
IUTEST_ATTRIBUTE_UNUSED_ int iuTest_ShowTestList(const iuUnitTest* unit_test);

/**
 * @biref	�e�X�g�P�[�X�̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestCase*	iuUnitTest_AddTestCase(const char* testcase_name
															   , iuTestSetUpTestCase setup
															   , iuTestTearDownTestCase teardown
															   , iuTest_AllocTestCase pfnAlloc);


#if IUTEST_C_HAS_PARAM_TEST

/**
 * @biref	�p�����[�^�e�X�g�o�^�p�e�X�g�P�[�X�̒ǉ�
*/
IUTEST_ATTRIBUTE_UNUSED_ iuTestCase*	iuUnitTest_AddParameterizedTestCase(const char* testcase_name
															   , iuTestSetUpTestCase setup
															   , iuTestTearDownTestCase teardown
															   , iuTest_AllocTestCase pfnAlloc);


IUTEST_ATTRIBUTE_UNUSED_ int iuUnitTest_AddTestParamHolder(iuTestParamHolder* holder);

IUTEST_ATTRIBUTE_UNUSED_ void iuUnitTest_ParamHolderRegisterTest(void);

#endif

#if IUTEST_C_HAS_MALLOC

IUTEST_ATTRIBUTE_UNUSED_ iuTestCase* iuUnitTest_AllocTestCase(void);

#endif

#endif

#if !IUTEST_C_HAS_LIB
#  include "impl/iutest_core_c.inl"
#endif

IUTEST_EXTERN_C_END()

#endif
