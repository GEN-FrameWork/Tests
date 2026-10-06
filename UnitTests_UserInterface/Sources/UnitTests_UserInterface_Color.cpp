/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Color.cpp
*
* @brief      UserInterface unit tests for UI_COLOR
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_COLOR
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

#include "UnitTests_UserInterface_Color.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Color.h"
#include "UI_Colors.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_COLOR
{


TEST(UNITTESTS_UI_COLOR_CLASSNAME, DefaultConstructorIsInvalidWithZeroChannels)
{
  UI_COLOR color;

  EXPECT_FALSE(color.IsValid());
  EXPECT_EQ(color.GetRed(), 0);
  EXPECT_EQ(color.GetGreen(), 0);
  EXPECT_EQ(color.GetBlue(), 0);
  EXPECT_EQ(color.GetAlpha(), 0);
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, ParsesRgbTripleWithOpaqueAlpha)
{
  UI_COLOR color;

  ASSERT_TRUE(color.SetFromString(_L("10,20,30")));
  EXPECT_EQ(color.GetRed(), 10);
  EXPECT_EQ(color.GetGreen(), 20);
  EXPECT_EQ(color.GetBlue(), 30);
  EXPECT_EQ(color.GetAlpha(), 255);
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, ParsesRgbPlusPercentAlpha)
{
  UI_COLOR color;

  ASSERT_TRUE(color.SetFromString(_L("10,20,30,50")));
  EXPECT_EQ(color.GetRed(), 10);
  EXPECT_EQ(color.GetGreen(), 20);
  EXPECT_EQ(color.GetBlue(), 30);
  EXPECT_EQ(color.GetAlpha(), 127);   // (50 * 255) / 100
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, ParsesCssHexRgbAndDefaultsAlphaTo255)
{
  UI_COLOR color;

  ASSERT_TRUE(color.SetFromString(_L("#112233")));
  EXPECT_TRUE(color.IsValid());
  EXPECT_EQ(color.GetRed(), 0x11);
  EXPECT_EQ(color.GetGreen(), 0x22);
  EXPECT_EQ(color.GetBlue(), 0x33);
  EXPECT_EQ(color.GetAlpha(), 255);
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, ParsesCssHexRgba)
{
  UI_COLOR color;

  ASSERT_TRUE(color.SetFromString(_L("#11223344")));
  EXPECT_EQ(color.GetRed(), 0x11);
  EXPECT_EQ(color.GetGreen(), 0x22);
  EXPECT_EQ(color.GetBlue(), 0x33);
  EXPECT_EQ(color.GetAlpha(), 0x44);
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, RejectsEmptyAndMalformedHex)
{
  UI_COLOR color;

  EXPECT_FALSE(color.SetFromString(_L("")));
  EXPECT_FALSE(color.SetFromString(_L("#123")));
  EXPECT_FALSE(color.SetFromString((XCHAR*)NULL));
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, CopyFromAndCopyToRoundTrip)
{
  UI_COLOR source;
  UI_COLOR dest;

  ASSERT_TRUE(source.SetFromString(_L("1,2,3,100")));
  ASSERT_TRUE(dest.CopyFrom(&source));

  EXPECT_EQ(dest.GetRed(), source.GetRed());
  EXPECT_EQ(dest.GetGreen(), source.GetGreen());
  EXPECT_EQ(dest.GetBlue(), source.GetBlue());
  EXPECT_EQ(dest.GetAlpha(), source.GetAlpha());

  UI_COLOR again;
  ASSERT_TRUE(source.CopyTo(&again));
  EXPECT_EQ(again.GetRed(), 1);
  EXPECT_EQ(again.GetGreen(), 2);
  EXPECT_EQ(again.GetBlue(), 3);
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, CopyFromNullFails)
{
  UI_COLOR color;

  EXPECT_FALSE(color.CopyFrom(NULL));
  EXPECT_FALSE(color.CopyTo(NULL));
}


TEST(UNITTESTS_UI_COLOR_CLASSNAME, ResolvesNamedColorThroughUiColorsRegistry)
{
  ASSERT_TRUE(GEN_UI_COLORS.Add(_L("ut_brand"), _L("9,8,7")));

  UI_COLOR color;
  ASSERT_TRUE(color.SetFromString(_L("ut_brand")));
  EXPECT_EQ(color.GetRed(), 9);
  EXPECT_EQ(color.GetGreen(), 8);
  EXPECT_EQ(color.GetBlue(), 7);
  EXPECT_EQ(color.GetAlpha(), 255);

  GEN_UI_COLORS.DeleteAll();
}


} // namespace TEST_UI_COLOR
#endif // GOOGLETEST_ACTIVE
