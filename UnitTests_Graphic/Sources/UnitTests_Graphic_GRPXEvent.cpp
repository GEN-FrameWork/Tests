/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPXEvent.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPXEVENT
* @brief      Graphic unit tests for GRPXEVENT class
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

#include "UnitTests_Graphic_GRPXEvent.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPXEvent.h"
#include "GRPViewPort.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPXEVENT
{


TEST(UNITTESTS_GRPXEVENT_CLASSNAME, DefaultPointersAndError)
{
  GRPXEVENT event(NULL, GRPXEVENT_TYPE_SCREEN_CREATED);

  EXPECT_EQ(event.GetScreen(), (GRPSCREEN*)NULL);
  EXPECT_EQ(event.GetViewport(), (GRPVIEWPORT*)NULL);
  EXPECT_FALSE(event.GetError());
  EXPECT_EQ(event.GetEventType(), (XDWORD)GRPXEVENT_TYPE_SCREEN_CREATED);
}


TEST(UNITTESTS_GRPXEVENT_CLASSNAME, SetScreenViewportAndError)
{
  GRPVIEWPORT viewport;
  GRPXEVENT   event(NULL, GRPXEVENT_TYPE_SCREEN_CHANGESIZE);

  event.SetViewport(&viewport);
  event.SetError(true);

  EXPECT_EQ(event.GetViewport(), &viewport);
  EXPECT_TRUE(event.GetError());
}


}
#endif
#endif
