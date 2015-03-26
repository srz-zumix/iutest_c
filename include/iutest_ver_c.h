/*======================================================================
----------------------------------------------------------------------*/
/**
 * @file		iutest_ver_c.h
 * @brief		iris unit test version
 *
 * @author		t.sirayanagi
 * @par			copyright
 * Copyright (C) 2012-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
/*----------------------------------------------------------------------
======================================================================*/
#ifndef INCG_IRIS_IUTEST_VER_C_H_D65CB7A7_D2AD_40FE_8F5F_8FBF376A0010_
#define INCG_IRIS_IUTEST_VER_C_H_D65CB7A7_D2AD_40FE_8F5F_8FBF376A0010_

/* define ============================================================*/
#define	IUTEST_C_VER			0x01050004	/*!< iutest version 1.5.0.4 */
#define IUTEST_C_MAJORVER		0x01		/*!< Major Version */
#define IUTEST_C_MINORVER		0x05		/*!< Minor Version */
#define IUTEST_C_BUILD			0x00		/*!< Build */
#define IUTEST_C_REVISION		0x04		/*!< Revision */

/**
 * @mainpage
 * @sa	@b	ProjectHome \n
 *			sourceforge : http://sourceforge.jp/projects/iutest/ \n
 *
 * @par		copyright
 * Copyright (C) 2012-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License.
 *
 * @par		LICENSE

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:\n
\n
  1. Redistributions of source code must retain the above copyright notice,\n
     this list of conditions and the following disclaimer.\n
  2. Redistributions in binary form must reproduce the above copyright notice,\n
     this list of conditions and the following disclaimer in the documentation \n
     and/or other materials provided with the distribution.\n
  3. the copyright holder's name is not used to endorse products \n
     built using this software without specific written permission.\n
\n
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

/**
 * @page	CMDLINE		コマンドラインオプション
 * @par		Command Line Options
 <table>
   <tr><td>--help, -h                        </td><td></td><td>generate help message.</td></tr>
   <tr><td>--iutest_output                   </td><td>xml[:path]</td><td>path of xml report.</td></tr>
   <tr><td>--iutest_list_tests               </td><td></td><td>list up tests.</td></tr>
   <tr><td>--iutest_color                    </td><td>&lt;yes|no|auto|ansi&gt;</td><td>console color enable.</td></tr>
   <tr><td>--iutest_filter                   </td><td>&lt;filter&gt;</td><td>Select the test run.</td></tr>
   <tr><td>--iutest_shuffle                  </td><td></td><td>do shuffle test.</td></tr>
   <tr><td>--iutest_random_seed              </td><td>&lt;seed&gt;</td><td>set random seed.</td></tr>
   <tr><td>--iutest_also_run_disabled_tests  </td><td></td><td>run disabled tests.</td></tr>
   <tr><td>--iutest_break_on_failure         </td><td>[0|1]</td><td>When that failed to break.</td></tr>
   <tr><td>--iutest_print_time               </td><td>&lt;0|1&gt;</td><td>Setting the display of elapsed time.</td></tr>
   <tr><td>--iutest_repeat                   </td><td>&lt;count&gt;</td><td>Set the number of repetitions of the test.</td></tr>
   <tr><td>--feature                         </td><td></td><td>show iutest feature.</td></tr>
   <tr><td>--version, -v                     </td><td></td><td>show iutest version.</td></tr>
 </table>
  * yes or no option can use "yes|y|on|true|t|1|no|n|off|false|f|0"
*/

/**
 * @page	CHANGELOG		変更履歴
 * @par		Changes
<ul>
  <li>v1.6.0.0
    <ul>
      <li>iuTestSetUp,iuTestTearDown 関数の引数を変更</li>
    </ul>
  </li>
  <li>v1.5.0.0
    <ul>
      <li>_Generic 対応</li>
    </ul>
  </li>
  <li>v1.4.0.0
    <ul>
      <li>IUTEST_SKIP 追加</li>
      <li>iuBoolean パラメータジェネレータを追加</li>
      <li>セクション指定に対応</li>
      <li>機能削減用コンフィグマクロを追加</li>
    </ul>
  </li>
  <li>v1.3.0.0
    <ul>
      <li>IUTEST_*_FATAL_FAILURE, IUTEST_*_NON_FATAL_FAILURE を追加</li>
      <li>値のパラメータテストの明示的登録に対応(IUTEST_REIGSTER_TEST_P)</li>
      <li>パラメータの組み合わせ(デカルト積)テストを生成する iuCombine を追加</li>
      <li>IUTEST_*_NO_FATAL_FAILURE, IUTEST_*_NO_FAILURE を追加</li>
      <li>明示的な成功と失敗に対応</li>
    </ul>
  </li>
  <li>v1.2.0.0
    <ul>
      <li>値のパラメータ化テストに対応</li>
    </ul>
  </li>
  <li>v1.1.0.0
    <ul>
      <li>ライブラリビルド対応</li>
    </ul>
  </li>
  <li>v1.0.1.1
    <ul>
      <li>テストフィクスチャ経由でユーザーデータを保持できるように修正</li>
      <li>オプションの環境変数を IUTEST_C から始まる名前に変更</li>
    </ul>
  </li>
  <li>v1.0.0.0
    <ul>
      <li>初期リリース</li>
      <li>アサーションで失敗した場合に実行時の値を出力するように変更</li>
    </ul>
  </li>
  <li>v0.9.3.0
    <ul>
      <li>環境変数に対応</li>
      <li>グローバル環境 SetUp - TearDown に対応</li>
      <li>IUTEST_STATIC_ASSERT 追加</li>
      <li>述語フォーマットが INFORM に対応していなかったので修正</li>
      <li>C90 対応</li>
    </ul>
  </li>
  <li>v0.8.0.0
    <ul>
      <li>テスト関数の自動収集に対応していない環境用に明示的な登録マクロを追加</li>
      <li>文字列出力関数ポインタを設定できるように修正</li>
    </ul>
  </li>
  <li>v0.7.0.0
    <ul>
      <li>ビルドエラー修正</li>
    </ul>
  </li>
  <li>v0.6.2.1
    <ul>
      <li>パラメタライズテスト対応</li>
    </ul>
  </li>
  <li>v0.5.1.0
    <ul>
      <li>Printer 対応</li>
      <li>テスト外での失敗も反映されるように修正</li>
    </ul>
  </li>
  <li>v0.4.1.0
    <ul>
      <li>RecordProperty 対応</li>
      <li>IUTEST_FALG で一部のオプションが参照できない不具合を修正</li>
      <li>repeat 回数に 0 以下を指定した際の不具合を修正</li>
      <li>xml 出力対応</li>
    </ul>
  </li>
  <li>v0.3.0.0
    <ul>
      <li>INFORM 対応</li>
      <li>DISABLED テスト対応</li>
      <li>--iutest_also_run_disabled_tests 対応</li>
      <li>--iutest_shuffle 対応</li>
      <li>--iutest_random_seed 対応</li>
      <li>--iutest_print_time 対応</li>
    </ul>
  </li>
  <li>v0.2.0.0
    <ul>
      <li>--iutest_break_on_failure 対応</li>
      <li>--iutest_repeat 対応</li>
      <li>--iutest_color 対応</li>
      <li>--iutest_list_tests 対応</li>
      <li>--feature 対応</li>
    </ul>
  </li>
  <li>v0.1.0.0
    <ul>
      <li>基本的なテストの作成に対応</li>
      <li>テストのフィルタリングに対応</li>
    </ul>
  </li>
</ul>
*/

#endif
