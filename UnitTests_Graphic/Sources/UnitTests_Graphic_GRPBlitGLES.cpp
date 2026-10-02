/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPBlitGLES.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPBLITGLES
* @brief      Graphic unit tests for GRPBLITGLES class (offline, no Create/Update)
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

#include "UnitTests_Graphic_GRPBlitGLES.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#ifdef GRP_OPENGL_ACTIVE
#ifdef WINDOWS
#include "GRPWINDOWSBlitGLES.h"
#endif
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_OPENGL_ACTIVE
namespace TEST_GRPBLITGLES
{


#ifdef WINDOWS

TEST(UNITTESTS_GRPBLITGLES_CLASSNAME, ConstructAndSettersWithoutCreate)
{
  // Offline-only: do not call Create/Update (would require EGL MakeCurrent).
  GRPWINDOWSBLITGLES blit;

  blit.SetFlipY(true);
  EXPECT_TRUE(blit.GetFlipY());

  blit.SetFlipX(true);
  EXPECT_TRUE(blit.GetFlipX());

  blit.SetUseVSync(false);
  EXPECT_FALSE(blit.GetUseVSync());

  blit.SetUsePBO(false);
  EXPECT_FALSE(blit.GetUsePBO());

  blit.SetUseAlpha(true);
  EXPECT_TRUE(blit.GetUseAlpha());

  blit.SetRotation(GRPSCREENROTATION_NONE);
  EXPECT_EQ(blit.GetRotation(), GRPSCREENROTATION_NONE);
}

#else

// GRPWINDOWSBlitGLES is Windows-only; other platforms skip this suite body.
TEST(UNITTESTS_GRPBLITGLES_CLASSNAME, SkipNonWindows)
{
  SUCCEED();
}

#endif


}
#endif
#endif
#endif
