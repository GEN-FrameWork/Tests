/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptErrorCode.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTERRORCODE
* @brief      Unit tests for Script error codes
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @cond
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files(the "Software"), to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense, and/ or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of
* the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
* THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* @endcond
*
* --------------------------------------------------------------------------------------------------------------------*/

#include "GEN_Defines.h"
#include "UnitTests_Script_ScriptErrorCode.h"
#include "gtest/gtest.h"
#include "Script_ErrorCode.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
namespace TEST_SCRIPTERRORCODE
{

TEST(UNITTESTS_SCRIPTERRORCODE_CLASSNAME, CommonValuesRemainStable)
{
  EXPECT_EQ(SCRIPT_ERRORCODE_NONE, 0);
  EXPECT_EQ(SCRIPT_ERRORCODE_INTERNALERROR, 1);
  EXPECT_EQ(SCRIPT_ERRORCODE_INSUF_PARAMS, 2);
  EXPECT_EQ(SCRIPT_ERRORCODE_OWN, 3);
}

}
#endif
