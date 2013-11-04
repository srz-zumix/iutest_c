/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_pred_c.h
 * @brief		iris unit test 述語 Assertion ファイル
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
#ifndef INCG_IRIS_iutest_pred_C_H_ADF851F3_C89B_4ca4_B9A0_A2B2229945C6_
#define INCG_IRIS_iutest_pred_C_H_ADF851F3_C89B_4ca4_B9A0_A2B2229945C6_

/* include ===========================================================*/
#include "iutest_assertion_c.h"

/* define ============================================================*/

/* 1 */
/**
 * @private
 * @{
*/
#define iuTestPred1Helper(pred_str, v1_str, pred, v1)	\
	((pred(v1)) ? iuAssertionSuccess() :		\
	iuAssertionFailureMessage("error: Expected: " pred_str "(" v1_str ")" ) )

#define IUTEST_PRED1_(pred, v1, on_failure)	\
	IUTEST_TEST_ASSERT_(iuTestPred1Helper(#pred, #v1, pred, v1), on_failure)

#define IUTEST_PRED_FORMAT1_(pred_formatter, v1, on_failure)	\
	IUTEST_TEST_ASSERT_(pred_formatter(#v1, v1), on_failure)
/**
 * @}
*/

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_ASSERT_PRED1(pred, v1)		\
	IUTEST_PRED1_(pred, v1, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_EXPECT_PRED1(pred, v1)		\
	IUTEST_PRED1_(pred, v1, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_INFORM_PRED1(pred, v1)		\
	IUTEST_PRED1_(pred, v1, IUTEST_INFORM_FAILURE)

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_ASSERT_PRED_FORMAT1(pred_formatter, v1)		\
	IUTEST_PRED_FORMAT1_(pred_formatter, v1, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_EXPECT_PRED_FORMAT1(pred_formatter, v1)		\
	IUTEST_PRED_FORMAT1_(pred_formatter, v1, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_INFORM_PRED_FORMAT1(pred_formatter, v1)		\
	IUTEST_PRED_FORMAT1_(pred_formatter, v1, IUTEST_INFORM_FAILURE)


/* 2 */
/**
 * @private
 * @{
*/
#define iuTestPred2Helper(pred_str, v1_str, v2_str, pred, v1, v2)	\
	((pred(v1, v2)) ? iuAssertionSuccess() :		\
	iuAssertionFailureMessage("error: Expected: " pred_str "(" v1_str ", " v2_str ")" ) )

#define IUTEST_PRED2_(pred, v1, v2, on_failure)	\
	IUTEST_TEST_ASSERT_(iuTestPred2Helper(#pred, #v1, #v2, pred, v1, v2), on_failure)

#define IUTEST_PRED_FORMAT2_(pred_formatter, v1, v2, on_failure)	\
	IUTEST_TEST_ASSERT_(pred_formatter(#v1, #v2, v1, v2), on_failure)
/**
 * @}
*/

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_ASSERT_PRED2(pred, v1, v2)		\
	IUTEST_PRED2_(pred, v1, v2, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_EXPECT_PRED2(pred, v1, v2)		\
	IUTEST_PRED2_(pred, v1, v2, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_INFORM_PRED2(pred, v1, v2)		\
	IUTEST_PRED2_(pred, v1, v2, IUTEST_INFORM_FAILURE)

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_ASSERT_PRED_FORMAT2(pred_formatter, v1, v2)		\
	IUTEST_PRED_FORMAT2_(pred_formatter, v1, v2, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_EXPECT_PRED_FORMAT2(pred_formatter, v1, v2)		\
	IUTEST_PRED_FORMAT2_(pred_formatter, v1, v2, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_INFORM_PRED_FORMAT2(pred_formatter, v1, v2)		\
	IUTEST_PRED_FORMAT2_(pred_formatter, v1, v2, IUTEST_INFORM_FAILURE)


/* 3 */
/**
 * @private
 * @{
*/
#define iuTestPred3Helper(pred_str, v1_str, v2_str, v3_str, pred, v1, v2, v3)	\
	((pred(v1, v2, v3)) ? iuAssertionSuccess() :								\
	iuAssertionFailureMessage("error: Expected: " pred_str "(" v1_str ", " v2_str ", " v3_str ")" ) )

#define IUTEST_PRED3_(pred, v1, v2, v3, on_failure)	\
	IUTEST_TEST_ASSERT_(iuTestPred3Helper(#pred, #v1, #v2, #v3, pred, v1, v2, v3), on_failure)

#define IUTEST_PRED_FORMAT3_(pred_formatter, v1, v2, v3, on_failure)	\
	IUTEST_TEST_ASSERT_(pred_formatter(#v1, #v2, #v3, v1, v2, v3), on_failure)
/**
 * @}
*/

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_ASSERT_PRED3(pred, v1, v2, v3)		\
	IUTEST_PRED3_(pred, v1, v2, v3, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_EXPECT_PRED3(pred, v1, v2, v3)		\
	IUTEST_PRED3_(pred, v1, v2, v3, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_INFORM_PRED3(pred, v1, v2, v3)		\
	IUTEST_PRED3_(pred, v1, v2, v3, IUTEST_INFORM_FAILURE)

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_ASSERT_PRED_FORMAT3(pred_formatter, v1, v2, v3)		\
	IUTEST_PRED_FORMAT3_(pred_formatter, v1, v2, v3, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_EXPECT_PRED_FORMAT3(pred_formatter, v1, v2, v3)		\
	IUTEST_PRED_FORMAT3_(pred_formatter, v1, v2, v3, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_INFORM_PRED_FORMAT3(pred_formatter, v1, v2, v3)		\
	IUTEST_PRED_FORMAT3_(pred_formatter, v1, v2, v3, IUTEST_INFORM_FAILURE)

/* 4 */
/**
 * @private
 * @{
*/
#define iuTestPred4Helper(pred_str, v1_str, v2_str, v3_str, v4_str, pred, v1, v2, v3, v4)	\
	((pred(v1, v2, v3, v4)) ? iuAssertionSuccess() :								\
	iuAssertionFailureMessage("error: Expected: " pred_str "(" v1_str ", " v2_str ", " v3_str ", " v4_str ")" ) )

#define IUTEST_PRED4_(pred, v1, v2, v3, v4, on_failure)	\
	IUTEST_TEST_ASSERT_(iuTestPred4Helper(#pred, #v1, #v2, #v3, #v4, pred, v1, v2, v3, v4), on_failure)

#define IUTEST_PRED_FORMAT4_(pred_formatter, v1, v2, v3, v4, on_failure)	\
	IUTEST_TEST_ASSERT_(pred_formatter(#v1, #v2, #v3, #v4, v1, v2, v3, v4), on_failure)
/**
 * @}
*/

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_ASSERT_PRED4(pred, v1, v2, v3, v4)		\
	IUTEST_PRED4_(pred, v1, v2, v3, v4, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_EXPECT_PRED4(pred, v1, v2, v3, v4)		\
	IUTEST_PRED4_(pred, v1, v2, v3, v4, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_INFORM_PRED4(pred, v1, v2, v3, v4)		\
	IUTEST_PRED4_(pred, v1, v2, v3, v4, IUTEST_INFORM_FAILURE)

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_ASSERT_PRED_FORMAT4(pred_formatter, v1, v2, v3, v4)		\
	IUTEST_PRED_FORMAT4_(pred_formatter, v1, v2, v3, v4, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_EXPECT_PRED_FORMAT4(pred_formatter, v1, v2, v3, v4)		\
	IUTEST_PRED_FORMAT4_(pred_formatter, v1, v2, v3, v4, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_INFORM_PRED_FORMAT4(pred_formatter, v1, v2, v3, v4)		\
	IUTEST_PRED_FORMAT4_(pred_formatter, v1, v2, v3, v4, IUTEST_INFORM_FAILURE)


/* 5 */
/**
 * @private
 * @{
*/
#define iuTestPred5Helper(pred_str, v1_str, v2_str, v3_str, v4_str, v5_str, pred, v1, v2, v3, v4, v5)	\
	((pred(v1, v2, v3, v4, v5)) ? iuAssertionSuccess() :												\
	iuAssertionFailureMessage("error: Expected: " pred_str "(" v1_str ", " v2_str ", " v3_str ", " v4_str ", " v5_str ")" ) )

#define IUTEST_PRED5_(pred, v1, v2, v3, v4, v5, on_failure)	\
	IUTEST_TEST_ASSERT_(iuTestPred5Helper(#pred, #v1, #v2, #v3, #v4, #v5, pred, v1, v2, v3, v4, v5), on_failure)

#define IUTEST_PRED_FORMAT5_(pred_formatter, v1, v2, v3, v4, v5, on_failure)	\
	IUTEST_TEST_ASSERT_(pred_formatter(#v1, #v2, #v3, #v4, #v5, v1, v2, v3, v4, v5), on_failure)
/**
 * @}
*/

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_ASSERT_PRED5(pred, v1, v2, v3, v4, v5)		\
	IUTEST_PRED5_(pred, v1, v2, v3, v4, v5, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_EXPECT_PRED5(pred, v1, v2, v3, v4, v5)		\
	IUTEST_PRED5_(pred, v1, v2, v3, v4, v5, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト
*/
#define IUTEST_INFORM_PRED5(pred, v1, v2, v3, v4, v5)		\
	IUTEST_PRED5_(pred, v1, v2, v3, v4, v5, IUTEST_INFORM_FAILURE)

/**
 * @ingroup	IUTEST_ASSERT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_ASSERT_PRED_FORMAT5(pred_formatter, v1, v2, v3, v4, v5)		\
	IUTEST_PRED_FORMAT5_(pred_formatter, v1, v2, v3, v4, v5, IUTEST_ASSERT_FAILURE)
/**
 * @ingroup	IUTEST_EXPECT_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_EXPECT_PRED_FORMAT5(pred_formatter, v1, v2, v3, v4, v5)		\
	IUTEST_PRED_FORMAT5_(pred_formatter, v1, v2, v3, v4, v5, IUTEST_EXPECT_FAILURE)
/**
 * @ingroup	IUTEST_INFORM_
 * @brief	述語 ASSERTION テスト(メッセージフォーマッター指定)
*/
#define IUTEST_INFORM_PRED_FORMAT5(pred_formatter, v1, v2, v3, v4, v5)		\
	IUTEST_PRED_FORMAT5_(pred_formatter, v1, v2, v3, v4, v5, IUTEST_INFORM_FAILURE)

#endif
