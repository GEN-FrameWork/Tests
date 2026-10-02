/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DVectorFileSVGRenderAGG.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DVECTORFILESVGRENDERAGG
* @brief      Graphic unit tests for GRP2DVECTORFILESVGRENDERAGG class
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

#include "UnitTests_Graphic_GRP2DVectorFileSVGRenderAGG.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "GRPFactory.h"
#include "GRPProperties.h"
#include "GRP2DCanvas.h"
#include "GRPVectorFileSVG.h"
#include "GRP2DVectorFileSVGRenderAGG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_SVG_ACTIVE
namespace TEST_GRP2DVECTORFILESVGRENDERAGG
{


TEST(UNITTESTS_GRP2DVECTORFILESVGRENDERAGG_CLASSNAME, RenderSvgRectOnCanvas)
{
  XSTRING content;
  content  = __L("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"64\" height=\"64\">");
  content += __L("<rect x=\"8\" y=\"8\" width=\"48\" height=\"48\" fill=\"#FF0000\"/>");
  content += __L("</svg>");

  GRPVECTORFILESVG svg;
  ASSERT_EQ(svg.Load(content), GRPVECTORFILERESULT_OK);

  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(64, 64);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());

  GRP2DVECTORFILESVGRENDERAGG renderer;
  EXPECT_TRUE(renderer.Render(&svg, canvas));

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


}
#endif
#endif
#endif
