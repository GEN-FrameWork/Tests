/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPBitmapFileJPG.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPBITMAPFILEJPG
* @brief      Graphic unit tests for GRPBITMAPFILE JPG class
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

#include "UnitTests_Graphic_GRPBitmapFileJPG.h"
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
#ifdef GRP_BITMAP_FILE_JPG_ACTIVE
namespace TEST_GRPBITMAPFILEJPG
{


TEST(UNITTESTS_GRPBITMAPFILEJPG_CLASSNAME, SaveLoadJpgDimensions)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, _L("unittests_graphic_roundtrip.jpg")));

  GRPBITMAP* source = GRPFACTORY::GetInstance().CreateBitmap(16, 12, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(source, (GRPBITMAP*)NULL);

  GRP2DCOLOR_RGBA8 color(200, 100, 50, 255);
  source->PutPixel(2, 2, &color);

  GRPBITMAPFILE file;
  ASSERT_TRUE(file.Save(xpath, source, 90));

  GRPBITMAP* loaded = file.Load(xpath, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(loaded, (GRPBITMAP*)NULL);
  EXPECT_EQ(loaded->GetWidth(), 16u);
  EXPECT_EQ(loaded->GetHeight(), 12u);

  GRPFACTORY::GetInstance().DeleteBitmap(loaded);
  GRPFACTORY::GetInstance().DeleteBitmap(source);

  UNITTESTS_GRAPHIC_HELPER::EraseAsset(xpath);
}


TEST(UNITTESTS_GRPBITMAPFILEJPG_CLASSNAME, LoadMissingFileReturnsNull)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, _L("unittests_graphic_missing_no_such.jpg")));

  GRPBITMAPFILE file;
  EXPECT_EQ(file.Load(xpath), (GRPBITMAP*)NULL);
}


}
#endif
#endif
#endif
