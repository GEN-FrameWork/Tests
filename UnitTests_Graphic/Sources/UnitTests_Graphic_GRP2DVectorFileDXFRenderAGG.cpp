/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DVectorFileDXFRenderAGG.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DVECTORFILEDXFRENDERAGG
* @brief      Graphic unit tests for GRP2DVECTORFILEDXFRENDERAGG class
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

#include "UnitTests_Graphic_GRP2DVectorFileDXFRenderAGG.h"
#include "UnitTests_Graphic_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPProperties.h"
#include "GRP2DCanvas.h"
#include "GRPVectorFileDXF.h"
#include "GRP2DVectorFileDXFRenderAGG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_DXF_ACTIVE
namespace TEST_GRP2DVECTORFILEDXFRENDERAGG
{


TEST(UNITTESTS_GRP2DVECTORFILEDXFRENDERAGG_CLASSNAME, DefaultsAndNullGuards)
{
  GRP2DVECTORFILEDXFRENDERAGG renderer;

  EXPECT_FALSE(renderer.GetForceColorActive());
  EXPECT_TRUE(renderer.GetDrawText());
  EXPECT_FALSE(renderer.Render(NULL, NULL));
}


TEST(UNITTESTS_GRP2DVECTORFILEDXFRENDERAGG_CLASSNAME, RenderLineOnCanvas)
{
  XSTRING dxfcontent;
  dxfcontent  = __L("0\nSECTION\n2\nHEADER\n0\nENDSEC\n");
  dxfcontent += __L("0\nSECTION\n2\nENTITIES\n");
  dxfcontent += __L("0\nLINE\n8\n0\n10\n0.0\n20\n0.0\n11\n10.0\n21\n10.0\n");
  dxfcontent += __L("0\nENDSEC\n0\nEOF\n");

  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::WriteTextAsset(__L("unittests_graphic_render.dxf"), dxfcontent.Get()));

  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, __L("unittests_graphic_render.dxf")));

  GRPVECTORFILEDXF dxf;
  dxf.GetPathFile()->Set(xpath);
  ASSERT_EQ(dxf.Load(), GRPVECTORFILERESULT_OK);

  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(64, 64);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());

  GRP2DVECTORFILEDXFRENDERAGG renderer;
  EXPECT_TRUE(renderer.Render(&dxf, canvas));

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
  UNITTESTS_GRAPHIC_HELPER::EraseAsset(xpath);
}


}
#endif
#endif
#endif
