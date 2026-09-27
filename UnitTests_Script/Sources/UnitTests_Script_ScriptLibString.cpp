/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibString.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBSTRING
* @brief      Unit tests for SCRIPT_LIB_STRING
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
#include "UnitTests_Script_ScriptLibString.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Lib_String.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBSTRING, UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SCRIPT_LIB_STRING, SCRIPT_LIB_NAME_STRING, __L("SPrintf"))

namespace TEST_SCRIPTLIBSTRING
{
TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SPrintfPreservesPercentInData)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT destination(__L(""));
  XVARIANT mask(__L("%s"));
  XVARIANT data(__L("100% ready"));
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  params.Add(&destination);
  params.Add(&mask);
  params.Add(&data);
  Call_SPrintf(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_EQ(text.Compare(__L("100% ready")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SPrintfFormatsIntegerAndWidth)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT destination(__L(""));
  XVARIANT mask(__L("n=%d pad=%05d"));
  XVARIANT value(42);
  XVARIANT pad(7);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  params.Add(&destination);
  params.Add(&mask);
  params.Add(&value);
  params.Add(&pad);
  Call_SPrintf(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_EQ(text.Compare(__L("n=42 pad=00007")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, CompareStringDetectsEqualAndDifferent)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT left(__L("alpha"));
  XVARIANT rightsame(__L("alpha"));
  XVARIANT rightdiff(__L("beta"));
  XVARIANT ignorecase(false);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  params.Add(&left);
  params.Add(&rightsame);
  params.Add(&ignorecase);
  Call_CompareString(&library, &script, &params, &result);
  EXPECT_TRUE((bool)result);

  params.DeleteAll();
  params.Add(&left);
  params.Add(&rightdiff);
  params.Add(&ignorecase);
  Call_CompareString(&library, &script, &params, &result);
  EXPECT_FALSE((bool)result);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, AddStringConcatenatesIntoFirstArgument)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT left(__L("foo"));
  XVARIANT right(__L("bar"));
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  params.Add(&left);
  params.Add(&right);
  Call_AddString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_EQ(text.Compare(__L("foobar")), 0);
}
}
#endif
