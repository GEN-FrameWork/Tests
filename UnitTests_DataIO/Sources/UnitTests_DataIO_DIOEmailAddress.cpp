/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOEmailAddress.cpp
*
* @class      UNITTESTS_DATAIO_DIOEMAILADDRESS
* @brief      DataIO unit tests for DIOEMAILADDRESS class
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

#include "DIOEmailAddress.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOEMAILADDRESS
{


TEST(DIOEMAILADDRESS, ValidAddressUserDomain)
{
  DIOEMAILADDRESS email(_L("user@example.local"));
  XSTRING         user;
  XSTRING         domain;

  EXPECT_TRUE(email.IsValid());
  EXPECT_TRUE(email.GetUser(user));
  EXPECT_TRUE(email.GetDomain(domain));
  EXPECT_EQ(user.Compare(_L("user")), 0);
  EXPECT_EQ(domain.Compare(_L("example.local")), 0);
}


TEST(DIOEMAILADDRESS, InvalidWithoutAt)
{
  DIOEMAILADDRESS email(_L("not-an-email"));

  EXPECT_FALSE(email.IsValid());
}


}
#endif
#endif
