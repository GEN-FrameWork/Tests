/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOAlerts.cpp
*
* @class      UNITTESTS_DATAIO_DIOALERTS
* @brief      DataIO unit tests for DIOALERTS class
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

#include "DIOAlerts.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_ALERTS_ACTIVE
namespace TEST_DIOALERTS
{


TEST(DIOALERT, SettersAndCopy)
{
  DIOALERT a;
  DIOALERT b;

  a.SetID(1001);
  a.SetLevel(DIOALERTLEVEL_WARNING);
  a.GetOrigin()->Set(__L("unit"));
  a.GetTitle()->Set(__L("title"));
  a.Get_Message()->Set(__L("message"));
  EXPECT_TRUE(a.Application_SetVersion(1, 2, 3));

  EXPECT_EQ(a.GetID(), (XDWORD)1001);
  EXPECT_EQ(a.GetLevel(), DIOALERTLEVEL_WARNING);
  EXPECT_EQ(a.GetOrigin()->Compare(__L("unit")), 0);
  EXPECT_EQ(a.GetTitle()->Compare(__L("title")), 0);
  EXPECT_EQ(a.Get_Message()->Compare(__L("message")), 0);

  EXPECT_TRUE(a.CopyFrom(&a));
  EXPECT_TRUE(b.CopyFrom(&a));
  EXPECT_EQ(b.GetID(), (XDWORD)1001);
}


TEST(DIOALERTS, CreateAlertWithoutSend)
{
  DIOALERTS& alerts = DIOALERTS::GetInstance();

  EXPECT_TRUE(alerts.Application_SetVersion(0, 0, 1));
  alerts.Application_GetID()->Set(__L("UnitTests_DataIO"));
  alerts.GetOrigin()->Set(__L("gtest"));

  DIOALERT* alert = alerts.CreateAlert(DIOALERTLEVEL_INFO, __L("t"), __L("m"));
  ASSERT_NE(alert, (DIOALERT*)NULL);
  EXPECT_EQ(alert->GetLevel(), DIOALERTLEVEL_INFO);

  EXPECT_TRUE(alerts.AddCondition(1, 0, 1));
  ASSERT_NE(alerts.GetCondition(1), (DIOALERT_CONDITION*)NULL);
  EXPECT_TRUE(alerts.DeleteAllConditions());

  delete alert;
  DIOALERTS::DelInstance();
}


}
#endif
#endif
#endif
