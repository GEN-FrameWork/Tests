/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOLocation.cpp
*
* @class      UNITTESTS_DATAIO_DIOLOCATION
* @brief      DataIO unit tests for DIOLOCATIONADDRESS class
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

#include "DIOLocationAddress.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOLOCATIONADDRESS
{


TEST(DIOLOCATIONADDRESS, StreetCityStateCountryPostal)
{
  DIOLOCATIONADDRESS address;

  address.GetStreet()->Set(_L("Main St"));
  address.GetCity()->Set(_L("Town"));
  address.GetState()->Set(_L("ST"));
  address.GetCountry()->Set(_L("Country"));
  address.SetPostalCode(12345);

  EXPECT_EQ(address.GetStreet()->Compare(_L("Main St")), 0);
  EXPECT_EQ(address.GetCity()->Compare(_L("Town")), 0);
  EXPECT_EQ(address.GetState()->Compare(_L("ST")), 0);
  EXPECT_EQ(address.GetCountry()->Compare(_L("Country")), 0);
  EXPECT_EQ(address.GetPostalCode(), (XDWORD)12345);
}


}
#endif
#endif
