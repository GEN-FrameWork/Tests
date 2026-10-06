/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPScreen.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPSCREEN
* @brief      Graphic unit tests for GRPSCREEN class (offline, no Create/Show)
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

#include "UnitTests_Graphic_GRPScreen.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPScreen.h"
#include "GRPViewPort.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPSCREEN
{


TEST(UNITTESTS_GRPSCREEN_CLASSNAME, CreateScreenOfflinePropertiesAndStyles)
{
  GRPSCREEN* screen = GRPFACTORY::GetInstance().CreateScreen();
  ASSERT_NE(screen, (GRPSCREEN*)NULL);

  EXPECT_TRUE(screen->SetPropertys(640, 480, 96.0f, 0, GRPPROPERTYMODE_32_RGBA_8888));
  EXPECT_EQ(screen->GetWidth(), 640u);
  EXPECT_EQ(screen->GetHeight(), 480u);
  EXPECT_EQ(screen->GetMode(), GRPPROPERTYMODE_32_RGBA_8888);

  screen->Styles_Set(GRPSCREENSTYLE_NONE);
  screen->Style_Add(GRPSCREENSTYLE_TITLE);
  EXPECT_TRUE(screen->Style_Is(GRPSCREENSTYLE_TITLE));
  EXPECT_FALSE(screen->Styles_IsFullScreen());

  screen->SetCanClose(false);
  EXPECT_FALSE(screen->CanClose());
  screen->SetCanClose(true);

  ASSERT_NE(screen->GetTitle(), (XSTRING*)NULL);
  screen->GetTitle()->Set(_L("UnitTests Graphic"));
  EXPECT_EQ(screen->GetTitle()->Compare(_L("UnitTests Graphic")), 0);

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteScreen(screen));
}


TEST(UNITTESTS_GRPSCREEN_CLASSNAME, CreateViewportWithoutShow)
{
  GRPSCREEN* screen = GRPFACTORY::GetInstance().CreateScreen();
  ASSERT_NE(screen, (GRPSCREEN*)NULL);

  EXPECT_TRUE(screen->SetPropertys(320, 240, 96.0f, 0, GRPPROPERTYMODE_32_RGBA_8888));
  EXPECT_TRUE(screen->CreateViewport(_L("ut_vp"), 0.0f, 0.0f, 320.0f, 240.0f, 0, 0, 320, 240));

  GRPVIEWPORT* viewport = screen->GetViewport(_L("ut_vp"));
  ASSERT_NE(viewport, (GRPVIEWPORT*)NULL);
  EXPECT_FLOAT_EQ(viewport->GetWidth(), 320.0f);
  EXPECT_FLOAT_EQ(viewport->GetHeight(), 240.0f);

  EXPECT_TRUE(screen->DeleteAllViewports());
  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteScreen(screen));
}


}
#endif
#endif
