/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVectorFileSVGStyle.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVECTORFILESVGSTYLE
* @brief      Graphic unit tests for GRPVECTORFILESVGSTYLE class
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

#include "UnitTests_Graphic_GRPVectorFileSVGStyle.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "GRP2DColor.h"
#include "GRPVectorFileSVGStyle.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_SVG_ACTIVE
namespace TEST_GRPVECTORFILESVGSTYLE
{


TEST(UNITTESTS_GRPVECTORFILESVGSTYLE_CLASSNAME, ParseColorHexNoneAndRgb)
{
  GRP2DCOLOR_RGBA8 color;
  bool             isnone = false;
  XSTRING          value;

  value = __L("#FF0000");
  EXPECT_TRUE(GRPVECTORFILESVGSTYLE::ParseColor(value, color, isnone));
  EXPECT_FALSE(isnone);
  EXPECT_EQ(color.r, 255);
  EXPECT_EQ(color.g, 0);
  EXPECT_EQ(color.b, 0);

  value = __L("none");
  EXPECT_TRUE(GRPVECTORFILESVGSTYLE::ParseColor(value, color, isnone));
  EXPECT_TRUE(isnone);

  value = __L("rgb(10,20,30)");
  EXPECT_TRUE(GRPVECTORFILESVGSTYLE::ParseColor(value, color, isnone));
  EXPECT_FALSE(isnone);
  EXPECT_EQ(color.r, 10);
  EXPECT_EQ(color.g, 20);
  EXPECT_EQ(color.b, 30);
}


}
#endif
#endif
#endif
