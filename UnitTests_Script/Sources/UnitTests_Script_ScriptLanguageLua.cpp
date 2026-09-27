/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLanguageLua.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLANGUAGELUA
* @brief      Unit tests for the Lua interpreter
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
#include "UnitTests_Script_ScriptLanguageLua.h"
#include "UnitTests_Script_TestHelpers.h"

#ifdef SCRIPT_LUA_ACTIVE
#include "Script_Language_Lua.h"
#endif

#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LUA_ACTIVE)
namespace TEST_SCRIPTLANGUAGELUA
{

static void UnitTests_ScriptLanguageLua_ReturnInteger(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 40;
}


static void UnitTests_ScriptLanguageLua_ReturnFloat(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 1.25f;
}


static void UnitTests_ScriptLanguageLua_ReturnDouble(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 2.75;
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, ExecutesNumericResult)
{
  SCRIPT_LNG_LUA script;
  int returnvalue = 0;

  (*script.GetScript()) = __L("return 42");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 42);
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, ReportsSyntaxError)
{
  SCRIPT_LNG_LUA script;

  (*script.GetScript()) = __L("function main(");
  EXPECT_NE(script.Run(), SCRIPT_ERRORCODE_NONE);
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, ExecutesReturnAfterLoadingChunk)
{
  SCRIPT_LNG_LUA script;
  int returnvalue = 0;

  (*script.GetScript()) = __L("return 7");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 7);
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, ReevaluatesScriptBetweenRuns)
{
  SCRIPT_LNG_LUA script;
  int returnvalue = 0;

  (*script.GetScript()) = __L("return 7");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 7);

  (*script.GetScript()) = __L("return 9");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 9);

  (*script.GetScript()) = __L("return 3");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 3);
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, NativeLibraryFunctionsReturnNumbers)
{
  SCRIPT_LNG_LUA script;
  SCRIPT_LIB library(__L("UnitTest"));
  int returnvalue = 0;

  ASSERT_TRUE(script.AddLibraryFunction(&library, __L("NativeInteger"), UnitTests_ScriptLanguageLua_ReturnInteger));

  (*script.GetScript()) = __L("return NativeInteger()");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 40);
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, NativeFloatAndDoubleReturnAsNumbers)
{
  SCRIPT_LNG_LUA script;
  SCRIPT_LIB library(__L("UnitTest"));
  int returnvalue = 0;

  ASSERT_TRUE(script.AddLibraryFunction(&library, __L("NativeFloat"), UnitTests_ScriptLanguageLua_ReturnFloat));
  ASSERT_TRUE(script.AddLibraryFunction(&library, __L("NativeDouble"), UnitTests_ScriptLanguageLua_ReturnDouble));

  (*script.GetScript()) = __L("return (NativeFloat() * 10) + (NativeDouble() * 10)");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 40);
}


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, LoadsStandardLibrariesWithInterpreter)
{
  SCRIPT_LNG_LUA script;
  int returnvalue = 0;

  (*script.GetScript()) = __L("if os == nil and io == nil then return 0 else return 1 end");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  #ifdef SCRIPT_LIB_SANDBOX_ACTIVE
  // Sandbox: os/io must not be present.
  EXPECT_EQ(returnvalue, 0);
  #else
  // Trusted (default): full luaL_openlibs.
  EXPECT_EQ(returnvalue, 1);
  #endif
}

}
#endif
