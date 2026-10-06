/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Property_Selectable.cpp
*
* @brief      UserInterface unit tests for UI_PROPERTY_SELECTABLE
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_PROPERTY_SELECTABLE
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

#include "UnitTests_UserInterface_Property_Selectable.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Property_Selectable.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_PROPERTY_SELECTABLE
{


TEST(UNITTESTS_UI_PROPERTY_SELECTABLE_CLASSNAME, DefaultsToDeactiveWithDefaultSelectionTimeAndTimer)
{
  UI_PROPERTY_SELECTABLE property;

  EXPECT_EQ(property.GetSelectableState(), UI_PROPERTY_SELECTABLE_STATE_DEACTIVE);
  EXPECT_EQ(property.GetTimeSelected(), UI_PROPERTY_SELECTABLE_DEFAULT_TIMESELECTED);
  EXPECT_NE(property.GetXTimerSelected(), (XTIMER*)NULL);
}


TEST(UNITTESTS_UI_PROPERTY_SELECTABLE_CLASSNAME, SetSelectableStateRoundTrips)
{
  UI_PROPERTY_SELECTABLE property;

  ASSERT_TRUE(property.SetSelectableState(UI_PROPERTY_SELECTABLE_STATE_SELECTED));
  EXPECT_EQ(property.GetSelectableState(), UI_PROPERTY_SELECTABLE_STATE_SELECTED);
}


TEST(UNITTESTS_UI_PROPERTY_SELECTABLE_CLASSNAME, SetSelectableStateFromStringMapsKnownTokens)
{
  UI_PROPERTY_SELECTABLE property;

  EXPECT_EQ(property.SetSelectableStateFromString(_L("active")), UI_PROPERTY_SELECTABLE_STATE_ACTIVE);
  EXPECT_EQ(property.GetSelectableState(), UI_PROPERTY_SELECTABLE_STATE_ACTIVE);

  EXPECT_EQ(property.SetSelectableStateFromString(_L("preselect")), UI_PROPERTY_SELECTABLE_STATE_PRESELECT);
  EXPECT_EQ(property.SetSelectableStateFromString(_L("selected")), UI_PROPERTY_SELECTABLE_STATE_SELECTED);
  EXPECT_EQ(property.SetSelectableStateFromString(_L("deactive")), UI_PROPERTY_SELECTABLE_STATE_DEACTIVE);
}


TEST(UNITTESTS_UI_PROPERTY_SELECTABLE_CLASSNAME, SetSelectableStateFromStringFallsBackToDeactive)
{
  UI_PROPERTY_SELECTABLE property;

  EXPECT_EQ(property.SetSelectableStateFromString((XCHAR*)NULL), UI_PROPERTY_SELECTABLE_STATE_DEACTIVE);
  EXPECT_EQ(property.SetSelectableStateFromString(_L("not-a-state")), UI_PROPERTY_SELECTABLE_STATE_DEACTIVE);
}


TEST(UNITTESTS_UI_PROPERTY_SELECTABLE_CLASSNAME, TimeSelectedRoundTrips)
{
  UI_PROPERTY_SELECTABLE property;

  property.SetTimeSelected(250);
  EXPECT_EQ(property.GetTimeSelected(), 250);
}


} // namespace TEST_UI_PROPERTY_SELECTABLE
#endif // GOOGLETEST_ACTIVE
