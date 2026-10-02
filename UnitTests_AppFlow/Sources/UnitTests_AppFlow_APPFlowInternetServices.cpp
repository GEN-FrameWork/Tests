/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowInternetServices.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWINTERNETSERVICES
* @brief      AppFlow unit tests for APPFLOWINTERNETSERVICES class
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

#include "APPFlowInternetServices.h"
#include "APPFlowCFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_INTERNETSERVICES_ACTIVE
namespace TEST_APPFLOWINTERNETSERVICES
{


TEST(APPFLOWINTERNETSERVICES, ConstructExitFlagsWithoutIni)
{
  APPFLOWINTERNETSERVICES services;

  EXPECT_FALSE(services.HaveInternetConnection());
  EXPECT_EQ(services.GetInternetLatency(), (XDWORD)0);

  ASSERT_NE(services.GetAutomaticLocalIP(), (XSTRING*)NULL);
  ASSERT_NE(services.GetAllLocalIP(), (XSTRING*)NULL);
  ASSERT_NE(services.GetPublicIP(), (XSTRING*)NULL);

  // SetActivedExit requires Ini() (checkinternetconnection); without Ini it must stay false.
  EXPECT_FALSE(services.SetActivedExit(true));
  EXPECT_FALSE(services.IsActivedExit());

  EXPECT_TRUE(services.End());
}


TEST(APPFLOWINTERNETSERVICES, IniWithZeroCadenceCreatesSchedulerWithoutNetTasks)
{
  // Leave Clean() defaults (cadences 0). DoDefault would set cadence 30 and arm net checks.
  APPFLOWCFG cfg((XCHAR*)NULL);
  EXPECT_EQ(cfg.InternetServices_GetCheckInternetStatusCadence(), 0);
  EXPECT_EQ(cfg.InternetServices_GetCheckIPsChangeCadence(), 0);
  EXPECT_EQ(cfg.InternetServices_GetUpdateTimeByNTPCadence(), 0);

  APPFLOWINTERNETSERVICES services;
  EXPECT_TRUE(services.Ini(&cfg, 0));

  ASSERT_NE(services.GetXScheduler(), (XSCHEDULER*)NULL);
  EXPECT_EQ(services.GetCheckInternetConnection(), (DIOCHECKINTERNETCONNECTION*)NULL);
  EXPECT_FALSE(services.HaveInternetConnection());
  EXPECT_FALSE(services.SetActivedExit(true));

  EXPECT_TRUE(services.End());
  EXPECT_TRUE(cfg.End());
}


}
#endif
#endif
#endif
