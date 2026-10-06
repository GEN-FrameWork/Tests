/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_XUtils_XFString.cpp
*
* @class      UNITTESTS_XUTILS_XFSTRING
* @brief      XUtils unit tests for XFString class
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
/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Defines.h"


/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "UnitTests_XUtils_XFString.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XFString.h"
#include "XVector.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


#ifdef GOOGLETEST_ACTIVE
namespace TEST_XFSTRING
{

// These tests focus on what XFSTRING actually ADDS over XSTRING (which is already covered by
// UnitTests_XUtils_XString.cpp): the Fast_* accessors/mutators, Scan(), and Explode(). The
// assignment/relational operators XFSTRING re-declares just forward to XSTRING::Set/Add/Compare,
// so only a couple of sanity checks are included for those.


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToIntParsesLeadingInteger)
{
  XFSTRING string(_L("123abc"));

  EXPECT_EQ(string.Fast_ConvertToInt(), 123);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToIntHonoursStartIndex)
{
  XFSTRING string(_L("ab42"));

  EXPECT_EQ(string.Fast_ConvertToInt(2), 42);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToDWordParsesUnsigned)
{
  XFSTRING string(_L("4000000000"));

  EXPECT_EQ(string.Fast_ConvertToDWord(), (XDWORD)4000000000UL);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToQWordParsesLargeValue)
{
  XFSTRING string(_L("123456789012"));

  EXPECT_EQ(string.Fast_ConvertToQWord(), (XQWORD)123456789012ULL);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToSQWordParsesSignedValue)
{
  XFSTRING string(_L("-987654321"));

  EXPECT_EQ(string.Fast_ConvertToSQWord(), (XQWORDSIG)(-987654321LL));
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToFloatParsesDecimal)
{
  XFSTRING string(_L("3.5"));

  EXPECT_FLOAT_EQ(string.Fast_ConvertToFloat(), 3.5f);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertToDoubleParsesDecimal)
{
  XFSTRING string(_L("2.25"));

  EXPECT_DOUBLE_EQ(string.Fast_ConvertToDouble(), 2.25);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastConvertOnNonNumericTextReturnsZero)
{
  XFSTRING string(_L("abc"));

  EXPECT_EQ(string.Fast_ConvertToInt(), 0);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastAddCharacterOnEmptyStringGrowsToOneCharacter)
{
  XFSTRING string;

  EXPECT_TRUE(string.IsEmpty());
  EXPECT_TRUE(string.Fast_AddCharacter(L'A'));

  EXPECT_EQ(string.GetSize(), (XDWORD)1);
  EXPECT_EQ(string.Get()[0], L'A');
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastAddCharacterAppendsToExistingString)
{
  XFSTRING string(_L("ab"));

  EXPECT_TRUE(string.Fast_AddCharacter(L'c'));

  EXPECT_EQ(string.GetSize(), (XDWORD)3);
  EXPECT_EQ(0, string.Compare(_L("abc"), false));
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastEmptyClearsSizeButKeepsObjectUsable)
{
  XFSTRING string(_L("hello"));

  EXPECT_EQ(string.GetSize(), (XDWORD)5);
  EXPECT_TRUE(string.Fast_Empty());

  EXPECT_EQ(string.GetSize(), (XDWORD)0);
  EXPECT_TRUE(string.IsEmpty());
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, FastEmptyOnAlreadyEmptyStringSucceeds)
{
  XFSTRING string;

  EXPECT_TRUE(string.Fast_Empty());
  EXPECT_EQ(string.GetSize(), (XDWORD)0);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, ScanParsesIntegerFromInternalBuffer)
{
  XFSTRING string(_L("77 rest"));

  int value = 0;
  EXPECT_EQ(string.Scan(_L("%d"), &value), 1);
  EXPECT_EQ(value, 77);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, ScanReturnsZeroWhenMaskDoesNotMatch)
{
  XFSTRING string(_L("notanumber"));

  int value = 0;
  EXPECT_EQ(string.Scan(_L("%d"), &value), 0);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, ExplodeSplitsOnTokenIntoOwnedFragments)
{
  XFSTRING string(_L("aa,bb,ccc"));
  XVECTOR<XFSTRING*> parts;

  EXPECT_TRUE(string.Explode(L',', &parts));

  ASSERT_EQ(parts.GetSize(), (XDWORD)3);
  EXPECT_EQ(0, parts.Get(0)->Compare(_L("aa"), false));
  EXPECT_EQ(0, parts.Get(1)->Compare(_L("bb"), false));
  EXPECT_EQ(0, parts.Get(2)->Compare(_L("ccc"), false));

  for(XDWORD c = 0; c < parts.GetSize(); c++) { GEN_DELETE parts.Get(c); }
  parts.DeleteAll();
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, ExplodeSkipsEmptyFieldsBetweenConsecutiveTokens)
{
  // Explode only Add()s a fragment when (end-start)>0, so back-to-back tokens ("a,,b")
  // produce just the non-empty fragments, not an empty string in between.
  XFSTRING string(_L("a,,b"));
  XVECTOR<XFSTRING*> parts;

  EXPECT_TRUE(string.Explode(L',', &parts));

  ASSERT_EQ(parts.GetSize(), (XDWORD)2);
  EXPECT_EQ(0, parts.Get(0)->Compare(_L("a"), false));
  EXPECT_EQ(0, parts.Get(1)->Compare(_L("b"), false));

  for(XDWORD c = 0; c < parts.GetSize(); c++) { GEN_DELETE parts.Get(c); }
  parts.DeleteAll();
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, ExplodeWithNoTokenPresentReturnsWholeStringAsOneFragment)
{
  XFSTRING string(_L("noseparatorhere"));
  XVECTOR<XFSTRING*> parts;

  EXPECT_TRUE(string.Explode(L',', &parts));

  ASSERT_EQ(parts.GetSize(), (XDWORD)1);
  EXPECT_EQ(0, parts.Get(0)->Compare(_L("noseparatorhere"), false));

  for(XDWORD c = 0; c < parts.GetSize(); c++) { GEN_DELETE parts.Get(c); }
  parts.DeleteAll();
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, AssignmentOperatorFromCharSetsContent)
{
  XFSTRING string;

  string = "hello";

  EXPECT_EQ(0, string.Compare(_L("hello"), false));
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, AppendOperatorFromXCharAppendsCharacter)
{
  XFSTRING string(_L("ab"));

  string += L'c';

  EXPECT_EQ(0, string.Compare(_L("abc"), false));
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, RelationalOperatorsMatchCompareResult)
{
  XFSTRING lower(_L("apple"));
  XFSTRING upper(_L("banana"));

  EXPECT_TRUE(lower < upper);
  EXPECT_TRUE(upper > lower);
  EXPECT_TRUE(lower <= upper);
  EXPECT_FALSE(lower == upper);
  EXPECT_TRUE(lower != upper);
}


TEST(UNITTESTS_XFSTRING_CLASSNAME, IndexOperatorReturnsCharacterAtPosition)
{
  XFSTRING string(_L("xyz"));

  EXPECT_EQ(string[0], L'x');
  EXPECT_EQ(string[2], L'z');
}


}
#endif
