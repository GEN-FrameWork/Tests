/**-------------------------------------------------------------------------------------------------------------------
* @file       UnitTests_Script_ScriptLanguageLua.cpp
* @brief      Unit tests for the Lua interpreter
* @ingroup    TESTS
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


TEST(UNITTESTS_SCRIPTLANGUAGELUA_CLASSNAME, LoadsStandardLibrariesWithInterpreter)
{
  SCRIPT_LNG_LUA script;
  int returnvalue = 0;

  (*script.GetScript()) = __L("if os == nil and io == nil then return 0 else return 1 end");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 1);
}

}
#endif
