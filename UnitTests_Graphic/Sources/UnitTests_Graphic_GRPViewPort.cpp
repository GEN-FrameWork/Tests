/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPViewPort.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVIEWPORT
* @brief      Graphic unit tests for GRPVIEWPORT class
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

#include "UnitTests_Graphic_GRPViewPort.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPViewPort.h"
#include "GRPProperties.h"
#include "GRPFactory.h"
#include "GRP2DCanvas.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPVIEWPORT
{


TEST(UNITTESTS_GRPVIEWPORT_CLASSNAME, PositionSizeProjectionAndActive)
{
  GRPVIEWPORT viewport;

  viewport.SetIsActive(true);
  viewport.SetProjectionType(GRPVIEWPORT_PROJECTIONTYPE_ORTHO);
  viewport.SetPosition(1.5f, 2.5f);
  viewport.SetSize(100.0f, 80.0f);
  viewport.SetMinSize(10.0f, 20.0f);
  viewport.SetMaxSize(1000.0f, 800.0f);

  EXPECT_TRUE(viewport.IsActive());
  EXPECT_EQ(viewport.GetProjectionType(), GRPVIEWPORT_PROJECTIONTYPE_ORTHO);
  EXPECT_FLOAT_EQ(viewport.GetPositionX(), 1.5f);
  EXPECT_FLOAT_EQ(viewport.GetPositionY(), 2.5f);
  EXPECT_FLOAT_EQ(viewport.GetWidth(), 100.0f);
  EXPECT_FLOAT_EQ(viewport.GetHeight(), 80.0f);
  EXPECT_FLOAT_EQ(viewport.GetMinWidth(), 10.0f);
  EXPECT_FLOAT_EQ(viewport.GetMinHeight(), 20.0f);
  EXPECT_FLOAT_EQ(viewport.GetMaxWidth(), 1000.0f);
  EXPECT_FLOAT_EQ(viewport.GetMaxHeight(), 800.0f);
}


TEST(UNITTESTS_GRPVIEWPORT_CLASSNAME, CreateCanvasOffline)
{
  GRPVIEWPORT viewport;
  GRPPROPERTIES props;

  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(32, 32);

  EXPECT_TRUE(viewport.CreateCanvas(props));
  ASSERT_NE(viewport.GetCanvas(), (GRP2DCANVAS*)NULL);
  EXPECT_TRUE(viewport.SetCanvasPosition(4.0f, 6.0f));
  EXPECT_FLOAT_EQ(viewport.GetCanvasPositionX(), 4.0f);
  EXPECT_FLOAT_EQ(viewport.GetCanvasPositionY(), 6.0f);
}


}
#endif
#endif
