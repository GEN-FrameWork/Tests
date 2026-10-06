/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOProtocol_ApplicationData.cpp
*
* @class      UNITTESTS_DATAIO_DIOPROTOCOL_APPLICATIONDATA
* @brief      DataIO unit tests for DIOPROTOCOL_APPLICATIONDATA class
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

#include "DIOProtocol_ApplicationData.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_PROTOCOL_ACTIVE
namespace TEST_DIOPROTOCOL_APPLICATIONDATA
{


TEST(DIOPROTOCOL_APPLICATIONDATA, VersionFieldsAndName)
{
  DIOPROTOCOL_APPLICATIONDATA data;

  data.protocolversion = 1;
  data.protocolsubversion = 0;
  data.protocolsubversionerr = 0;
  data.applicationversion = 2;
  data.applicationsubversion = 3;
  data.applicationsubversionerr = 4;
  data.applicationname.Set(_L("UnitTests_DataIO"));

  EXPECT_EQ(data.protocolversion, (XWORD)1);
  EXPECT_EQ(data.applicationversion, (XWORD)2);
  EXPECT_EQ(data.applicationname.Compare(_L("UnitTests_DataIO")), 0);
}


#ifdef DIO_ALERTS_ACTIVE
TEST(DIOPROTOCOL_APPLICATIONDATA, AlertAddExtractDelete)
{
  DIOPROTOCOL_APPLICATIONDATA data;
  DIOALERT                    alert;
  DIOALERT                    extracted;

  alert.SetLevel(DIOALERTLEVEL_INFO);
  alert.GetTitle()->Set(_L("t"));
  alert.Get_Message()->Set(_L("m"));

  EXPECT_TRUE(data.AddAlert(alert));
  EXPECT_TRUE(data.AddAlert(alert));
  EXPECT_TRUE(data.ExtractAlert(0, extracted));
  EXPECT_EQ(extracted.GetLevel(), DIOALERTLEVEL_INFO);
  // ExtractAlert already removes the entry; DeleteAllAlerts clears any remaining.
  EXPECT_TRUE(data.DeleteAllAlerts());
}
#endif


}
#endif
#endif
#endif
