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
 * @page	CMDLINE		�R�}���h���C���I�v�V����
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
 * @page	CHANGELOG		�ύX����
 * @par		Changes
<ul>
  <li>v1.6.0.0
    <ul>
      <li>iuTestSetUp,iuTestTearDown �֐��̈�����ύX</li>
    </ul>
  </li>
  <li>v1.5.0.0
    <ul>
      <li>_Generic �Ή�</li>
    </ul>
  </li>
  <li>v1.4.0.0
    <ul>
      <li>IUTEST_SKIP �ǉ�</li>
      <li>iuBoolean �p�����[�^�W�F�l���[�^��ǉ�</li>
      <li>�Z�N�V�����w��ɑΉ�</li>
      <li>�@�\�팸�p�R���t�B�O�}�N����ǉ�</li>
    </ul>
  </li>
  <li>v1.3.0.0
    <ul>
      <li>IUTEST_*_FATAL_FAILURE, IUTEST_*_NON_FATAL_FAILURE ��ǉ�</li>
      <li>�l�̃p�����[�^�e�X�g�̖����I�o�^�ɑΉ�(IUTEST_REIGSTER_TEST_P)</li>
      <li>�p�����[�^�̑g�ݍ��킹(�f�J���g��)�e�X�g�𐶐����� iuCombine ��ǉ�</li>
      <li>IUTEST_*_NO_FATAL_FAILURE, IUTEST_*_NO_FAILURE ��ǉ�</li>
      <li>�����I�Ȑ����Ǝ��s�ɑΉ�</li>
    </ul>
  </li>
  <li>v1.2.0.0
    <ul>
      <li>�l�̃p�����[�^���e�X�g�ɑΉ�</li>
    </ul>
  </li>
  <li>v1.1.0.0
    <ul>
      <li>���C�u�����r���h�Ή�</li>
    </ul>
  </li>
  <li>v1.0.1.1
    <ul>
      <li>�e�X�g�t�B�N�X�`���o�R�Ń��[�U�[�f�[�^��ێ��ł���悤�ɏC��</li>
      <li>�I�v�V�����̊��ϐ��� IUTEST_C ����n�܂閼�O�ɕύX</li>
    </ul>
  </li>
  <li>v1.0.0.0
    <ul>
      <li>���������[�X</li>
      <li>�A�T�[�V�����Ŏ��s�����ꍇ�Ɏ��s���̒l���o�͂���悤�ɕύX</li>
    </ul>
  </li>
  <li>v0.9.3.0
    <ul>
      <li>���ϐ��ɑΉ�</li>
      <li>�O���[�o���� SetUp - TearDown �ɑΉ�</li>
      <li>IUTEST_STATIC_ASSERT �ǉ�</li>
      <li>�q��t�H�[�}�b�g�� INFORM �ɑΉ����Ă��Ȃ������̂ŏC��</li>
      <li>C90 �Ή�</li>
    </ul>
  </li>
  <li>v0.8.0.0
    <ul>
      <li>�e�X�g�֐��̎������W�ɑΉ����Ă��Ȃ����p�ɖ����I�ȓo�^�}�N����ǉ�</li>
      <li>������o�͊֐��|�C���^��ݒ�ł���悤�ɏC��</li>
    </ul>
  </li>
  <li>v0.7.0.0
    <ul>
      <li>�r���h�G���[�C��</li>
    </ul>
  </li>
  <li>v0.6.2.1
    <ul>
      <li>�p�����^���C�Y�e�X�g�Ή�</li>
    </ul>
  </li>
  <li>v0.5.1.0
    <ul>
      <li>Printer �Ή�</li>
      <li>�e�X�g�O�ł̎��s�����f�����悤�ɏC��</li>
    </ul>
  </li>
  <li>v0.4.1.0
    <ul>
      <li>RecordProperty �Ή�</li>
      <li>IUTEST_FALG �ňꕔ�̃I�v�V�������Q�Ƃł��Ȃ��s����C��</li>
      <li>repeat �񐔂� 0 �ȉ����w�肵���ۂ̕s����C��</li>
      <li>xml �o�͑Ή�</li>
    </ul>
  </li>
  <li>v0.3.0.0
    <ul>
      <li>INFORM �Ή�</li>
      <li>DISABLED �e�X�g�Ή�</li>
      <li>--iutest_also_run_disabled_tests �Ή�</li>
      <li>--iutest_shuffle �Ή�</li>
      <li>--iutest_random_seed �Ή�</li>
      <li>--iutest_print_time �Ή�</li>
    </ul>
  </li>
  <li>v0.2.0.0
    <ul>
      <li>--iutest_break_on_failure �Ή�</li>
      <li>--iutest_repeat �Ή�</li>
      <li>--iutest_color �Ή�</li>
      <li>--iutest_list_tests �Ή�</li>
      <li>--feature �Ή�</li>
    </ul>
  </li>
  <li>v0.1.0.0
    <ul>
      <li>��{�I�ȃe�X�g�̍쐬�ɑΉ�</li>
      <li>�e�X�g�̃t�B���^�����O�ɑΉ�</li>
    </ul>
  </li>
</ul>
*/

#endif
