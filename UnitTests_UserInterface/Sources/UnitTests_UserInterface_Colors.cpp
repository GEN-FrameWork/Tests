/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Colors.cpp
*
* @brief      UserInterface unit tests for UI_COLORS
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_COLORS
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

#include "UnitTests_UserInterface_Colors.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Colors.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_COLORS
{


TEST(UNITTESTS_UI_COLORS_CLASSNAME, AddThenGetReturnsTheRegisteredString)
{
  GEN_UI_COLORS.DeleteAll();

  ASSERT_TRUE(GEN_UI_COLORS.Add(__L("ut_red"), __L("255,0,0")));

  XSTRING* value = GEN_UI_COLORS.Get(__L("ut_red"));
  ASSERT_NE(value, (XSTRING*)NULL);
  EXPECT_EQ(value->Compare(__L("255,0,0"), true), 0);

  GEN_UI_COLORS.DeleteAll();
}


TEST(UNITTESTS_UI_COLORS_CLASSNAME, GetUnknownNameReturnsNull)
{
  GEN_UI_COLORS.DeleteAll();

  EXPECT_EQ(GEN_UI_COLORS.Get(__L("does_not_exist")), (XSTRING*)NULL);
}


TEST(UNITTESTS_UI_COLORS_CLASSNAME, DeleteAllClearsPreviousEntries)
{
  ASSERT_TRUE(GEN_UI_COLORS.Add(__L("ut_tmp"), __L("1,2,3")));
  ASSERT_NE(GEN_UI_COLORS.Get(__L("ut_tmp")), (XSTRING*)NULL);

  ASSERT_TRUE(GEN_UI_COLORS.DeleteAll());
  EXPECT_EQ(GEN_UI_COLORS.Get(__L("ut_tmp")), (XSTRING*)NULL);
}


} // namespace TEST_UI_COLORS
#endif // GOOGLETEST_ACTIVE
