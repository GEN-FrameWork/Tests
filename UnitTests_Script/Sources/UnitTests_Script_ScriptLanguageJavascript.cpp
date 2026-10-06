/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLanguageJavascript.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLANGUAGEJAVASCRIPT
* @brief      Unit tests for the JavaScript interpreter
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
#include "UnitTests_Script_ScriptLanguageJavascript.h"
#include "UnitTests_Script_TestHelpers.h"

#ifdef SCRIPT_JAVASCRIPT_ACTIVE
#include "Script_Language_Javascript.h"
#endif

#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_JAVASCRIPT_ACTIVE)
namespace TEST_SCRIPTLANGUAGEJAVASCRIPT
{

static void UnitTests_ScriptLanguageJavascript_ReturnFloat(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 1.25f;
}


static void UnitTests_ScriptLanguageJavascript_ReturnDouble(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 2.75;
}


TEST(UNITTESTS_SCRIPTLANGUAGEJAVASCRIPT_CLASSNAME, ExecutesNumericResult)
{
  SCRIPT_LNG_JAVASCRIPT script;
  int returnvalue = 0;

  (*script.GetScript()) = _L("42");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 42);
}


TEST(UNITTESTS_SCRIPTLANGUAGEJAVASCRIPT_CLASSNAME, RejectsNonNumericResult)
{
  SCRIPT_LNG_JAVASCRIPT script;
  int returnvalue = 0;

  (*script.GetScript()) = _L("'not numeric'");
  EXPECT_NE(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
}


TEST(UNITTESTS_SCRIPTLANGUAGEJAVASCRIPT_CLASSNAME, NativeFloatAndDoubleReturnAsNumbers)
{
  SCRIPT_LNG_JAVASCRIPT script;
  SCRIPT_LIB library(_L("UnitTest"));
  int returnvalue = 0;

  ASSERT_TRUE(script.AddLibraryFunction(&library, _L("NativeFloat"), UnitTests_ScriptLanguageJavascript_ReturnFloat));
  ASSERT_TRUE(script.AddLibraryFunction(&library, _L("NativeDouble"), UnitTests_ScriptLanguageJavascript_ReturnDouble));

  (*script.GetScript()) = _L("(NativeFloat() * 10) + (NativeDouble() * 10)");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 40);
}


}
#endif
