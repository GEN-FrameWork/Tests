/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPBitmapFile.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPBITMAPFILE
* @brief      Graphic unit tests for GRPBITMAPFILE class
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

#include "UnitTests_Graphic_GRPBitmapFile.h"
#include "UnitTests_Graphic_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XFile.h"
#include "XFactory.h"

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
namespace TEST_GRPBITMAPFILE
{


TEST(UNITTESTS_GRPBITMAPFILE_CLASSNAME, GetTypeFromExtension)
{
  GRPBITMAPFILE file;

  EXPECT_EQ(file.GetTypeFromExtenxion(__L("sample.bmp")), GRPBITMAPFILE_TYPE_BMP);
  EXPECT_EQ(file.GetTypeFromExtenxion(__L("sample.PNG")), GRPBITMAPFILE_TYPE_PNG);
  EXPECT_EQ(file.GetTypeFromExtenxion(__L("sample.jpg")), GRPBITMAPFILE_TYPE_JPG);
  EXPECT_EQ(file.GetTypeFromExtenxion(__L("sample.tga")), GRPBITMAPFILE_TYPE_TGA);
  EXPECT_EQ(file.GetTypeFromExtenxion(__L("sample.xyz")), GRPBITMAPFILE_TYPE_UNKNOWN);
}


TEST(UNITTESTS_GRPBITMAPFILE_CLASSNAME, SaveLoadBmpRoundTrip)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, __L("unittests_graphic_roundtrip.bmp")));

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

  XFILE* xfile = GEN_XFACTORY.Create_File();
  if(xfile)
    {
      xfile->Erase(xpath.Get());
      GEN_XFACTORY.Delete_File(xfile);
    }
}


TEST(UNITTESTS_GRPBITMAPFILE_CLASSNAME, LoadMissingFileReturnsNull)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, __L("unittests_graphic_missing_no_such.bmp")));

  GRPBITMAPFILE file;
  EXPECT_EQ(file.Load(xpath), (GRPBITMAP*)NULL);
}


}
#endif
#endif
