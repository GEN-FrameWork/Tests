/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DPath.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DPATH
* @brief      Graphic unit tests for GRP2DPATH class
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

#include "UnitTests_Graphic_GRP2DPath.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRP2DPath.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRP2DPATH
{


TEST(UNITTESTS_GRP2DPATH_CLASSNAME, MoveLineCloseSizeDeleteAllFillRule)
{
  GRP2DPATH path;

  EXPECT_TRUE(path.MoveTo(0.0, 0.0));
  EXPECT_TRUE(path.LineTo(10.0, 0.0));
  EXPECT_TRUE(path.LineTo(10.0, 10.0));
  EXPECT_TRUE(path.Close());
  EXPECT_EQ(path.GetSize(), 4u);

  path.SetFillRule(GRP2DPATHFILLRULE_EVENODD);
  EXPECT_EQ(path.GetFillRule(), GRP2DPATHFILLRULE_EVENODD);

  EXPECT_TRUE(path.DeleteAll());
  EXPECT_EQ(path.GetSize(), 0u);
  EXPECT_TRUE(path.IsEmpty());
}


}
#endif
#endif
