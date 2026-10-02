/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPFactory.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPFACTORY
* @brief      Graphic unit tests for GRPFACTORY class
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

#include "UnitTests_Graphic_GRPFactory.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPBitmap.h"
#include "GRPProperties.h"
#include "GRP2DCanvas.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPFACTORY
{


TEST(UNITTESTS_GRPFACTORY_CLASSNAME, CreateBitmapRejectsUnknownMode)
{
  GRPBITMAP* bitmap = GRPFACTORY::GetInstance().CreateBitmap(16, 16, GRPPROPERTYMODE_XX_UNKNOWN);

  EXPECT_EQ(bitmap, (GRPBITMAP*)NULL);
}


TEST(UNITTESTS_GRPFACTORY_CLASSNAME, CreateAndDeleteBitmapRGBA)
{
  GRPBITMAP* bitmap = GRPFACTORY::GetInstance().CreateBitmap(32, 24, GRPPROPERTYMODE_32_RGBA_8888);

  ASSERT_NE(bitmap, (GRPBITMAP*)NULL);
  EXPECT_TRUE(bitmap->IsValid());
  EXPECT_EQ(bitmap->GetWidth(), 32u);
  EXPECT_EQ(bitmap->GetHeight(), 24u);
  EXPECT_NE(bitmap->GetBuffer(), (XBYTE*)NULL);

  GRPFACTORY::GetInstance().DeleteBitmap(bitmap);
}


TEST(UNITTESTS_GRPFACTORY_CLASSNAME, CreateAndDeleteCanvas)
{
  GRPPROPERTIES props;

  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(64, 48);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);

  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  EXPECT_EQ(canvas->GetWidth(), 64u);
  EXPECT_EQ(canvas->GetHeight(), 48u);
  EXPECT_TRUE(canvas->Buffer_Create());

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


TEST(UNITTESTS_GRPFACTORY_CLASSNAME, CreateCanvasRejectsZeroSize)
{
  GRPPROPERTIES props;

  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(0, 0);

  EXPECT_EQ(GRPFACTORY::GetInstance().CreateCanvas(&props), (GRP2DCANVAS*)NULL);
}


}
#endif
#endif
