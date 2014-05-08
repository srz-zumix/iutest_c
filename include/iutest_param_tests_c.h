/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_param_tests_c.h
 * @brief		iris unit test parameter 定義 ファイル
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_PARAM_TESTS_C_H_3DBBF55E_A076_4207_B49E_34734EE333EE_
#define INCG_IRIS_IUTEST_PARAM_TESTS_C_H_3DBBF55E_A076_4207_B49E_34734EE333EE_

/* include ===========================================================*/
#include "iutest_core_c.h"

#if IUTEST_C_HAS_PARAM_TEST

/* define ============================================================*/

/**
 * @ingroup TESTDEF
 * @brief	テストを明示的に登録
*/
#define IUTEST_REGISTER_TEST_P(prefix_, testcase_)	IUTEST_C_CALL_INITIALIZATION_SECTION(IIUT_C_TEST_P_ADD_HOLDER_SECTION_NAME(prefix_, testcase_))

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_INSTANTIATE_TEST_CASE_P
 * @brief	パラメータテストインスタンス化マクロ
 * @param	type_		= パラメータの型
 * @param	prefix_		= インスタンス名
 * @param	testcase_	= テストケース名
 * @param	generator_	= 生成パターン
 * @param	...			= params
*/
#define IUTEST_INSTANTIATE_TEST_CASE_P(type_, prefix_, testcase_, generator_, ...)	\
													IIUT_INSTANTIATE_TEST_CASE_P_(type_, prefix_, testcase_, generator_, __VA_ARGS__)

/**
 * @ingroup TESTDEF
 * @brief	パラメータテストインスタンスの明示的登録
*/
#define IUTEST_REGISTER_TEST_CASE_P(prefix_, testcase_)	IUTEST_C_CALL_INITIALIZATION_SECTION(IIUT_C_TEST_P_ADD_HOLDER_SECTION_NAME(prefix_, testcase_))

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_P(testcase_, testname_)
 * @brief	パラメータユーザー指定テスト関数定義マクロ
 * @param	type_		= パラメータの型
 * @param	testcase_	= テストケース名
 * @param	testname_	= テスト名
 * @note	
 *  IUTEST_P(Type, TestCaseName, TestName) {}\n
 *  IUTEST_INSTANTIATE_TEST_CASE_P(Type, InstantiateName, TestCaseName, ParamGenerator, Params);\n
*/
#define IUTEST_P(type_, testcase_, testname_)	IIUT_TEST_P_(type_, testcase_, testname_)

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_P_F(testcase_, testname_)
 * @brief	パラメータユーザー指定テスト関数定義マクロ(フィクスチャ対応)
 * @param	type_		= パラメータの型
 * @param	testcase_	= テストケース名
 * @param	testname_	= テスト名
 * @note	
 *  IUTEST_P_F(Type, TestCaseName, TestName) {}\n
 *  IUTEST_INSTANTIATE_TEST_CASE_P(Type, InstantiateName, TestCaseName, ParamGenerator, Params);\n
*/
#define IUTEST_P_F(type_, testcase_, testname_)	IIUT_TEST_PF_(type_, testcase_, testname_)

/**
 * @ingroup	TESTDEF
 * @def		IUTEST_P_TYPE(types_)
 * @brief	パラメータテスト用パラメータ構造体の宣言
 * @param	types_		= パラメータの型 tuple
 * @note	
 *  typedef IUTEST_P_TYPE((int, char)) TestParamType;
*/
#define IUTEST_P_TYPE(types_)	IIUT_TEST_P_TYPE(types_)


/**
 * @ingroup	TESTDEF
 * @brief	真偽値のパラメータ生成
 * @note	このマクロは IUTEST_INSTANTIATE_TEST_CASE_P の generator_ に指定して使用します
*/
#define iuBoolean(type_, varname_, initfunc_)					IIUT_TEST_P_VALUES(type_, varname_, initfunc_, FALSE, TRUE)

/**
 * @ingroup	TESTDEF
 * @brief	値のパラメータ生成
 * @note	このマクロは IUTEST_INSTANTIATE_TEST_CASE_P の generator_ に指定して使用します
*/
#define iuValues(type_, varname_, initfunc_, ...)				IIUT_TEST_P_VALUES(type_, varname_, initfunc_, __VA_ARGS__)

/**
 * @ingroup	TESTDEF
 * @brief	範囲パラメータ生成
 * @note	このマクロは IUTEST_INSTANTIATE_TEST_CASE_P の generator_ に指定して使用します
*/
#if defined(__GNUC__)
#  define iuRange(type_, varname_, initfunc_, begin, end, ...)	IIUT_TEST_P_RANGE(type_, varname_, initfunc_, begin, end, ##__VA_ARGS__, 1)
#else
#  define iuRange(type_, varname_, initfunc_, begin, end)		IIUT_TEST_P_RANGE(type_, varname_, initfunc_, begin, end, 1)
#endif

/**
 * @ingroup	TESTDEF
 * @brief	範囲パラメータ生成
 * @note	このマクロは IUTEST_INSTANTIATE_TEST_CASE_P の generator_ に指定して使用します
*/
#define iuStepRange(type_, varname_, initfunc_, begin, end, step)	IIUT_TEST_P_RANGE(type_, varname_, initfunc_, begin, end, step)

#if IUTEST_C_HAS_COMBINE

/**
 * @ingroup	TESTDEF
 * @brief	複合パラメータ生成
 * @note	このマクロは IUTEST_INSTANTIATE_TEST_CASE_P の generator_ に指定して使用します
*/
#define iuCombine(type_, varname_, initfunc_, ...)		IIUT_TEST_P_COMBINE(type_, varname_, initfunc_, __VA_ARGS__)

#endif

/**
 * @private
 * @{
*/

#define IIUT_TEST_P_VALUES(type_, varname_, initfunc_, ...)			\
	IUTEST_DATA_SECTION_ static type_ varname_[] = { __VA_ARGS__ };	\
	IUTEST_TEST_SECTION_ void initfunc_(void) {}

#define IIUT_TEST_P_RANGE(type_, varname_, initfunc_, begin, end, step, ...)			\
	IUTEST_PP_STATIC_ASSERT(((begin) <= (end)) && ((step) > 0));						\
	IUTEST_DATA_SECTION_ static type_ varname_[((end)-(begin)+(step)-1)/(step)];		\
	IUTEST_TEST_SECTION_ void initfunc_(void) { type_ n=(begin); size_t i=0;			\
		for( ; i < IUTEST_PP_COUNTOF(varname_); n+=(step), ++i ) { varname_[i] = n; }	\
	}


#define IIUT_COMBINE_PARAM_PARSE_(i, param)	IUTEST_PP_TUPLE_ELEM(i, param)

#define IIUT_COMBINE_ELEM_GENERATE_(i, type_, varname_, initfunc_, genrator_)						\
	IIUT_COMBINE_ELEM_GENERATE_I(i, type_, varname_, initfunc_, IUTEST_PP_TUPLE_ELEM(0, genrator_)	\
		, IUTEST_PP_TUPLE_ELEM(1, genrator_))

#ifdef _MSC_VER

#define IIUT_COMBINE_ELEM_GENERATE_I(i, type_, varname_, initfunc_, genrator_, param_)			\
	genrator_( type_, IUTEST_PP_CAT(varname_,i), IUTEST_PP_CAT(initfunc_,i)						\
		, IUTEST_PP_ENUM(IUTEST_PP_TUPLE_SIZE(param_), IIUT_COMBINE_PARAM_PARSE_, param_)		\
	)

#else

#define IIUT_COMBINE_ELEM_GENERATE_I(i, type_, varname_, initfunc_, genrator_, param_)			\
	IIUT_COMBINE_ELEM_GENERATE_II(i, type_, varname_, initfunc_, genrator_						\
		, IUTEST_PP_ENUM(IUTEST_PP_TUPLE_SIZE(param_), IIUT_COMBINE_PARAM_PARSE_, param_)		\
	)
#define IIUT_COMBINE_ELEM_GENERATE_II(i, type_, varname_, initfunc_, genrator_, ...)			\
	genrator_( type_, IUTEST_PP_CAT(varname_,i), IUTEST_PP_CAT(initfunc_,i), __VA_ARGS__)

#endif

#define IIUT_COMBINE_ELEM_GENERATE(i, param1, generators_)										\
	IIUT_COMBINE_ELEM_GENERATE_(i, IUTEST_PP_TUPLE_ELEM(i, IUTEST_PP_TUPLE_ELEM(2,param1))		\
	, IUTEST_PP_TUPLE_ELEM(0,param1), IUTEST_PP_TUPLE_ELEM(1,param1), IUTEST_PP_TUPLE_ELEM(i, generators_))


#define IIUT_COMBINE_INIT_PARAM_BEGIN(i, param)	for( IUTEST_PP_CAT(ii,i)=0; IUTEST_PP_CAT(ii,i) < IUTEST_PP_COUNTOF( IUTEST_PP_CAT(param, i) ); ++IUTEST_PP_CAT(ii,i) ) {
#define IIUT_COMBINE_INIT_PARAM_END(i, param)	}

#define IIUT_COMBINE_ELEM_INIT(i, param)	IUTEST_PP_CAT(param,i)();
#define IIUT_COMBINE_INIT_PARAM(i, varname_, index)				\
	varname_[index].IUTEST_PP_CAT(value,i) = IUTEST_PP_CAT(varname_,i)[ IUTEST_PP_CAT(ii,i) ];

#define IIUT_COMBINE_TOTAL_PARAMCOUNT_I(i, param)	* IUTEST_PP_COUNTOF( IUTEST_PP_CAT(param,i) )
#define IIUT_COMBINE_TOTAL_PARAMCOUNT(type_, varname_)				\
	1 IUTEST_PP_REPEAT(IUTEST_PP_TUPLE_SIZE(type_), IIUT_COMBINE_TOTAL_PARAMCOUNT_I, varname_)

#define IIUT_TEST_P_COMBINE(types_, varname_, initfunc_, ...)										\
	IUTEST_PP_REPEAT_BINARY(IUTEST_PP_TUPLE_SIZE(types_), IIUT_COMBINE_ELEM_GENERATE				\
			, (varname_, initfunc_, types_), (__VA_ARGS__))											\
	IUTEST_DATA_SECTION_ static IUTEST_P_TYPE(types_) varname_[IIUT_COMBINE_TOTAL_PARAMCOUNT(types_, varname_)];	\
	IUTEST_TEST_SECTION_ void initfunc_(void) {														\
		size_t index=0;																				\
		size_t IUTEST_PP_ENUM_PARAMS(IUTEST_PP_TUPLE_SIZE(types_), ii);								\
		IUTEST_PP_REPEAT(IUTEST_PP_TUPLE_SIZE(types_), IIUT_COMBINE_ELEM_INIT, initfunc_)			\
		IUTEST_PP_REPEAT(IUTEST_PP_TUPLE_SIZE(types_), IIUT_COMBINE_INIT_PARAM_BEGIN, varname_)		\
		IUTEST_PP_REPEAT_BINARY(IUTEST_PP_TUPLE_SIZE(types_), IIUT_COMBINE_INIT_PARAM, varname_, index)	\
		++index;																					\
		IUTEST_PP_REPEAT(IUTEST_PP_TUPLE_SIZE(types_), IIUT_COMBINE_INIT_PARAM_END, varname_)		\
	}

#define IIUT_TEST_P_TYPE_REPEAT_(i, param)	IUTEST_PP_TUPLE_ELEM(i, param) IUTEST_PP_CAT(value, i);
#define IIUT_TEST_P_TYPE(type_)	struct {															\
		IUTEST_PP_REPEAT(IUTEST_PP_TUPLE_SIZE(type_), IIUT_TEST_P_TYPE_REPEAT_, type_)				\
	}

#define IIUT_INSTANTIATE_TEST_CASE_P_(type_, prefix_, testcase_, generator_, ...)					\
	IUTEST_PP_EXPAND( generator_(type_, IIUT_C_TEST_P_PARAMS_NAME(prefix_, testcase_)				\
		, IIUT_C_TEST_P_INIT_PARAMS_DECL_NAME(prefix_, testcase_), __VA_ARGS__) )					\
	IUTEST_DATA_SECTION_ static iuTestCase IIUT_C_TEST_P_PARAMS_TESTCASE_ARRAY_NAME(prefix_, testcase_)[IIUT_C_TEST_P_PARAMS_COUNT(prefix_, testcase_)];	\
	IUTEST_DATA_SECTION_ static iuTestParamHolder IIUT_C_TEST_P_PARAMS_HOLDER_NAME(prefix_, testcase_) =	\
		iuTestParamHolder_ctor(testcase_, IIUT_C_TEST_P_PARAMS_TESTCASE_ARRAY_NAME(prefix_, testcase_)		\
		, IIUT_C_TEST_P_PARAMS_NAME(prefix_, testcase_));											\
	IUTEST_TEST_SECTION_ static const char** IIUT_C_TEST_P_GET_TESTCASENAMES_DECL_NAME(prefix_, testcase_)(void) {	\
		static const char dummy[] = IUTEST_PP_TOSTRING( prefix_/testcase_/0 );						\
		const size_t dummy_len = IUTEST_PP_COUNTOF(dummy);											\
		static char names[IIUT_C_TEST_P_PARAMS_COUNT(prefix_, testcase_)][IUTEST_PP_COUNTOF(dummy)+32];	\
		static const char* names_ptr[IIUT_C_TEST_P_PARAMS_COUNT(prefix_, testcase_)]; size_t i=0;	\
		for( i=0; i < IIUT_C_TEST_P_PARAMS_COUNT(prefix_, testcase_); ++i ) {						\
			iu_memcpy(names[i], dummy, sizeof(dummy));												\
			iu_itoa(i, &names[i][dummy_len-2], 10);													\
			names_ptr[i] = &names[i][0];															\
		} return &names_ptr[0];																		\
	}																								\
	IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN( IIUT_C_TEST_P_ADD_HOLDER_SECTION_NAME(prefix_, testcase_) )	\
		IIUT_C_TEST_P_INIT_PARAMS_DECL_NAME(prefix_, testcase_)();									\
		IIUT_C_TEST_P_PARAMS_HOLDER_NAME(prefix_, testcase_).testcase_names =						\
		IIUT_C_TEST_P_GET_TESTCASENAMES_DECL_NAME(prefix_, testcase_)();							\
		iuUnitTest_AddTestParamHolder(&IIUT_C_TEST_P_PARAMS_HOLDER_NAME(prefix_, testcase_));		\
	IUTEST_C_DECL_INITIALIZATION_SECTION_END()

#define IIUT_TEST_P_(type_, testcase_, testname_)	\
		IIUT_C_TEST_P_ADD_(type_, testcase_, testname_, NULL, NULL, NULL, NULL, NULL)

#define IIUT_TEST_PF_(type_, testfix_, testname_)	\
		IIUT_C_TEST_P_ADD_(type_, testfix_, testname_, testfix_.setup_testcase	\
		, testfix_.teardown_testcase, testfix_.setup, testfix_.teardown, testfix_.user)

#if IUTEST_C_HAS_MALLOC

#define IIUT_C_TEST_P_ADD_(type_, testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_)	\
	IIUT_C_TEST_P_ADD_I_(type_, testcase_, testname_, setup_testcase_, teardown_testcase_		\
	, setup_, teardown_, user_, iuUnitTest_AllocTestCase)

#else

#define IIUT_C_TEST_P_ADD_(type_, testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_)	\
	IUTEST_TEST_SECTION_ static iuTestCase * IUTEST_PP_CAT(iutest_c_alloc_##testcase_##_dummy_, __LINE__)(void) {		\
	static iuTestCase instance; return &instance; }												\
	IIUT_C_TEST_P_ADD_I_(type_, testcase_, testname_, setup_testcase_, teardown_testcase_		\
	, setup_, teardown_, user_, IUTEST_PP_CAT(iutest_c_alloc_##testcase_##_dummy_, __LINE__))
#endif

#define IIUT_C_TEST_P_ADD_I_(type_, testcase_, testname_, setup_testcase_, teardown_testcase_, setup_, teardown_, user_, allocator_)	\
	void IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_)(void);														\
	IUTEST_DATA_SECTION_ static iuTestInfo IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_) =							\
	iuTestInfo_ctor(#testname_, IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_) );										\
	IUTEST_C_DECL_INITIALIZATION_SECTION_BEGIN( IIUT_C_TEST_INITIALIZATION_SECTION_NAME(testcase_, testname_) )			\
	iuTestCase_AddTestInfo(iuUnitTest_AddParameterizedTestCase(#testcase_, setup_testcase_, teardown_testcase_, allocator_),			\
	& IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_) );																\
	IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_).test.setup = setup_;												\
	IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_).test.teardown = teardown_;											\
	IIUT_C_TEST_INFO_DECL_NAME(testcase_, testname_).test.user = user_;													\
	IUTEST_C_DECL_INITIALIZATION_SECTION_END()																			\
	IUTEST_TEST_SECTION_ void IIUT_C_TEST_P_BODY_DECL_NAME(testcase_, testname_)(type_ param);							\
	IUTEST_TEST_SECTION_ void IIUT_C_TEST_BODY_DECL_NAME(testcase_, testname_)(void) {									\
		iuTestInfo* info = iuUnitTest_GetCurrentTestInfo();																\
		type_ param = *(type_*)(info->param);																			\
		IIUT_C_TEST_P_BODY_DECL_NAME(testcase_, testname_)(param);														\
	}																													\
	void IIUT_C_TEST_P_BODY_DECL_NAME(testcase_, testname_)(type_ param)

#define IIUT_C_TEST_P_SETUP_PARAMS_DECL_NAME(prefix_, testcase_)		iutest_c_test_p_setup_params_##prefix_##_##testcase_##_
#define IIUT_C_TEST_P_INIT_PARAMS_DECL_NAME(prefix_, testcase_)			iutest_c_test_p_init_params_##prefix_##_##testcase_##_
#define IIUT_C_TEST_P_GET_TESTCASENAMES_DECL_NAME(prefix_, testcase_)	iutest_c_test_p_get_testcase_names_##prefix_##_##testcase_##_
#define IIUT_C_TEST_P_ADD_HOLDER_SECTION_NAME(prefix_, testcase_)		iutest_c_test_p_add_holder_dummy_##prefix_##_##testcase_##_
#define IIUT_C_TEST_P_PARAMS_TESTCASE_ARRAY_NAME(prefix_, testcase_)	iutest_c_test_p_params_testcases_##prefix_##_##testcase_##_
#define IIUT_C_TEST_P_PARAMS_HOLDER_NAME(prefix_, testcase_)	iutest_c_test_p_params_holder_##prefix_##_##testcase_##_
#define IIUT_C_TEST_P_PARAMS_NAME(prefix_, testcase_)			iutest_c_test_p_params_##prefix_##_##testcase_##_x_
#define IIUT_C_TEST_P_BODY_DECL_NAME(testcase_, testname_)		iutest_c_test_p_body_##testcase_##_##testname_##_

#define IIUT_C_TEST_P_PARAMS_COUNT(prefix_, testcase_)			IUTEST_PP_COUNTOF(IIUT_C_TEST_P_PARAMS_NAME(prefix_, testcase_))

/**
 * @}
*/

#endif	/* IUTEST_C_HAS_PARAM_TEST */

#endif
