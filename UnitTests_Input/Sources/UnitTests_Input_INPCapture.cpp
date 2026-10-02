/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPCapture.cpp
*
* @class      UNITTESTS_INPUT_INPCAPTURE
* @brief      Input unit tests for INPCAPTURE class
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

#include "UnitTests_Input_INPCapture.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPCapture.h"
#include "XBuffer.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef INP_CAPTURE_ACTIVE
namespace TEST_INPCAPTURE
{


TEST(UNITTESTS_INPCAPTURE_CLASSNAME, DefaultLimitAndGetters)
{
  INPCAPTURE capture;

  EXPECT_EQ(capture.GetLimit(), (XDWORD)0);
  EXPECT_EQ(capture.GetNKeys(), (XDWORD)0);
}


TEST(UNITTESTS_INPCAPTURE_CLASSNAME, SetLimitAndNKeysRoundTrip)
{
  INPCAPTURE capture;

  capture.SetLimit(INPCAPTURE_DEFAULTLIMIT);
  capture.SetNKeys(7);

  EXPECT_EQ(capture.GetLimit(), (XDWORD)INPCAPTURE_DEFAULTLIMIT);
  EXPECT_EQ(capture.GetNKeys(), (XDWORD)7);

  capture.SetLimit();
  EXPECT_EQ(capture.GetLimit(), (XDWORD)INPCAPTURE_DEFAULTLIMIT);
}


TEST(UNITTESTS_INPCAPTURE_CLASSNAME, GetBufferAndGetStringNonNull)
{
  INPCAPTURE capture;

  EXPECT_NE(capture.GetBuffer(), (XBUFFER*)NULL);
  EXPECT_NE(capture.GetString(), (XSTRING*)NULL);
}


TEST(UNITTESTS_INPCAPTURE_CLASSNAME, BaseActivateAndDeactivateReturnFalse)
{
  INPCAPTURE capture;

  EXPECT_FALSE(capture.Activate());
  EXPECT_FALSE(capture.Deactivate());
}


}
#endif
#endif
