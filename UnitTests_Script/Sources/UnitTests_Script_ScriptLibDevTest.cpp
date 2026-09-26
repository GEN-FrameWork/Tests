/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibDevTest.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBDEVTEST
* @brief      Unit tests for SCRIPT_LIB_DEVTEST
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
#include "UnitTests_Script_ScriptLibDevTest.h"
#include "UnitTests_Script_TestHelpers.h"
#ifdef SCRIPT_LIB_DEVTEST_ACTIVE
#include "Script_Lib_DevTest.h"
#endif
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_DEVTEST_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBDEVTEST, UNITTESTS_SCRIPTLIBDEVTEST_CLASSNAME, SCRIPT_LIB_DEVTEST, SCRIPT_LIB_NAME_DEVTEST, __L("DevTest_Func1"))

namespace TEST_SCRIPTLIBDEVTEST
{
TEST(UNITTESTS_SCRIPTLIBDEVTEST_CLASSNAME, ReturnsDevelopmentPayload)
{
  SCRIPT script;
  SCRIPT_LIB_DEVTEST library;
  XVECTOR<XVARIANT*> params;
  XVARIANT result;
  XSTRING text;

  Call_DevTest_Func1(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_NE(text.Find(__L("Pepe"), false), XSTRING_NOTFOUND);
}
}
#endif
