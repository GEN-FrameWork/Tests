/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Property_Editable.cpp
*
* @brief      UserInterface unit tests for UI_PROPERTY_EDITABLE
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_PROPERTY_EDITABLE
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

#include "UnitTests_UserInterface_Property_Editable.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Property_Editable.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_PROPERTY_EDITABLE
{


TEST(UNITTESTS_UI_PROPERTY_EDITABLE_CLASSNAME, DefaultsCursorAndMaxSizeToZero)
{
  UI_PROPERTY_EDITABLE property;

  EXPECT_EQ(property.Cursor_GetPosition(), 0);
  EXPECT_EQ(property.GetMaxSize(), 0);
}


TEST(UNITTESTS_UI_PROPERTY_EDITABLE_CLASSNAME, CursorAndMaxSizeRoundTrip)
{
  UI_PROPERTY_EDITABLE property;

  property.Cursor_SetPosition(7);
  property.SetMaxSize(128);

  EXPECT_EQ(property.Cursor_GetPosition(), 7);
  EXPECT_EQ(property.GetMaxSize(), 128);
}


} // namespace TEST_UI_PROPERTY_EDITABLE
#endif // GOOGLETEST_ACTIVE
