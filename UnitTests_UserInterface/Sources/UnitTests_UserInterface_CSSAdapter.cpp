/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_CSSAdapter.cpp
*
* @brief      UserInterface unit tests for UI_CSSAdapter helpers
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_CSSADAPTER
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

#include "UnitTests_UserInterface_CSSAdapter.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_CSSAdapter.h"
#include "UI_Element.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_CSSADAPTER
{


TEST(UNITTESTS_UI_CSSADAPTER_CLASSNAME, GetOnNullElementReturnsZeroBox)
{
  UI_CSSBOX box = UI_CSSBox_Get(NULL);

  EXPECT_EQ(box.left, 0.0);
  EXPECT_EQ(box.top, 0.0);
  EXPECT_EQ(box.width, 0.0);
  EXPECT_EQ(box.height, 0.0);
}


TEST(UNITTESTS_UI_CSSADAPTER_CLASSNAME, SetThenGetRoundTripsCssTopLeftBox)
{
  UI_ELEMENT element;

  UI_CSSBOX input;
  input.left = 100.0;
  input.top = 50.0;
  input.width = 200.0;
  input.height = 80.0;

  UI_CSSBox_Set(&element, input);

  // Internal Y stores the BOTTOM edge (top + height).
  EXPECT_EQ(element.GetBoundaryLine()->width, 200.0);
  EXPECT_EQ(element.GetBoundaryLine()->height, 80.0);
  EXPECT_EQ(element.GetLeftX(), 100.0);
  EXPECT_EQ(element.GetTopY(), 50.0);

  UI_CSSBOX output = UI_CSSBox_Get(&element);
  EXPECT_EQ(output.left, 100.0);
  EXPECT_EQ(output.top, 50.0);
  EXPECT_EQ(output.width, 200.0);
  EXPECT_EQ(output.height, 80.0);
}


TEST(UNITTESTS_UI_CSSADAPTER_CLASSNAME, SetOnNullElementIsNoOp)
{
  UI_CSSBOX box = { 1.0, 2.0, 3.0, 4.0 };
  UI_CSSBox_Set(NULL, box);   // must not crash
}


} // namespace TEST_UI_CSSADAPTER
#endif // GOOGLETEST_ACTIVE
