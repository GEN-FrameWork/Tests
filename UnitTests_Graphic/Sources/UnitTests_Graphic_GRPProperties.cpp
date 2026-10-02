/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPProperties.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPPROPERTIES
* @brief      Graphic unit tests for GRPPROPERTIES class
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

#include "UnitTests_Graphic_GRPProperties.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPProperties.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPPROPERTIES
{


TEST(UNITTESTS_GRPPROPERTIES_CLASSNAME, DefaultModeAndCenteredPosition)
{
  GRPPROPERTIES props;

  EXPECT_EQ(props.GetMode(), GRPPROPERTYMODE_24_BGR_888);
  EXPECT_EQ(props.GetPositionX(), GRPPROPERTYMODE_SCREEN_CENTER);
  EXPECT_EQ(props.GetPositionY(), GRPPROPERTYMODE_SCREEN_CENTER);
  EXPECT_EQ(props.GetWidth(), 0u);
  EXPECT_EQ(props.GetHeight(), 0u);
  EXPECT_EQ(props.GetBitsperPixel(), 24);
  EXPECT_EQ(props.GetBytesperPixel(), 3);
}


TEST(UNITTESTS_GRPPROPERTIES_CLASSNAME, SetSizeModeAndBitsPerPixel)
{
  GRPPROPERTIES props;

  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(320, 240);
  props.SetPosition(8, 16);
  props.SetDPI(96.0f);
  props.SetIsBufferInverse(true);

  EXPECT_EQ(props.GetMode(), GRPPROPERTYMODE_32_RGBA_8888);
  EXPECT_EQ(props.GetWidth(), 320u);
  EXPECT_EQ(props.GetHeight(), 240u);
  EXPECT_EQ(props.GetPositionX(), 8);
  EXPECT_EQ(props.GetPositionY(), 16);
  EXPECT_FLOAT_EQ(props.GetDPI(), 96.0f);
  EXPECT_TRUE(props.IsBufferInverse());
  EXPECT_EQ(props.GetBitsperPixel(), 32);
  EXPECT_EQ(props.GetBytesperPixel(), 4);
}


TEST(UNITTESTS_GRPPROPERTIES_CLASSNAME, CopyPropertysAndEqualSize)
{
  GRPPROPERTIES source;
  GRPPROPERTIES dest;

  source.SetMode(GRPPROPERTYMODE_24_RGB_888);
  source.SetSize(100, 50);

  dest.CopyPropertysFrom(&source);

  EXPECT_EQ(dest.GetMode(), GRPPROPERTYMODE_24_RGB_888);
  EXPECT_EQ(dest.GetWidth(), 100u);
  EXPECT_EQ(dest.GetHeight(), 50u);
  EXPECT_EQ(source.IsEqualSizeTo(&dest), ISEQUAL);

  dest.SetSize(100, 100);
  EXPECT_EQ(source.IsEqualSizeTo(&dest), ISLESS);
}


}
#endif
#endif
