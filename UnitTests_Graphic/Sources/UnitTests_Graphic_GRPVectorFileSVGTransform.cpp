/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVectorFileSVGTransform.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVECTORFILESVGTRANSFORM
* @brief      Graphic unit tests for GRPVECTORFILESVGTRANSFORM class
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

#include "UnitTests_Graphic_GRPVectorFileSVGTransform.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPVectorFileSVGTransform.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_SVG_ACTIVE
namespace TEST_GRPVECTORFILESVGTRANSFORM
{


TEST(UNITTESTS_GRPVECTORFILESVGTRANSFORM_CLASSNAME, ParseTranslateApplyAndIdentity)
{
  GRPVECTORFILESVGTRANSFORM transform;

  EXPECT_TRUE(transform.ParseFromString(__L("translate(10,20)")));

  double x = 1.0;
  double y = 2.0;
  transform.ApplyToPoint(x, y);
  EXPECT_DOUBLE_EQ(x, 11.0);
  EXPECT_DOUBLE_EQ(y, 22.0);

  transform.SetIdentity();
  EXPECT_TRUE(transform.IsIdentity());
}


}
#endif
#endif
#endif
