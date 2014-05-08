/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_body_c.inl
 * @brief		iris unit test テスト単体クラス ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_BODY_C_INL_3EEA6706_9954_4330_B292_129667FA6B96_
#define INCG_IRIS_IUTEST_BODY_C_INL_3EEA6706_9954_4330_B292_129667FA6B96_

/* include ===========================================================*/
#include "../iutest_body_c.h"

/* function ==========================================================*/
IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTest_Init(iuTest* test_body, iuTestSetUp setup, iuTestTearDown teardown, void* user)
{
	test_body->setup = setup;
	test_body->teardown = teardown;
	test_body->user = user;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ iuBOOL iuTest_RecordProperty(const char *key, const char *value)
{
	/* 不正なキーのチェック */
	{
#if IUTEST_C_HAS_MALLOC
		const char* ban[] = { "name", "status", "time", "classname", "type_param", "value_param" };
		int i=0, n=IUTEST_PP_COUNTOF(ban);
		for( i=0; i < n; ++i )
		{
			if( iuString_IsStringEqual(key, ban[i]) )
			{
				return FALSE;
			}
		}
#else
		if( iuString_IsStringEqual(key, "name") ) return FALSE;
		if( iuString_IsStringEqual(key, "status") ) return FALSE;
		if( iuString_IsStringEqual(key, "time") ) return FALSE;
		if( iuString_IsStringEqual(key, "classname") ) return FALSE;
		if( iuString_IsStringEqual(key, "type_param") ) return FALSE;
		if( iuString_IsStringEqual(key, "value_param") ) return FALSE;
#endif
	}
	{
		iuTestResult *result = iuUnitTest_GetCurrentTestResult();
		iuTestProperty *prop_top = result->properties;
		iuTestProperty *prop = iuTestResult_AllocTestProperty();
		prop->key = key;
		prop->value = value;
		prop->next = NULL;
		iuTestHelper_AddList(iuTestProperty, prop_top, prop);
		result->properties = prop_top;

		iuTestEnv_ListenerEvent_OnTestRecordProperty(prop);
	}
	return TRUE;
}

IUTEST_C_INL_INLINE IUTEST_ATTRIBUTE_UNUSED_ void iuTest_CommitResult(iuTestPartResult* part_result)
{
	iuTestResult* test_result = iuUnitTest_GetCurrentTestResult();
	if(test_result == NULL) return;

	{
		iuTestEnv* env = iuTestEnv_GetInstance();
		if(env->commit_result.func != NULL)
		{
			if((*env->commit_result.func)(part_result
				, env->commit_result.user))
			{
				return;
			}
		}
	}
	if( part_result == NULL || part_result->type != kTestResultSuccess )
	{
		test_result->result = FALSE;
		if( iuTestEnv_IsEnableBreakOnFailure() )
		{
			IUTEST_C_BREAK();
		}
	}
	iuTestResult_AddPartResult(test_result, part_result);
	iuTestEnv_ListenerEvent_OnTestPartResult(part_result);
}

#endif
