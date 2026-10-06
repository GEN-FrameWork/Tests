/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPBitmapFilePNG.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPBITMAPFILEPNG
* @brief      Graphic unit tests for GRPBITMAPFILE PNG class
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

#include "UnitTests_Graphic_GRPBitmapFilePNG.h"
#include "UnitTests_Graphic_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPBitmap.h"
#include "GRPBitmapFile.h"
#include "GRP2DColor.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_BITMAP_FILE_PNG_ACTIVE
namespace TEST_GRPBITMAPFILEPNG
{


TEST(UNITTESTS_GRPBITMAPFILEPNG_CLASSNAME, SaveLoadPngRoundTrip)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, _L("unittests_graphic_roundtrip.png")));

  GRPBITMAP* source = GRPFACTORY::GetInstance().CreateBitmap(8, 8, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(source, (GRPBITMAP*)NULL);

  GRP2DCOLOR_RGBA8 color(40, 80, 120, 255);
  source->PutPixel(1, 1, &color);

  GRPBITMAPFILE file;
  ASSERT_TRUE(file.Save(xpath, source));

  GRPBITMAP* loaded = file.Load(xpath, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(loaded, (GRPBITMAP*)NULL);
  EXPECT_EQ(loaded->GetWidth(), 8u);
  EXPECT_EQ(loaded->GetHeight(), 8u);

  GRP2DCOLOR_RGBA8* got = (GRP2DCOLOR_RGBA8*)loaded->GetPixel(1, 1);
  ASSERT_NE(got, (GRP2DCOLOR_RGBA8*)NULL);
  EXPECT_EQ(got->r, 40);
  EXPECT_EQ(got->g, 80);
  EXPECT_EQ(got->b, 120);

  GRPFACTORY::GetInstance().DeleteBitmap(loaded);
  GRPFACTORY::GetInstance().DeleteBitmap(source);

  UNITTESTS_GRAPHIC_HELPER::EraseAsset(xpath);
}


TEST(UNITTESTS_GRPBITMAPFILEPNG_CLASSNAME, LoadMissingFileReturnsNull)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, _L("unittests_graphic_missing_no_such.png")));

  GRPBITMAPFILE file;
  EXPECT_EQ(file.Load(xpath), (GRPBITMAP*)NULL);
}


}
#endif
#endif
#endif
