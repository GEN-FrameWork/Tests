/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DCanvas.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DCANVAS
* @brief      Graphic unit tests for GRP2DCANVAS class
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

#include "UnitTests_Graphic_GRP2DCanvas.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPProperties.h"
#include "GRP2DCanvas.h"
#include "GRP2DColor.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRP2DCANVAS
{


TEST(UNITTESTS_GRP2DCANVAS_CLASSNAME, CreateBufferClearGetPixelAndFontSize)
{
  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(32, 24);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());
  EXPECT_NE(canvas->Buffer_Get(), (XBYTE*)NULL);

  GRP2DCOLOR_RGBA8 clearcolor(5, 6, 7, 255);
  canvas->Clear(&clearcolor);

  GRP2DCOLOR_RGBA8* pixel = (GRP2DCOLOR_RGBA8*)canvas->GetPixel(0, 0);
  ASSERT_NE(pixel, (GRP2DCOLOR_RGBA8*)NULL);
  EXPECT_EQ(pixel->r, 5);
  EXPECT_EQ(pixel->g, 6);
  EXPECT_EQ(pixel->b, 7);

  ASSERT_NE(canvas->Vectorfont_GetConfig(), (GRP2DCANVAS_VECTORFONT_CONFIG*)NULL);
  EXPECT_TRUE(canvas->Vectorfont_GetConfig()->SetSize(14.0));
  EXPECT_DOUBLE_EQ(canvas->Vectorfont_GetConfig()->GetSize(), 14.0);

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


}
#endif
#endif
