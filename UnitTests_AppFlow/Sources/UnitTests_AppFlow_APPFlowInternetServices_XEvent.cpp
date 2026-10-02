/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowInternetServices_XEvent.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWINTERNETSERVICES_XEVENT
* @brief      AppFlow unit tests for APPFLOWINTERNETSERVICES_XEVENT class
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

#include "UnitTests_AppFlow_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "APPFlowInternetServices_XEvent.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_INTERNETSERVICES_ACTIVE
namespace TEST_APPFLOWINTERNETSERVICES_XEVENT
{


TEST(APPFLOWINTERNETSERVICES_XEVENT, ConnexionStateLatencyAndIPChangeFields)
{
  APPFLOWINTERNETSERVICES_XEVENT event((XSUBJECT*)NULL);

  EXPECT_EQ(event.GetInternetConnexionState(), APPFLOWINTERNETSERVICES_CHECKINTERNETCONNEXION_STATE_NONE);
  event.SetInternetConnexionState(APPFLOWINTERNETSERVICES_CHECKINTERNETCONNEXION_STATE_CHECKED);
  EXPECT_EQ(event.GetInternetConnexionState(), APPFLOWINTERNETSERVICES_CHECKINTERNETCONNEXION_STATE_CHECKED);

  event.SetLatency(77);
  EXPECT_EQ(event.GetLatency(), (XDWORD)77);

  event.SetInternetConnextionCut(NULL);
  EXPECT_EQ(event.GetInternetConnextionCut(), (DIOCHECKTCPIPCONNECTION_CUT*)NULL);

  event.SetIsChangePublicIP(true);
  event.SetIsChangeLocalIP(true);
  EXPECT_TRUE(event.IsChangePublicIP());
  EXPECT_TRUE(event.IsChangeLocalIP());

  event.GetChangePublicIP()->Set(__L("203.0.113.10"));
  event.GetChangeLocalIP()->Set(__L("192.168.1.10"));
  EXPECT_EQ(event.GetChangePublicIP()->Compare(__L("203.0.113.10")), 0);
  EXPECT_EQ(event.GetChangeLocalIP()->Compare(__L("192.168.1.10")), 0);

  event.SetNChangesIP(3);
  event.SetNChangesLocalIP(1);
  event.SetNChangesPublicIP(2);
  EXPECT_EQ(event.GetNChangesIP(), (XDWORD)3);
  EXPECT_EQ(event.GetNChangesLocalIP(), (XDWORD)1);
  EXPECT_EQ(event.GetNChangesPublicIP(), (XDWORD)2);
}


}
#endif
#endif
#endif
