/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPDevice.cpp
*
* @class      UNITTESTS_INPUT_INPDEVICE
* @brief      Input unit tests for INPDEVICE class
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

#include "UnitTests_Input_INPDevice.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPDevice.h"
#include "INPButton.h"
#include "INPCursor.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_INPDEVICE
{


TEST(UNITTESTS_INPDEVICE_CLASSNAME, DefaultsNotCreatedOrEnabled)
{
  INPDEVICE device;

  EXPECT_FALSE(device.IsCreated());
  EXPECT_FALSE(device.IsEnabled());
  EXPECT_EQ(device.GetType(), INPDEVICE_TYPE_NONE);
  EXPECT_EQ(device.GetNButtons(), 0);
  EXPECT_EQ(device.GetNCursors(), 0);
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, SetEnabledAndTypeRoundTrip)
{
  INPDEVICE device;

  device.SetEnabled(true);
  device.SetType(INPDEVICE_TYPE_KEYBOARD);

  EXPECT_TRUE(device.IsEnabled());
  EXPECT_EQ(device.GetType(), INPDEVICE_TYPE_KEYBOARD);
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, CreateButtonThenLookupByIdAndCode)
{
  INPDEVICE device;

  EXPECT_TRUE(INPBUTTON::CreateButton(device.GetButtons(), 0x41, INPBUTTON_ID_A, __C('A')));

  INPBUTTON* by_id = device.GetButton(INPBUTTON_ID_A);
  ASSERT_NE(by_id, (INPBUTTON*)NULL);
  EXPECT_EQ(by_id->GetID(), INPBUTTON_ID_A);

  INPBUTTON* by_code = device.GetButtonByCode(0x41);
  ASSERT_NE(by_code, (INPBUTTON*)NULL);
  EXPECT_EQ(by_code, by_id);

  EXPECT_EQ(device.GetNButtons(), 1);

  device.DeleteAllButtons();
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, IsPressButtonAndReleaseAllButtons)
{
  INPDEVICE device;

  EXPECT_TRUE(INPBUTTON::CreateButton(device.GetButtons(), 0x41, INPBUTTON_ID_A, __C('A')));

  INPBUTTON* button = device.GetButton(INPBUTTON_ID_A);
  ASSERT_NE(button, (INPBUTTON*)NULL);

  EXPECT_EQ(device.IsPressButton(), (INPBUTTON*)NULL);

  button->SetPressed(true);
  EXPECT_EQ(device.IsPressButton(), button);

  EXPECT_TRUE(device.ReleaseAllButtons());
  EXPECT_FALSE(button->IsPressed());
  EXPECT_EQ(device.IsPressButton(), (INPBUTTON*)NULL);

  device.DeleteAllButtons();
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, AddCursorAndIsChangeCursor)
{
  INPDEVICE device;

  INPCURSOR* cursor = GEN_NEW INPCURSOR();
  ASSERT_NE(cursor, (INPCURSOR*)NULL);

  cursor->SetID(INPCURSOR_ID_MOUSE);
  cursor->SetIsChanged(true);

  EXPECT_TRUE(device.GetCursors()->Add(cursor));
  EXPECT_EQ(device.GetNCursors(), 1);
  EXPECT_EQ(device.GetCursor(INPCURSOR_ID_MOUSE), cursor);
  EXPECT_EQ(device.IsChangeCursor(), cursor);

  device.DeleteAllCursors();
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, DeleteAllClears)
{
  INPDEVICE device;

  EXPECT_TRUE(INPBUTTON::CreateButton(device.GetButtons(), 0x41, INPBUTTON_ID_A, __C('A')));

  INPCURSOR* cursor = GEN_NEW INPCURSOR();
  ASSERT_NE(cursor, (INPCURSOR*)NULL);
  EXPECT_TRUE(device.GetCursors()->Add(cursor));

  EXPECT_TRUE(device.DeleteAllButtons());
  EXPECT_TRUE(device.DeleteAllCursors());

  EXPECT_EQ(device.GetNButtons(), 0);
  EXPECT_EQ(device.GetNCursors(), 0);
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, BaseUpdateReturnsTrue)
{
  INPDEVICE device;

  EXPECT_TRUE(device.Update());
}


TEST(UNITTESTS_INPDEVICE_CLASSNAME, BaseReleaseAndSetScreenReturnFalse)
{
  INPDEVICE device;

  EXPECT_FALSE(device.Release());
  EXPECT_FALSE(device.SetScreen(NULL));
}


}
#endif
