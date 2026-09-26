/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Text.cpp
*
* @brief      UserInterface unit tests for UI_TEXT
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_TEXT
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

#include "UnitTests_UserInterface_Text.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Text.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_TEXT
{


TEST(UNITTESTS_UI_TEXT_CLASSNAME, DefaultNameAndTextAreEmpty)
{
  UI_TEXT text;

  ASSERT_NE(text.GetName(), (XSTRING*)NULL);
  ASSERT_NE(text.GetText(), (XSTRING*)NULL);
  EXPECT_TRUE(text.GetName()->IsEmpty());
  EXPECT_TRUE(text.GetText()->IsEmpty());
}


TEST(UNITTESTS_UI_TEXT_CLASSNAME, NameAndTextRoundTripThroughSetters)
{
  UI_TEXT text;

  text.GetName()->Set(__L("caption"));
  text.GetText()->Set(__L("Hello UI"));

  EXPECT_EQ(text.GetName()->Compare(__L("caption"), true), 0);
  EXPECT_EQ(text.GetText()->Compare(__L("Hello UI"), true), 0);
}


} // namespace TEST_UI_TEXT
#endif // GOOGLETEST_ACTIVE
