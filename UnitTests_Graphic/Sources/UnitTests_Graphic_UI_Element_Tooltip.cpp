/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_UI_Element_Tooltip.cpp
*
* @class      UNITTESTS_GRAPHIC_UI_ELEMENT_TOOLTIP
* @brief      Graphic unit tests for UI_ELEMENT_TOOLTIP
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

#include "UnitTests_Graphic_UI_Element_Tooltip.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#ifdef USERINTERFACE_ACTIVE
#include "UI_Element_Tooltip.h"
#include "UI_BoundaryLine.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef USERINTERFACE_ACTIVE
namespace TEST_UI_ELEMENT_TOOLTIP
{


TEST(UNITTESTS_UI_ELEMENT_TOOLTIP_CLASSNAME, DefaultTypeHiddenAndShowDelay)
{
  UI_ELEMENT_TOOLTIP tip;

  EXPECT_EQ(tip.GetType(), UI_ELEMENT_TYPE_TOOLTIP);
  ASSERT_NE(tip.GetTypeString(), (XSTRING*)NULL);
  EXPECT_EQ(tip.GetTypeString()->Compare(_L("tooltip"), true), 0);

  EXPECT_FALSE(tip.IsVisible());
  EXPECT_EQ(tip.GetShowDelayMs(), (XDWORD)UI_ELEMENT_TOOLTIP_DEFAULT_SHOW_DELAY_MS);

  tip.SetShowDelayMs(200);
  EXPECT_EQ(tip.GetShowDelayMs(), (XDWORD)200);
}


TEST(UNITTESTS_UI_ELEMENT_TOOLTIP_CLASSNAME, ShowHideToggleVisibilityAndDirty)
{
  UI_ELEMENT_TOOLTIP tip;

  EXPECT_FALSE(tip.IsVisible());
  EXPECT_TRUE(tip.Show());
  EXPECT_TRUE(tip.IsVisible());
  EXPECT_TRUE(tip.MustReDraw());

  tip.SetMustReDraw(false);
  EXPECT_TRUE(tip.Hide());
  EXPECT_FALSE(tip.IsVisible());
}


TEST(UNITTESTS_UI_ELEMENT_TOOLTIP_CLASSNAME, ShowAtSetsEdgeBottomGeometry)
{
  UI_ELEMENT_TOOLTIP tip;

  ASSERT_NE(tip.GetBoundaryLine(), (UI_BOUNDARYLINE*)NULL);
  tip.GetBoundaryLine()->width  = 280.0;
  tip.GetBoundaryLine()->height = 72.0;

  EXPECT_TRUE(tip.ShowAt(120.0, 400.0));
  EXPECT_TRUE(tip.IsVisible());
  EXPECT_DOUBLE_EQ(tip.GetXPosition(), 120.0);
  EXPECT_DOUBLE_EQ(tip.GetYPosition(), 400.0);
  EXPECT_DOUBLE_EQ(tip.GetBoundaryLine()->x, 120.0);
  EXPECT_DOUBLE_EQ(tip.GetBoundaryLine()->y, 400.0);
}


TEST(UNITTESTS_UI_ELEMENT_TOOLTIP_CLASSNAME, SetContentStoresLiteralAndClearsMask)
{
  UI_ELEMENT_TOOLTIP tip;
  XSTRING            body;

  tip.GetMaskText()->Set(_L("#[TRANSLATE_1]"));
  body = _L("88.14.204.122\nMadrid, Spain\nOperador: Test");

  EXPECT_TRUE(tip.SetContent(body));
  ASSERT_NE(tip.GetText(), (XSTRING*)NULL);
  EXPECT_EQ(tip.GetText()->Compare(body.Get(), true), 0);
  EXPECT_TRUE(tip.GetMaskText()->IsEmpty());
  EXPECT_TRUE(tip.MustReDraw());

  EXPECT_TRUE(tip.SetContent((XCHAR*)NULL));
  EXPECT_TRUE(tip.GetText()->IsEmpty());
}


TEST(UNITTESTS_UI_ELEMENT_TOOLTIP_CLASSNAME, SetContentKeepsImageMarkupLiteral)
{
  UI_ELEMENT_TOOLTIP tip;
  XSTRING            body;

  body = _L("![IMAGE staticmaps/map.png]\n\n1.2.3.4\nCity, Country");
  EXPECT_TRUE(tip.SetContent(body.Get()));
  EXPECT_EQ(tip.GetText()->Compare(body.Get(), true), 0);
  EXPECT_NE(tip.GetText()->Find(_L("![IMAGE"), true), XSTRING_NOTFOUND);
}


}
#endif
#endif
