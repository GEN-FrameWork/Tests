/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOIP.cpp
*
* @class      UNITTESTS_DATAIO_DIOIP
* @brief      DataIO unit tests for DIOIP class
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

#include "DIOIP.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOIP
{


TEST(DIOIP, DefaultsEmpty)
{
  DIOIP ip;

  EXPECT_TRUE(ip.IsEmpty());
}


TEST(DIOIP, SetFromStringAndGetXString)
{
  DIOIP   ip;
  XSTRING out;

  EXPECT_TRUE(ip.Set(_L("192.168.1.10")));
  EXPECT_FALSE(ip.IsEmpty());
  EXPECT_TRUE(ip.GetXString(out));
  EXPECT_EQ(out.Compare(_L("192.168.1.10")), 0);
}


TEST(DIOIP, SetBytesLocalAndMask)
{
  DIOIP ip;

  EXPECT_TRUE(ip.Set(127, 0, 0, 1));
  EXPECT_TRUE(ip.IsLocal());
  ASSERT_NE(ip.GetMask(), (DIOIPADDRESS*)NULL);
}


TEST(DIOIP, CompareAddresses)
{
  DIOIP a;
  DIOIP b;

  EXPECT_TRUE(a.Set(_L("10.0.0.1")));
  EXPECT_TRUE(b.Set(_L("10.0.0.1")));
  EXPECT_TRUE(a.Compare(b));
}


}
#endif
#endif
