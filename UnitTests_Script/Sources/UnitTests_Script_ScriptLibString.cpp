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
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBSTRING, UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SCRIPT_LIB_STRING, SCRIPT_LIB_NAME_STRING, _L("ExtractBetween"))

namespace TEST_SCRIPTLIBSTRING
{
TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SPrintfPreservesPercentInData)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT destination(_L(""));
  XVARIANT mask(_L("%s"));
  XVARIANT data(_L("100% ready"));
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  params.Add(&destination);
  params.Add(&mask);
  params.Add(&data);
  Call_SPrintf(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_EQ(text.Compare(_L("100% ready")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SPrintfFormatsIntegerAndWidth)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT destination(_L(""));
  XVARIANT mask(_L("n=%d pad=%05d"));
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
  EXPECT_EQ(text.Compare(_L("n=42 pad=00007")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, CompareStringDetectsEqualAndDifferent)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT left(_L("alpha"));
  XVARIANT rightsame(_L("alpha"));
  XVARIANT rightdiff(_L("beta"));
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
  XVARIANT left(_L("foo"));
  XVARIANT right(_L("bar"));
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  params.Add(&left);
  params.Add(&right);
  Call_AddString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_EQ(text.Compare(_L("foobar")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, GetStringSizeAndIsEmpty)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT text(_L("abcd"));
  XVARIANT empty(_L(""));
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  params.Add(&text);
  Call_GetStringSize(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 4);

  Call_IsEmptyString(&library, &script, &params, &result);
  EXPECT_FALSE((bool)result);

  params.DeleteAll();
  params.Add(&empty);
  Call_IsEmptyString(&library, &script, &params, &result);
  EXPECT_TRUE((bool)result);
  Call_GetStringSize(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, SubStringAndSubStringFrom)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT text(_L("0123456789"));
  XVARIANT start(2);
  XVARIANT end(5);
  XVARIANT from(7);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING out;

  params.Add(&text);
  params.Add(&start);
  params.Add(&end);
  Call_SubString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("234")), 0);

  params.DeleteAll();
  params.Add(&text);
  params.Add(&from);
  Call_SubStringFrom(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("789")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, FindStringWithOptionalStartIndex)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT haystack(_L("one two one"));
  XVARIANT needle(_L("one"));
  XVARIANT ignorecase(false);
  XVARIANT start(1);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  params.Add(&haystack);
  params.Add(&needle);
  params.Add(&ignorecase);
  Call_FindString(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 0);

  params.Add(&start);
  Call_FindString(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 8);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, ExtractBetweenFindsPayloadAndFailsCleanly)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT html(_L("<b class=\"x\">1.2.3.4</b><b class=\"x\">5.6.7.8</b>"));
  XVARIANT startmark(_L("<b class=\"x\">"));
  XVARIANT endmark(_L("</b>"));
  XVARIANT ignorecase(false);
  XVARIANT from(0);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING out;

  params.Add(&html);
  params.Add(&startmark);
  params.Add(&endmark);
  Call_ExtractBetween(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("1.2.3.4")), 0);

  params.Add(&ignorecase);
  XVARIANT fromsecond(20);
  params.Add(&fromsecond);
  Call_ExtractBetween(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("5.6.7.8")), 0);

  params.DeleteAll();
  XVARIANT missingstart(_L("<ip>"));
  params.Add(&html);
  params.Add(&missingstart);
  params.Add(&endmark);
  Call_ExtractBetween(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_TRUE(out.IsEmpty());
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, TrimToUpperToLowerGetCharReplaceAll)
{
  SCRIPT script;
  SCRIPT_LIB_STRING library;
  XVARIANT padded(_L("  hello  \r\n"));
  XVARIANT mixed(_L("AbC"));
  XVARIANT sample(_L("a-b-a"));
  XVARIANT find(_L("a"));
  XVARIANT replace(_L("x"));
  XVARIANT index(1);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING out;

  params.Add(&padded);
  Call_TrimString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("hello")), 0);

  params.DeleteAll();
  params.Add(&mixed);
  Call_ToUpperString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("ABC")), 0);

  Call_ToLowerString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("abc")), 0);

  params.DeleteAll();
  params.Add(&mixed);
  params.Add(&index);
  Call_GetCharString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("b")), 0);

  params.DeleteAll();
  params.Add(&sample);
  params.Add(&find);
  params.Add(&replace);
  Call_ReplaceAllString(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(out));
  EXPECT_EQ(out.Compare(_L("x-b-x")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSTRING_CLASSNAME, RegistersAllNewStringHelpers)
{
  SCRIPT_LIB_STRING library;
  SCRIPT script;

  ASSERT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(_L("GetStringSize")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("IsEmptyString")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("SubString")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("SubStringFrom")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("ExtractBetween")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("TrimString")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("ToUpperString")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("ToLowerString")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("GetCharString")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("ReplaceAllString")), (SCRIPT_LIB_FUNCTION*)NULL);
}
}
#endif
