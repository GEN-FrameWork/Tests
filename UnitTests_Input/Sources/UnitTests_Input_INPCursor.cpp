/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPCursor.cpp
*
* @class      UNITTESTS_INPUT_INPCURSOR
* @brief      Input unit tests for INPCURSOR class
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

#include "UnitTests_Input_INPCursor.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPCursor.h"
#include "INPCursorMotion.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_INPCURSOR
{


TEST(UNITTESTS_INPCURSOR_CLASSNAME, DefaultIdIsNone)
{
  INPCURSOR cursor;

  EXPECT_EQ(cursor.GetID(), INPCURSOR_ID_NONE);
}


TEST(UNITTESTS_INPCURSOR_CLASSNAME, SetIdMouse)
{
  INPCURSOR cursor;

  cursor.SetID(INPCURSOR_ID_MOUSE);

  EXPECT_EQ(cursor.GetID(), INPCURSOR_ID_MOUSE);
}


TEST(UNITTESTS_INPCURSOR_CLASSNAME, GetTimerNonNull)
{
  INPCURSOR cursor;

  EXPECT_NE(cursor.GetTimer(), (XTIMER*)NULL);
}


TEST(UNITTESTS_INPCURSOR_CLASSNAME, HavePreSelectAndIsChangedFlags)
{
  INPCURSOR cursor;

  EXPECT_FALSE(cursor.HavePreSelect());
  EXPECT_FALSE(cursor.IsChanged());

  EXPECT_TRUE(cursor.SetHavePreSelect(true));
  EXPECT_TRUE(cursor.SetIsChanged(true));

  EXPECT_TRUE(cursor.HavePreSelect());
  EXPECT_TRUE(cursor.IsChanged());
}


TEST(UNITTESTS_INPCURSOR_CLASSNAME, IsPositionInRectAfterPointSet)
{
  INPCURSOR cursor;

  // Do not call INPCURSOR::Set/SetX/SetY (divide-by-zero with empty source/destination rects).
  cursor.INPCURSORMOTIONPOINT::Set(5.0f, 5.0f, 0.0f);

  EXPECT_TRUE(cursor.IsPositionInRect(0, 0, 10, 10));
  EXPECT_FALSE(cursor.IsPositionInRect(20, 20, 5, 5));
}


TEST(UNITTESTS_INPCURSOR_CLASSNAME, AddPointToMotionGrowsMotion)
{
  INPCURSOR cursor;

  cursor.INPCURSORMOTIONPOINT::Set(3.0f, 4.0f, 0.0f);

  INPCURSORMOTION* motion = cursor.GetMotion();
  ASSERT_NE(motion, (INPCURSORMOTION*)NULL);

  int before = motion->GetNPoints();

  EXPECT_TRUE(cursor.AddPointToMotion(true));
  EXPECT_GT(motion->GetNPoints(), before);
  EXPECT_TRUE(motion->IsInCurse());

  EXPECT_TRUE(cursor.AddPointToMotion(false));
  EXPECT_FALSE(motion->IsInCurse());
}


}
#endif
