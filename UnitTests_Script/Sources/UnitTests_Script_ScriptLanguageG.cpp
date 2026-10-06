/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLanguageG.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLANGUAGEG
* @brief      Unit tests for the G interpreter
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
#include "UnitTests_Script_ScriptLanguageG.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Language_G.h"
#include "GEN_Control.h"
#include "XSleep.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_G_ACTIVE)
namespace TEST_SCRIPTLANGUAGEG
{

TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, CommandStoresTextAndToken)
{
  SCRIPT_LNG_G_COMMAND command;

  ASSERT_TRUE(command.Set(_L("return"), SCRIPT_LNG_G_TOKENIREPS_RETURN));
  EXPECT_EQ(command.GetCommand()->Compare(_L("return")), 0);
  EXPECT_EQ(command.GetToken(), SCRIPT_LNG_G_TOKENIREPS_RETURN);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, FloatVariableRoundTripsThroughVariant)
{
  SCRIPT_LNG_G_VAR source;
  SCRIPT_LNG_G_VAR destination;
  XVARIANT variant;

  EXPECT_TRUE(source.SetType(SCRIPT_LNG_G_TOKENIREPS_FLOAT));
  EXPECT_TRUE(source.SetValueFloat(3.75f));
  EXPECT_TRUE(source.ConvertToXVariant(variant));
  EXPECT_TRUE(destination.ConvertFromXVariant(variant));
  EXPECT_EQ(destination.GetType(), SCRIPT_LNG_G_TOKENIREPS_FLOAT);
  EXPECT_FLOAT_EQ(destination.GetValueFloat(), 3.75f);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, FunctionNameSetterReportsSuccess)
{
  SCRIPT_LNG_G_FUNCTIONTYPE function;

  EXPECT_TRUE(function.SetName(_L("main")));
  EXPECT_EQ(function.GetName()->Compare(_L("main")), 0);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, ExecutesIntegerAndFloatExpressions)
{
  SCRIPT_LNG_G script;
  int returnvalue = 0;

  (*script.GetScript()) = _L("int main(){ float value; value = 1.5 + 2.25; if(value == 3.75){ return 42; } return 0; }");

  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 42);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, ReportsUnexpectedEndOfInput)
{
  SCRIPT_LNG_G script;

  (*script.GetScript()) = _L("int main(){ string value; value = \"unterminated; }");

  EXPECT_NE(script.Run(), SCRIPT_ERRORCODE_NONE);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, RejectsModuloByZero)
{
  SCRIPT_LNG_G script;

  (*script.GetScript()) = _L("int main(){ return 10 % 0; }");

  EXPECT_EQ(script.Run(), SCRIPT_LNG_G_ERRORCODE_DIV_BY_ZERO);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, RunWithThreadExposesReturnValue)
{
  SCRIPT_LNG_G script;
  int          error       = -1;
  int          returnvalue = -1;
  int          spins       = 0;

  (*script.GetScript()) = _L("int main(){ return 42; }");

  ASSERT_TRUE(script.RunWithThread());

  while(script.IsRunThread(&error, &returnvalue) && (spins < 500))
    {
      GEN_XSLEEP.MilliSeconds(10);
      spins++;
    }

  EXPECT_LT(spins, 500);
  EXPECT_EQ(error, SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 42);
  EXPECT_EQ(script.GetReturnValueScript(), 42);
}


static void UnitTests_ScriptLanguageG_ReturnDouble(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 2.75;
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, NativeDoubleReturnMapsToFloat)
{
  SCRIPT_LNG_G script;
  SCRIPT_LIB   library(_L("UnitTest"));
  int          returnvalue = 0;

  ASSERT_TRUE(script.AddLibraryFunction(&library, _L("NativeDouble"), UnitTests_ScriptLanguageG_ReturnDouble));

  (*script.GetScript()) = _L("int main(){ float v; v = NativeDouble(); if(v == 2.75){ return 1; } return 0; }");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 1);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, AllowsMissingMain)
{
  SCRIPT_LNG_G script;
  int          returnvalue = -1;

  (*script.GetScript()) = _L("int helper(){ return 7; }");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 0);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, AllowsUnbracedIfElse)
{
  SCRIPT_LNG_G script;
  int          returnvalue = 0;

  (*script.GetScript()) = _L("int main(){ int a; a = 3; if(a > 5) return 1; else return 2; }");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 2);
}


static void UnitTests_ScriptLanguageG_ReturnDoubleNeedsPrecision(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  // Not exactly representable in IEEE float32 (2^24+1).
  if(returnvalue) (*returnvalue) = 16777217.0;
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, LogicalNotAndAndOr)
{
  SCRIPT_LNG_G script;
  int          returnvalue = 0;

  (*script.GetScript()) =
    _L("int main(){ int a; int b; a = 0; b = 5; if(!a && b){ } else { return 1; } if(a || !b){ return 2; } if(!(a == 0) || (b == 5)){ } else { return 3; } if(!!b && !a){ return 42; } return 4; }");

  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 42);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, LogicalOrPrecedenceOverAnd)
{
  SCRIPT_LNG_G script;
  int          returnvalue = 0;

  // false && true || true  =>  (false && true) || true  => true
  (*script.GetScript()) = _L("int main(){ if(0 && 1 || 1){ return 7; } return 0; }");

  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 7);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, EscapedQuotesInStringLiterals)
{
  SCRIPT_LNG_G script;
  int          returnvalue = 0;

  // G source after C escapes: q = "\"";  → string of one quote.
  (*script.GetScript()) =
    _L("int main(){ string q; q = \"\\\"\"; return GetStringSize(q); }");

  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 1);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, ExtractBetweenWithEscapedJsonMarks)
{
  SCRIPT_LNG_G script;
  int          returnvalue = 0;

  // Avoid '{' / '}' inside G string literals (brace scanner does not skip strings).
  // Build JSON-like marks via AddString so body escapes stay unambiguous.
  (*script.GetScript()) =
    _L("int main(){ string q; string start; string body; string country; q = \"\\\"\"; start = AddString(q, \"country\"); start = AddString(start, q); start = AddString(start, \":\"); start = AddString(start, q); body = AddString(\"x\", start); body = AddString(body, \"Spain\"); body = AddString(body, q); body = AddString(body, \"y\"); country = ExtractBetween(body, start, q); if(CompareString(country, \"Spain\", 0)){ return 9; } return 2; }");

  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 9);
}


TEST(UNITTESTS_SCRIPTLANGUAGEG_CLASSNAME, DoublePrecisionSurvivesLibraryRoundTrip)
{
  SCRIPT_LNG_G script;
  SCRIPT_LIB   library(_L("UnitTest"));
  int          returnvalue = 0;

  ASSERT_TRUE(script.AddLibraryFunction(&library, _L("NativePrecise"), UnitTests_ScriptLanguageG_ReturnDoubleNeedsPrecision));

  (*script.GetScript()) = _L("int main(){ float v; v = NativePrecise(); if(v == 16777217){ return 1; } return 0; }");
  EXPECT_EQ(script.Run(&returnvalue), SCRIPT_ERRORCODE_NONE);
  EXPECT_EQ(returnvalue, 1);
}

}
#endif
