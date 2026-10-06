/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOMAC.cpp
*
* @class      UNITTESTS_DATAIO_DIOMAC
* @brief      DataIO unit tests for DIOMAC class
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

#include "UnitTests_DataIO_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "DIOMAC.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOMAC
{


TEST(DIOMAC, DefaultsAreZero)
{
  DIOMAC mac;

  EXPECT_TRUE(mac.IsZero());
}


TEST(DIOMAC, SetFromStringAndGetXString)
{
  DIOMAC  mac;
  XSTRING input(_L("AA:BB:CC:DD:EE:FF"));
  XSTRING out;

  EXPECT_TRUE(mac.Set(input));
  EXPECT_FALSE(mac.IsZero());
  EXPECT_TRUE(mac.GetXString(out));
  EXPECT_EQ(out.Compare(_L("AA:BB:CC:DD:EE:FF"), true), 0);
}


TEST(DIOMAC, SetFromBytesAndIsEqual)
{
  DIOMAC mac1;
  DIOMAC mac2;
  XBYTE  bytes[DIOMAC_MAXSIZE] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };

  EXPECT_TRUE(mac1.Set(bytes));
  EXPECT_TRUE(mac2.Set(bytes));
  EXPECT_TRUE(mac1.IsEqual(&mac2));
  EXPECT_TRUE(mac1.IsEqual(mac2));
}


}
#endif
#endif
