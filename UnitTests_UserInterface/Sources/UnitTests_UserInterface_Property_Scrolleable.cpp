/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Property_Scrolleable.cpp
*
* @brief      UserInterface unit tests for UI_PROPERTY_SCROLLEABLE
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_PROPERTY_SCROLLEABLE
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

#include "UnitTests_UserInterface_Property_Scrolleable.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Property_Scrolleable.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_PROPERTY_SCROLLEABLE
{


TEST(UNITTESTS_UI_PROPERTY_SCROLLEABLE_CLASSNAME, OverflowDefaultsToAutoPerAxis)
{
  UI_PROPERTY_SCROLLEABLE property;

  EXPECT_EQ(property.Scroll_GetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL), UI_OVERFLOW_AUTO);
  EXPECT_EQ(property.Scroll_GetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL), UI_OVERFLOW_AUTO);
}


TEST(UNITTESTS_UI_PROPERTY_SCROLLEABLE_CLASSNAME, OverflowSetPerAxisRoundTripsIndependently)
{
  UI_PROPERTY_SCROLLEABLE property;

  property.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL, UI_OVERFLOW_HIDDEN);
  property.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL, UI_OVERFLOW_SCROLL);

  EXPECT_EQ(property.Scroll_GetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL), UI_OVERFLOW_HIDDEN);
  EXPECT_EQ(property.Scroll_GetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL), UI_OVERFLOW_SCROLL);
}


TEST(UNITTESTS_UI_PROPERTY_SCROLLEABLE_CLASSNAME, OverflowSetAllAppliesToBothAxes)
{
  UI_PROPERTY_SCROLLEABLE property;

  property.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_ALL, UI_OVERFLOW_AUTO);

  EXPECT_EQ(property.Scroll_GetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL), UI_OVERFLOW_AUTO);
  EXPECT_EQ(property.Scroll_GetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL), UI_OVERFLOW_AUTO);
}


TEST(UNITTESTS_UI_PROPERTY_SCROLLEABLE_CLASSNAME, ActivateModesRoundTrip)
{
  UI_PROPERTY_SCROLLEABLE property;

  ASSERT_TRUE(property.Scroll_SetActivate(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL, true));
  EXPECT_EQ(property.Scroll_GetActivateMode(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL), UI_PROPERTY_SCROLLEABLE_ACTIVATE_ON);

  ASSERT_TRUE(property.Scroll_SetActivate(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL, false));
  EXPECT_EQ(property.Scroll_GetActivateMode(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL), UI_PROPERTY_SCROLLEABLE_ACTIVATE_OFF);

  ASSERT_TRUE(property.Scroll_SetActivateAuto(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL));
  EXPECT_EQ(property.Scroll_GetActivateMode(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL), UI_PROPERTY_SCROLLEABLE_ACTIVATE_AUTO);
}


TEST(UNITTESTS_UI_PROPERTY_SCROLLEABLE_CLASSNAME, NeedClipFollowsOverflowVisibleRule)
{
  UI_PROPERTY_SCROLLEABLE property;

  // Default overflow is AUTO, which already requires clipping.
  EXPECT_TRUE(property.Scroll_NeedClip());

  property.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_ALL, UI_OVERFLOW_VISIBLE);
  EXPECT_FALSE(property.Scroll_NeedClip());

  property.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL, UI_OVERFLOW_HIDDEN);
  EXPECT_TRUE(property.Scroll_NeedClip());
}


} // namespace TEST_UI_PROPERTY_SCROLLEABLE
#endif // GOOGLETEST_ACTIVE
