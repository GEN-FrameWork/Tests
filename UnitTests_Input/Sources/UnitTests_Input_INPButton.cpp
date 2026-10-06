/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPButton.cpp
*
* @class      UNITTESTS_INPUT_INPBUTTON
* @brief      Input unit tests for INPBUTTON class
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

#include "UnitTests_Input_INPButton.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPButton.h"
#include "XVector.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_INPBUTTON
{


TEST(UNITTESTS_INPBUTTON_CLASSNAME, DefaultConstructorState)
{
  INPBUTTON button;

  EXPECT_EQ(button.GetID(), INPBUTTON_ID_NOBUTTON);
  EXPECT_EQ(button.GetState(), INPBUTTON_STATE_UNKNOWN);
  EXPECT_FLOAT_EQ(button.GetPressure(), 0.0f);
  EXPECT_FALSE(button.IsPressed());
}


TEST(UNITTESTS_INPBUTTON_CLASSNAME, SettersGettersRoundTrip)
{
  INPBUTTON button;

  button.SetID(INPBUTTON_ID_A);
  button.SetKeyCode(0x41);
  button.SetSymbol(_C('A'));
  button.SetState(INPBUTTON_STATE_PRESSED);
  button.SetPressure(0.5f);

  EXPECT_EQ(button.GetID(), INPBUTTON_ID_A);
  EXPECT_EQ(button.GetKeyCode(), (XWORD)0x41);
  EXPECT_EQ(button.GetSymbol(), _C('A'));
  EXPECT_EQ(button.GetState(), INPBUTTON_STATE_PRESSED);
  EXPECT_FLOAT_EQ(button.GetPressure(), 0.5f);
}


TEST(UNITTESTS_INPBUTTON_CLASSNAME, SetPressedAndIsPressed)
{
  INPBUTTON button;

  EXPECT_FALSE(button.IsPressed());

  button.SetPressed(true);
  EXPECT_TRUE(button.IsPressed());

  button.SetPressed(false);
  EXPECT_FALSE(button.IsPressed());
}


TEST(UNITTESTS_INPBUTTON_CLASSNAME, IsPressedWithReleaseCycle)
{
  INPBUTTON button;

  button.SetPressed(true);
  EXPECT_FALSE(button.IsPressedWithRelease());

  button.SetPressed(false);
  EXPECT_TRUE(button.IsPressedWithRelease());
  EXPECT_FALSE(button.IsPressedWithRelease());
}


TEST(UNITTESTS_INPBUTTON_CLASSNAME, CreateButtonAddsToVector)
{
  XVECTOR<INPBUTTON*> buttons;

  EXPECT_TRUE(INPBUTTON::CreateButton(&buttons, 0x41, INPBUTTON_ID_A, _C('A')));
  EXPECT_EQ(buttons.GetSize(), (XDWORD)1);

  INPBUTTON* button = buttons.Get(0);
  ASSERT_NE(button, (INPBUTTON*)NULL);
  EXPECT_EQ(button->GetKeyCode(), (XWORD)0x41);
  EXPECT_EQ(button->GetID(), INPBUTTON_ID_A);
  EXPECT_EQ(button->GetSymbol(), _C('A'));

  EXPECT_FALSE(INPBUTTON::CreateButton(NULL, 0x41, INPBUTTON_ID_A, _C('A')));

  buttons.DeleteContents();
  buttons.DeleteAll();
}


}
#endif
