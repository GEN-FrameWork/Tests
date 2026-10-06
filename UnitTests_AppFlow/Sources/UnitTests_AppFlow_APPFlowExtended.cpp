/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowExtended.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWEXTENDED
* @brief      AppFlow unit tests for APPFLOWEXTENDED class
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

#include "APPFlowExtended.h"
#include "APPFlowCFG.h"

#ifdef APPFLOW_LOG_ACTIVE
#include "APPFlowLog.h"
#endif

#ifdef APPFLOW_EXTENDED_APPLICATIONSTATUS_ACTIVE
#include "APPFlowExtended_ApplicationStatus.h"
#endif

#ifdef APPFLOW_EXTENDED_INTERNETSTATUS_ACTIVE
#include "APPFlowExtended_InternetStatus.h"
#include "APPFlowInternetServices.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_EXTENDED_ACTIVE
namespace TEST_APPFLOWEXTENDED
{


TEST(APPFLOWEXTENDED, GetIsInstancedFalseThenGetAndDelWithoutAPPStart)
{
  if(APPFLOWEXTENDED::GetIsInstanced())
    {
      APPFLOWEXTENDED::GetInstance().APPEnd();
      APPFLOWEXTENDED::DelInstance();
    }

  EXPECT_FALSE(APPFLOWEXTENDED::GetIsInstanced());

  APPFLOWEXTENDED& extended = APPFLOWEXTENDED::GetInstance();
  EXPECT_TRUE(APPFLOWEXTENDED::GetIsInstanced());
  EXPECT_EQ(extended.GetCFG(), (APPFLOWCFG*)NULL);
  EXPECT_EQ(extended.GetConsole(), (APPFLOWCONSOLE*)NULL);

  EXPECT_TRUE(APPFLOWEXTENDED::DelInstance());
  EXPECT_FALSE(APPFLOWEXTENDED::GetIsInstanced());
}


TEST(APPFLOWEXTENDED, APPStartRejectsNullOrInactiveLogCfg)
{
  if(APPFLOWEXTENDED::GetIsInstanced())
    {
      APPFLOWEXTENDED::GetInstance().APPEnd();
      APPFLOWEXTENDED::DelInstance();
    }

  APPFLOWEXTENDED& extended = APPFLOWEXTENDED::GetInstance();

  EXPECT_FALSE(extended.APPStart(NULL, NULL));

  // Clean() leaves Log_IsActive false; APPStart must reject before starting threads/net paths.
  APPFLOWCFG cfg((XCHAR*)NULL);
  EXPECT_FALSE(cfg.Log_IsActive());
  EXPECT_FALSE(extended.APPStart(&cfg, NULL));

  EXPECT_EQ(extended.GetCFG(), (APPFLOWCFG*)NULL);

  EXPECT_TRUE(APPFLOWEXTENDED::DelInstance());
  EXPECT_TRUE(cfg.End());
}


TEST(APPFLOWEXTENDED, APPStartAndAPPEndWithOfflineCfg)
{
  if(APPFLOWEXTENDED::GetIsInstanced())
    {
      APPFLOWEXTENDED::GetInstance().APPEnd();
      APPFLOWEXTENDED::DelInstance();
    }

  #ifdef APPFLOW_LOG_ACTIVE
  if(APPFLOWLOG::GetIsInstanced())
    {
      APPFLOWLOG::GetInstance().End();
      APPFLOWLOG::DelInstance();
    }
  #endif

  XSTRING cfgname;
  cfgname = _L("unittests_appflow_extended");

  XSTRING cfgfilename;
  cfgfilename  = cfgname;
  cfgfilename += _L(".ini");

  ASSERT_TRUE(UNITTESTS_APPFLOW_HELPER::WriteOfflineAppFlowCfgAsset(cfgfilename.Get()));

  {
    APPFLOWCFG cfg(cfgname.Get());
    EXPECT_TRUE(cfg.DoVariableMapping());
    EXPECT_TRUE(cfg.DoDefault());
    EXPECT_TRUE(cfg.Load());
    EXPECT_TRUE(cfg.LoadReadjustment());

    #ifdef APPFLOW_CFG_LOG_ACTIVE
    ASSERT_TRUE(cfg.Log_IsActive());
    #endif
    #ifdef APPFLOW_CFG_INTERNETSERVICES_ACTIVE
    ASSERT_EQ(cfg.InternetServices_GetCheckInternetStatusCadence(), 0);
    ASSERT_EQ(cfg.InternetServices_GetCheckIPsChangeCadence(), 0);
    ASSERT_EQ(cfg.InternetServices_GetUpdateTimeByNTPCadence(), 0);
    #endif

    APPFLOWEXTENDED& extended = APPFLOWEXTENDED::GetInstance();
    EXPECT_TRUE(extended.APPStart(&cfg, NULL));
    EXPECT_EQ(extended.GetCFG(), &cfg);
    EXPECT_EQ(extended.GetConsole(), (APPFLOWCONSOLE*)NULL);

    #ifdef APPFLOW_EXTENDED_APPLICATIONSTATUS_ACTIVE
    ASSERT_NE(extended.GetApplicationStatus(), (APPFLOWEXTENDED_APPLICATIONSTATUS*)NULL);
    #endif
    #ifdef APPFLOW_EXTENDED_INTERNETSTATUS_ACTIVE
    ASSERT_NE(extended.GetInternetStatus(), (APPFLOWEXTENDED_INTERNETSTATUS*)NULL);
    ASSERT_NE(extended.GetInternetStatus()->GetInternetServices(), (APPFLOWINTERNETSERVICES*)NULL);
    EXPECT_FALSE(extended.GetInternetStatus()->GetHaveInternetConnection());
    #endif

    EXPECT_TRUE(extended.APPEnd());
    EXPECT_EQ(extended.GetCFG(), (APPFLOWCFG*)NULL);
    EXPECT_TRUE(APPFLOWEXTENDED::DelInstance());
    EXPECT_TRUE(cfg.End());
  }

  XPATH xpath;
  if(UNITTESTS_APPFLOW_HELPER::BuildAssetPath(xpath, cfgfilename.Get()))
    {
      UNITTESTS_APPFLOW_HELPER::EraseAsset(xpath);
    }

  if(UNITTESTS_APPFLOW_HELPER::BuildAssetPath(xpath, _L("unittests_appflow.log")))
    {
      UNITTESTS_APPFLOW_HELPER::EraseAsset(xpath);
    }
}


}
#endif
#endif
#endif
