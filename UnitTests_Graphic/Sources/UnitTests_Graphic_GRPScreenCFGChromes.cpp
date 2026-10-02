/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPScreenCFGChromes.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPSCREENCFGCHROMES
* @brief      Graphic unit tests for GRPSCREENCFGCHROMES class
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

#include "UnitTests_Graphic_GRPScreenCFGChromes.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPScreenCFGChromes.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPSCREENCFGCHROMES
{


TEST(UNITTESTS_GRPSCREENCFGCHROMES_CLASSNAME, SettersAndCopyToFrom)
{
  GRPSCREENCFGCHROMES source;
  GRPSCREENCFGCHROMES target;

  source.SetNativeCaptionActive(false);
  source.SetNativeTitleActive(false);
  source.SetNativeIconActive(false);
  source.SetNativeMaximizeActive(false);
  source.SetNativeMinimizeActive(true);
  source.SetNativeCloseActive(true);
  source.SetResizeActive(false);

  EXPECT_FALSE(source.GetNativeCaptionActive());
  EXPECT_FALSE(source.GetNativeTitleActive());
  EXPECT_FALSE(source.GetNativeIconActive());
  EXPECT_FALSE(source.GetNativeMaximizeActive());
  EXPECT_TRUE(source.GetNativeMinimizeActive());
  EXPECT_TRUE(source.GetNativeCloseActive());
  EXPECT_FALSE(source.GetResizeActive());

  EXPECT_TRUE(source.CopyTo(target));
  EXPECT_FALSE(target.GetNativeCaptionActive());
  EXPECT_FALSE(target.GetNativeTitleActive());
  EXPECT_FALSE(target.GetResizeActive());

  GRPSCREENCFGCHROMES restored;
  restored.SetNativeCaptionActive(true);
  restored.SetNativeTitleActive(true);
  restored.SetResizeActive(true);

  EXPECT_TRUE(target.CopyFrom(restored));
  EXPECT_TRUE(target.GetNativeCaptionActive());
  EXPECT_TRUE(target.GetNativeTitleActive());
  EXPECT_TRUE(target.GetResizeActive());
}


}
#endif
#endif
