/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DVertexs.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DVERTEXS
* @brief      Graphic unit tests for GRP2DVERTEXS class
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

#include "UnitTests_Graphic_GRP2DVertexs.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRP2DVertexs.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRP2DVERTEXS
{


TEST(UNITTESTS_GRP2DVERTEXS_CLASSNAME, AddGetDeleteAll)
{
  GRP2DVERTEXS vertexs;

  EXPECT_TRUE(vertexs.Add(1.5, 2.5));
  EXPECT_TRUE(vertexs.Add(3.0, 4.0));
  EXPECT_EQ(vertexs.GetSize(), 2u);

  GRP2DVERTEX* v0 = vertexs.Get(0);
  ASSERT_NE(v0, (GRP2DVERTEX*)NULL);
  EXPECT_DOUBLE_EQ(v0->x, 1.5);
  EXPECT_DOUBLE_EQ(v0->y, 2.5);

  EXPECT_TRUE(vertexs.DeleteAll());
  EXPECT_EQ(vertexs.GetSize(), 0u);
}


}
#endif
#endif
