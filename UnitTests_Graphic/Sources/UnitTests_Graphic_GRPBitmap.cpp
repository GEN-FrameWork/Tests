/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPBitmap.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPBITMAP
* @brief      Graphic unit tests for GRPBITMAP class
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

#include "UnitTests_Graphic_GRPBitmap.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPBitmap.h"
#include "GRP2DColor.h"
#include "GRPRect.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPBITMAP
{


TEST(UNITTESTS_GRPBITMAP_CLASSNAME, PutGetPixelRoundTrip)
{
  GRPBITMAP* bitmap = GRPFACTORY::GetInstance().CreateBitmap(8, 8, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(bitmap, (GRPBITMAP*)NULL);

  GRP2DCOLOR_RGBA8 color(10, 20, 30, 255);
  bitmap->PutPixel(2, 3, &color);

  GRP2DCOLOR_RGBA8* got = (GRP2DCOLOR_RGBA8*)bitmap->GetPixel(2, 3);
  ASSERT_NE(got, (GRP2DCOLOR_RGBA8*)NULL);
  EXPECT_EQ(got->r, 10);
  EXPECT_EQ(got->g, 20);
  EXPECT_EQ(got->b, 30);

  GRPFACTORY::GetInstance().DeleteBitmap(bitmap);
}


TEST(UNITTESTS_GRPBITMAP_CLASSNAME, CloneCompareAndHandle)
{
  GRPBITMAP* bitmap = GRPFACTORY::GetInstance().CreateBitmap(4, 4, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(bitmap, (GRPBITMAP*)NULL);

  GRP2DCOLOR_RGBA8 color(1, 2, 3, 255);
  bitmap->PutPixel(0, 0, &color);
  bitmap->SetHandle(42);

  EXPECT_EQ(bitmap->GetHandle(), 42u);

  GRPBITMAP* clone = bitmap->Clone();
  ASSERT_NE(clone, (GRPBITMAP*)NULL);
  EXPECT_TRUE(bitmap->Compare(clone));

  GRPFACTORY::GetInstance().DeleteBitmap(clone);
  GRPFACTORY::GetInstance().DeleteBitmap(bitmap);
}


TEST(UNITTESTS_GRPBITMAP_CLASSNAME, CropProducesSubBitmap)
{
  GRPBITMAP* bitmap = GRPFACTORY::GetInstance().CreateBitmap(16, 16, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(bitmap, (GRPBITMAP*)NULL);

  GRP2DCOLOR_RGBA8 fill(200, 100, 50, 255);
  for(int y=4; y<8; y++)
    {
      for(int x=4; x<8; x++)
        {
          bitmap->PutPixel(x, y, &fill);
        }
    }

  GRPRECTINT rect(4, 4, 8, 8);
  EXPECT_TRUE(bitmap->Crop(rect));
  EXPECT_EQ(bitmap->GetWidth(), 4u);
  EXPECT_EQ(bitmap->GetHeight(), 4u);

  GRP2DCOLOR_RGBA8* got = (GRP2DCOLOR_RGBA8*)bitmap->GetPixel(0, 0);
  ASSERT_NE(got, (GRP2DCOLOR_RGBA8*)NULL);
  EXPECT_EQ(got->r, 200);
  EXPECT_EQ(got->g, 100);
  EXPECT_EQ(got->b, 50);

  GRPFACTORY::GetInstance().DeleteBitmap(bitmap);
}


}
#endif
#endif
