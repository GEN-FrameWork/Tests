/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPRect.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPRECT
* @brief      Graphic unit tests for GRPRECT class
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

#include "UnitTests_Graphic_GRPRect.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPRect.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPRECT
{


TEST(UNITTESTS_GRPRECT_CLASSNAME, DefaultIsEmptyAndInvalidSizeZero)
{
  GRPRECTINT rect;

  EXPECT_TRUE(rect.IsEmpty());
  EXPECT_TRUE(rect.IsValid());
  EXPECT_EQ(rect.GetWidth(), 0);
  EXPECT_EQ(rect.GetHeight(), 0);
}


TEST(UNITTESTS_GRPRECT_CLASSNAME, SetGetWidthHeightAndHit)
{
  GRPRECTINT rect(10, 20, 40, 50);

  EXPECT_EQ(rect.GetWidth(), 30);
  EXPECT_EQ(rect.GetHeight(), 30);
  EXPECT_TRUE(rect.IsHit(10, 20));
  EXPECT_TRUE(rect.IsHit(40, 50));
  EXPECT_FALSE(rect.IsHit(9, 20));
  EXPECT_FALSE(rect.IsHit(10, 51));
}


TEST(UNITTESTS_GRPRECT_CLASSNAME, NormalizeClipCopy)
{
  GRPRECTINT inverted(40, 50, 10, 20);
  inverted.Normalize();

  EXPECT_EQ(inverted.x1, 10);
  EXPECT_EQ(inverted.y1, 20);
  EXPECT_EQ(inverted.x2, 40);
  EXPECT_EQ(inverted.y2, 50);

  GRPRECTINT clipbox(0, 0, 30, 30);
  EXPECT_TRUE(inverted.Clip(clipbox));
  EXPECT_EQ(inverted.x2, 30);
  EXPECT_EQ(inverted.y2, 30);

  GRPRECTINT copy;
  EXPECT_TRUE(inverted.CopyTo(&copy));
  EXPECT_EQ(copy.x1, inverted.x1);
  EXPECT_EQ(copy.y2, inverted.y2);
}


TEST(UNITTESTS_GRPRECT_CLASSNAME, IntersectAndUniteRectangles)
{
  GRPRECTINT a(0, 0, 20, 20);
  GRPRECTINT b(10, 10, 40, 40);

  GRPRECTINT inter = IntersectRectangles(a, b);
  EXPECT_EQ(inter.x1, 10);
  EXPECT_EQ(inter.y1, 10);
  EXPECT_EQ(inter.x2, 20);
  EXPECT_EQ(inter.y2, 20);

  GRPRECTINT united = UniteRectangles(a, b);
  EXPECT_EQ(united.x1, 0);
  EXPECT_EQ(united.y1, 0);
  EXPECT_EQ(united.x2, 40);
  EXPECT_EQ(united.y2, 40);
}


}
#endif
#endif
