/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPCursorMotion.cpp
*
* @class      UNITTESTS_INPUT_INPCURSORMOTION
* @brief      Input unit tests for INPCURSORMOTION / INPCURSORMOTIONPOINT classes
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

#include "UnitTests_Input_INPCursorMotion.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPCursorMotion.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_INPCURSORMOTION
{


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, PointSetGetRoundTrip)
{
  INPCURSORMOTIONPOINT point;

  point.Set(1.5f, 2.5f, 3.5f);

  EXPECT_FLOAT_EQ(point.GetX(), 1.5f);
  EXPECT_FLOAT_EQ(point.GetY(), 2.5f);
  EXPECT_FLOAT_EQ(point.GetZ(), 3.5f);

  point.SetX(10.0f);
  point.SetY(20.0f);
  point.SetZ(30.0f);

  EXPECT_FLOAT_EQ(point.GetX(), 10.0f);
  EXPECT_FLOAT_EQ(point.GetY(), 20.0f);
  EXPECT_FLOAT_EQ(point.GetZ(), 30.0f);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, EmptyMotionHasZeroPoints)
{
  INPCURSORMOTION motion;

  EXPECT_EQ(motion.GetNPoints(), 0);
  EXPECT_EQ(motion.GetFirstPoint(), (INPCURSORMOTIONPOINT*)NULL);
  EXPECT_EQ(motion.GetLastPoint(), (INPCURSORMOTIONPOINT*)NULL);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, AddPointAndDeleteAllPoints)
{
  INPCURSORMOTION motion;

  EXPECT_TRUE(motion.AddPoint(1.0f, 2.0f, 3.0f));
  EXPECT_EQ(motion.GetNPoints(), 1);

  INPCURSORMOTIONPOINT* point = motion.GetFirstPoint();
  ASSERT_NE(point, (INPCURSORMOTIONPOINT*)NULL);
  EXPECT_FLOAT_EQ(point->GetX(), 1.0f);
  EXPECT_FLOAT_EQ(point->GetY(), 2.0f);
  EXPECT_FLOAT_EQ(point->GetZ(), 3.0f);

  EXPECT_TRUE(motion.DeleteAllPoints());
  EXPECT_EQ(motion.GetNPoints(), 0);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, HorizontalLineDirectionIsRight)
{
  INPCURSORMOTION motion;

  EXPECT_TRUE(motion.AddPoint(0.0f, 0.0f));
  EXPECT_TRUE(motion.AddPoint(10.0f, 0.0f));

  EXPECT_EQ(motion.GetDirectionByAngle(false), INPCURSORMOTION_DIR_RIGHT);
  EXPECT_EQ(motion.GetDirectionByDifferential(), INPCURSORMOTION_DIR_RIGHT);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, VerticalLineDirectionIsUpOrDown)
{
  INPCURSORMOTION motion_up;

  EXPECT_TRUE(motion_up.AddPoint(0.0f, 0.0f));
  EXPECT_TRUE(motion_up.AddPoint(0.0f, 10.0f));

  INPCURSORMOTION_DIR dir_up = motion_up.GetDirectionByAngle(false);
  EXPECT_TRUE((dir_up == INPCURSORMOTION_DIR_UP) || (dir_up == INPCURSORMOTION_DIR_DOWN));
  EXPECT_EQ(motion_up.GetDirectionByDifferential(), INPCURSORMOTION_DIR_UP);

  INPCURSORMOTION motion_down;

  EXPECT_TRUE(motion_down.AddPoint(0.0f, 10.0f));
  EXPECT_TRUE(motion_down.AddPoint(0.0f, 0.0f));

  INPCURSORMOTION_DIR dir_down = motion_down.GetDirectionByAngle(false);
  EXPECT_TRUE((dir_down == INPCURSORMOTION_DIR_UP) || (dir_down == INPCURSORMOTION_DIR_DOWN));
  EXPECT_EQ(motion_down.GetDirectionByDifferential(), INPCURSORMOTION_DIR_DOWN);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, AddFromLineIncreasesPoints)
{
  INPCURSORMOTION motion;

  int before = motion.GetNPoints();
  motion.AddFromLine(INPCURSORMOTION_REDUCEDMODE_NONE, 0, 0, 0, 10, 0);

  EXPECT_GT(motion.GetNPoints(), before);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, AddFromCircleProducesPoints)
{
  INPCURSORMOTION motion;

  EXPECT_TRUE(motion.AddFromCircle(INPCURSORMOTION_REDUCEDMODE_NONE, 0, 50, 50, 10));
  EXPECT_GT(motion.GetNPoints(), 0);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, InvertYAxisFlipsY)
{
  INPCURSORMOTION motion;

  EXPECT_TRUE(motion.AddPoint(5.0f, 10.0f));
  EXPECT_TRUE(motion.InvertYAxis(100));

  INPCURSORMOTIONPOINT* point = motion.GetFirstPoint();
  ASSERT_NE(point, (INPCURSORMOTIONPOINT*)NULL);
  EXPECT_FLOAT_EQ(point->GetY(), 90.0f);
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, IsReadyToTestReflectsPointCount)
{
  INPCURSORMOTION motion;

  EXPECT_FALSE(motion.IsReadyToTest(1));

  EXPECT_TRUE(motion.AddPoint(1.0f, 1.0f));
  EXPECT_TRUE(motion.AddPoint(2.0f, 2.0f));

  EXPECT_TRUE(motion.IsReadyToTest(1));
  EXPECT_TRUE(motion.IsReadyToTest(2));
  EXPECT_FALSE(motion.IsReadyToTest(3));
}


TEST(UNITTESTS_INPCURSORMOTION_CLASSNAME, IsInRectForKnownBBox)
{
  INPCURSORMOTION motion;

  EXPECT_TRUE(motion.AddPoint(5.0f, 5.0f));
  EXPECT_TRUE(motion.AddPoint(8.0f, 8.0f));

  EXPECT_TRUE(motion.IsInRect(0, 0, 10, 10));
  EXPECT_FALSE(motion.IsInRect(20, 20, 5, 5));
}


}
#endif
