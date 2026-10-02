/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPCapture_XEvent.cpp
*
* @class      UNITTESTS_INPUT_INPCAPTURE_XEVENT
* @brief      Input unit tests for INPCAPTURE_XEVENT class
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

#include "UnitTests_Input_INPCapture_XEvent.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPCapture_XEvent.h"
#include "XSubject.h"
#include "XBuffer.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef INP_CAPTURE_ACTIVE
namespace TEST_INPCAPTURE_XEVENT
{


TEST(UNITTESTS_INPCAPTURE_XEVENT_CLASSNAME, RoundTripFieldsAndBuffers)
{
  XSUBJECT subject;
  INPCAPTURE_XEVENT event(&subject, INPCAPTURE_XEVENT_TYPE_PRESSKEY);

  event.SetVKCode(0x41);
  event.SetScanCode(0x1E);
  event.SetFlags(0x0001);
  event.SetIsKeyLocked(true);
  event.SetNKeys(3);
  event.SetLimit(100);

  EXPECT_EQ(event.GetVKCode(), (XDWORD)0x41);
  EXPECT_EQ(event.GetScanCode(), (XWORD)0x1E);
  EXPECT_EQ(event.GetFlags(), (XDWORD)0x0001);
  EXPECT_TRUE(event.IsKeyLocked());
  EXPECT_EQ(event.GetNKeys(), (XDWORD)3);
  EXPECT_EQ(event.GetLimit(), (XDWORD)100);

  EXPECT_NE(event.GetBuffer(), (XBUFFER*)NULL);
  EXPECT_NE(event.GetString(), (XSTRING*)NULL);
}


TEST(UNITTESTS_INPCAPTURE_XEVENT_CLASSNAME, ConstructWithNullSubject)
{
  INPCAPTURE_XEVENT event(NULL, INPCAPTURE_XEVENT_TYPE_PRESSKEY);

  EXPECT_EQ(event.GetEventType(), (XDWORD)INPCAPTURE_XEVENT_TYPE_PRESSKEY);
  EXPECT_NE(event.GetBuffer(), (XBUFFER*)NULL);
  EXPECT_NE(event.GetString(), (XSTRING*)NULL);
}


}
#endif
#endif
