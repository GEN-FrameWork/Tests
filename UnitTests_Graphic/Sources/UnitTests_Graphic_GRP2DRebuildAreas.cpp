/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DRebuildAreas.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DREBUILDAREAS
* @brief      Graphic unit tests for GRP2DREBUILDAREAS class
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

#include "UnitTests_Graphic_GRP2DRebuildAreas.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPProperties.h"
#include "GRP2DCanvas.h"
#include "GRP2DRebuildAreas.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRP2DREBUILDAREAS
{


TEST(UNITTESTS_GRP2DREBUILDAREAS_CLASSNAME, SetExcessEdgeCreateAndDeleteAll)
{
  GRP2DREBUILDAREAS areas;

  EXPECT_TRUE(areas.SetExcessEdge(4));
  EXPECT_EQ(areas.GetExcessEdge(), 4u);

  // Base GetBitmap returns NULL, so CreateRebuildArea needs a canvas override.
  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(64, 64);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());

  EXPECT_TRUE(canvas->SetExcessEdge(2));
  EXPECT_TRUE(canvas->CreateRebuildArea(8.0, 8.0, 16.0, 16.0));
  ASSERT_NE(canvas->GetRebuildAreas(), (XVECTOR<GRP2DREBUILDAREA*>*)NULL);
  EXPECT_GT(canvas->GetRebuildAreas()->GetSize(), 0u);

  EXPECT_TRUE(canvas->DeleteAllRebuildAreas());
  EXPECT_EQ(canvas->GetRebuildAreas()->GetSize(), 0u);

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


}
#endif
#endif
